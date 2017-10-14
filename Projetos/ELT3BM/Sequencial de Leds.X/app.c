/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 28 de Setembro de 2016, 11:04
 */


#include <xc.h>

#include "Oscilador.h"
#include "Display de Leds.h"
#include "Atrasos.h"


#define NUMERO_DE_PASSOS    9

//Sequencia     0b87654321
#define P0      0b10000000
#define P1      0b00000001
#define P2      0b11000000
#define P3      0b00000011
#define P4      0b11100000
#define P5      0b00000111
#define P6      0b11110000
#define P7      0b00001111
#define P8      0b11111111


//Alocação de memória
const char Sequencia[]={P0,P1,P2,P3,P4,\
                        P5,P6,P7,P8};
Uchar Passo;

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
        if (Passo == NUMERO_DE_PASSOS)Passo = 0;
    }
}
