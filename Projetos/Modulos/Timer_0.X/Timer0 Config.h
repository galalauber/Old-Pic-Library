/* 
 * Arquivo: Timer0 Config.h
 * Autor:   JABNeto
 * Versão:  2016.09.20
 */

#ifndef TIMER_0_CONFIG_H
#define	TIMER_0_CONFIG_H

/*
 * 1. Modo de operação do temporizador Timer 0
 * O temporizador Timer 0 pode operar no modo de 8 bits ou 16 bits.
 * Nesse passo da configuração o usuário define o modo de operação.
 * 
 * Opções:
 * TIMER0_8BITS:  Seleciona o modo de 8 bits
 * TIMER0_16BITS: Seleciona o modo de 16 bits
 */
#define _TIMER0_MODO_DE_OPERACAO            TIMER0_MODO_TEMPORIZADOR_16BITS   


/*
 * 2. Fonte de clock do Timer 0 
 * O temporizador Timer 0 pode ser incrementado pelo sinal de clock
 * interno da CPU (FOP/4) ou através de um sinal externo aplicado no
 * T0CKI (Timer 0 Clock Input (RA4))
 * 
 * Opções:
 * _8BITS:  Seleciona o modo de 8 bits
 * _16BITS: Seleciona o modo de 16 bits
 */
 







#endif	/* TIMER_0_CONFIG_H */

