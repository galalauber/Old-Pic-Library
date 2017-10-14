/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 26 de Setembro de 2016, 19:30
 */


#include <xc.h>

#include "Display de Leds.h"
#include "Teclado.h"


Uchar Contador;
_Codigo7segmentos;

void main(void) 
{
    Display_Inicializacao();
    Display_LigaDigito(_Digito6,_br);
    Teclado_Inicializacao();

    while(1)
    {
        Contador = 0;
                
        if (_S1 --== _PRESSIONADA) Contador++;
        if (_S2 == _PRESSIONADA) Contador++;
        if (_S3 == _PRESSIONADA) Contador++;
        if (_S4 == _PRESSIONADA) Contador++;
        if (_S5 == _PRESSIONADA) Contador++;

        Display_ExibeCaractere(Codigo7segmentos[Contador]);
    }
}


