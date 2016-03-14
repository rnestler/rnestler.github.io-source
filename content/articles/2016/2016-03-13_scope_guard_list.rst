C++ List of ScopeGuard
======================

:tags: programming, C++
:language: en
:summary: Implementing a easy to use List of ScopeGuard

I recently implemented a ScopeGuard based on a `talk of Andrei Alexandrescu
<https://channel9.msdn.com/Shows/Going+Deep/C-and-Beyond-2012-Andrei-Alexandrescu-Systematic-Error-Handling-in-C>`_
for `LibrePCB <https://github.com/LibrePCB/LibrePCB>`_.

Usage of a ScopeGuard
---------------------

The ScopeGuard allows to write transactional code that will undo previous parts
if later code throws an exception.

.. sourcecode:: cpp

    doThing1();
    auto guard = makeGuard([&]() { undoThing1(); });

    // Do stuff that may trow

    // everything worked, so don't undo
    guard.dismiss();


.. sourcecode:: cpp

    struct ScopeGuardBase {
        ScopeGuardBase():
            mActive(true)
        { }

        ScopeGuardBase(ScopeGuardBase&& rhs):
            mActive(rhs.mActive)
        {
            rhs.dismiss();
        }

        void dismiss() noexcept
        { mActive = false; }

    protected:
        ~ScopeGuardBase() = default;
        bool mActive;
    };

    template<class Fun>
    struct ScopeGuard: public ScopeGuardBase {
        ScopeGuard() = delete;
        ScopeGuard(const ScopeGuard&) = delete;

        ScopeGuard(Fun f) noexcept:
            ScopeGuardBase(),
            mF(std::move(f))
        { }

        ScopeGuard(ScopeGuard&& rhs) noexcept :
            ScopeGuardBase(std::move(rhs)),
            mF(std::move(rhs.mF))
        { }

        ~ScopeGuard() noexcept
        {
            if (mActive) {
                try { mF(); } catch(...) {}
            }
        }

        ScopeGuard& operator=(const ScopeGuard&) = delete;

    private:
        Fun mF;
    };



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


To avoid that repetition and the potential error of a missing call to dismiss
we came up with a ScopeGuardList.

Using std::function<>
---------------------

One implementation just contained a list of std::function<>

.. sourcecode:: cpp

    struct ScopeGuardList : public ScopeGuardBase {
        ScopeGuardList() = default;

        ScopeGuardList(ScopeGuardList&& rhs):
            ScopeGuardBase(std::move(rhs)),
            mScopeGuards(std::move(rhs.mScopeGuards))
        { }

        ~ScopeGuardList() {
            if (mActive) {
                for (auto& scopeGuard : mScopeGuards) {
                    scopeGuard();
                }
            }
        }

        template<class Fun> void add(Fun f)
        { mScopeGuards.emplace_back(std::move(f)); }

    private:
        std::vector<std::function<void()>> mScopeGuards;
    };

Have comments? Discuss on `Hacker News <https://news.ycombinator.com/`_ or `Reddit <https://>`

