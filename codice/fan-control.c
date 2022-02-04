#include <pic18F26K22_SSD1306.h>
#include <Global.c>      // vengono definite delle macro e delle funzioni di sistema
#include <setUpDisplay.c>// procedure di inizializzazione del display
#include <Utility.c>     // funzini di stampa su display
//***************************************************************************

/*****************************************************************************
**                    FUNZIONI CHE POSSONO ESSERE USATE                     **
**    displayInitialization();          --inizializza il display--          **
**--------------------------------------------------------------------------**
**    viewThreshold(datoSoglia,te);     --visualizza sul display sia la     **
**                                         temperatura della soglia che     **
**                                         quella ambientale--              **
**--------------------------------------------------------------------------**
**    blinking();                       --Lampeggia il led di sistema--     **
**--------------------------------------------------------------------------**
**    writeFanOn();                     -- scrive sul display ON--          **
**--------------------------------------------------------------------------**
**    writeFanOff();                    -- scrive sul display OFF-          **
**--------------------------------------------------------------------------**
**    FanOff();                         -- spegne la ventola--              **
**--------------------------------------------------------------------------**
**    FanOn();                          -- accende la ventola--             **
**--------------------------------------------------------------------------**
**    FanOn();                          -- accende la ventola--             **
**--------------------------------------------------------------------------**
**    temperatureReading()              --abilita ADC e restituisce il      **
**                                         valore del registro valore       ** 
**                                         compreso tra 0 e 255)--          **
*****************************************************************************/

void main(){
  setup_adc_ports(sAN0|sAN1);
  setup_adc(ADC_CLOCK_INTERNAL|ADC_TAD_MUL_0);
  
  
  //aggiungi le tue variabili
   int8 datoTemp;         // variabile dove viene salvato il valore convertito dall'ADC
   int8 datoSoglia=SOGLIA;// variabile dove viene salvato la soglia 80=>25°C vedi global.C
   float te=0;            // valore della temperatura ambiente
   float s;

 /*/////////////////////////////////////////////////////////////////////////////////
 //esempio di come si converte il dato letto dall ADC in temperatura              //
 //datoTemp=temperatureReading();                                                 //
 //te=(float)(datoTemp)*0.31372549;//te=datoTemp*80/255:conversione in temperatura//
 /////////////////////////////////////////////////////////////////////////////////*/
 
 
  // qui mettete il vostro programma......................
  displayInitialization();
  FanOff();
  blinking();
   while(TRUE) {
      datoTemp = temperatureReading();
      
      te=(float)(datoTemp)*0.31372549;          // 80:255=te:datoTemp  te=datotemp*80/255
      s=(float)(datoSoglia)*0.31372549;         // datoSoglia:255=soglia:80   soglia=datoSoglia*80/255
      
      if(te > s)  FanOn();
      else        FanOff();
      
      viewThreshold(datoSoglia,te);
      
      delay_ms(1000);   // delay di 1 secondo 
      blinking();
   }
}
