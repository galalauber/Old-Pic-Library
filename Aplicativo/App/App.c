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






//Fun��es do m�dulo ----------------------------------------------------------
/*
 * App_InicializacaoDaCpu
 * Faz a inicializa��o dos m�dulos da Cpu
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
 * Faz a inicializa��o dos modulods do aplicativo.
 */
void App_InicializacaoDosModulos(void)
{
    Medidas_Inicializacao();
    Rotinas_Inicializacao();    
    Lcd_Inicializacao();
}


/*
 * App_Inicializacao
 * Faz a inicializa��o do aplicativo
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
 * Execu��o das tarefas que s�o independentes do fluxo do programa. Essas
 * tarefas s�o constantemente executadas.
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
    //Cabe�alho ---------------------------------------------------------------
    if (Rotinas_ExecutarCabecalho(0) == _SIM)
    {
        Rotinas_ConfiguraNivel (0,0,2);
    }

    
    //Execu��o das tarefas peri�dicas do aplicativo
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


