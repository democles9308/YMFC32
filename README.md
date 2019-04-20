# YMFC32
My version of Joop Brokkings code for an autonomous drone (http://www.brokking.net/ymfc-32_auto_main.html)

As I'm working with VSCode + PlatformIO, I had to modify the project structure as the compilation order is different than the Arduino IDE.

The mod so far:
1. added to extra channels ( channel 7 and 8)
2. the order for the motors has changed du to my hardwaresetup.
3. had to modify the serial for the GPS comms. on my board it is Serial1!
4. changed onboard led to PA1 to match my hardware

