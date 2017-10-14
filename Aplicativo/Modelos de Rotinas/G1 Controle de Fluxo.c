/* 
 * Arquivo: G1_CtrlFluxo.c
 * Autor:   JABNeto
 * Versao:  
 */

#include "Definicoes Gerais.h"
#include "Controle de Rotinas.h"
#include "G1 Exibe Tela Principal.h"
#include "G1 Exibe Nome do Produto.h"

//Aloca��o de mem�ria para o m�dulo -------------------------------------------


//Fun��es do m�dulo -----------------------------------------------------------
/*
 * G1_CtrlFluxo
 * 
 */
void G1_CtrlFluxo (void)
{
    //Cabe�alho ---------------------------------------------------------------
    if (Rotinas_ExecutarCabecalho(1) == _SIM)
    {
        Rotinas_ConfiguraNivel(1,9,1);
    }
    
    //Controle de fluxo ------------------------------------------------------
    switch (CtrlRotinas.Nivel[1].Valor)
    {
        case 0:
            G1_ExibeTelaPrincipal();
            break;

    

            
        case 9:    
            G1_ExibeNomeDoProduto();  
            break;
    }
}


