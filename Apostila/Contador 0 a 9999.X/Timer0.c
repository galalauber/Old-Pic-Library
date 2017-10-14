/* 
 * Arquivo: Timer0.c
 * Autor:   JABNeto
 * Data:    09/03/2016
 */


#include "Timer0.h"
#include <xc.h>


void Timer0_Recarga (void);

//Funções do módulo -----------------------------------------------------------

/* Timer0_Inicializacao
 * Carrega os registradores TMR0H:TMR0L
 * TMR0H:TMR0L = 65536 - ((Tempo * Fop)/Prescaler))
 */
void Timer0_Inicializacao (void)
{
    T0CON = 0;
    T0CONbits.PSA = 1;
    Timer0_Recarga();
    INTCONbits.T0IE = 1;
    TMR0_Eventos.Temporizador100ms = 100;
    TMR0_Eventos.EventosDe100ms.Valor = 0;
    T0CONbits.TMR0ON = 1;
}


void Timer0_CarregaValor(void)
{
    
    
}



/* Timer0_Recarga
 * Carrega os registradores TMR0H:TMR0L
 * TMR0H:TMR0L = 65536 - ((Tempo * Fop)/Prescaler))
 * Tempo = 1ms
 * Fop = 8MHz
 * Prescaler = 1;
 * TMR0H:TMR0L = 57536
 */
void Timer0_Recarga (void)
{
    Uint16 ValorDeCarga;
    
    INTCONbits.TMR0IF = 0;    

    ValorDeCarga.valor = 57536;
    
    TMR0H = ValorDeCarga.bytes.byte1;
    TMR0L = ValorDeCarga.bytes.byte0;
}
