#include <setup.h>

void main(){
   int8  port = PIN_D0;
   int1  button_state = 0;
   
   initial_setup();
   
   while(true){
      if(!input(PIN_B0)) button_state = !button_state;

      blink(&port);

      peripheral_segments(&port, button_state);

   }
}
