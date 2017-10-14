/* 
 * File:   Display 7 segmentos.c
 * Author: jose_010573
 *
 * Created on 6 de Setembro de 2016, 22:15
 */

#include "Display 7 segmentos.h"


void Display_LigaDigito(unsigned char Digito,\
                        unsigned char Caractere)
{
   //Latch no modo Hi-z 
    LATDbits.LATD3 = 1;

   //Escreve codigo do digito no latch
    LATB = Digito;

    //PULSO DE CLOCK
    LATDbits.LATD2 = 1;
    NOP();
    NOP();
    LATDbits.LATD2 = 0;

    //Exibe o caractere
    LATB = Caractere;
    
   //Habilita as saídas do Latch
    LATDbits.LATD3 = 0;    
}

void Display_Inicializacao (void)
{
    //RD3 (OE)
    ANSELDbits.ANSD3 = 0;
    LATDbits.LATD3 = 1;
    TRISDbits.TRISD3  = 0; 

    //RD2 (CLK)
    ANSELDbits.ANSD2 = 0;
    LATDbits.LATD2 = 0;
    TRISDbits.TRISD2  = 0;     

    //PORTB
    ANSELB = 0;
    LATB = 0;
    TRISB = 0;
    
    Display_LigaDigito(0,0);

}