/* 
 *  Arquivo:    Fvr.c
 *  uC:         PIC18F46K22
 *  Autor:      JABNeto
 *  Vers�o:     161011 
 */

#include "Fvr.h"


//Aloca��o de mem�ria para o m�dulo -------------------------------------------



//Fun��es Locais --------------------------------------------------------------




//Fun��es P�blicas ------------------------------------------------------------
/*
 *  Fvr_Inicializacao
 *  Faz a inicializa��o do m�dulo Fvr
 */
void Fvr_Inicializacao (void)
{
    VREFCON0bits.FVRS = FVR_TENSAO_DE_REFERENCIA;
    VREFCON0bits.FVREN = Sim;
    
    while (!VREFCON0bits.FVRST){};
}