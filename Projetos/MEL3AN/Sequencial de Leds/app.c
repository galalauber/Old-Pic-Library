/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 3 de Outubro de 2016, 19:33
 */


#include <xc.h>

#include "Display de Leds.h"
#include "Oscilador.h"
#include "Atrasos.h"


//Definições do aplicativo
//              0b87654321
#define P0      0b10000001
#define P1      0b01000010
#define P2      0b00100100
#define P3      0b00011000
#define P4      0b00011000
#define P5      0b00111100
#define P6      0b01111110
#define P7      0b11111111
#define P8      0b11100111
#define P9      0b11000011

#define NUMERO_PASSOS   10

//Alocação de memória
Uchar   Passo;
Cchar   Sequencia[]= {P0,P1,P2,P3,P4,\
                      P5,P6,P7,P8,P9};  

void main(void)
{
    Oscilador_Inicializacao();
    Display_Inicializacao();
    Display_LigaDigito(_Leds,_br);
    
    Passo = 0;
    
    while (1)
    {
        Display_ExibeCaractere(Sequencia[Passo]);
        
        Atrasos_1ms(200);
        
        Passo++;
        if(Passo == NUMERO_PASSOS) Passo = 0;
        }
}
