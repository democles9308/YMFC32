# YMFC32
My version of Joop Brokkings code for an autonomous drone (http://www.brokking.net/ymfc-32_auto_main.html)

As I'm working with VSCode + PlatformIO, I had to modify the project structure as the compilation order is different than the Arduino IDE.
I'm using a "core board" https://wiki.cuvoodoo.info/doku.php?id=stm32f1xx on which I made a shield with the various components (leds, gyro,gps,...)

The mods so far:
1. Added to extra channels (channel 7 and 8)
2. The order for the motors has changed due to my hardware setup.
3. Had to change the serialport for the GPS comms. On my board it is Serial1!
4. Had to changed onboard led to PA1 to match my hardware

