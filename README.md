# RoomControl - WIFI/TCP/MQTT driver for a Light bulb and a LED strip

This project uses an Arduino Pro Mini (ATmega328) and an ESP8266 module to control a light bulb and a LED strip in my room's ceiling using MQTT as the main message exchange protocol. The server (broker) will publish the messages on topics that the microcontroller should be listening. The content of the message will set state of the lamp and the LED strip, its color and light intensity.

### TODO
* ~~Write the code that will actually drive the LED strip.~~
* Test the code above using the TIP122 transistor and a 12V power supply and calculate the right resistor to the base.
* Use the ESP8266 libraries to establish a TCP communication. Use it to control the lamp and the LED strip.
* Use the MQTT library to establish a connection with the broker and set the callbacks for the messages.
* Finish the hardware soldering and install it in the ceiling!
