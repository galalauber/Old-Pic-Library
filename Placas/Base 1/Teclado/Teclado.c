/* 
 * Arquivo: Teclado.c
 * Autor:   JABNeto
 * Versao:  150710
 */


#include "Teclado.h"

#if (TECLADO_FUNCOES_LCD == _SIM)
#include "Display lcd alfa.h"
#endif


//Alocação de memória para o módulo -------------------------------------------
#if (TECLADO_FUNCOES_ESTENDIDAS == _SIM)
_Ctrl_Teclado       Ctrl_Teclado;
#endif



//Funções locais do módulo ----------------------------------------------------




//Funções públicas do módulo --------------------------------------------------
void Teclado_Inicializacao (void)
{
    ANSELA = 0;
    
    #if (TECLADO_FUNCOES_ESTENDIDAS == _SIM)
        Ctrl_Teclado.Controle.Valor = 0;
        Ctrl_Teclado.Eventos.Valor = 0;
    #endif
}


#if (TECLADO_FUNCOES_ESTENDIDAS == _SIM)
/*
 * Teclado_Monitor
 * Faz o monitoramento do teclado no modo estendido
 */
void Teclado_Monitor(void)
{
    #if (TECLADO_MODO_DE_CAPTURA == _DIRETO)
    {
        if (_S1 == _PRESSIONADA) Ctrl_Teclado.Eventos.S1 = _SIM;
        if (_S2 == _PRESSIONADA) Ctrl_Teclado.Eventos.S2 = _SIM;
        if (_S3 == _PRESSIONADA) Ctrl_Teclado.Eventos.S3 = _SIM;
        if (_S4 == _PRESSIONADA) Ctrl_Teclado.Eventos.S4 = _SIM;
        if (_S5 == _PRESSIONADA) Ctrl_Teclado.Eventos.S5 = _SIM;        
    }
    #else
    {
        if ((PORTA | 0b11000100) == 0xFF) Ctrl_Teclado.Controle.Recuo = _SIM;
        else
        {
            if (Ctrl_Teclado.Controle.Recuo == _SIM)
            {
                Ctrl_Teclado.Controle.Recuo = _NAO;
                
                if (_S1 == _PRESSIONADA) Ctrl_Teclado.Eventos.S1 = _SIM;
                else if (_S2 == _PRESSIONADA) Ctrl_Teclado.Eventos.S2 = _SIM;
                else if (_S3 == _PRESSIONADA) Ctrl_Teclado.Eventos.S3 = _SIM;              
                else if (_S4 == _PRESSIONADA) Ctrl_Teclado.Eventos.S4 = _SIM;                
                else if (_S5 == _PRESSIONADA) Ctrl_Teclado.Eventos.S5 = _SIM;
            }
        }
    }
    
    #if (TECLADO_FUNCOES_LCD == _SIM)
        #if (_LCD_MODO_GREEN == _SIM)
        if (Ctrl_Teclado.Eventos.Valor != 0)
        {
            CtrlDisplay.BackLight.Sinais.Restart = _SIM;                    
        }
        #endif
    #endif    
    
    #endif
}

/*
 * Tecla_Pressionada
 * Detecta se existe evento para a tecla fornecida
 * Retorno:
 * _NAO (0): Não existe evento de tecla pressionda para a tecla fornecida
 * _SIM (1): Existe evento de tecla pressionda para a tecla fornecida
 * 
 * Tecla: corresponde ao numero da tecla que se deseja detectar a existencia
 * do evento. (1,2,3,4 ou 5). O evento é removido após a detecção e, somente
 * para a tecla em teste.
 * 
 * Ex de aplicação. if (Tecla_pressionada(1) == _SIM)
 */
Uchar Tecla_Pressionada (Uchar Tecla)
{
    Uchar Retorno = _NAO;

    switch (Tecla)
    {
        case 1:
            if (Ctrl_Teclado.Eventos.S1 == _SIM)
            {
                Ctrl_Teclado.Eventos.S1 = _NAO;
                Retorno = _SIM;
            }
            break;

        case 2:
            if (Ctrl_Teclado.Eventos.S2 == _SIM)
            {
                Ctrl_Teclado.Eventos.S2 = _NAO;
                Retorno = _SIM;
            }
            break;

        case 3:
            if (Ctrl_Teclado.Eventos.S3 == _SIM)
            {
                Ctrl_Teclado.Eventos.S3 = _NAO;
                Retorno = _SIM;
            }
            break;

        case 4:
            if (Ctrl_Teclado.Eventos.S4 == _SIM)
            {
                Ctrl_Teclado.Eventos.S4 = _NAO;
                Retorno = _SIM;
            }
            break;
            
        case 5:
            if (Ctrl_Teclado.Eventos.S5 == _SIM)
            {
                Ctrl_Teclado.Eventos.S5 = _NAO;
                Retorno = _SIM;
            }
    }


    return Retorno;
}

#endif




