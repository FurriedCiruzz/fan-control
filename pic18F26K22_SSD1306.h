#include <18F26K22.h>
#device ADC=8

//#device PASS_STRINGS = IN_RAM

#FUSES NOWDT                   //No Watch Dog Timer

//#use fast_io(C)

#use delay(crystal=8MHz)
#use i2c(Master,Fast,sda=PIN_C4,scl=PIN_C3, force_hw, stream=SSD1306_STREAM, SMBUS)

