Reading the SHTC1 smart gadget BLE device
=========================================

:tags: BLE, bluetooth, bluez, SHTC1, SmartGadget
:language: en
:summary: Connection to a SHTC1 smart gadget and read its sensor values

Requirements
------------

First we need to install the bluez bluetooth stack:

.. sourcecode:: bash

    $ sudo pacman -S bluez bluez-utils

To be able to switch the bluetooth on and off I use the bluetooth command from
tlp:

.. sourcecode:: bash

    $ sudo pacman -S tlp
    $ sudo bluetooth on

Next we activate the bluetooth service:

.. sourcecode:: bash

    $ sudo systemctl daemon-reload
    $ sudo systemctl start bluetooth.service

Connecting
----------

.. sourcecode:: bash

    $ sudo hcitool dev
    Devices:
            hci0    F8:16:54:CD:5F:CC
    $ sudo hcitool lescan
    LE Scan ...
    BC:6A:29:C1:A9:3B SHTC1 smart gadget

    $ sudo gatttool -b BC:6A:29:C1:A9:3B -I
    [BC:6A:29:C1:A9:3B][LE]> connect
    Attempting to connect to BC:6A:29:C1:A9:3B
    Connection successful

Reading the sensordata
----------------------

According to `the SmartGadget-iOS code <https://github.com/Sensirion/SmartGadget-iOS/blob/50dc0f36c0624f825f7637bceeb5a34da7c878f3/Classes/Peripheral/Services/Sensirion/Shtc1/Shtc1RhtService.m>`_
The UUID to read the temperature is 0xAA21.
So we try to read it:

.. sourcecode:: bash

    [BC:6A:29:C1:A9:3B][LE]> char-read-uuid 0xAA21
    handle: 0x0025   value: 66 0b b9 14

The first 16-bit value is the temperature and the second the humidity. Note
that the byte order of the values is big endian.

So to calculate the measured temperature in python we need to:

.. sourcecode:: python

    >>> temperature = 0x0b66/100.0
    >>> print(str(temperature)+ "°C")
    29.18°C
    >>> humidity = 0x14b9
    >>> print(str(humidity)+ "%RH")
    53.05%RH


