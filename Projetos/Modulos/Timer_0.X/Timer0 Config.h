/* 
 * Arquivo: Timer0 Config.h
 * Autor:   JABNeto
 * Vers�o:  2016.09.20
 */

#ifndef TIMER_0_CONFIG_H
#define	TIMER_0_CONFIG_H

/*
 * 1. Modo de opera��o do temporizador Timer 0
 * O temporizador Timer 0 pode operar no modo de 8 bits ou 16 bits.
 * Nesse passo da configura��o o usu�rio define o modo de opera��o.
 * 
 * Op��es:
 * TIMER0_8BITS:  Seleciona o modo de 8 bits
 * TIMER0_16BITS: Seleciona o modo de 16 bits
 */
#define _TIMER0_MODO_DE_OPERACAO            TIMER0_MODO_TEMPORIZADOR_16BITS   


/*
 * 2. Fonte de clock do Timer 0 
 * O temporizador Timer 0 pode ser incrementado pelo sinal de clock
 * interno da CPU (FOP/4) ou atrav�s de um sinal externo aplicado no
 * T0CKI (Timer 0 Clock Input (RA4))
 * 
 * Op��es:
 * _8BITS:  Seleciona o modo de 8 bits
 * _16BITS: Seleciona o modo de 16 bits
 */
 







#endif	/* TIMER_0_CONFIG_H */

