/* 
 *  Arquivo: Adc1.h
 *  uC:      PIC18F46K22
 *  Autor:   JABNeto
 *  Vers�o:  161011
 */


#ifndef ADC1_CONFIG_H
#define	ADC1_CONFIG_H

/*  1. Canais Anal�gicos
 *  Define os canais anal�gicos que s�o utilizados no sistema.
 *  
 *  Op��es
 *  Nao: O Canal n�o � utilizado e o pino pode ser configurado com digital por
 *       outro modulo.
 *  Sim: O Canal � utilizado e o pino � configurado para opera no modo anal�gico 
 */
#define ADC1_CANAL0_UTILIZADO                           Nao
#define ADC1_CANAL1_UTILIZADO                           Nao
#define ADC1_CANAL2_UTILIZADO                           Nao
#define ADC1_CANAL3_UTILIZADO                           Nao
#define ADC1_CANAL4_UTILIZADO                           Nao
#define ADC1_CANAL5_UTILIZADO                           Nao
#define ADC1_CANAL6_UTILIZADO                           Sim
#define ADC1_CANAL7_UTILIZADO                           Nao
#define ADC1_CANAL8_UTILIZADO                           Nao
#define ADC1_CANAL9_UTILIZADO                           Nao
#define ADC1_CANAL10_UTILIZADO                          Nao
#define ADC1_CANAL11_UTILIZADO                          Nao
#define ADC1_CANAL12_UTILIZADO                          Nao
#define ADC1_CANAL13_UTILIZADO                          Nao
#define ADC1_CANAL14_UTILIZADO                          Nao
#define ADC1_CANAL15_UTILIZADO                          Nao
#define ADC1_CANAL16_UTILIZADO                          Nao
#define ADC1_CANAL17_UTILIZADO                          Nao
#define ADC1_CANAL18_UTILIZADO                          Nao
#define ADC1_CANAL19_UTILIZADO                          Nao
#define ADC1_CANAL20_UTILIZADO                          Sim
#define ADC1_CANAL21_UTILIZADO                          Nao
#define ADC1_CANAL22_UTILIZADO                          Nao
#define ADC1_CANAL23_UTILIZADO                          Nao
#define ADC1_CANAL24_UTILIZADO                          Nao
#define ADC1_CANAL25_UTILIZADO                          Nao
#define ADC1_CANAL26_UTILIZADO                          Nao
#define ADC1_CANAL27_UTILIZADO                          Nao


/*  2. Formata��o do valor convertido
 *  Configura��o da formata��o do valor resultante da convers�o
 *  
 *  Op��es
 *  ADC1_FORMATACAO_ESQUERDA Resultado alinhado � esquerda (rrrr rrrr rr00 0000)
 *  ADC1_FORMATACAO_DIREITA  Resultado alinhado � direita  (0000 00rr rrrr rrrr)
 */
#define ADC1_FORMATACAO                                 ADC1_FORMATACAO_DIREITA


/*  3. Fonte de tens�o de refer�ncia positiva
 *  Define a fonte de tens�o de refer�ncia positiva (fundo de escala ADC)
 *  
 *  Op��es
 *  ADC1_VREF_POSITIVA_AVDD     Tens�o de refer�ncia � VDD
 *  ADC1_VREF_POSITIVA_VREF     Tens�o de refer�ncia aplicada no pino VREF+
 *  ADC1_VREF_POSITIVA_FVR      Tens�o de refer�ncia � definida pelo m�dulo Fvr
 */
#define ADC1_VREF_POSITIVA                              ADC1_VREF_POSITIVA_FVR


/*  4. Fonte de tens�o de refer�ncia negativa
 *  Define a fonte de tens�o de refer�ncia negativa
 *  
 *  Op��es
 *  ADC1_VREF_NEGATIVA_AVSS     Tens�o de refer�ncia � VSS
 *  ADC1_VREF_NEGATIVA_VREF     Tens�o de refer�ncia aplicada no pino VREF-
 */
#define ADC1_VREF_NEGATIVA                              ADC1_VREF_NEGATIVA_AVSS


/*  5. Modo Trigger Event
 *  No modo Trigger Event uma fonte geradora de evento de trigger provoca o
 *  inicio da convers�o. A fonte geradora deve ser configurada para que o
 *  evento possa ser gerado.
 *  
 *  Op��es
 *  ADC1_TRIGGER_CCP5     O evento de trigger � gerado pelo modulo CCP5
 *  ADC1_TRIGGER_CTMU     O evento de trigger � gerado pelo modulo CTMU
 */
#define ADC1_TRIGGER                                    ADC1_TRIGGER_CTMU



/*  6. Interrup��es
 *  
 *  6.1. ADC1_USA_INTERRUPCAO
 *  Define se o m�dulo utiliza interrup��o na convers�o
 *  
 *  Op��es
 *  Nao     O m�dulo de convers�o AD n�o interrompe a Cpu ap�s a convers�o
 *  Sim     O m�dulo de convers�o AD interrompe a Cpu ap�s a convers�o
 * 
 *  6.1. ADC1_INTERRUPCAO_PRIORIDADE
 *  Define o nivel de prioridade de interrup��o do m�dulo ADC
 * 
 *  Op��es
 *  Baixa   Interrup��o de baixa prioridade
 *  Alta    Interrup��o de alta prioridade
 */
#define ADC1_USA_INTERRUPCAO                            Nao
#define ADC1_INTERRUPCAO_PRIORIDADE                     Alta

#endif	/* ADC1_CONFIG_H */

