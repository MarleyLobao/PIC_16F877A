#include <setup.h>

float pwm_pot   = 0;
float pot_r     = 0;
float temp_r    = 0;
int8 interrup   = 0;
float curr_temp = 0;

#INT_TIMER1
void  TIMER1_isr(void){
   interrup++;
   if(interrup==2){
      set_adc_channel(PIN_A0);
      temp_r = read_adc();
      set_adc_channel(PIN_A1);
      pot_r = read_adc();

      //ADC (10 -> 8 bits): 2^10 = 1023 ~ 1000
      pwm_pot = (pot_r*1000)/255;

      set_pwm1_duty((int16)pwm_pot);

      // Model (Temperature Sensor)
      //ADC ------- T (celsius)
      //85  ------- 27.5
      //185 ------- 77.5

      //a=(185-85)/(77.5-27.5)
      //b=85-27.5*a
      //y = ax+b = 2x+30

      curr_temp = (temp_r-30)/2; 
      interrup = 0;                      
   }
}

void main(){
   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_DIV_2);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_4); //262 ms overflow
   setup_timer_2(T2_DIV_BY_16,249,1);      //4,0 ms overflow, 4,0 ms interrupt

   ini_lcd_16x2();

   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)0);

   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);

   while(TRUE){
      printf(show_lcd,"\fTemp(C): %lf\n",curr_temp);
      printf(show_lcd,"DutyPWM: %lf\n",pwm_pot/10);
      delay_ms(50);
   }
}
