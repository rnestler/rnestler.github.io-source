Verify Every Single Commit on a git rebase
==========================================

:tags: git, rebase
:language: en
:summary: Check every commit when reordering commits with git rebase -i

Sometimes when one uses ``git rebase -i`` to reorder, split or merge commits,
we screw up the commits in between without noticing, since the final commit
compiles and passes every unit test.

For example imagine we have this little Rust code:

.. sourcecode:: Rust

    fn main() {
        println!("Hello, world!");
    }

Now we want to show how nicely Rust can print a ``std::Vec`` so we create a
branch: ``git checkout -b add_vector`` and add the following:

.. sourcecode:: Rust

    fn main() {
        let v = vec![1,2,3];
        println!("v: {:?}", v);

        println!("Hello, world!");
    }

This will compile and give us some wonderful output:

.. sourcecode:: Bash

    $ cargo run
    v: [1, 2, 3]
    Hello, world!

We are satisfied with the changes and commit it:

.. sourcecode:: Shell

    $ git add src/main.rs
    $ git commit -m "Print vector"


We than add some more code to show the length of our fancy vector:

.. sourcecode:: Rust

    fn main() {
        let v = vec![1,2,3];
        println!("v: {:?}", v);

        println!("Hello, world!");

        println!("v.len(): {}", v.len());
    }

This also works just fine so we commit it:

.. sourcecode:: Shell

    $ git add src/main.rs
    $ git commit -m "Print length of vector"

But of course we are not satisfied with the commit history and want to
rearrange our two commits. So we do a interactive rebase:

.. sourcecode:: Shell

    $ git rebase -i master
    pick 8fc4573 Print length of vector
    pick 6d22bd9 Print vector

This will succeed without error and we still receive the correct output:

.. sourcecode:: Shell

    $ cargo run
    v: [1, 2, 3]
    Hello, world!
    v.len(): 3

But we introduced a broken commit while rebasing! To detect this we can run the
following:

.. sourcecode:: Shell

    $ git rebase -i master -x "cargo build"

    Executing: cargo build
       Compiling git_rebase_x_test v0.1.0 (file:///home/rnestler/proggen/git_rebase_x_test)
    error[E0425]: unresolved name `v`
     --> src/main.rs:4:29
      |
    4 |     println!("v.len(): {}", v.len());
      |                             ^
    <std macros>:2:27: 2:58 note: in this expansion of format_args!
    <std macros>:3:1: 3:54 note: in this expansion of print! (defined in <std macros>)
    src/main.rs:4:5: 4:38 note: in this expansion of println! (defined in <std macros>)

    error: aborting due to previous error

    error: Could not compile `git_rebase_x_test`.

    To learn more, run the command again with --verbose.
    Execution failed: cargo build
    You can fix the problem, and then run

        git rebase --continue

This will execute the command after ``-x`` for every commit and stop rebasing
if the command fails.  We now can go on and fix this commit and continue
rebasing.

This little git feature allows us to not only have a nice looking, but also
*working* git history after rebasing!
