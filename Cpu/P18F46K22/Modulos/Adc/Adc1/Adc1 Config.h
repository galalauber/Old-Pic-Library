/* 
 *  Arquivo: Adc1.h
 *  uC:      PIC18F46K22
 *  Autor:   JABNeto
 *  Versão:  161011
 */


#ifndef ADC1_CONFIG_H
#define	ADC1_CONFIG_H

/*  1. Canais Analógicos
 *  Define os canais analógicos que são utilizados no sistema.
 *  
 *  Opções
 *  Nao: O Canal não é utilizado e o pino pode ser configurado com digital por
 *       outro modulo.
 *  Sim: O Canal é utilizado e o pino é configurado para opera no modo analógico 
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


/*  2. Formatação do valor convertido
 *  Configuração da formatação do valor resultante da conversão
 *  
 *  Opções
 *  ADC1_FORMATACAO_ESQUERDA Resultado alinhado à esquerda (rrrr rrrr rr00 0000)
 *  ADC1_FORMATACAO_DIREITA  Resultado alinhado à direita  (0000 00rr rrrr rrrr)
 */
#define ADC1_FORMATACAO                                 ADC1_FORMATACAO_DIREITA


/*  3. Fonte de tensão de referência positiva
 *  Define a fonte de tensão de referência positiva (fundo de escala ADC)
 *  
 *  Opções
 *  ADC1_VREF_POSITIVA_AVDD     Tensão de referância é VDD
 *  ADC1_VREF_POSITIVA_VREF     Tensão de referância aplicada no pino VREF+
 *  ADC1_VREF_POSITIVA_FVR      Tensão de referância é definida pelo módulo Fvr
 */
#define ADC1_VREF_POSITIVA                              ADC1_VREF_POSITIVA_FVR


/*  4. Fonte de tensão de referência negativa
 *  Define a fonte de tensão de referência negativa
 *  
 *  Opções
 *  ADC1_VREF_NEGATIVA_AVSS     Tensão de referância é VSS
 *  ADC1_VREF_NEGATIVA_VREF     Tensão de referância aplicada no pino VREF-
 */
#define ADC1_VREF_NEGATIVA                              ADC1_VREF_NEGATIVA_AVSS


/*  5. Modo Trigger Event
 *  No modo Trigger Event uma fonte geradora de evento de trigger provoca o
 *  inicio da conversão. A fonte geradora deve ser configurada para que o
 *  evento possa ser gerado.
 *  
 *  Opções
 *  ADC1_TRIGGER_CCP5     O evento de trigger é gerado pelo modulo CCP5
 *  ADC1_TRIGGER_CTMU     O evento de trigger é gerado pelo modulo CTMU
 */
#define ADC1_TRIGGER                                    ADC1_TRIGGER_CTMU



/*  6. Interrupções
 *  
 *  6.1. ADC1_USA_INTERRUPCAO
 *  Define se o módulo utiliza interrupção na conversão
 *  
 *  Opções
 *  Nao     O módulo de conversão AD não interrompe a Cpu após a conversão
 *  Sim     O módulo de conversão AD interrompe a Cpu após a conversão
 * 
 *  6.1. ADC1_INTERRUPCAO_PRIORIDADE
 *  Define o nivel de prioridade de interrupção do módulo ADC
 * 
 *  Opções
 *  Baixa   Interrupção de baixa prioridade
 *  Alta    Interrupção de alta prioridade
 */
#define ADC1_USA_INTERRUPCAO                            Nao
#define ADC1_INTERRUPCAO_PRIORIDADE                     Alta

#endif	/* ADC1_CONFIG_H */

