#include "display7seg.h"

void digit_turn_on(int8 port, int8 digit, int time_delay_ms){
   output_high(port);
   output_d(digit);
   delay_ms(time_delay_ms);
   output_low(port);
}
