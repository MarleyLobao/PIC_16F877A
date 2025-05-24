#ifndef LCD_16X2_H
#define LCD_16X2_H

#ifndef  CS_LCD

#define CS_LCD PIN_E1  // CS - CHIP SELECT from LCD ------ (pin  6).
#define RS_LCD PIN_E0  // RS - REGISTER SELECT from LCD -- (pin  4).
#define D4_LCD PIN_D4  // D4 - Data 4 from LCD ----------- (pin 11).
#define D5_LCD PIN_D5  // D5 - Data 5 from LCD ----------- (pin 12).
#define D6_LCD PIN_D6  // D6 - Data 6 from LCD ----------- (pin 13).
#define D7_LCD PIN_D7  // D7 - Data 7 from LCD ----------- (pin 14).

#endif

#define lcd_type 2       // 0=5x7, 1=5x10, 2=2 lines
#define lcd_sec_lin 0x40 // Second line address in the RAM from LCD

byte CONST seq_ini_lcd[4] = {0x20 | (lcd_type << 2), 0x0c, 1, 6};

#endif
