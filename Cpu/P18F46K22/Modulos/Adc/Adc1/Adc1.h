/* 
 *  Arquivo:    Adc1.h
 *  uC:         PIC18F46K22
 *  Autor:      JABNeto
 *  Versão:     161011 
 */

#ifndef ADC1_H
#define	ADC1_H

#include "Definicoes Gerais.h"
#include "Oscilador.h"
#include "Portas.h"


//Definições do módulo --------------------------------------------------------
#define ADC1_RESOLUCAO_10BITS

//Canais
#define ADC1_CANAL0                     0
#define ADC1_CANAL1                     1
#define ADC1_CANAL2                     2
#define ADC1_CANAL3                     3
#define ADC1_CANAL4                     4
#define ADC1_CANAL5                     5
#define ADC1_CANAL6                     6
#define ADC1_CANAL7                     7
#define ADC1_CANAL8                     8
#define ADC1_CANAL9                     9
#define ADC1_CANAL10                    10
#define ADC1_CANAL11                    11
#define ADC1_CANAL12                    12
#define ADC1_CANAL13                    13
#define ADC1_CANAL14                    14
#define ADC1_CANAL15                    15
#define ADC1_CANAL16                    16
#define ADC1_CANAL17                    17
#define ADC1_CANAL18                    18
#define ADC1_CANAL19                    19
#define ADC1_CANAL20                    20
#define ADC1_CANAL21                    21
#define ADC1_CANAL22                    22
#define ADC1_CANAL23                    23
#define ADC1_CANAL24                    24
#define ADC1_CANAL25                    25
#define ADC1_CANAL26                    26
#define ADC1_CANAL27                    27
#define ADC1_CANAL_CTMU                 29
#define ADC1_CANAL_DAC                  30
#define ADC1_CANAL_FVR                  31


//Tensão de Referência Positiva
#define ADC1_VREF_POSITIVA_AVDD         0
#define ADC1_VREF_POSITIVA_VREF         1       
#define ADC1_VREF_POSITIVA_FVR          2

//Tensão de Referência Negativa
#define ADC1_VREF_NEGATIVA_AVSS         0
#define ADC1_VREF_NEGATIVA_VREF         1   

//Formatação
#define ADC1_FORMATACAO_ESQUERDA        0
#define ADC1_FORMATACAO_DIREITA         1

//Especial Event Trigger
#define ADC1_TRIGGER_CCP5               0
#define ADC1_TRIGGER_CTMU               1

//Aquisição
#define ADC1_ACQT_TAD_0                 0
#define ADC1_ACQT_TAD_2                 1
#define ADC1_ACQT_TAD_4                 2
#define ADC1_ACQT_TAD_6                 3
#define ADC1_ACQT_TAD_8                 4
#define ADC1_ACQT_TAD_12                5 
#define ADC1_ACQT_TAD_16                6
#define ADC1_ACQT_TAD_20                7

//Frequencia de clock
#define ADC1_ADCS_FOSC_2                0
#define ADC1_ADCS_FOSC_4                4
#define ADC1_ADCS_FOSC_8                1
#define ADC1_ADCS_FOSC_16               5
#define ADC1_ADCS_FOSC_32               2
#define ADC1_ADCS_FOSC_64               6
#define ADC1_ADCS_FRC                   8


//Pinos de controle do conversor
#define ADC1_AN0_IO                     ConfiguraPinRA0_Analogico
#define ADC1_AN1_IO                     ConfiguraPinRA1_Analogico
#define ADC1_AN2_IO                     ConfiguraPinRA2_Analogico
#define ADC1_AN3_IO                     ConfiguraPinRA3_Analogico
#define ADC1_AN4_IO                     ConfiguraPinRA5_Analogico
#define ADC1_AN5_IO                     ConfiguraPinRE0_Analogico
#define ADC1_AN6_IO                     ConfiguraPinRE1_Analogico
#define ADC1_AN7_IO                     ConfiguraPinRE2_Analogico
#define ADC1_AN8_IO                     ConfiguraPinRB2_Analogico
#define ADC1_AN9_IO                     ConfiguraPinRB3_Analogico
#define ADC1_AN10_IO                    ConfiguraPinRB1_Analogico
#define ADC1_AN11_IO                    ConfiguraPinRB4_Analogico
#define ADC1_AN12_IO                    ConfiguraPinRB0_Analogico
#define ADC1_AN13_IO                    ConfiguraPinRB5_Analogico
#define ADC1_AN14_IO                    ConfiguraPinRC2_Analogico
#define ADC1_AN15_IO                    ConfiguraPinRC3_Analogico
#define ADC1_AN16_IO                    ConfiguraPinRC4_Analogico
#define ADC1_AN17_IO                    ConfiguraPinRC5_Analogico
#define ADC1_AN18_IO                    ConfiguraPinRC6_Analogico
#define ADC1_AN19_IO                    ConfiguraPinRC7_Analogico
#define ADC1_AN20_IO                    ConfiguraPinRD0_Analogico
#define ADC1_AN21_IO                    ConfiguraPinRD1_Analogico
#define ADC1_AN22_IO                    ConfiguraPinRD2_Analogico
#define ADC1_AN23_IO                    ConfiguraPinRD3_Analogico
#define ADC1_AN24_IO                    ConfiguraPinRD4_Analogico
#define ADC1_AN25_IO                    ConfiguraPinRD6_Analogico
#define ADC1_AN26_IO                    ConfiguraPinRD6_Analogico
#define ADC1_AN27_IO                    ConfiguraPinRD7_Analogico



#include "Adc1 Config.h"


//Processamento das definições ------------------------------------------------

//Ajuste da frequencia de operação do módulo
#if (_FOSC > 32000000)
    #define ADC1_ADCS   ADC1_ADCS_FOSC_64
#elif (_FOSC > 16000000)
    #define ADC1_ADCS   ADC1_ADCS_FOSC_32
#elif (_FOSC > 8000000)
    #define ADC1_ADCS   ADC1_ADCS_FOSC_16
#elif (_FOSC > 4000000)
    #define ADC1_ADCS   ADC1_ADCS_FOSC_8
#elif (_FOSC > 2000000)
    #define ADC1_ADCS   ADC1_ADCS_FOSC_4
#elif (_FOSC > 1000000)
    #define ADC1_ADCS   ADC1_ADCS_FOSC_2
#else
    #define ADC1_ADCS   ADC1_ADCS_FRC
#endif

//Tempo da amostra
#define ADC1_ACQT   ADC1_ACQT_TAD_8


//Interrupção
#if (ADC1_USA_INTERRUPCAO == Sim)
    #ifndef CPU_USA_INTERRUPCOES
    #define CPU_USA_INTERRUPCOES
    #endif

    #if (ADC1_INTERRUPCAO_PRIORIDADE == Baixa)
        #ifndef CPU_USA_NIVEL_DE_INTERRUPCAO
        #define CPU_USA_NIVEL_DE_INTERRUPCAO
        #endif
    #endif
#endif



//Publicação das funções do módulo -------------------------------------------
void Adc1_Inicializacao (void);

#if (ADC1_USA_INTERRUPCAO == Sim)
void Adc1_ConverteCanal(Uchar Canal);
#else 
Uint Adc1_ConverteCanal(Uchar Canal);
#endif



#endif	/* ADC1_H */

