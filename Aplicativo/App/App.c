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
#include "Eeprom.h"
#include "Interrupcoes.h"
#include "Controle de Rotinas.h"
#include "Display lcd alfa.h"
#include "G1 Controle de Fluxo.h"
#include "Controle do Forno.h"

#include "App.h"






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
    

    if (EEPROM_DetectaInicializacao() == _NAO)
    {
        Medidas_ResetaParametros();
        EEPROM_EscreveInicializacao();
    }
}


/*
 * App_InicializacaoDosModulos
 * Faz a inicialização dos modulods do aplicativo.
 */
void App_InicializacaoDosModulos(void)
{
    Medidas_Inicializacao();
    Rotinas_Inicializacao();    
    Lcd_Inicializacao();
}


/*
 * App_Inicializacao
 * Faz a inicialização do aplicativo
 */
void App_Inicializacao(void)
{
    App_InicializacaoDaCpu();
    App_InicializacaoDosModulos();
    CtrlRotinas.Nivel[0].Controle.ExecutarCabecalho = _SIM;;
    
    Habilita_Interrupcoes();
}


/*
 * App_Tarefas
 * Execução das tarefas que são independentes do fluxo do programa. Essas
 * tarefas são constantemente executadas.
 */
void App_Tarefas(void)
{


}



/*
 * App_Monitor
 * 
 */
void App_Monitor (void)
{
    //Cabeçalho ---------------------------------------------------------------
    if (Rotinas_ExecutarCabecalho(0) == _SIM)
    {
        Rotinas_ConfiguraNivel (0,0,2);
    }

    
    //Execução das tarefas periódicas do aplicativo
    App_Tarefas();
  
    
    //Controle de fluxo ------------------------------------------------------
    switch (CtrlRotinas.Nivel[0].Valor)
    {
        case 0:
            G1_CtrlFluxo();
            break;
            
//        case 1:
//            G2_CtrlFluxo();
//            break;
//            
//        case 2:
//            G3_CtrlFluxo();
//            break;           
            
    }
}


