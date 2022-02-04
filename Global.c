/* ================================= Define ================================= */
#define  LED    PIN_B0  //Led di sistema
#define  FAN    PIN_B1  //Fan control pin 

//=============================================================================
/*fixed threshold register for fan intervention tra 0-255, 0   --> 00°C
                                                           1   --> 0.3125°C
                                                           02  --> 0.625°C
                                                           04  --> 1.25°C
                                                           08  --> 2.5°C
                                                           16  --> 5°C
                                                           32  --> 10°C
                                                           64  --> 20°C
                                                           128 --> 40°C
                                                           255 --> 80°C
registro sogila=threshold --> temperatura=threshold 80/255
se voglio calcolre la soglia dalla tempertura=threshold*255/80                */
                                                           
#define SOGLIA 80  //fixed threshold register for fan intervention at 25°C
//=============================================================================


//=============================================================================
//                                  MACRO
//=============================================================================
#define FanOn()   output_high(FAN)
#define FanOff()  output_low(FAN)

#define LedOn()    output_high(LED)
#define LedOff()   output_low(LED)

#define blinking()   { LedOn(); delay_ms(100); LedOff();  delay_ms(500);}

#define STATO_VENTOLA_ON 1
#define STATO_VENTOLA_OFF 0
