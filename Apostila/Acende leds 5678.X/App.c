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
    
    //Inicialização do pino RD2
    //Latch (CLK) = 0
    LATDbits.LATD2 = 0;    
    TRISDbits.TRISD2 = 0;     
    ANSELDbits.ANSD2 = 0;

    //Inicialização do PORT B
    LATB = 0;
    TRISB = 0;
    ANSELB = 0;    
    
    //Escreve no latch
    LATBbits.LATB6 = 1;    
    LATDbits.LATD2 = 1;
    NOP();
    NOP();    
    NOP();    
    NOP();
    LATDbits.LATD2 = 0;
    
    //Define no PORT B os
    //Leds que devem acender
    LATB = 0b11110000;  
    
    //Retira as saídas do latch
    //do modo de alta impedância
    LATDbits.LATD3 = 0;
    
    while(1)
    {

        
    }

    return (EXIT_SUCCESS);
}

