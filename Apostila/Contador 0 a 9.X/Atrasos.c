/* 
 * File:    Atrasos.c
 * Autor:   JABNeto
 * Data:    13/02/2016
 */


#include "Atrasos.h"


//Aloca��o de mem�ria para o m�dulo ------------------




//Fun��es do m�dulo ----------------------------------
void Atrasos_1ms (unsigned int Atraso)
{
    while (Atraso > 0)
    {
      __delay_ms(1);
      Atraso--;
    }
}