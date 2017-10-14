/* 
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 23 de Março de 2016, 09:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


int main(int argc, char** argv)
{
    //Latch (OE)
    ANSELDbits.ANSD3 = 0;
    LATDbits.LATD3 = 1;
    TRISDbits.TRISD3 = 0;
    
    //Latch (CLK)
    ANSELDbits.ANSD2 = 0;
    LATDbits.LATD2 = 0;
    TRISDbits.TRISD2 = 0;    
    
    //PORTB    
    ANSELB = 0;
    LATB = 0b01000000;
    TRISB = 0;
    
    //Pulso de clock
    LATDbits.LATD2 = 1;
    NOP();
    NOP();
    LATDbits.LATD2 = 0;    
    
    LATB = 0b11110000;    
    LATDbits.LATD3 = 0;    
    
    while (1)
    {
        
    }
    
    return (EXIT_SUCCESS);
}

