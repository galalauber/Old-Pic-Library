/*
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 12 de Setembro de 2016, 19:34
 */


#include <xc.h>
#include "Display de Leds.h"
#include "Teclado.h"


void main(void)
{
    //Inicializacao do Hardware
    Display_Inicializacao();
    
    //Liga leds
    Display_LigaDigito(_Leds,0);
    
    //Inicialização do Teclado
    Teclado_Inicializacao();
  
    
    while (1)
    {
        if(_S1 == _PRESSIONADA) LATB = 0b00000001;
        else LATB = 0;
 
    }



    return;
}
