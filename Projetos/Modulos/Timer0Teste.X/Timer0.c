/* 
 * File:   Timer0.h
 * Author: jose_010573
 *
 * Created on 25 de Outubro de 2016, 16:58
 */

#include <xc.h>
#include "Definicoes Gerais.h"
#include "Timer0.h"



//Funções públicas do módulo -------------------------------------------------

void Timer0_Inicializacao (void)
{
    T0CONbits.T08BIT = 0;
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 1;
    
    Timer0_CarregaValor ();
    
    INTCONbits.T0IF = 0;
    INTCONbits.T0IE = 1;    

    T0CONbits.TMR0ON = 1;
}


void Timer0_CarregaValor (void)
{
    Uint16 ValorDeCarga;
    
    ValorDeCarga.valor = TMR0_VALOR_DE_CARGA;
    
    TMR0H = ValorDeCarga.bytes.byte1;
    TMR0L = ValorDeCarga.bytes.byte0;            
}
