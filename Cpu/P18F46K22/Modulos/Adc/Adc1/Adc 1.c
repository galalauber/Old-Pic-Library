/* 
 * Arquivo: ADC 1.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include "Adc 1.h"

//Aloca��o de mem�ria para o m�dulo ------------------------------------------




//Fun��es locais -------------------------------------------------------------





//Fun��es p�blicas -----------------------------------------------------------
/*
 * ADC1_Inicializacao
 * Faz a inicializa��o do m�dulo ADC 1
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
 * Faz a convers�o do canal especificado
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


