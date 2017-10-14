/* 
 * Arquivo: Atrasos.c
 * Autor:   JABNeto
 * Versao:  150710
 */


#include "Atrasos.h"



//Aloca��o de mem�ria para o m�dulo--------------------------------------------



//Fun��es locais --------------------------------------------------------------




//Fun��es p�blicas ------------------------------------------------------------
/*
 * Atrasos_1ms
 * Gera atraso de N vezes 1ms
 * Tempo_ms: Define o temo em ms desejado. O valor
 *           m�ximo � 65535 (65,5s).
 * 
 * Ex. Atrasos_1ms(400): gera um atraso de 400ms.
 */
void Atrasos_1ms (unsigned int Tempo_ms)
{
    while(Tempo_ms-- > 0)
    {
        __delay_ms (1);        
    }
}



