#include "timer_w_lcd.h"

#define TIME_LIMIT 10000

#INT_EXT
void  EXT_isr(void){
   pause++; // Button Pressed (External Interrupt)
}

#INT_TIMER2
void  TIMER2_isr(void){
   if(!time_units) to_show = 1; // Start and Reset (LCD)

   if(!pause){                  // No External Interrupts
      if(counter == 5){         // 5*20ms = 100ms
         time_units++;
         if(!(time_units%10)){  // 10*100ms = 1000ms = 1s
            to_show = 1;
            seconds++;
         }
         counter = 0;
      } else {
         counter++;
      }
   } else if(pause == 2){       // Reset
      time_units = 0;
      pause      = 0;
      minutes    = 0;
      seconds    = 0;
   }
}

void update_digits(){
      d[0] = time_units%10;
      d[1] = (time_units%100)/10;
      d[2] = (time_units/100)%10;
      d[3] = time_units/1000;

      if(seconds == 60){
         minutes++;
         seconds = 0;
      }

      if(time_units == TIME_LIMIT) time_units = 0;
}
