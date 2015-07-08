Learning Rust
=============

:tags: programming, Rust
:language: en
:summary: Learning the programming language rust

Reading the news that Rust reached `1.0 Alpha
<http://blog.rust-lang.org/2015/01/09/Rust-1.0-alpha.html>`_ I decided to take
a deeper look at `it <http://www.rust-lang.org/>`_.

Getting Rust
------------

Installing Rust under arch is as easy

.. sourcecode:: bash

  $ sudo pacman -S rust

The above will install the latest version from the `community repo
<https://www.archlinux.org/packages/community/x86_64/rust/>`_.  If you want the
latest and greatest version you could also try `the nightly build
<https://aur.archlinux.org/packages/rust-nightly/>`_.

The lazy people can try it `online <https://play.rust-lang.org/?code=%2F%2F%20This%20code%20is%20editable%20and%20runnable!%0Afn%20main()%20%7B%0A%20%20%20%20println!(%22Hello%20World!%22%3B%0A%7D>`_.

Hello World!
------------

Here comes the obligatory "Hello World!" code in Rust

.. sourcecode:: rust

    fn main() {
        println!("Hello World!");
    }

Immutability
------------

Beeing a `C++ const-nazi
<http://gamesfromwithin.com/wp-content/uploads/2010/07/const_nazi.mov>`_ I
really liked that by default all variable bindings are immutable.

.. sourcecode:: rust

    fn main() {
        let x = 1;
        x+=1;
        println!("{}", x);
    }

The example above will give you a compile error:

.. code-block:: bash

    mut.rs:4:5: 4:9 error: re-assignment of immutable variable `x`
    mut.rs:4     x+=1;
                 ^~~~
    mut.rs:3:9: 3:10 note: prior assignment occurs here
    mut.rs:3     let x = 1;
                     ^
    error: aborting due to previous error

By using the "mut" keyword we mark the variable as mutable

.. sourcecode:: rust

    fn main() {
        let mut x = 1;
        x+=1;
        println!("{}", x);
    }

So the code will print "2"

Rust will also emit a warning when not using variables or an error when trying
to use uninitialized variables.

