/* 
 * Arquivo: Atrasos.c
 * Autor:   JABNeto
 * Versao:  150710
 */


#include "Atrasos.h"



//Aloca��o de mem�ria para o m�dulo--------------------------------------------



//Fun��es locais --------------------------------------------------------------




//Fun��es p�blicas ------------------------------------------------------------
void Atrasos_1ms (unsigned int Tempo_ms)
{
    while(Tempo_ms-- > 0)
    {
        __delay_ms (1);        
    }
}



