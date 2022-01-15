#include <BD34701KS2.h>

  BD34701KS2 bd(2,3); // CL, DA

void setup() {
  audio();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void audio(){
   bd.set0(0, 0, 0, 1); 
    // Input Selector (MAIN)
    // chip >> 0 (0...1)
    // sub >> 0 (0...1)
    // rec >> 0 (0...1)
    // input >> 1 (1...12 = in1...in12 , 0 = MUTE)
     bd.set1(0, 1);
    // IInput Selector (SUB)
    // chip >> 0 (0...1)
    // input >> 1 (1...12 = in1...in12 , 0 = MUTE)
     bd.set2(0,0,1,1,1,1);
    // chip >> 0 (0...1)
    // adc_att >> 0 (0...8)
    // mode_sbl_sbrch >> 1 (0...3)
    // mmode_sl_srch >> 1 (0...3)
    // mode_c_swch >> 1 (0...3)
    // mode_fr_frch >> 1 (0...3)
     bd.set3(0, 0, 0);
     bd.set3(0, 0, 1);
     bd.set3(0, 0, 2);
     bd.set3(0, 0, 3);
     bd.set3(0, 0, 4);
     bd.set3(0, 0, 5);
     bd.set3(0, 0, 6);
     bd.set3(0, 0, 7);
    // chip >> 0 (0...1)
    // volume >> 0 (-190...64)
    // ch_vol_sel >> 0,1,2,3,4,5,6,7
     bd.set7(0, 0, 0, 0, 0);
    // chip >> 0 (0...1)
    // reset >> 0 (0...1)
    // base_clock >> 0 (0...1)
    // sw_ba >> 0 (0...7)
    // sw_ab >> 0 (0...7)

  }
