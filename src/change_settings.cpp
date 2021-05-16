///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//In this part the settings that can be set via the transmitter are handled.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Changing the settings is explained in this video:
//https://youtu.be/ys-YpOaA2ME
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Arduino.h>
#include "Globals.h"

void change_settings(void) {
    
  blue_led(HIGH);

  adjustable_setting_1 = variable_1_to_adjust;
  adjustable_setting_2 = variable_2_to_adjust;
  adjustable_setting_3 = variable_3_to_adjust;

  for (error = 0; error < 150; error ++) {
    delay(20);
    send_telemetry_data();
  }
  error = 0;

  while (channel_7 >= 1900) {
    delayMicroseconds(3700);
    send_telemetry_data();
    if (channel_1 > 1550) adjustable_setting_1 += (float)(channel_1 - 1550) * 0.000001;
    if (channel_1 < 1450) adjustable_setting_1 -= (float)(1450 - channel_1) * 0.000001;
    if (adjustable_setting_1 < 0) adjustable_setting_1 = 0;
    variable_1_to_adjust = adjustable_setting_1;
    
    if (channel_2 > 1550) adjustable_setting_2 += (float)(channel_2 - 1550) * 0.000001;
    if (channel_2 < 1450) adjustable_setting_2 -= (float)(1450 - channel_2) * 0.000001;
    if (adjustable_setting_2 < 0)adjustable_setting_2 = 0;
    variable_2_to_adjust = adjustable_setting_2;

    if (channel_4 > 1550) adjustable_setting_3 += (float)(channel_4 - 1550) * 0.000001;
    if (channel_4 < 1450) adjustable_setting_3 -= (float)(1450 - channel_4) * 0.000001;
    if (adjustable_setting_3 < 0) adjustable_setting_3 = 0;
    variable_3_to_adjust = adjustable_setting_3;

    #if defined (DEBUG_CHG) 
      Serial1.print("DEBUG Changing Param >");
      Serial1.print(channel_1);
      Serial1.print(" | ");
      Serial1.print(channel_2);
      Serial1.print(" | ");
      Serial1.print(channel_3);
      Serial1.print(" | ");
      Serial1.print(channel_4);
      Serial1.print(" | ");
      Serial1.print(channel_5);
      Serial1.print(" | ");
      Serial1.print(channel_6);
      Serial1.print(" | ");
      Serial1.print(channel_7);
      Serial1.print(" | ");
      Serial1.print(channel_8);
      Serial1.print(" | ");
      Serial1.print(adjustable_setting_1);
      Serial1.print(" | ");
      Serial1.print(adjustable_setting_2);
      Serial1.print(" | ");
      Serial1.println(adjustable_setting_3);
    #endif
  }

  blue_led(LOW);
  
  loop_timer = micros();                                                           //Set the timer for the next loop.
  
}
