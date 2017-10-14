/*
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 1 de Junho de 2016, 09:05
 */

#include <xc.h>

#include "Display de Leds.h"
#include "Teclado.h"


void main(void) 
{
    Display_Inicializacao();
    Teclado_Inicializacao();
    
    Display_LigaDigito(_Leds,_br);

    while (1)
    {
        if(_S1 == _PRESSIONADA) Display_ExibeCaractere(0x08);
        else Display_ExibeCaractere(0);
    }
}
