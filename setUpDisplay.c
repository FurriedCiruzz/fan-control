
//***************************************************************************
//display dimensions - the physical LCD //                                  *
#define S_LCDWIDTH               128    //                                  *
#define S_LCDHEIGHT              64     //                                  *
//--------------------------------------//                                  *
#define SH1106       //If you want to use the SH1106, add this #define      *
#define TEXT_ONLY    //If this is defined, gives a smaller text driver only *
#define SSDADDR 0x78 //address for the chip - usually 0x7C or 0x78.         *
#include <string.h>  //                                                     *                                                          
#include "ssd1306.h" //The OLED driver                                      *
//***************************************************************************

void displayInitialization(){
 char text[15]; //temporary text buffer
   delay_ms(10);                //OLED takes time to wake
   //now try to initialise OLED
   OLED_commands(init_sequence,sizeof(init_sequence)); //initialise the OLED
   //Now try some text
   set=TRUE;
   size=NORMAL;
   OLED_CLS(); //clear the physical screen
   OLED_gotoxy(0,0);
   strcpy(text,"Temperatura = ");
   OLED_text(text,strlen(text)); //This is the fastest way to write text
   delay_ms(2000);  //pause for two seconds*/
    size=LARGE;
   OLED_gotoxy(5,5);
   printf(OLED_putc,"fan ");
   }
   
   

