Creating this Blog
==================

:tags: blog
:language: en
:summary: How and why I created this blog.

Recently a friend of mine asked me how I configured my system so that `slock
<http://tools.suckless.org/slock>`_ locks the screen when I close the lid.

Since I couldn't remember how I did it, I thought it's time to create a blog
where I can write down stuff like this.

The same friend recommended me to use `pelican <http://getpelican.com/>`_ to
create my blog.

Setting up pelican
------------------
Setting up pelican is quite straight forward. First I created a new developement environment with `virtualenv <http://www.virtualenv.org/>`_.

.. sourcecode:: bash

  $ virtualenv blogenv
  $ cd blogenv
  $ . bin/acivate

Then installing pelican

.. sourcecode:: bash

  $ pip install pelican

The next step is to create the base structure with the interactive
pelican-quickstart

.. sourcecode:: bash

  $ mkdir blog; cd blog
  $ pelican-quickstart
  $ ls
  content/            fabfile.py  output/         publishconf.py
  develop_server.sh*  Makefile    pelicanconf.py

Thats it! Your pelican installation is finished! To generate your still empty blog is easy

.. sourcecode:: bash

  $ make html
  $ make devserver

After that you can preview you blog on http://localhost:8000

Integrating with github pages
-----------------------------
Since I don't own any webspace I wanted to use the pages feature of `github
<https://help.github.com/articles/user-organization-and-project-pages>`_

I created two repositories

 - username/username.github.io-source, where I host the pelican sources
 - username/username.github.io, where I host the generated output

Pelican supports this approach as seen in http://docs.getpelican.com/en/3.3.0/tips.html#user-pages

So all you need to do is to install ghp-import

.. sourcecode:: bash

  % pip install ghp-import

Then change SITEURL in publishconf.py to http://username.github.io and edit the
github target in the Makefile to look like this

.. sourcecode:: Makefile

  github: publish
    ghp-import $(OUTPUTDIR)
    git push git@github.com:username.username.io.git gh-pages:master

ghp-import will create a branch in the current git repository called gh-pages
and commit any changes in the output directory to it. Then we push this branch
to the master branch in our username.github.io repository.

So if you type

.. sourcecode:: bash

  $ make github

The blog gets published under http://username.github.io

