/* 
 * Arquivo: App.c
 * Autor:   JABNeto
 * Versao:  
 */

#include "Definicoes Gerais.h"
#include "Oscilador.h"
#include "Adc 1.h"
#include "Timer 0.h"
#include "Medidas.h"
#include "Fvr.h"
#include "Interrupcoes.h"
#include "Controle de Rotinas.h"
#include "Display lcd alfa.h"
#include "Teclado.h"
#include "App.h"
#include "G1_ControleDeFluxo.h"



//Funções do módulo ----------------------------------------------------------
/*
 * App_InicializacaoDaCpu
 * Faz a inicialização dos módulos da Cpu
 */
void App_InicializacaoDaCpu(void)
{
    Oscilador_Inicializacao();
    ADC1_Inicializacao();
    Fvr_Inicializacao();
    Timer0_Inicializacao();    
}


/*
 * App_InicializacaoDo Aplicativo
 * Faz a inicialização do aplicativo. As rotinas de inicialização dos 
 * módulos devem ser chamadas aqui.
 */
void App_InicializacaoDoAplicativo(void)
{
    Lcd_Inicializacao();
    Teclado_Inicializacao();
    Medidas_Inicializacao();
    Rotinas_Inicializacao();    
}


/*
 * App_Inicializacao
 * Faz a inicialização do aplicativo
 */
void App_Inicializacao(void)
{
    App_InicializacaoDaCpu();
    App_InicializacaoDoAplicativo();
    CtrlRotinas.Controle.Cabecalho1 = _SIM;
    
    #ifdef INTERRUPCOES_H
    Habilita_Interrupcoes();
    #endif
}


/*
 * App_Monitor
 * Executa as tarefas periodicas do sistema
 */
void App_Monitor(void)
{

    
    
    
    
}


/*
 * App_ControleDeFuxo
 * 
 */
void App_ControleDeFuxo (void)
{
    //Cabeçalho ---------------------------------------------------------------
    if (Rotinas_ExecutarCabecalho(1) == _SIM)
    {
        CtrlRotinas.Fluxo.Nivel1.Valor = 1;
        CtrlRotinas.Fluxo.Nivel1.ValorMaximo = 3;
        CtrlRotinas.Controle.Cabecalho2 = _SIM;
    }

    
    //Tarefas conatantes
    App_Monitor();
    
    
    //Controle de fluxo ------------------------------------------------------
    switch (CtrlRotinas.Fluxo.Nivel1.Valor)
    {
        case 1:
            G1_ControleDeFuxo();
            break;
            
//        case 2:
//            G2_ControleDeFuxo();
//            break;
//            
//        case 3:
//            G3_ControleDeFuxo();
//            break;           
            
    }
}


