/* 
 * Arquivo: Interrupcoes.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include "Interrupcoes.h"


    #if (ATENDIMENTO_MODULO_ADC1 == _SIM)
    #include "Adc 1.h"
    #endif

    #if (ATENDIMENTO_MODULO_TIMER0 == _SIM)
    #include "Timer0.h"
    #endif

    #if (ATENDIMENTO_MODULO_TIMER1 == _SIM)
    #include "Timer 1.h"
    #endif

    #if (ATENDIMENTO_MODULO_TIMER2 == _SIM)
    #include "Timer 2.h"
    #endif

    #if (ATENDIMENTO_MODULO_TIMER3 == _SIM)
    #include "Timer 3.h"
    #endif

    #if (ATENDIMENTO_MODULO_TIMER4 == _SIM)
    #include "Timer 4.h"
    #endif

    #if (ATENDIMENTO_MODULO_TIMER5 == _SIM)
    #include "Timer 5.h"
    #endif

    #if (ATENDIMENTO_MODULO_MSSP1 == _SIM)
    #include "Mssp 1.h"
    #endif

    #if (ATENDIMENTO_MODULO_MSSP2 == _SIM)
    #include "Mssp 2.h"
    #endif

    #if (ATENDIMENTO_MODULO_USART1 == _SIM)
    #include "Usart 1.h"
    #endif

    #if (ATENDIMENTO_MODULO_USART2 == _SIM)
    #include "Usart 2.h"
    #endif

    #if (ATENDIMENTO_MODULO_INT0 == _SIM)
    #include "Int 0.h"
    #endif

    #if (ATENDIMENTO_MODULO_INT1 == _SIM)
    #include "Int 1.h"
    #endif

    #if (ATENDIMENTO_MODULO_INT2 == _SIM)
    #include "Int 2.h"
    #endif





//Alocação de memória para o módulo--------------------------------------------




//Funções locais --------------------------------------------------------------
/*
 * Habilita_Interrupcoes
 * Atendimento das interrupções de alta prioridade
 */
void Habilita_Interrupcoes (void)
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;    
}

/*
 * Desabilita_Interrupcoes
 * Atendimento das interrupções de alta prioridade
 */
void Desabilita_Interrupcoes (void)
{
    INTCONbits.GIE = 0;
}


/*
 * InterrupcoesDeAltaPrioridade
 * Atendimento das interrupções de alta prioridade
 */
void interrupt high_priority InterrupcoesDeAltaPrioridade (void)
{
    #if (ATENDIMENTO_MODULO_ADC1 == _SIM)
    ADC1_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_TIMER0 == _SIM)
    Timer0_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_TIMER1 == _SIM)
    Timer1_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_TIMER2 == _SIM)
    Timer2_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_TIMER3 == _SIM)
    Timer3_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_TIMER4 == _SIM)
    Timer4_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_TIMER5 == _SIM)
    Timer5_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_MSSP1 == _SIM)
    Mssp1_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_MSSP2 == _SIM)
    Mssp2_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_USART1 == _SIM)
    Usart1_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_USART2 == _SIM)
    Usart2_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_INT0 == _SIM)
    Int0_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_INT1 == _SIM)
    Int1_Interrupcao();
    #endif

    #if (ATENDIMENTO_MODULO_INT2 == _SIM)
    Int2_Interrupcao();
    #endif
}




