# YMFC32
My version of Joop Brokkings code for an [autonomous drone](http://www.brokking.net/ymfc-32_auto_main.html)

As I'm working with VSCode + PlatformIO, I had to modify the project structure as the compilation order is different than the Arduino IDE.
I'm using a ["core board"](https://wiki.cuvoodoo.info/doku.php?id=stm32f1xx) on which I made a shield with the various components (leds, gyro,gps,...)

Channels - related to my transmitter
- CH1: Roll (A)
- CH2: Pitch (E)
- CH3: Throttle (T)
- CH4: Yaw (R)
- CH5: Arm (start=1)
- CH6: Flightmode (FM1-3)
- CH7: head lock
- CH8: beeper ( still to implement)

The mods so far:
1. Added two additional channels (channel 7 and 8)
2. The order for the motors has changed due to my hardware setup.
    - Motor 1 > PB9
    - Motor 2 > PB7
    - Motor 3 > PB6
    - Motor 4 > PB8
3. Serial ports:
    - Serial1 (UART1): used for debug. On my board this ports is next to the usb connector and together with the SWD pins.
    - Serial2 (UART2): used by the GPS
4. Had to change the onboard led to PA1 to match my hardware

