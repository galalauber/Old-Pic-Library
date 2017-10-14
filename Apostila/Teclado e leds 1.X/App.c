/* 
 * Projeto: Teclado e leds 1
 * Arquivo: App.c
 * Autor:   JABNeto
 * Data:    10/02/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

int main(int argc, char** argv)
{
    //Inicializa��o do pino RD3
    //Latch (OE) = 1
    LATDbits.LATD3 = 1;    
    TRISDbits.TRISD3 = 0;     
    ANSELDbits.ANSD3 = 0;
    
    //Inicializa��o do pino RD2
    //Latch (CLK) = 0
    LATDbits.LATD2 = 0;    
    TRISDbits.TRISD2 = 0;     
    ANSELDbits.ANSD2 = 0;

    //Inicializa��o do PORT A
    ANSELA = 0b00000100;
    
    //Inicializa��o do PORT B
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
    
    //Leds partem apagados
    LATB = 0;  
    
    //Retira as sa�das do latch
    //do modo de alta imped�ncia
    LATDbits.LATD3 = 0;

    while(1)
    {
        if (PORTAbits.RA0 == 0)
        {
            LATB = 0b00000001;
        }
        else
        {
            LATB = 0b00000000; 
        }
    }

    return (EXIT_SUCCESS);
}









