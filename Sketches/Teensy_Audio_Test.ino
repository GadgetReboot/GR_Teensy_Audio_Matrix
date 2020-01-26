// Simple audio input/output passthrough test
// for Teensy 3.6 using the audio shield,
// ADC input, and DAC/PWM output
//
// Gadget Reboot

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputAnalogStereo   adcs1;          //xy=258,186
AudioInputI2S            i2s1;           //xy=259,133
AudioMixer4              mixer1;         //xy=488,146
AudioMixer4              mixer2;         //xy=488,230
AudioOutputPWM           pwm1;           //xy=713,237
AudioOutputAnalogStereo  dacs1;          //xy=714,189
AudioOutputI2S           i2s2;           //xy=715,142
AudioConnection          patchCord1(adcs1, 0, mixer1, 1);
AudioConnection          patchCord2(adcs1, 1, mixer2, 1);
AudioConnection          patchCord3(i2s1, 0, mixer1, 0);
AudioConnection          patchCord4(i2s1, 1, mixer2, 0);
AudioConnection          patchCord5(mixer1, 0, i2s2, 0);
AudioConnection          patchCord6(mixer1, 0, dacs1, 0);
AudioConnection          patchCord7(mixer1, pwm1);
AudioConnection          patchCord8(mixer2, 0, i2s2, 1);
AudioConnection          patchCord9(mixer2, 0, dacs1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=494,50
// GUItool: end automatically generated code

const int myInput = AUDIO_INPUT_LINEIN;

void setup() {
  // audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(30);

  // set mixer input gain
  mixer1.gain(0, 0.4);
  mixer1.gain(1, 0.4);
  mixer1.gain(2, 0);
  mixer1.gain(3, 0);
  mixer2.gain(0, 0.4);
  mixer2.gain(1, 0.4);
  mixer2.gain(2, 0);
  mixer2.gain(3, 0);

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(0.5);

  AudioInterrupts();

}

void loop() {

  // nothing to do, audio channels are open

}
