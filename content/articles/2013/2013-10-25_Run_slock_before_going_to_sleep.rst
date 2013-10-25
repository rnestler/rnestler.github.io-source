Run slock before going to sleep
===============================

:tags: systemd, slock, suspend
:language: en
:summary: How to configure systemd to run slock when going to sleep

As noted in my previous post, I configured my system to run slock as soon as
the system enters sleep state.  This is how its done.

First we create a new systemd unit in /etc/systemd/system called
suspend@.service


.. sourcecode:: ini

    [Unit]
    Description=User suspend actions
    Before=sleep.target

    [Service]
    User=%I
    Type=simple
    Environment=DISPLAY=:0
    ExecStart=/usr/bin/slock

    [Install]
    WantedBy=sleep.target


So what did we do? We created a unit that runs before sleep.target is reached.
This unit will run as a configurable user by enabling `suspend@$USER.service`

.. sourcecode:: console

  # systemctl enable suspend@$USER.service

So the /usr/bin/slock runs as $USER.  To be able to communicate with the
X-Server we need to set the DISPLAY variable to :0.

So now when your system is going to sleep systemd should start slock.

Sadly this works only for a one user system since the username is hardcoded
when enabling the unit file.  To make it work with multible users one would
need to create a script which determines which user is running the X-Server
then change to this user and lock the screen.
