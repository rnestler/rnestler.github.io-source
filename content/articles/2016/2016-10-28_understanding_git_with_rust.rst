Understanding Git by Implementing it in Rust
============================================

.. Improve the title. Impmlementing what exactly in Rust?

:tags: git, Rust
:language: en
:summary: Understanding the git repository format by implementing a simple reader
:status: draft

Recently I read the blog post `Git from the inside out`_ and discovered that
the format git uses to store our beloved data is actually quite simple and
straightforward to understand.

Previously I somehow expected this to be super complex magic happening, but
this may be just due to the CLI interface git provides ;)

How simple and elegant the basics of git are can be seen in the `README of the
first commit`_.

Anyway, to dive deeper into it I started implementing a simple reader for the
git repository format in Rust.

First I tried to gather more information about the format. The best source is
the git repository itself:

- https://github.com/git/git/blob/master/Documentation/technical/index-format.txt

.. _`Git from the inside out`: https://codewords.recurse.com/issues/two/git-from-the-inside-out
.. _`README of the first commit`: https://github.com/git/git/blob/e83c5163316f89bfbde7d9ab23ca2e25604af290/README
