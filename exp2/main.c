#include "setup.h"

void main(){
   int8 i, j;

   // Timer2 Setup
   setup_timer_2(T2_DIV_BY_16,249,5); // 4,0 ms overflow, 20,0 ms interrupt

   enable_interrupts(INT_EXT);
   enable_interrupts(INT_TIMER2);
   enable_interrupts(GLOBAL);

   // LCD Initial Setup
   ini_lcd_16x2();

   while(TRUE){
      update_digits();

      for(i = PIN_B4, j = 0; j < 4; i++, j++) digit_turn_on(i, LUT[d[j]], 1);

      if(to_show){
         printf(show_lcd, "\f Min:Sec\n");
         printf(show_lcd, "   %d:%d", minutes, seconds);
         to_show = 0;
      }
   }
}
