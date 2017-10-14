/* 
 * Arquivo: Fvr.c
 * Autor:   JABNeto
 * Versao:  2016.05.19
 */


#include "Fvr.h"

//Aloca��o de mem�ria para o m�dulo -------------------------------------------



//Fun��es locais --------------------------------------------------------------



//Fun��es publicas ------------------------------------------------------------

/*
 * Fvr_Inicializacao
 * Faz a inicializa��o do m�dulo Fvr.
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