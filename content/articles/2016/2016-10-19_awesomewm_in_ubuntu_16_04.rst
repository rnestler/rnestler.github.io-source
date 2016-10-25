Setting up the Awesome Window Manager in Ubuntu 16.04
=====================================================

:tags: Linux, Ubuntu, awesome window manager
:language: en
:summary: Setting up the awesome window manager under Ubuntu 16.04
:status: draft

My window manager of choice is the `awesome window manager`_. On my private
laptop I have it setup together with the display manager `SLiM`_ and a custom
``.xinitrc`` which starts a few helpers like the `gnome-keyring-daemon`_.

On my work laptop I have Ubuntu 16.04 installed.  Ubuntu uses `LightDM`_ (The
Light Display Manager) to manage logins. After installing awesome with ``sudo
apt install awesome`` LightDM will allow you to start an awesome session.  This
is due to the ``/usr/share/xsessions/awesome.desktop`` file contained in the
awesome package.

Unfortunately this starts awesome directly and does not execute the
``~/.xinitrc`` file.  But it does load the various ``/etc/X11/Xsession.d/``
files which will then load the ``~/.xsessionrc`` file if it exists.  When
``.xsessionrc`` gets loaded it will pass the session to be started as the first
argument (``$1``). So to start any helpers we create it with the following
content:

.. sourcecode:: bash

    #!/bin/sh
    #
    # ~/.xsessionrc
    #

    case $1 in
    awesome)
        export $(gnome-keyring-daemon -s -c pkcs11,secrets,ssh,gpg)
        ;;
    esac

This starts the gnome-keyring-daemon and export the ``SSH_AUTH_SOCK`` variable,
but only if we are trying to start an awesome session.

.. _`awesome window manager`: https://awesomewm.org/
.. _`SLiM`: https://wiki.archlinux.org/index.php/SLiM
.. _`gnome-keyring-daemon`: https://wiki.gnome.org/Projects/GnomeKeyring
.. _`LightDM`: https://freedesktop.org/wiki/Software/LightDM/
