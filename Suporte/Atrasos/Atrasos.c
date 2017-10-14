/* 
 * Arquivo: Atrasos.c
 * Autor:   JABNeto
 * Versao:  150710
 */


#include "Atrasos.h"



//Alocação de memória para o módulo--------------------------------------------



//Funções locais --------------------------------------------------------------




//Funções públicas ------------------------------------------------------------
void Atrasos_1ms (unsigned int Tempo_ms)
{
    while(Tempo_ms-- > 0)
    {
        __delay_ms (1);        
    }
}



