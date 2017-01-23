Switching from SLiM to LightDM
==============================

:tags: Linux, ArchLinux, SLiM, LightDM
:language: en
:summary: Switching from SLiM to LightDM
:status: draft

For a long time I have been using `SLiM`_ as my display manager on ArchLinux.
It worked quite well for me, but is unmaintained since at least 3 years. Also
according to the `ArchLinux WiKi`_ there are issues regarding to systemd
compatibility. Also the Linux desktop is headed towards Wayland so I need a
display manager which can start Wayland sessions.

So my choice fell on `LightDM`_, which should "support different display
technologies (X, Mir, Wayland, ...)" according to their website.

Installing it on ArchLinux is as easy as:

.. sourcecode:: shell

   sudo pacman -S lightdm-gtk-greeter

Then we need to deactivate SLiM and activate LightDM:

.. sourcecode:: shell

   sudo systemctl disable slim.service
   sudo systemctl enable lightdm.service

To switch without a reboot one needs to logout from the X-session, switch to a
TTY with Ctrl-Alt-1 and stop SLiM and start LightDM:

.. sourcecode:: shell

   sudo systemctl stop slim.service
   sudo systemctl start lightdm.service

After that I could login just to notice that my `~/.xinitrc` wasn't getting
executed, so my helper tools like nm-applet weren't running. Since I already
solved that issue under `Ubuntu`_, I was a bit surprised that I need to solve
it differently under ArchLinux according to `the WiKi`_:

.. sourcecode:: shell

    mv ~/.xinitrc ~/.xprofile
    vim ~/.xprofile # remove the "exec awesome" line

After that I could enjoy a working X-Session with the `awesome window manager`_
again, while looking forward to a Wayland based desktop, maybe running the `Way
Cooler`_ window manager.

.. _`SLiM`: https://wiki.archlinux.org/index.php/SLiM
.. _`ArchLinux WiKi`: https://wiki.archlinux.org/index.php/SLiM
.. _`awesome window manager`: https://awesomewm.org/
.. _`gnome-keyring-daemon`: https://wiki.gnome.org/Projects/GnomeKeyring
.. _`LightDM`: https://freedesktop.org/wiki/Software/LightDM/
.. _`Ubuntu`: https://rnestler.github.io/setting-up-the-awesome-window-manager-in-ubuntu-1604.html
.. _`the WiKi`: https://wiki.archlinux.org/index.php/LightDM#Migrating_from_SLiM
.. _`Way Cooler`: https://github.com/Immington-Industries/way-cooler
