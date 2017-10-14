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
    Display_LigaDigito(_Digito3,_br);
    
    
    while (1)
    {
        if (_S1 == _PRESSIONADA)Display_ExibeCaractere(_1);
        else if (_S2 == _PRESSIONADA)Display_ExibeCaractere(_2);
        else if (_S3 == _PRESSIONADA)Display_ExibeCaractere(_3);
        else if (_S4 == _PRESSIONADA)Display_ExibeCaractere(_4);       
        else if (_S5 == _PRESSIONADA)Display_ExibeCaractere(_5);
        else Display_ExibeCaractere(_sg);       
    }
}
