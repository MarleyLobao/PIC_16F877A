#ifndef SETUP_H
#define SETUP_H

#include <16F877A.h>

#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)

#include "..\general_libs\lcd_16x2.c"
#include "timer_w_lcd.c"
#include "display7seg.c"

#endif
