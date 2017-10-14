/* 
 * Arquivo: Menu1_ControleDeFluxo.c
 * Autor:   JABNeto
 * Versao:  
 */

#include "Definicoes Gerais.h"
#include "Controle de Rotinas.h"
#include "G1_ExibeTelaPrincipal.h"
#include "G1_ExibeHorario.h"

//Alocação de memória para o módulo -------------------------------------------



//Funções do módulo -----------------------------------------------------------
/*
 * Menu1_ControleDeFuxo
 * 
 */
void G1_ControleDeFuxo (void)
{
    //Cabeçalho ---------------------------------------------------------------
    if (Rotinas_ExecutarCabecalho(2) == _SIM)
    {
        CtrlRotinas.Fluxo.Nivel2.Valor = 1;
        CtrlRotinas.Fluxo.Nivel2.ValorMaximo = 9;
        CtrlRotinas.Controle.Cabecalho3 = _SIM;
    }
    
    //Controle de fluxo ------------------------------------------------------
    
    switch (CtrlRotinas.Fluxo.Nivel2.Valor)
    {
        case 1:
            G1_ExibeTelaPrincipal();
            
            break;

        case 2:            
            G1_ExibeHorario();
            break;            

//        case 3:            
//            G1_ExibeData();
//            break;                    
//    
//        case 4:        
//            G1_ExibeGaveta1();
//            break;
//            
//        case 5:
//            G1_ExibeGaveta2();
//            break;             
//    
//        case 6:
//            G1_ExibeGaveta3();
//            break;
//        
//        case 7:    
//            G1_ExibeGaveta4();
//            break;             
//        
//        case 8:    
//            G1_ExibeGaveta5();
//            break;
//
//        case 9:    
//            G1_ExibeGaveta6();
    }
}


