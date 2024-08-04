#include "lcd_16x2.h"

void send_nibble_lcd(byte data){
   output_bit(D4_LCD,bit_test(data,0));
   output_bit(D5_LCD,bit_test(data,1));
   output_bit(D6_LCD,bit_test(data,2));
   output_bit(D7_LCD,bit_test(data,3));

   // Enable pulse (CS)
   output_high(CS_LCD);
   output_low(CS_LCD);
}

void send_byte_lcd(boolean address, byte data){
   output_low(RS_LCD);

   //while( bit_test(lcd_read_byte(),7) ) ;

   output_bit(RS_LCD,address);

   delay_us(100);

   // output_low(RW_LCD);

   output_low(CS_LCD);

   send_nibble_lcd(data >> 4);

   send_nibble_lcd(data & 0x0f);
}

void ini_lcd_16x2(){
   byte i;

   output_low(CS_LCD);
   output_low(D4_LCD);
   output_low(D6_LCD);
   output_low(D7_LCD);
   output_low(RS_LCD);

   // output_high(RW_LCD);

   output_low(CS_LCD);

   delay_ms(25);

   // It sends a sequence with 3 times the 0x03 value and then the
   // value 0x02 is sended to configure the LCD bus in the 4-bit mode.
   for(i = 1 ;i <= 3 ; ++i){
      send_nibble_lcd(3);
      delay_ms(15);
   }

   send_nibble_lcd(2);

   // It sends a string to initialize the display
   for(i = 0; i <=3 ; ++i) send_byte_lcd(0,seq_ini_lcd[i]);
}

void xy_position_lcd( byte x, byte y ){
   byte address;

   if(y != 1)
      address = lcd_sec_lin;
      
   else
      address = 0;

   address += (x-1);
   send_byte_lcd(0,0x80|address);
}


void show_lcd( char caracter ){
   switch (caracter){
      case '\f' : // (CLEAR)
         send_byte_lcd(0,1);
         delay_ms(2);
         break;

     case '\n' :
     // case '\r' :
        xy_position_lcd(1,2);
        break;

      case '\b' :
         send_byte_lcd(0,10);
         break;

      default: // (ASCII)
         send_byte_lcd(1,caracter);
         break;
   }
}

//==============================================================================
