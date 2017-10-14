/* 
 * Arquivo: Timer 0.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef TIMER_0_H
#define	TIMER_0_H


#include "Oscilador.h"
#include "Definicoes Gerais.h"


//Definicoes do módulo --------------------------------------------------------
#ifndef _BAIXA
#define _BAIXA              0
#endif

#ifndef _ALTA
#define _ALTA               1
#endif


#include "Timer0 Config.h"

//Processamento das definicoes-------------------------------------------------


//Valor de carga para 1ms (16bits, Prescaler = 2)
#define TIMER0_VALOR_DE_CARGA       (65536 - (_FOP / 2000))

//Estruturas do modulo --------------------------------------------------------
typedef struct
{
    unsigned char Temporizador10ms;
    unsigned char Temporizador100ms;    
    unsigned char Temporizador250ms;
    unsigned int  Temporizador1s;
}_Ctrl_Timer0;


#if (_TIMER0_HABILITAR_EVENTOS_10MS == _SIM)
typedef struct
{
    union
    {
        Uchar valor;
        
        struct
        {
            Uint _EVENTOS_10MS_1:1;
            Uint _EVENTOS_10MS_2:1;
            Uint _EVENTOS_10MS_3:1;
            Uint _EVENTOS_10MS_4:1;
            Uint _EVENTOS_10MS_5:1;
            Uint _EVENTOS_10MS_6:1;
            Uint _EVENTOS_10MS_7:1;
            Uint _EVENTOS_10MS_8:1;            
        };
    };
}_Eventos10ms;

#endif

#if (_TIMER0_HABILITAR_EVENTOS_100MS == _SIM)
typedef struct
{
    union
    {
        Uchar valor;
        
        struct
        {
            Uint _EVENTOS_100MS_1:1;
            Uint _EVENTOS_100MS_2:1;
            Uint _EVENTOS_100MS_3:1;
            Uint _EVENTOS_100MS_4:1;
            Uint _EVENTOS_100MS_5:1;
            Uint _EVENTOS_100MS_6:1;
            Uint _EVENTOS_100MS_7:1;
            Uint _EVENTOS_100MS_8:1;            
        };
    };
}_Eventos100ms;

#endif

#if (_TIMER0_HABILITAR_EVENTOS_1S == _SIM)
typedef struct
{
    union
    {
        Uchar valor;
        
        struct
        {
            Uint _EVENTOS_1S_1:1;
            Uint _EVENTOS_1S_2:1;
            Uint _EVENTOS_1S_3:1;
            Uint _EVENTOS_1S_4:1;
            Uint _EVENTOS_1S_5:1;
            Uint _EVENTOS_1S_6:1;
            Uint _EVENTOS_1S_7:1;
            Uint _EVENTOS_1S_8:1;            
        };
    };
}_Eventos1s;

#endif



//Publicação das funções do módulo --------------------------------------------
void Timer0_Inicializacao (void);
void Timer0_Interrupcao (void);


//Publicacão das variáveis do módulo ------------------------------------------
#if (_TIMER0_HABILITAR_EVENTOS_10MS == _SIM)
extern _Eventos10ms   Eventos10ms;
#endif

#if (_TIMER0_HABILITAR_EVENTOS_100MS == _SIM)
extern _Eventos100ms   Eventos100ms;
#endif

#if (_TIMER0_HABILITAR_EVENTOS_1S == _SIM)
extern _Eventos1s      Eventos1s;
#endif


#endif	/* TIMER_0_H */

