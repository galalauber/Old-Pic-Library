/* 
 * Projeto: Teclado e Display 1
 * Arquivo: App.c
 * Autor:   JABNeto
 * Data:    10/02/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "Base_1.h"

//Sequencia de acendimento dos leds
//                      0b87654321
#define _SEQ0           0b00000001
#define _SEQ1           0b00000010
#define _SEQ2           0b00000100
#define _SEQ3           0b00001000
#define _SEQ4           0b00010000
#define _SEQ5           0b00100000
#define _SEQ6           0b01000000
#define _SEQ7           0b10000000
#define _SEQ8           0b11000000
#define _SEQ9           0b11100000
#define _SEQ10          0b11110000
#define _SEQ11          0b11111000
#define _SEQ12          0b11111100
#define _SEQ13          0b11111110
#define _SEQ14          0b11111111
#define _SEQ15          0b01111111
#define _SEQ16          0b00111111
#define _SEQ17          0b00011111
#define _SEQ18          0b00001111
#define _SEQ19          0b00000111
#define _SEQ20          0b00000011
#define _SEQ21          0b00000001

#define _XTAL_FREQ      1000000

//Alocação de memória para o Módulo-------------------
const char Codigo_Seq[] = {_SEQ0,_SEQ1,_SEQ2,_SEQ3,
                           _SEQ4,_SEQ5,_SEQ6,_SEQ7,
                           _SEQ8,_SEQ9,_SEQ10,_SEQ11,
                           _SEQ12,_SEQ13,_SEQ14,_SEQ15,
                           _SEQ16,_SEQ17,_SEQ18,_SEQ19,
                           _SEQ20,_SEQ21};  

Uchar   Sequencia;

int main(int argc, char** argv)
{
    Display_Inicializacao(0,_Leds);
    Sequencia = 0;
    
    while(1)
    {
       LATB = Codigo_Seq[Sequencia];
       
       __delay_ms(100);
       
       if(++Sequencia == 22) Sequencia = 0;
    }
        
    return (EXIT_SUCCESS);
}

