RustFest and Visiting Hacklab Kyiv
==================================

:tags: tour de hackerspace, hackerspace, travelling, blockchain
:language: en
:status: draft
:summary: Attending RustFest and visiting the Hacklab Kyiv

I originally planed to fly to Kiev on Friday to visit `Hacklab Kyiv`_ and
attend the `RustFest`_ workshops the next day.  But as `you may heard about`_,
I missed my flight due to my silliness.  So I was busy for most of Friday
riding trains, trying to learn a bit of Ukrainian [#]_, discuss the validity of
my ticket with the train crew, buying additional tickets and so on.

The train ride was quite an adventure and I even got to ride the famous
"platzkart" class night train.

.. figure:: /images/tour_de_hackerspace/kiev/kiev_train_ride_3.jpg
    :target: /images/tour_de_hackerspace/kiev/kiev_train_ride_3.jpg
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

`RustFest`_
-----------

After getting a long overdue shower, we went to the RustFest workshops.  I was
really happy to meet `@andrewhobden`_ and `@NGC_3572`_, which both did an
amazing job as part of the `RustFest team`_!

Despite being a few hours to late we could still attend the workshops.  I
attended the `Exonum cryptocurrency workshop`_ instead of the web development I
originally signed up for.  Since I missed the introduction, I jumped right into
writing Rust code without having any clue how their blockchain implementation
even works.  By the end of the workshop we had some kind of crypto currency
implemented with a little node based web app to create new wallets, add funds
out of nowhere and transfer funds.

.. figure:: /images/tour_de_hackerspace/kiev/kiev_rustfest_crypto_3.png
    :target: /images/tour_de_hackerspace/kiev/kiev_rustfest_crypto_3.png
    :alt: Screenshots from the webapp
    :align: center
    :width: 80%
    :figwidth: 80%

    Screenshots from the webapp

I found a bug in the implementation, where if one transferred funds from a
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
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_7.jpg
    :alt: View over parts of Kiev
    :align: center
    :width: 80%
    :figwidth: 80%

    View over parts of Kiev

Here are some more images:


.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_1.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_1.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_2.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_2.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_3.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_3.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_4.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_4.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_5.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_5.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_6.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_6.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_7.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_7.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_8.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_8.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_9.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_9.jpg
    :width: 10%

.. image:: /images/tour_de_hackerspace/kiev/city/kiev_city_10.jpg
    :target: /images/tour_de_hackerspace/kiev/city/kiev_city_10.jpg
    :width: 10%

In the evening we found a wonderful place for dinner and later met with some
other Rustaceans to spend some time in a bar which `Steve Klabnik`_ suggested.

The next morning it was time for a quite diverse range of `talks`_.  I
particularly enjoyed:

* "'Open' as in 'Welcoming': Facilitating Contributions" by `Manish
  Goregaokar`_ because it basically summarized what RustFest is all about.
* "The Illustrated Adventure Survival Guide for New Rustaceans" by `Liz
  Baillie`_ because it was super entertaining with cute images
* "Making a game in Rust" by `lislis`_ because I also tried to create a `game
  with Rust`_ (still not finished)

During the day I had the pleasure to met the brilliant author of the `Plushie
Rustacean Pattern`_, `E Dunham`_.  She was impressed, that my girlfriend
actually managed to create a Plushie Ferris from her description.

In the evening we had a great time during the after party.  Getting to know the
community from this very relaxed and personal side was absolutely awesome!  I
talked to quite a few people and learned lots of stuff.  I also talked to
`Ashley Williams`_ about how to best teach kids programming and other stuff,
since we `do that`_ in `our hackerspace`_.

Just like last year, RustFest was just amazing!  It's so awesome to meet with
this incredible community!  I'm really looking forward to the next RustFest
this fall in `Zurich`_!

Visiting Hacklab Kyiv
---------------------

The next day I met with Dmitriy, who I met at RustFest, to get lunch together.
Since he speaks Russian it was quite easy for him to chat with the locals and
find us a good place to get some Ukrainian food.

I arranged with Anastasia from the Hacklab Kyiv that I could couch surf at
their place.  Since I wanted to meet with Anastasia to drop off my luggage, I
agreed with Dimitry to split and see each other again in the hackerspace.
Anastasia to drop off my luggage.  Anastasia and her partner Sasha are some of
the most lovely people I've ever met!  They showed me around the city, helped
me with public transport and it was always fun to hang out with them.  So I was
happy I brought some Swiss chocolate with me which I could give them as a gift.

After dropping my luggage we went to the hackerspace.

.. figure:: /images/tour_de_hackerspace/kiev/kiev_entry.jpg
    :target: /images/tour_de_hackerspace/kiev/kiev_entry.jpg
    :alt: Entry to the HackLab  Kyiv
    :align: center
    :width: 80%
    :figwidth: 80%

    Entry to the HackLab  Kyiv

Their hackerspace consist mostly of people which are interested in mechanical
engineering and electronics.  So they are quite awesomely equipped with
multiple CNC machines, 3D printers, compressors and lots of other tools.

.. figure:: /images/tour_de_hackerspace/kiev/kiev_cnc.jpg
    :target: /images/tour_de_hackerspace/kiev/kiev_cnc.jpg
    :alt: CNC mill
    :align: center
    :width: 80%
    :figwidth: 80%

    CNC mill


.. figure:: /images/tour_de_hackerspace/kiev/kiev_big_cnc.jpg
    :target: /images/tour_de_hackerspace/kiev/kiev_big_cnc.jpg
    :alt: Even bigger CNC mill
    :align: center
    :width: 80%
    :figwidth: 80%

    Even bigger CNC mill

.. figure:: /images/tour_de_hackerspace/kiev/kiev_3d_printers.jpg
    :target: /images/tour_de_hackerspace/kiev/kiev_3d_printers.jpg
    :alt: 3D printers
    :align: center
    :width: 80%
    :figwidth: 80%

    3D printers

They created quite some awesome stuff with their 3D printer, including molds to
create metallic stuff!

.. figure:: /images/tour_de_hackerspace/kiev/kiev_3d_prints.jpg
    :target: /images/tour_de_hackerspace/kiev/kiev_3d_prints.jpg
    :alt: Awesome stuff they created with the 3D printers
    :align: center
    :width: 80%
    :figwidth: 80%

    Awesome stuff they created with the 3D printers

Like most hackerspaces they also feature a big main working room

.. figure:: /images/tour_de_hackerspace/kiev/kiev_main_room_2.jpg
    :target: /images/tour_de_hackerspace/kiev/kiev_main_room_2.jpg
    :alt: Main room
    :align: center
    :width: 80%
    :figwidth: 80%

    Main room

Additionally to that they feature:

* A workshop
    .. image:: /images/tour_de_hackerspace/kiev/kiev_workshop.jpg
        :target: /images/tour_de_hackerspace/kiev/kiev_workshop.jpg
        :width: 10%
* A storage room
    .. image:: /images/tour_de_hackerspace/kiev/kiev_workshop.jpg
        :target: /images/tour_de_hackerspace/kiev/kiev_workshop.jpg
        :width: 10%
* Chemistry lab
    .. image:: /images/tour_de_hackerspace/kiev/kiev_chemistry.jpg
        :target: /images/tour_de_hackerspace/kiev/kiev_chemistry.jpg
        :width: 10%
* A soldering place
    .. image:: /images/tour_de_hackerspace/kiev/kiev_soldering.jpg
        :target: /images/tour_de_hackerspace/kiev/kiev_soldering.jpg
        :width: 10%
* A Tesla coil
    .. image:: /images/tour_de_hackerspace/kiev/kiev_tesla_coil.jpg
        :target: /images/tour_de_hackerspace/kiev/kiev_tesla_coil.jpg
        :width: 10%

In a room next to the hackerspace there is a studio for people working with
ceramics.  They told me that they share some tools together and generally
support each other.

.. figure:: /images/tour_de_hackerspace/kiev/kiev_ceramics_2.jpg
    :target: /images/tour_de_hackerspace/kiev/kiev_ceramics_2.jpg
    :alt: Ceramics studio
    :align: center
    :width: 80%
    :figwidth: 80%

    Ceramics studio

After they had shown me around and I talked to most of them for some time, some
of us went to get dinner together. We spent quite some time discussing various
things, amongst other the problem that a lot of spaces share: The founders are
basically the only ones taking care of everything in regard to organizing the
space.

We have this problem as well in our space and tried to solve it, by actively
splitting responsibilities for various tasks.  An example is: For a long time
`Danilo Bargen`_, our formal president, was responsible for every single IT
infrastructure task at coredump.  So I encouraged him to show me how to manage
our servers, update services and so on.  This not only let to him having more
times at hand, but also removed a single point of failure in our organization.

The next day I spent some time trying to `repair my Fairphone`_.  At first it
seemed to work perfectly, but after some time it did again refuse to charge.

My flight back was on 16:45. This time I actually was able to catch it, but if
you want to hear a funny story on how I almost missed it again, feel free to DM
me on Twitter ;)

I definitely enjoyed my stay in Kiev and my visit to Hacklab Kyiv.  But my
travel continued back to Budapest and then further on to Szeged.

.. [#] It always amazes me how much communication is possible with just `some sentences`_, lots of smiling, gestures and some pictures from a mobile phone.

.. _`Hacklab Kyiv`: http://hacklab.kiev.ua/en/
.. _`RustFest`: http://2017.rustfest.eu
.. _`you may heard about`: https://twitter.com/rnstlr/status/857902876588486658
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
.. _`Zurich`: https://rustfest.ch/
.. _`Danilo Bargen`: https://github.com/dbrgn
.. _`repair my fairphone`: https://twitter.com/rnstlr/status/859351392871428097

