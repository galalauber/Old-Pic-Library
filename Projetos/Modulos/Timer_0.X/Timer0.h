/* 
 * Arquivo: Timer0.h
 * Autor:   JABNeto
 * Versão:  2016.09.20
 */

#ifndef TIMER_0_H
#define	TIMER_0_H

#include "Oscilador.h"


//Definições do módulo ------------------------------------------------------
typedef enum 
{
    _TEMPORIZADOR,    
    _CONTADOR_TRANSICAO_POSITIVA,
    _CONTADOR_TRANSICAO_NEGATIVA     
}_TIMER0_MODOS_DE_OPERACAO;


typedef struct
{
    Uint    ValorDeCarga;
}ObjTimer0;


void Timer0_Temporizador_Config (void);

#endif	/* TIMER_0_H */

