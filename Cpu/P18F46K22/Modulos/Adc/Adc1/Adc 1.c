/* 
 * Arquivo: ADC 1.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include "Adc 1.h"

//Alocação de memória para o módulo ------------------------------------------




//Funções locais -------------------------------------------------------------





//Funções públicas -----------------------------------------------------------
/*
 * ADC1_Inicializacao
 * Faz a inicialização do módulo ADC 1
 */
void ADC1_Inicializacao (void)
{
    ADCON2bits.ADFM = ADC1_FORMATACAO;   
    ADCON2bits.ADCS = ADC1_FREQUENCIA_CLOCK;
    ADCON2bits.ACQT = ADC1_AQUISICAO;
    
    ADCON1bits.TRIGSEL = ADC1_TRIGGER_EVENT;
    ADCON1bits.PVCFG = _VP_AVDD;
    ADCON1bits.NVCFG = _VN_AVSS;
    
    ADCON0bits.ADON = 1;
}

/*
 * ADC1_ConverteCanal (unsiged char Canal)
 * Faz a conversão do canal especificado
 */
Uint ADC1_ConverteCanal (Uchar Canal)
{
    Uint16 Resultado;
    
    ADCON0bits.CHS = Canal;
    
    ADCON0bits.GODONE = 1;
    while (ADCON0bits.GODONE == 1){};
    
    Resultado.bytes.byte0 = ADRESL;
    Resultado.bytes.byte1 = ADRESH;    
    
    return Resultado.valor;
}


