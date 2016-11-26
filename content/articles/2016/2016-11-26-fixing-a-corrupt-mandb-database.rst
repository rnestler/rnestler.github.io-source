Fixing a Corrupt mandb Database
===============================

:tags: Linux, ArchLinux, man-db
:language: en
:summary: Fixing a corrupt mandb database
:status: draft

Recently, probably due to an unexpected power failure, the `man page`_ cache on
my machine which is managed by ``mandb`` got corrupt. I noticed when
``systemctl`` showed the ``man-db.service`` as failed:

.. sourcecode:: bash

    % sudo systemctl
    ...
    ● man-db.service                     loaded failed failed    Update man-db cache
    ...

``systemctl status`` didn't reveal that much information on the issue:

.. sourcecode:: bash

    % sudo systemctl status man-db.service
    ● man-db.service - Update man-db cache
       Loaded: loaded (/usr/lib/systemd/system/man-db.service; static; vendor preset: disabled)
       Active: failed (Result: exit-code) since Sam 2016-11-26 16:47:53 CET; 10min ago
      Process: 23481 ExecStart=/usr/bin/mandb (code=exited, status=1/FAILURE)
      Process: 23475 ExecStart=/usr/bin/mkdir -p /var/cache/man (code=exited, status=0/SUCCESS)
     Main PID: 23481 (code=exited, status=1/FAILURE)

    Nov 26 16:47:53 tuxedo mandb[23481]: Handbuchseiten unter /usr/share/man/ru.KOI8-R werden verar
    Nov 26 16:47:53 tuxedo mandb[23481]: Alte Datenbankeinträge in /usr/share/man/tr werden gelösch
    Nov 26 16:47:53 tuxedo mandb[23481]: Handbuchseiten unter /usr/share/man/tr werden verarbeitet
    Nov 26 16:47:53 tuxedo mandb[23481]: Alte Datenbankeinträge in /usr/share/man/fi werden gelösch
    Nov 26 16:47:53 tuxedo mandb[23481]: Handbuchseiten unter /usr/share/man/fi werden verarbeitet
    Nov 26 16:47:53 tuxedo mandb[23481]: Alte Datenbankeinträge in /usr/share/man/zh werden gelösch
    Nov 26 16:47:53 tuxedo systemd[1]: man-db.service: Main process exited, code=exited, status=1/F
    Nov 26 16:47:53 tuxedo systemd[1]: Failed to start Update man-db cache.
    Nov 26 16:47:53 tuxedo systemd[1]: man-db.service: Unit entered failed state.
    Nov 26 16:47:53 tuxedo systemd[1]: man-db.service: Failed with result 'exit-code'.


So I ran ``mandb`` manually to figure out what was wrong:

.. sourcecode:: bash

    % sudo mandb
    Purging old database entries in /usr/share/man...
    Processing manual pages under /usr/share/man...
    Purging old database entries in /usr/share/man/sr@latin...
    Processing manual pages under /usr/share/man/sr@latin...
    ...
    Purging old database entries in /usr/share/man/zh...
    gdbm fatal: Unexpected end of file


So gdbm seemed to have some problem. Since I didn't know what ``gdbm`` was, I
asked the all knowingly package manager of ArchLinux:

.. sourcecode:: bash

    % pacman -Qi gdbm
    Name            : gdbm
    Version         : 1.12-2
    Description     : GNU database library
    ...

Since it is a database library I assumed that the database must be corrupt.
Lucky enough ``mandb`` provides an option to create the database from scratch:

.. sourcecode:: bash

    % sudo mandb -c

    Processing manual pages under /usr/share/man...
    Updating index cache for path `/usr/share/man/man1'. Wait...mandb: warning: /usr/share/man/man1/gdk-pixbuf-csource.1.gz: whatis parse for gdk-pixbuf-csource(1) failed
    mandb: warning: /usr/share/man/man1/gdk-pixbuf-query-loaders.1.gz: whatis parse for gdk-pixbuf-query-loaders(1) failed
    ...
    Processing manual pages under /usr/local/man...
    124 man subdirectories contained newer manual pages.
    22844 manual pages were added.
    0 stray cats were added.


It spilled my screen with lots of `output and warnings`_, but seemed to finish
properly.

It didn't help though and ``mandb`` still failed. Looking at the output again I
noticed the line ``Purging old database entries in /usr/share/man/zh...``. To
see which package placed its manpage there I queried pacman again:

.. sourcecode:: bash

    % LANG=C pacman -Qo /usr/share/man/zh
    /usr/share/man/zh/ is owned by nmap 7.31-1

So I tried to uninstall and reinstall nmap:

.. sourcecode:: bash

    % sudo pacman -R nmap
    % sudo mandb
    % sudo pacman -S nmap
    % sudo mandb

And this time it finally worked! I'm still not sure what exactly triggered the
failure in the first place, but I'm not sure how to further debug it.

.. _`man page`: https://wiki.archlinux.org/index.php/Man_page
.. _`output and warnings`: https://gist.github.com/rnestler/0ad8fdeb54e732922721bd4ef785a8d9#file-mandb_c_output-txt
