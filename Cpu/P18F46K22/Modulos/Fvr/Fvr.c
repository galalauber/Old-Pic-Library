/* 
 *  Arquivo:    Fvr.c
 *  uC:         PIC18F46K22
 *  Autor:      JABNeto
 *  Versão:     161011 
 */

#include "Fvr.h"


//Alocação de memória para o módulo -------------------------------------------



//Funções Locais --------------------------------------------------------------




//Funções Públicas ------------------------------------------------------------
/*
 *  Fvr_Inicializacao
 *  Faz a inicialização do módulo Fvr
 */
void Fvr_Inicializacao (void)
{
    VREFCON0bits.FVRS = FVR_TENSAO_DE_REFERENCIA;
    VREFCON0bits.FVREN = Sim;
    
    while (!VREFCON0bits.FVRST){};
}