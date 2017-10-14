/* 
 * Arquivo: Oscilador.c
 * Autor:   JABNeto
 * Data:    150817
 */

#include "Oscilador.h"


#if (_SISTEMA_USA_OSCILADOR_PRIMARIO == Sim)
#pragma config FOSC = _OSC_PRIMARIO_TIPO
#else
#pragma config FOSC = _OSC_INTERNO_TIPO
#endif

#pragma config PLLCFG = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config PRICLKEN = ON


//Alocação de memória para o módulo -------------------------------------------




//Funções do módulo -----------------------------------------------------------


/*
 * Oscilador_Inicializacao
 * 
 * Faz a inicialização do módulo oscilador. Essa função deve ser chamadada
 * na inicialização do sistema.
 */
void Oscilador_Inicializacao (void)
{
    OSCCONbits.SCS = 0;
    
#if(_OSC_INTERNO_FREQUENCIA == _HF_16MHz)
    OSCCONbits.IRCF = 7;
#elif (_OSC_INTERNO_FREQUENCIA == _HF_8MHz)
    OSCCONbits.IRCF = 6;
#elif (_OSC_INTERNO_FREQUENCIA == _HF_4MHz)
    OSCCONbits.IRCF = 5;
#elif (_OSC_INTERNO_FREQUENCIA == _HF_2MHz)
    OSCCONbits.IRCF = 4;    
#elif (_OSC_INTERNO_FREQUENCIA == _HF_1MHz)
    OSCCONbits.IRCF = 3;
#elif (_OSC_INTERNO_FREQUENCIA == _HF_500KHz)
    OSCCONbits.IRCF = 2;       
    OSCTUNEbits.INTSRC = 1; 
    OSCCON2bits.MFIOSEL = 0;
#elif (_OSC_INTERNO_FREQUENCIA == _HF_250KHz)
    OSCCONbits.IRCF = 1;       
    OSCTUNEbits.INTSRC = 1; 
    OSCCON2bits.MFIOSEL = 0;     
#elif (_OSC_INTERNO_FREQUENCIA == _HF_31KHz)
    OSCCONbits.IRCF = 0;       
    OSCTUNEbits.INTSRC = 1; 
    OSCCON2bits.MFIOSEL = 0;   
#elif (_OSC_INTERNO_FREQUENCIA == _MF_500KHz)
    OSCCONbits.IRCF = 2;       
    OSCTUNEbits.INTSRC = 1; 
    OSCCON2bits.MFIOSEL = 1; 
#elif (_OSC_INTERNO_FREQUENCIA == _MF_250KHz)
    OSCCONbits.IRCF = 1;       
    OSCTUNEbits.INTSRC = 1; 
    OSCCON2bits.MFIOSEL = 1;  
#elif (_OSC_INTERNO_FREQUENCIA == _MF_31KHz)
    OSCCONbits.IRCF = 0;       
    OSCTUNEbits.INTSRC = 1; 
    OSCCON2bits.MFIOSEL = 1;    
#elif (_OSC_INTERNO_FREQUENCIA == _LF_31KHz)
    OSCCONbits.IRCF = 0;       
    OSCTUNEbits.INTSRC = 0; 
    OSCCON2bits.MFIOSEL = 1;       
#endif
    
    
#if (_SISTEMA_USA_OSCILADOR_PRIMARIO == Nao)
    OSCCON2bits.PRISD = 0;
#else
    OSCCON2bits.PRISD = 1; 
#endif  
    
#if (_OSC_PRIMARIO_PLL_ATIVADO == Sim)
    OSCTUNEbits.PLLEN= 1; 
#else
    OSCTUNEbits.PLLEN= 0; 
#endif    
}












