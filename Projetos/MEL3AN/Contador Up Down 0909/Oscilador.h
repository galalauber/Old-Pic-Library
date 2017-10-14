/* 
 * Arquivo: Oscilador.h
 * Autor:   JABNeto
 * Data:    17/08/2015
 */

#ifndef OSCILADOR_H
#define	OSCILADOR_H

#include "Definicoes Gerais.h"


//Tipos do oscilador primario -------------------------------------------------
#define _XTAL_LP                                0
#define _XTAL_XT                                1
#define _XTAL_HS_MP                             2
#define _XTAL_HS_HP                             3
#define _EC_HP_CLOCK_OUT_OSC2                   4                                    
#define _EC_HP                                  5 
#define _RC_CLOCK_OUT_OSC2                      6
#define _RC                                     7
#define _INTOSC                                 8
#define _INTOSC_CLOCK_OUT_OSC2                  9
#define _EC_MP_CLOCK_OUT_OSC2                   10                                    
#define _EC_MP                                  11 
#define _EC_LP_CLOCK_OUT_OSC2                   12                                    
#define _EC_LP                                  13 

#define _OSC_INTERNO_HF                         0
#define _OSC_INTERNO_MF                         1
#define _OSC_INTERNO_LF                         2

#define _HF_31KHz                               31250
#define _HF_250KHz                              250000
#define _HF_500KHz                              500000
#define _HF_1MHz                                1000000
#define _HF_2MHz                                2000000
#define _HF_4MHz                                4000000
#define _HF_8MHz                                8000000
#define _HF_16MHz                               16000000
#define _MF_31KHz                               31250
#define _MF_250KHz                              250000
#define _MF_500KHz                              500000
#define _LF_31KHz                               31250



#include "Oscilador Config.h"


//Processamento das definicoes do módulo -------------------------------------

#if (_SISTEMA_USA_OSCILADOR_PRIMARIO == _SIM)
    #if (_OSC_PRIMARIO_PLL_ATIVADO == _SIM)
        #define CLOCK_PRIMARIO_FREQUENCIA    (_OSC_PRIMARIO_FREQUENCIA * 4)
    #else    
        #define CLOCK_PRIMARIO_FREQUENCIA     _OSC_PRIMARIO_FREQUENCIA
    #endif    
#else
    #if (_OSC_PRIMARIO_PLL_ATIVADO == _SIM)
        #if ((_OSC_INTERNO_FREQUENCIA == _HF_8MHz)||(_OSC_INTERNO_FREQUENCIA == _HF_16MHz))
            #define CLOCK_PRIMARIO_FREQUENCIA    (_OSC_INTERNO_FREQUENCIA * 4)
        #else
            #define CLOCK_PRIMARIO_FREQUENCIA    _OSC_INTERNO_FREQUENCIA
        #endif
    #else       
            #define CLOCK_PRIMARIO_FREQUENCIA    _OSC_INTERNO_FREQUENCIA
    #endif
#endif


#if (_SISTEMA_USA_OSCILADOR_SECUNDARIO == _SIM)
    #define OSC_SECUNDARIO_FREQUENCIA           _OSC_SECUNDARIO_FREQUENCIA
#else 
    #define OSC_SECUNDARIO_FREQUENCIA           0
#endif


#define _XTAL_FREQ                              CLOCK_PRIMARIO_FREQUENCIA
#define _FOSC                                   CLOCK_PRIMARIO_FREQUENCIA
#define _FOP                                    (CLOCK_PRIMARIO_FREQUENCIA / 4)


//Publicação das funções do módulo -------------------
void Oscilador_Inicializacao (void);

#endif	/* OSCILADOR_H */

