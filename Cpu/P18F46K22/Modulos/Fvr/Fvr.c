/* 
 * Arquivo: Fvr.c
 * Autor:   JABNeto
 * Versao:  2016.05.19
 */


#include "Fvr.h"

//Alocação de memória para o módulo -------------------------------------------



//Funções locais --------------------------------------------------------------



//Funções publicas ------------------------------------------------------------

/*
 * Fvr_Inicializacao
 * Faz a inicialização do módulo Fvr.
 */
void Fvr_Inicializacao (void)
{
    FVRCONbits.FVRS = _FVR_TENSAO_DE_SAIDA;
    
    if (FVRCONbits.FVRS != 0)
    {
        FVRCONbits.FVREN = 1;
        while (FVRCONbits.FVRST == 0) {};
    }
}