/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 28 de Setembro de 2016, 07:20
 */


#include <xc.h>

#include "Oscilador.h"
#include "Display de Leds.h"
#include "Atrasos.h"

#define NUMERO_DE_PASSOS    9

//              0b87654321
#define P0      0b10000000
#define P1      0b11000000
#define P2      0b01100000
#define P3      0b00110000
#define P4      0b00011000
#define P5      0b00001100
#define P6      0b00000110
#define P7      0b00000011
#define P8      0b00000001

//Alocação de memória
Cchar Sequencia[]= {P0,P1,P2,P3,P4,\
                    P5,P6,P7,P8};

Uchar Passo;

void main(void)
{
    Oscilador_Inicializacao();
    Display_Inicializacao();
    Display_LigaDigito(_Leds,_br);
        
    Passo = 0;
    
    while(1)
    {
        Display_ExibeCaractere(Sequencia[Passo]);
        Atrasos_1ms(250);
        
        Passo++;
        if (Passo == NUMERO_DE_PASSOS)Passo = 0;
    }
}
