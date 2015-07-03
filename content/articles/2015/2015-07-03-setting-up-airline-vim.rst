Setting up airline-vim
======================

:tags: Vim, airline, urxvt, ArchLinux
:language: en
:summary: Setting up the airline-vim plug-in and configure the powerline fonts

Recently I noticed, that my Vim configuration is getting a bit outdated. The
configuration of one of my mate had a fancy status line, showed syntax errors
when saving a buffer and he used `vundle
<https://github.com/gmarik/Vundle.vim>`_ to manage his Vim plug-ins.  I used to
manage my Vim plug-ins with `yaourt <https://github.com/archlinuxfr/yaourt>`_, a
package manager for `user packages <https://aur4.archlinux.org/>`_ in ArchLinux. 


Installing vundle
-----------------

First one needs to get the vundle plugin via git:

.. sourcecode:: bash

    git clone https://github.com/gmarik/vundle.git /home/roughl/.vim/bundle/vundle
    
Then one needs to setup Vim to use it:

.. sourcecode:: vim

    " ~/.vimrc
    set nocompatible
    filetype off

    set rtp+=~/.vim/bundle/Vundle.vim/
    call vundle#rc()

    Plugin 'gmarik/Vundle.vim'

    filetype plugin indent on

From there adding additional plug-ins is as easy as adding a ``Plugin ...`` line
right after the vundle plug-in.

So adding `airline <https://github.com/bling/vim-airline>`_ for a fancy status
line, `syntastic <https://github.com/scrooloose/syntastic>`_ as a syntax checker
and git support with `fugitive <https://github.com/tpope/vim-fugitive>`_ is as
easy as this:

.. sourcecode:: vim

    Plugin 'scrooloose/syntastic'
    Plugin 'tpope/vim-fugitive'
    Plugin 'bling/vim-airline'

Configuring airline
-------------------

Out of the box airline does show the status bar only if at least one split is
active:

.. image:: images/vim-airline0.png
    :alt: Vim screen shot with airline
    :align: center
    :width: 100 %

Also the default symbols used in the statusline aren't that fancy. Adding ``set
laststatus=2`` enables the statusline by default and ``let
g:airline_powerline_fonts = 1`` lets one use the `powerline fonts
<https://github.com/powerline/fonts>`_

Configuring my terminal emulator of choise, urxvt, turned out to be a bit of a
hassle.

Installing the fonts was easy:

.. sourcecode:: bash

    git clone https://github.com/powerline/fonts.git
    cd fonts
    ./install.sh

Then in ``~/.Xresources`` configure urxvt to use a powerline font:

.. sourcecode:: bash

    URxvt.font: xft:DejaVu Sans Mono for Powerline:size=11

Then reloading the configuration

.. sourcecode:: bash

    xrdb -merge ~/.Xresources

The problem was that urxvt didn't like that at all and displayed the fonts with
the spacing all messed up. After an hour of googeling and trying out different
stuff, it turned out I just needed to kill and restart the urxvtd daemon!

.. sourcecode:: bash

    % killall urxvtd
    % urxvtd -q -o -f

After that it worked like a charm and the special symbols did show up nicely:

.. image:: images/vim-airline1.png
    :alt: Vim screen shot with airline and powerline fonts
    :align: center
    :width: 100 %

