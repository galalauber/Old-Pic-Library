/* 
 * Arquivo: Menu1_ExibeTelaPrincipal.c
 * Autor:   JABNeto
 * Versao:  
 */

#include "Definicoes Gerais.h"
#include "Controle de Rotinas.h"
#include "Display lcd alfa.h"
#include "Teclado.h"
#include "G1_ExibeTelaPrincipal.h"


//Alocação de memória para o módulo -------------------------------------------



//Funções do módulo -----------------------------------------------------------

/*
 * G1_ExibeTelaPrincipal
 * Exibe a tela principla no display
 */
void G1_ExibeTelaPrincipal (void)
{
    //Cabeçalho//
    if (Rotinas_ExecutarCabecalho(3) == _SIM)
    {
        Rotinas_PedidoDeAtualizacao();
    }

    
    //Atualização//
    if (Rotinas_Atualizacao() == _SIM)
    {
        Lcd_LimpaBuffers();
        
        
        
        
        
        
        
        
        
    }    

    //Teclado//
    if (Tecla_Pressionada(UP) == _SIM)
    {
        Rotinas_DecrementaNivel(&CtrlRotinas.Fluxo.Nivel1);        
    }

    if (Tecla_Pressionada(DOWN) == _SIM)
    {
        Rotinas_IncrementaNivel(&CtrlRotinas.Fluxo.Nivel1);
    }
    
    if (Tecla_Pressionada(LEFT) == _SIM)
    {
        
        
    }
    
    if (Tecla_Pressionada(RIGHT) == _SIM)
    {
        
        
    }
    
    if (Tecla_Pressionada(ENTER) == _SIM)
    {
        
        
    }    
}
