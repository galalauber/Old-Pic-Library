/* 
 * Arquivo: Timer 0.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include "Timer0 Config.h"
#include "Definicoes Gerais.h"

#if (_TIMER0_HABILITAR_FUNCOES_TECLADO == _SIM)
#include "Teclado.h"
#endif

#if (_TIMER0_HABILITAR_FUNCOES_LCD == _SIM)
#include "Display lcd alfa.h"
#endif

#if (_TIMER0_HABILITAR_FUNCOES_ROTINAS == _SIM)
#include "Controle de Rotinas.h"
#endif

#include "Timer0.h"

//Alocação de memória para o módulo--------------------------------------------
_Ctrl_Timer0    Ctrl_Timer0;

#if (_TIMER0_HABILITAR_EVENTOS_10MS == _SIM)
_Eventos10ms    Eventos10ms;
#endif

#if (_TIMER0_HABILITAR_EVENTOS_100MS == _SIM)
_Eventos100ms    Eventos100ms;
#endif

#if (_TIMER0_HABILITAR_EVENTOS_1S == _SIM)
_Eventos1s      Eventos1s;
#endif


//Funções locais --------------------------------------------------------------
/*
 * Timer0_CarregaValor
 * Recarrega o temporizador Timer 0 com valor que gera 1ms
 */
void Timer0_CarregaValor (void)
{
    Uint32 ValorDeCarga;

    T0IF = 0;
    
    ValorDeCarga.valor =  TIMER0_VALOR_DE_CARGA;

    TMR0H = ValorDeCarga.bytes.byte1;
    TMR0L = ValorDeCarga.bytes.byte0; 
}


//Funções publicas ------------------------------------------------------------

/*
 * Timer0_Inicializacao
 * Faz a inicializacao do Temporizador Timer0
 */
void Timer0_Inicializacao (void)
{
    Ctrl_Timer0.Temporizador10ms = 10;
    Ctrl_Timer0.Temporizador100ms = 100;
    Ctrl_Timer0.Temporizador250ms = 250;
    Ctrl_Timer0.Temporizador1s = 1000;    

    T0CON = 0;
    
    Timer0_CarregaValor();
    
    #if (_TIMER0_USA_INTERRUPCAO == _SIM)
    INTCONbits.TMR0IE = 1;
    #endif

    T0CONbits.TMR0ON = 1;
}


#if (_TIMER0_USA_INTERRUPCAO == _SIM)
/*
 * Timer0_Interrupcao
 * Atendimento dos pedidos de interrupção do módulo
 */
void Timer0_Interrupcao (void)
{
    if (T0IE && T0IF)
    {
        Timer0_CarregaValor();
        
        //Chamada de funções de 1ms
        #if (_TIMER0_HABILITAR_FUNCOES_TECLADO == _SIM)
            Teclado_Monitor();
        #endif
        
            
        if (--Ctrl_Timer0.Temporizador10ms == 0)
        {
            Ctrl_Timer0.Temporizador10ms = 10;
            
        #if (_TIMER0_HABILITAR_EVENTOS_10MS == _SIM)              
            Eventos10ms.valor = 0xFF;
        #endif            
        }

        
        if (--Ctrl_Timer0.Temporizador100ms == 0)
        {
            Ctrl_Timer0.Temporizador100ms = 100;
            
        #if (_TIMER0_HABILITAR_EVENTOS_100MS == _SIM)              
            Eventos100ms.valor = 0xFF;
        #endif            
        }
        
      
        if (--Ctrl_Timer0.Temporizador250ms == 0)
        {
            Ctrl_Timer0.Temporizador250ms = 250;

            #if (_TIMER0_HABILITAR_FUNCOES_LCD == _SIM)
                Lcd_AtualizaIntermitencia();
            #endif
                
            #if (_TIMER0_HABILITAR_FUNCOES_ROTINAS == _SIM)
                Rotinas_PedidoDeAtualizacao();
            #endif
        }

        if (--Ctrl_Timer0.Temporizador1s == 0)
        {
            Ctrl_Timer0.Temporizador1s = 1000;
            
            #if (_TIMER0_HABILITAR_EVENTOS_1S == _SIM)  
                Eventos1s.valor = 0xFF;
            #endif
                
            #if (_TIMER0_HABILITAR_FUNCOES_LCD == _SIM)
                Lcd_LigaEventoBackLight();
            #endif
        }
    }
}
#endif
