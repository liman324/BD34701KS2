// liman324@yandex.ru rcl-radio.ru


#ifndef BD34701KS2_H
#define BD34701KS2_H

#define ADDR_0 0
#define ADDR_1 1
#define ADDR_2 2
#define ADDR_3 3
#define ADDR_7 11


#include <Arduino.h>
class BD34701KS2
{
  public:
    BD34701KS2(uint8_t cl, uint8_t da);
    void set0(int chip, int sub, int rec, int input_main); 
    // Input Selector (MAIN)
    // chip >> 0 (0...1)
    // sub >> 0 (0...1)
    // rec >> 0 (0...1)
    // input >> 1 (1...12 = in1...in12 , 0 = MUTE)
    void set1(int chip, int input);
    // IInput Selector (SUB)
    // chip >> 0 (0...1)
    // input >> 1 (1...12 = in1...in12 , 0 = MUTE)
    void set2(int chip, int adc_att, int mode_sbl_sbrch, int mode_sl_srch, int mode_c_swch, int mode_fr_frch);
    // chip >> 0 (0...1)
    // adc_att >> 0 (0...8)
    // mode_sbl_sbrch >> 1 (0...3)
    // mmode_sl_srch >> 1 (0...3)
    // mode_c_swch >> 1 (0...3)
    // mode_fr_frch >> 1 (0...3)
    void set3(int chip, int volume, int ch_vol_sel);
    // chip >> 0 (0...1)
    // volume >> 0 (-190...64)
    // ch_vol_sel >> 0,1,2,3,4,5,6,7
    void set7(int chip, int reset, int base_clock, int sw_ba, int sw_ab);
    // chip >> 0 (0...1)
    // reset >> 0 (0...1)
    // base_clock >> 0 (0...1)
    // sw_ba >> 0 (0...7)
    // sw_ab >> 0 (0...7)

	
  private:
	void writeBD(char data);
        uint8_t CL;
        uint8_t DA;
};
	
#endif //BD34701KS2_H
