#include <blink_leds.h>

void initial_setup(void){
   //Activating transistor Q1
   output_high(PIN_B4);
   //Deactivating dot and middle diode
   output_low(PIN_D6);
   output_low(PIN_D7);
}

void blink(int8* port){
   output_high(*port);
   delay_ms(IDLE_TIME);
   output_low(*port);
   delay_ms(IDLE_TIME);
}

void peripheral_segments(int8* port, int1 button_state){
  (button_state)? (*port)++ : (*port)--;

  if(*port == PIN_D6) *port = PIN_D0;
  if(*port == (PIN_D0-1)) *port = PIN_D5;
}
