/* *****************************************************************************
** Utility.c                                                                  **
**                                                                            **
** Libreria di funzioni di utilità per v1.0                                   **
**                                                    (C)   Monterotondo-Rm   **
***************************************************************************** */

/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++ Function: writeFanOn()                                                     ++
++ Description: writes on the display in column 12 line 5 the string: "on"    ++
++ Author: ..........                                                         //
++ date: 11/12/2021                                                           //
++ Parameters: Void                                                           //
++ Returned: Void                                                             //
                                                                              */
void writeFanOn(){                                                            //
       size=LARGE;                                                            //
       OLED_gotoxy(12,5);                                                     //
       printf(OLED_putc,"on ");//This is the fastest way to write text        //
}                                                                             //
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++ Function: writeFanOff()                                                    //
++ Description: writes on the display in column 12 line 5 the string: "on"    //
++ Author: ..........                                                         //
++ date: 11/12/2021                                                           //
++ Parameters: Void                                                           //
++ Returned: Void                                                             //
                                                                              */
void writeFanOff(){                                                           //
       size=LARGE;                                                            //
       OLED_gotoxy(12,5);                                                     //
       printf(OLED_putc,"off");//This is the fastest way to write text        //
}                                                                             //
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
       
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++ Function: view(float temperature)                                          //
++ Description: displays the temperature and the bar                          //
++ Author: ..........                                                         //
++ date: 11/12/2021                                                           //
++ Parameters: temperatura                                                    //
++ Returned: Void                                                             //
++                                                                            */
void view(float temperature){                                                 //
       int8 bar;                                                              //
       size=NORMAL;                                                           //
       OLED_gotoxy(13,0);                                                     //
       printf(OLED_putc,"%3.1f C ",temperature);                              //
       /*La barra è piena quando il suo valore vale 100. Si effettua la       //
        propozione in modo da avere la barra piena quando raggiugimo gli 80 °C*/
       bar=(int8) ((10*temperature)/8);                                       //
       OLED_gotoxy(2,2);                                                      //
       size=LARGE;                                                            //
       OLED_textbar(bar);                                                     //
       delay_ms(50);                                                          //
}                                                                             //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++ Function: viewThreshold(int8 threshold,float t)                            //
++ Description: displays the temperature and the bar and Threshold            //
++ Author: ..........                                                         //
++ date: 11/12/2021                                                           //
++ Parameters: temperatura t, e la soglia (intero da 0 255).  La temperatura  //
               imostata nel registro sogila --> temperatura=threshold 80/255  //
               se voglio calcolre la soglia dalla tempertura=threshold*255/80 //
               Il dato della soglia è pronto per essere letto dalla tensione  //
               ai capi di un poteziometro con un atro canale ADC              //
++ Returned: Void                                                             */

void viewThreshold(int8 threshold,float t){                                   //
       int i;                                                                 //
       float s;                                                               //
       char text[3];// array utilizzato per l'indicatore dell soglia          //
       s=(float)(threshold)*0.31372549;//valore in temperatura della soglia   //
       threshold=(int8)(threshold*0.0784313725);//adattemento sul display     //
       view(t); // visulizza il valore e la barra della temperatura           //
       size=NORMAL; //ampizza del carattere                                   //
       OLED_gotoxy(threshold,3); // posizionameto dell'indicatore 1/2 di riga //
       strcpy(text,"|");                                                      //
       OLED_text(text,strlen(text)); //satampa l'indicatore                   //
       OLED_gotoxy(threshold,2);//posizionameto dell'indicatore 2° metà di riga/
       strcpy(text,"|");                                                      //
       OLED_text(text,strlen(text));                                          //
       for (i=0;i<threshold-2;i++){                                           //
            OLED_gotoxy(i,4);                                                 //
            printf(OLED_putc," ");//stampa i primi stampa spazi vuoti         //
       }                                                                      //
       OLED_gotoxy(threshold-2,4);                                            //
       printf(OLED_putc,"%3.1f C",s);//stampa il valore della soglia          //
       for (i=threshold+4;i<20;i++){                                          //
           OLED_gotoxy(i,4);                                                  //
           printf(OLED_putc," ");// stampa i seguenti spazi vuoti             //
        }                                                                     //
}                                                                             //
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++ Function: float temperatureReading()                                      //                  
++ Description: enables the A0 channel and reads the voltage that is         //
++              converted to entire at 8 bit                                 //
++ Author: ..........                                                        //
++ date: 11/12/2021                                                          //
++ Parameters: void                                                          //
++ Returned:  il valore del registro convertito dall'ADC                     */ 
int8 temperatureReading(){                                                   //
      int8 dt;                                                               //
      set_ADC_channel(0);                                                    //
      delay_us(20);                                                          //
      dt=read_adc();                                                         //
      return  dt;                                                            //
}                                                                            //
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++ Function: aggiornaDisplay(void)                                            //
++ Description: updates the displayed fan's state accordingly to its current  //
++              state                                                         //
++ Author: Gabriele Mercolino                                                 //
++ date: 30/01/2022                                                           //
++ Parameters: statoVentolaAttuale e statoVentolaPrecedente. Sono usati per   //
++             aggiornare il display solo quando necessario                   //
++ Returned: Void                                                             */
void aggiornaDisplay(float te, int8 datoSoglia, int1 statoVentolaAttuale, int1 statoVentolaPrecedente){  
   viewThreshold(datoSoglia, te);
   if(statoVentolaAttuale == statoVentolaPrecedente)  return;                 //
   if(statoVentolaAttuale == STATO_VENTOLA_ON)  writeFanOn();                 //
   else writeFanOff();                                                        //
   statoVentolaPrecedente = statoVentolaAttuale;                              //
}                                                                             //
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
