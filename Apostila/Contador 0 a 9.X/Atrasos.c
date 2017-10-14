/* 
 * File:    Atrasos.c
 * Autor:   JABNeto
 * Data:    13/02/2016
 */


#include "Atrasos.h"


//Alocação de memória para o módulo ------------------




//Funções do módulo ----------------------------------
void Atrasos_1ms (unsigned int Atraso)
{
    while (Atraso > 0)
    {
      __delay_ms(1);
      Atraso--;
    }
}