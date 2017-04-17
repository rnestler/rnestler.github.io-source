Visiting Warsaw Hackerspace
===========================

:tags: tour de hackerspace, hackerspace, travelling
:language: en
:status: draft
:summary: Visiting Warsaw Hackerspace

I was warned on IRC that the activity would be rather low in the Warsaw
Hackerspace Due to being Easter.  So when I arrived in Warsaw I just monitored
their `member tracking site`_ from time to time until it showed some people
being present.

The entry to the space was a bit hard to find, because it's in the basement.
But they later told me, that they will move their space to a different location
next month anyway.

.. figure:: /images/tour_de_hackerspace/warsaw/warsaw_entry.jpg
    :alt: Entry to the Warsaw Hackerspace
    :align: center
    :width: 80%
    :figwidth: 80%

    Entry to the `Warsaw Hackerspace`_

On arrival they showed me around their hackerspace.  Of course they have a
laser-cutter [#]_ and some 3D printers.

.. figure:: /images/tour_de_hackerspace/warsaw/warsaw_laser_cutter.jpg
    :alt: Laser cutter and 3D printers
    :align: center
    :width: 80%
    :figwidth: 80%

    Laser cutter and 3D printers

I was told, that the `Warsaw Hackerspace`_ has around 100 members consisting of
a good mix of computer science, electronic engineering, mechanical engineering
and other people.

What really impressed me was the equipment in their work shop! They have
amongst other stuff a CNC mill and `lathe`_,  which they control using
`linuxcnc`_.

.. figure:: /images/tour_de_hackerspace/warsaw/warsaw_work_shop_cnc.jpg
    :alt: CNC mill
    :align: center
    :width: 80%
    :figwidth: 80%

    CNC mill

They also have equipment to produce their own PCBs, using a cheap UV nail
curing lamp.

.. figure:: /images/tour_de_hackerspace/warsaw/warsaw_pcb_manufactoring.jpg
    :alt: PCB manufactoring equipment
    :align: center
    :width: 80%
    :figwidth: 80%

    PCB manufactoring equipment

Also impressive was their retro computing collection! Amongst other devices
they own a VT520 terminal which they use to print the messages posted on IRC.

.. figure:: /images/tour_de_hackerspace/warsaw/warsaw_vt520.jpg
    :alt: VT520 terminal
    :align: center
    :width: 80%
    :figwidth: 80%

    VT520 terminal used to print IRC messages

When I asked for a beverage, they showed me there vending machine, which is
broken and can't accept coins anymore.  But stand back, they hacked it to hook
up with their internal payment system!  It's apparently as simple as hooking up
a Raspberry Pi to the `Multidrop bus`_ to control the machine.

.. figure:: /images/tour_de_hackerspace/warsaw/warsaw_vending_machine.jpg
    :alt: Hacked vending machine
    :align: center
    :width: 80%
    :figwidth: 80%

    Hacked vending machine

Later in the evening I had an awesome debugging session with one of their
members who tried to intercept C library calls (This was part of an university
assignment).  Since I never looked into how dynamic linking works in Linux,
this was very interesting for me!  Maybe I'll write a separate blog post about
that if I find time to dig a bit deeper into the topic.

I really enjoyed the time I spent with this awesome and very active
hackerspace! My next stop will be Hackerspace Kraków!

.. [#] We should really get a laser-cutter for coredump. This will be the first thing I will do when I return!

.. _`member tracking site`: http://at.hackerspace.pl/
.. _`Warsaw Hackerspace`: https://www.hackerspace.pl/
.. _`lathe`: /images/tour_de_hackerspace/warsaw/warsaw_work_show_cnc_lathe.jpg
.. _`linuxcnc`: http://linuxcnc.org/
.. _`Multidrop bus`: https://en.wikipedia.org/wiki/Multidrop_bus#MDB_in_Vending_Machines
