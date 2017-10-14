/* 
 * File:   App.c
 * Author: JABNeto
 *
 * Created on 10 de Fevereiro de 2016, 09:05
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

int main(int argc, char** argv)
{
    //Inicialização do pino RD3
    //Latch (OE) = 1
    LATDbits.LATD3 = 1;    
    TRISDbits.TRISD3 = 0;     
    ANSELDbits.ANSD3 = 0;

    //Inicialização do PORT B
    //Leds 1234 acesos
    LATB = 0b00001111;
    TRISB = 0;
    ANSELB = 0;
    
    while(1)
    {

        
    }

    return (EXIT_SUCCESS);
}


