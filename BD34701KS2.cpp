#include <Arduino.h>
#include "BD34701KS2.h"

BD34701KS2::BD34701KS2(uint8_t cl, uint8_t da){
	CL = cl;
        DA = da;
      pinMode(CL,OUTPUT);
      pinMode(DA,OUTPUT);
}


void BD34701KS2::set0(int chip, int sub, int rec, int input_main){
  writeBD(ADDR_0 + (2 << chip) + (6 << sub) + (9 << rec) + (10 << input_main) );
}

void BD34701KS2::set1(int chip, int input){
  writeBD(ADDR_1 + (2 << chip) + (10 << input) );
}

void BD34701KS2::set2(int chip, int adc_att, int mode_sbl_sbrch, int mode_sl_srch, int mode_c_swch, int mode_fr_frch){
  writeBD(ADDR_2 + (2 << chip) + (4 << adc_att) + (8 << mode_sbl_sbrch) + (10 << mode_sl_srch) + (12 << mode_c_swch) + (14 << mode_fr_frch) );
}

void BD34701KS2::set3(int chip, int volume, int ch_vol_sel){
    int vol_d;
    if(volume > 0) {vol_d = 0;}
    if(volume <= 0) {volume = abs(volume);vol_d = 1;}
  writeBD(ADDR_3 + (2 << chip) + (4 << volume) + (13 << ch_vol_sel) + (12 << vol_d) );
}

void BD34701KS2::set7(int chip, int reset, int base_clock, int sw_ba, int sw_ab){
   writeBD(ADDR_7 + (2 << chip) + (6 << reset) + (9 << base_clock) + (10 << sw_ba) + (13 << sw_ab) );
}


void BD34701KS2::writeBD(char data){
   
   for(int i = 15; i >= 0; i--){
        digitalWrite(CL,LOW);
        digitalWrite(DA, (data >> i) & 0x01);
        digitalWrite(CL,HIGH);
        }  
   digitalWrite(CL,LOW);
   digitalWrite(DA,LOW);
   delay(100);
}
