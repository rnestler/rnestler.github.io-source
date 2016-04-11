C++ List of ScopeGuard
======================

:tags: programming, C++
:language: en
:summary: Implementing a easy to use list of ScopeGuard

Recently the developer of `LibrePCB <https://github.com/LibrePCB/LibrePCB>`_
asked me about a C++ pattern to undo parts of an action if an exception gets
thrown in the middle of it.

Of course he basically described the main usage of a ScopeGuard. I went ahead
and `implemented one <https://github.com/LibrePCB/LibrePCB/pull/57>`_ based on
a `talk of Andrei Alexandrescu
<https://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2012-Andrei-Alexandrescu-Systematic-Error-Handling-in-C>`_

Basic Use of a ScopeGuard
-------------------------

The ScopeGuard allows to write transactional code that will undo previous parts
if later code throws an exception.

.. sourcecode:: cpp

    myVector.push_back(item);
    auto guard = scopeGuard([&]() { myVector.pop_back() });

    // Do stuff that may trow
    database.add(item);

    // everything worked, so don't undo
    guard.dismiss();


Using C++11 and later the implementation is fairly simple:

.. include:: ../../examples/scopeguard/scopeguard.h
    :code: cpp

Why a ScopeGuardList?
---------------------

If you have a transaction that consists of a lot of steps that may throw and
need to be undone it leads to code like the following:

.. sourcecode:: cpp

    doThing1();
    auto guard = makeGuard([&]() { undoThing1(); });
    doThing2();
    auto guard = makeGuard([&]() { undoThing2(); });
    doThing3();
    auto guard = makeGuard([&]() { undoThing3(); });

    // Do stuff that may trow

    guard1.dismiss();
    guard2.dismiss();
    guard3.dismiss();


Things get even worse when doing something in a loop:

.. sourcecode:: cpp

    for (int i=0; i<10; ++i) {
        doStuff(i);
        // how do we create a guard for every operation?
    }


To avoid that repetition and the potential error of a missing call to
``dismiss()`` we came up with a ``ScopeGuardList``.

Implementation With std::function<>
-----------------------------------

A simple implementation just contains a list of ``std::function<>``:

.. include:: ../../examples/scopeguard/scopeguardlist.h
    :code: cpp

This implementation uses the type erasure of ``std::function`` to store several
undo functions. While being fairly simple it performs worse compared to the
above ScopeGuard implementation.

A quick benchmark showed that the ``ScopeGuard`` performs ~14 times faster than
``ScopeGuardList``:

.. include:: ../../examples/scopeguard/benchmark.cpp
    :code: cpp


.. table:: Benchmark with different optimization levels

   =====  ================== =====================
   -O$N   Time[s] ScopeGuard Time[s] ScopGuardList
   =====  ================== =====================
   0      0.178144           2.61144
   1      0.0180427          0.286136
   2      0.0170452          0.283548
   3      0.0170423          0.289958
   =====  ================== =====================

Since the ``ScopeGuardList`` isn't used in any performance critical part in
LibrePCB we didn't look further for a better performing way without type
erasure.

Do you have any comments, found a bug or an error? Please leave a note on
`Reddit <https://reddit.org>`_

