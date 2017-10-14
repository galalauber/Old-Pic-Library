/* 
 * Arquivo: ADC 1.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef ADC_1_H
#define	ADC_1_H

#include "Definicoes Gerais.h"
#include "Oscilador.h"

//Definições do módulo --------------------------------------------------------
//ADSC: AD Clock Select
#define ADC1_FOSC_2             0
#define ADC1_FOSC_4             4
#define ADC1_FOSC_8             1
#define ADC1_FOSC_16            5
#define ADC1_FOSC_32            2
#define ADC1_FOSC_64            6
#define ADC1_FOSC_FRC           7

//Formatação
#define _ESQUERDA               0
#define _DIREITA                1

//Aquisição
#define _TAD_0                  0
#define _TAD_2                  1
#define _TAD_4                  2
#define _TAD_6                  3
#define _TAD_8                  4
#define _TAD_12                 5
#define _TAD_16                 6
#define _TAD_20                 7

//Trigger Event
#define _EVENT_CCP5             0
#define _EVENT_CTMU             1

//Tensão de referência positiva
#define _VP_AVDD                0
#define _VP_VREF                1
#define _VP_FVR                 2

//Tensão de referência negativa
#define _VN_AVSS                0
#define _VN_VREF                1

//Canais
#define _CANAL_0                0
#define _CANAL_1                1
#define _CANAL_2                2
#define _CANAL_3                3
#define _CANAL_4                4
#define _CANAL_5                5
#define _CANAL_6                6
#define _CANAL_7                7
#define _CANAL_8                8
#define _CANAL_9                9
#define _CANAL_10               10
#define _CANAL_11               11
#define _CANAL_12               12
#define _CANAL_13               13
#define _CANAL_14               14
#define _CANAL_15               15
#define _CANAL_16               16
#define _CANAL_17               17
#define _CANAL_18               18
#define _CANAL_19               19
#define _CANAL_20               20
#define _CANAL_21               21
#define _CANAL_22               22
#define _CANAL_23               23
#define _CANAL_24               24
#define _CANAL_25               25
#define _CANAL_26               26
#define _CANAL_27               27
#define _CANAL_CTMU             29
#define _CANAL_DAC              30
#define _CANAL_FVR              31


#include "Adc 1 Config.h"


//Processamento das definições ------------------------------------------------
#if (CLOCK_PRIMARIO_FREQUENCIA <= 1000000)
    #define ADC1_FREQUENCIA_CLOCK       ADC1_FOSC_FRC
    #define ADC1_AQUISICAO              _TAD_4
#elif (CLOCK_PRIMARIO_FREQUENCIA <= 2000000)
    #define ADC1_FREQUENCIA_CLOCK       ADC1_FOSC_2
    #define ADC1_AQUISICAO              _TAD_4
#elif (CLOCK_PRIMARIO_FREQUENCIA <= 4000000)
    #define ADC1_FREQUENCIA_CLOCK       ADC1_FOSC_4
    #define ADC1_AQUISICAO              _TAD_4
#elif (CLOCK_PRIMARIO_FREQUENCIA <= 8000000)
    #define ADC1_FREQUENCIA_CLOCK       ADC1_FOSC_8
    #define ADC1_AQUISICAO              _TAD_4
#elif (CLOCK_PRIMARIO_FREQUENCIA <= 16000000)
    #define ADC1_FREQUENCIA_CLOCK       ADC1_FOSC_16
    #define ADC1_AQUISICAO              _TAD_4
#elif (CLOCK_PRIMARIO_FREQUENCIA <= 32000000)
    #define ADC1_FREQUENCIA_CLOCK       ADC1_FOSC_32
    #define ADC1_AQUISICAO              _TAD_4
#elif (CLOCK_PRIMARIO_FREQUENCIA <= 64000000)
    #define ADC1_FREQUENCIA_CLOCK       ADC1_FOSC_64
    #define ADC1_AQUISICAO              _TAD_4
#endif




//Estruturas do módulo --------------------------------------------------------




//Publicação das funções do módulo --------------------------------------------
void ADC1_Inicializacao (void);
Uint ADC1_ConverteCanal (Uchar Canal);





#endif	/* ADC_1_H */

