/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 28 de Setembro de 2016, 08:57
 */


#include <xc.h>

#include "Oscilador.h"
#include "Display de Leds.h"
#include "Atrasos.h"


#define NUMERO_DE_PASSOS    10

//Sequencia
//          0b87654321
#define P0  0b10000001
#define P1  0b01000010
#define P2  0b00100100
#define P3  0b00011000
#define P4  0b00100100
#define P5  0b01000010
#define P6  0b10000001
#define P7  0b11000011
#define P8  0b11100111
#define P9  0b11111111


//Aloca��o de mem�ria
const char Sequencia[] = {P0,P1,P2,P3,P4,\
                          P5,P6,P7,P8,P9};  
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
