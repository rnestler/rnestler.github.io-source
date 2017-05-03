RustFest and Visiting Hacklab Kyiv
==================================

:tags: tour de hackerspace, hackerspace, travelling, blockchain
:language: en
:status: draft
:summary: Attending RustFest and visiting the Hacklab Kyiv

I originally planed to fly to Kiev on Friday to visit `Hacklab Kyiv`_ and
attend the RustFest workshops the next day.  But as you may heard about, I
missed my flight due to my silliness.  So I was busy for most of Friday riding
trains, trying to learn a bit of Ukrainian [#]_, discuss the validity of my
ticket with the train crew, buying additional tickets and so on.

The train ride was quite an adventure and I even got to ride the famous
"platzkart" class night train.

.. figure:: /images/tour_de_hackerspace/kiev/kiev_train_ride_3.jpg
    :alt: The famous platzkart
    :align: center
    :width: 80%
    :figwidth: 80%

    The famous platzkart

I didn't take many pictures during the platzkart train ride, but if you want
the get a better feeling for it just `search for pictures`_.  I arrived in Kiev
around 11 in the morning (original plan was to arrive at 9) and met with
`Dns2utf8`_ at the train station because I arranged to share a hotel room with
him for the duration of RustFest.

RustFest
--------

After getting a long overdue shower, we went to the RustFest workshops.  I was
really happy to meet `@andrewhobden`_ and `@NGC_3572`_, which did an amazing
job as part of the `RustFest team`_!

Despite being a few hours to late we could still attend the workshops.  I
attended the `Exonum cryptocurrency workshop`_ instead of the web development I
originally signed up for.  Since I missed the introduction, I jumped right into
writing Rust code without having any clue how their blockchain implementation
even works.  By the end of the workshop we had some kind of crypto currency
implemented with a little node based web app to create new wallets, add funds
out of nowhere and transfer funds.

.. figure:: /images/tour_de_hackerspace/kiev/kiev_rustfest_crypto_3.png
    :alt: Screenshots from the webapp
    :align: center
    :width: 80%
    :figwidth: 80%

    Screenshots from the webapp

I found a bug in the implementation, where if one transfered funds from a
wallet to itself it would just increase the balance of this wallet!  The fix
was as simple as adding

.. sourcecode:: rust

    if sender == receiver {
        return Ok(())
    }

inside a function.  I didn't have time to figure out why the bug happened
exactly, since all the function does is decrement on the ``sender`` and
increment on the ``receiver``, which should lead to an equal final balance if
``sender == receiver``.

After the workshop we formed a little group of Rustaceans and had a great time
taking a look at the city!

.. figure:: /images/tour_de_hackerspace/kiev/city/kiev_city_7.jpg
    :alt: View over parts of Kiev
    :align: center
    :width: 80%
    :figwidth: 80%

    View over parts of Kiev

You can find some more images `here`_.  In the evening we found a wonderful
place for dinner and later met with some other Rustaceans to spend some time in
a bar which `Steve Klabnik`_ suggested.

The next morning it was time for a quite diverse range of `talks`_.  I
particularly enjoyed:

* "'Open' as in 'Welcoming': Facilitating Contributions" by `Manish
  Goregaokar`_ because it basically summarized what RustFest is all about.
* "The Illustrated Adventure Survival Guide for New Rustaceans" by `Liz
  Baillie`_ because it was super entertaining with cute images
* "Making a game in Rust" by `lislis`_ because I also tried to create a `game
  with Rust`_ (still not finished)

I also met the brilliant author of the `Plushie Rustacean Pattern`_, `E
Dunham`_.  She was impressed, that my girlfriend actually managed to create a
Plushie Ferris from her description.

In the evening we had a great time during the afterparty, getting to know the
community from this very relaxed and personal side was absolutly awesome!  I
talked to quite a few poeple and learned lots of stuff.  I also talked to
`Ashley Williams`_ about how to best teach kids programming and other stuff,
since we `do that`_ in `our hackerspace`_.


.. [#] It always amazes me how much communication is possible with just `some sentences`_, lots of smiling, gestures and some pictures from a mobile phone.

.. _`Hacklab Kyiv`: http://hacklab.kiev.ua/en/
.. _`search for pictures`: https://duckduckgo.com/?q=platzkart&atb=v10&iar=images&iax=1&ia=images
.. _`Dns2utf8`: https://github.com/dns2utf8
.. _`Exonum cryptocurrency workshop`: https://github.com/exonum/workshop
.. _`@andrewhobden`: https://twitter.com/andrewhobden
.. _`@NGC_3572`: https://twitter.com/NGC_3572
.. _`RustFest team`: http://2017.rustfest.eu/about/
.. _`here`: /images/tour_de_hackerspace/kiev/city/
.. _`some sentences`: http://www.omniglot.com/language/phrases/ukrainian.php
.. _`Steve Klabnik`: https://twitter.com/steveklabnik
.. _`talks`: http://2017.rustfest.eu/talks/
.. _`Manish Goregaokar`: https://github.com/Manishearth
.. _`Liz Baillie`: https://twitter.com/_lbaillie
.. _`lislis`: https://github.com/lislis
.. _`game with Rust`: https://github.com/coredump-ch/rpsrtsrs
.. _`Plushie Rustacean Pattern`: http://edunham.net/2016/04/11/plushie_rustacean_pattern.html
.. _`E Dunham`: https://twitter.com/qedunham
.. _`Ashley Williams`: https://twitter.com/ag_dubs
.. _`do that`: https://www.coredump.ch/2014/11/10/ferienpass-im-hackerspace/
.. _`our hackerspace`: https://www.coredump.ch/2016/11/01/ferienpass-2016/

