/*
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 1 de Junho de 2016, 07:40
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
        if(_S1 == _PRESSIONADA)Display_ExibeCaractere(0b00001111);
        else Display_ExibeCaractere(0b11110000);
        
        
        
    }
}
