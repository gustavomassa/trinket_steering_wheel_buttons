## Trinket Bluetooth Steering Wheel Buttons

### Features
- Using PlatformIO with vscode
- Using HC-06 bluetooth module as slave
- Communicating with a HC-05 bluetooth module as master

### Structe
- main folder contains the .ino file
- hardware folder is the Arduino's hardware folder
- libraries folder is the Arduino's libraries folder

### Board config
- Board: Adafruit Trinket Mini/Pro
- Programmer: USBtinyISP
- Low speed USB is only able to accept data packets 8 bytes in length or less

### Linux USBtiny setup
- sudo gedit /etc/udev/rules.d/10-usbtinyisp.rules
- SUBSYSTEM=="usb", ATTR{idVendor}=="1781", SYSFS{idVendor}=="1781", SYSFS{idProduct}=="0c9f", GROUP="adm", MODE="0666"
- sudo service udev restart
- Read serial/FTDI ports: dmesg | grep tty

### platformIO boards
- [https://docs.platformio.org/en/latest/boards/atmelavr/trinket3.html](https://docs.platformio.org/en/latest/boards/atmelavr/trinket3.html)
- [https://docs.platformio.org/en/latest/boards/atmelavr/protrinket5.html](https://docs.platformio.org/en/latest/boards/atmelavr/protrinket5.html)


### Adafruit docs about Trinket
- [https://www.adafruit.com/product/1500](https://www.adafruit.com/product/1500)
- [https://www.adafruit.com/product/2000](https://www.adafruit.com/product/2000)
- [https://learn.adafruit.com/introducing-trinket/16mhz-vs-8mhz-clock](https://learn.adafruit.com/introducing-trinket/16mhz-vs-8mhz-clock)
- [https://learn.adafruit.com/trinket-usb-keyboard/code](https://learn.adafruit.com/trinket-usb-keyboard/code)
- [https://learn.adafruit.com/pro-trinket-usb-hid-mouse/example-joystick-mouse](https://learn.adafruit.com/pro-trinket-usb-hid-mouse/example-joystick-mouse)


### Adafruit repos for Trinket
- [https://gist.github.com/RickCarlino/00e51e6d3137064ec337](https://gist.github.com/RickCarlino/00e51e6d3137064ec337)
- [https://github.com/adafruit/Adafruit_Arduino_Boards](https://github.com/adafruit/Adafruit_Arduino_Boards/)
- [https://github.com/adafruit/Adafruit_Windows_Drivers](https://github.com/adafruit/Adafruit_Windows_Drivers)
- [https://github.com/adafruit/Adafruit-Trinket-USB] (https://github.com/adafruit/Adafruit-Trinket-USB)

### Libs
- [https://github.com/nickgammon/SendOnlySoftwareSerial](https://github.com/nickgammon/SendOnlySoftwareSerial)
- [https://github.com/adafruit/Pro_Trinket_USB_Mouse](https://github.com/adafruit/Pro_Trinket_USB_Mouse)
- [https://github.com/adafruit/Pro_Trinket_USB_Keyboard_Library](https://github.com/adafruit/Pro_Trinket_USB_Keyboard_Library)
- [https://github.com/adafruit/Adafruit-Trinket-USB](https://github.com/adafruit/Adafruit-Trinket-USB)
- [https://github.com/buxit/Pro_Trinket_USB_Gamepad](https://github.com/buxit/Pro_Trinket_USB_Gamepad)
