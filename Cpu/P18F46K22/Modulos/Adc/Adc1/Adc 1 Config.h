/* 
 * Arquivo: ADC 1 Config.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef ADC_1_CONFIG_H
#define	ADC_1_CONFIG_H

/* 1. Formatação -------------------------------------------------------------
 * Definição do tipo de formatação do resultado.
 * _ESQUERDA: resultado alinhado a esquerda (rrrr rrrr rr00)
 * _DIREITA:  resultado alinhado a direita  (00rr rrrr rrrr)
 */
#define ADC1_FORMATACAO                         _DIREITA


/* 2. Tensão de referência positiva -------------------------------------------
 * Define a fonte de tensão positiva de referência do conversor AD.
 * _VP_AVDD: Utiliza o sinal AVDD interno
 * _VP_VREF: Utiliza o sinal presente no pino VREF+
 * _VP_FVR:  Utiliza o módulo FVR (fixed voltage Reference)
 */
#define ADC1_VREF_POSITIVA                       _VP_FVR


/* 3. Tensão de referência negativa -------------------------------------------
 * Define a fonte de tensão positiva de referência do conversor AD.
 * _VN_AVSS: Utiliza o sinal AVSS interno
 * _VN_VREF: Utiliza o sinal presente no pino VREF-
 */
#define ADC1_VREF_NEGATIVA                       _VN_AVSS


/* 4. Trigger Event------------------------------------------------------------
 * Define a fonte geradora do evento que dispara a conversão. Esse modo de 
 * operação deve ser definido nos módulos CCP5 ou CTMU
 * _EVENT_CCP5: o módulo CCP5 é a fonte do evento
 * _EVENT_CTMU: o módulo CTMU é a fonte do evento
 */
#define ADC1_TRIGGER_EVENT                       _EVENT_CCP5






#endif	/* ADC_1_CONFIG_H */

