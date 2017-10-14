/* 
 * Arquivo: Teclado Config.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef TECLADO_CONFIG_H
#define	TECLADO_CONFIG_H


/* O m�dulo de controle do teclado � dependente do temporizador TIMER0 quando
 * uma das fun��es temporizadas s�o utilizadas. A fun��o de monitoramento do
 * teclado deve ser chamada na rotina de atendimento das interrup��es do
 * TIMER0 (evento de 1ms)
 */


#define UP                  1
#define DOWN                2
#define LEFT                3
#define RIGHT               4
#define ENTER               5



/* 1. Pinos de controle do teclado -------------------------------------------
 * Ex. _PORTA_0
 */

#define _TECLA1                             PORTAbits.RA0
#define _TECLA1_AD                          ANSELAbits.ANSA0

#define _TECLA2                             PORTAbits.RA1
#define _TECLA2_AD                          ANSELAbits.ANSA1

#define _TECLA3                             PORTAbits.RA3
#define _TECLA3_AD                          ANSELAbits.ANSA3

#define _TECLA4                             PORTAbits.RA4
//#define _TECLA4_AD                          ANSELAbits.ANSA4

#define _TECLA5                             PORTAbits.RA5
#define _TECLA5_AD                          ANSELAbits.ANSA5

//#define _TECLA6                             PORTAbits.RA0
//#define _TECLA6_AD                          ANSELAbits.ANSA0

//#define _TECLA7                             PORTAbits.RA0
//#define _TECLA7_AD                          ANSELAbits.ANSA0

//#define _TECLA8                             PORTAbits.RA0
//#define _TECLA8_AD                          ANSELAbits.ANSA0


/* 2. Estados l�gicos das teclas ---------------------------------------------
 */
#define _PRESSIONADA                        0
#define _NPRESSIONADA                       1


/* 3. Temporizador de amostras -----------------------------------------------
 *      
 * 3.1  _TECLADO_TEMPORIZADOR_AMOSTRAS    
 *      Define o tempo entres uma amostra e outra do teclado. O tempo � dado
 *      em ms.
 */
#define _TECLADO_TEMPORIZADOR_AMOSTRAS       20



/* 4. Modos de opera��o do teclado -------------------------------------------
 * 
 * 4.1  _TECLADO_MODO_DE_OPERACAO
 *      Define o modo de opera��o do teclado.
 *      _RECUO:         � necess�rio haver o recuo de todas as teclas para que
 *                      outro evento de tecla pressionada seja gerado.
 *                      Nesse modo os temporizadores de aguardo e disparo s�o
 *                      ignorados.
 *      _TRANSPARENTE:  Os eventos de teclas pressionadas acompanham os estados
 *                      das teclas.
 *                      Nesse modo os temporizadores de aguardo e disparo s�o
 *                      ignorados.
 *      _DISPARO:       Mantendo uma tecla pressionada, eventos s�o gerados em
 *                      tempos peri�dicos.
 *                      Nesse modo os temporizadores de aguardo e disparo s�o
 *                      utilizados.
 * 
 * 4.2  _TECLADO_TEMPORIZADOR_AGUARDO
 *      Define o tempo aguardado ap�s uma tecla ser mantida pressionada, antes
 *      de iniciar os disparos. O tempo � dado em ms.
 * 
 * 4.3  _TECLADO_TEMPORIZADOR_DISPARO
 *      Define o intervalo de tempo do eventos peri�dicos gerados para a tecla
 *      mantida pressionada. O tempo � dadop em ms.
 */
#define _TECLADO_MODO_DE_OPERACAO           _RECUO
#define _TECLADO_TEMPORIZADOR_AGUARDO       1000
#define _TECLADO_TEMPORIZADOR_DISPARO       100


#endif	/* TECLADO_CONFIG_H */

