avrdude -p atmega32u4 -P USB -c avr109 -D -U flash:w:vitamins_included_rev1_via.hex

avrdude -p atmega32u4 -P USB -c avr109 -D -U flash:w:vitamins_included_rev1_via.hex


ioreg -p IOUSB -l -b | grep -E "@|PortNum|USB Serial Number" | grep vitamins
  | | | +-o Lets Split sockets vitamins included@14423000  <class AppleUSBDevice, id 0x101e42208, registered, matched, active, busy 0 (75 ms), retain 14>

tty.usbmodem14423000