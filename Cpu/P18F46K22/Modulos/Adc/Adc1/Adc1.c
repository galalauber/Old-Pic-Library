/* 
 *  Arquivo:    Adc1.c
 *  uC:         PIC18F46K22
 *  Autor:      JABNeto
 *  Versão:     161011 
 */


#include <xc.h>
#include "Adc1.h"


//Funções locais --------------------------------------------------------------




//Funções públicas ------------------------------------------------------------
void Adc1_Inicializacao (void)
{
    #ifdef ADC1_CANAL0_UTILIZADO
        #if (ADC1_CANAL0_UTILIZADO == Sim)
            ADC1_AN0_IO;
        #endif
    #endif
    
    #ifdef ADC1_CANAL1_UTILIZADO
        #if (ADC1_CANAL1_UTILIZADO == Sim)
            ADC1_AN1_IO;  
        #endif
    #endif
    
    #ifdef ADC1_CANAL2_UTILIZADO
        #if (ADC1_CANAL2_UTILIZADO == Sim)
            ADC1_AN2_IO; 
        #endif
    #endif
    
    #ifdef ADC1_CANAL3_UTILIZADO
        #if (ADC1_CANAL3_UTILIZADO == Sim)
            ADC1_AN3_IO;  
        #endif
    #endif
        
    #ifdef ADC1_CANAL4_UTILIZADO
        #if (ADC1_CANAL4_UTILIZADO == Sim)
            ADC1_AN4_IO;   
        #endif
    #endif        
        
    #ifdef ADC1_CANAL5_UTILIZADO
        #if (ADC1_CANAL5_UTILIZADO == Sim)
            ADC1_AN5_IO;  
        #endif
    #endif
            
    #ifdef ADC1_CANAL6_UTILIZADO
        #if (ADC1_CANAL6_UTILIZADO == Sim)
            ADC1_AN6_IO; 
        #endif
    #endif            
            
    #ifdef ADC1_CANAL7_UTILIZADO
        #if (ADC1_CANAL7_UTILIZADO == Sim)
            ADC1_AN7_IO;    
        #endif
    #endif            
            
    #ifdef ADC1_CANAL8_UTILIZADO
        #if (ADC1_CANAL8_UTILIZADO == Sim)
            ADC1_AN8_IO; 
        #endif
    #endif            

    #ifdef ADC1_CANAL9_UTILIZADO
        #if (ADC1_CANAL9_UTILIZADO == Sim)
            ADC1_AN9_IO;   
        #endif
    #endif            

    #ifdef ADC1_CANAL10_UTILIZADO
        #if (ADC1_CANAL10_UTILIZADO == Sim)
            ADC1_AN10_IO;  
        #endif
    #endif

    #ifdef ADC1_CANAL11_UTILIZADO
        #if (ADC1_CANAL11_UTILIZADO == Sim)
            ADC1_AN11_IO;  
        #endif
    #endif

    #ifdef ADC1_CANAL12_UTILIZADO
        #if (ADC1_CANAL12_UTILIZADO == Sim)
            ADC1_AN12_IO;   
        #endif
    #endif

    #ifdef ADC1_CANAL13_UTILIZADO
        #if (ADC1_CANAL13_UTILIZADO == Sim)
            ADC1_AN13_IO;   
        #endif
    #endif

    #ifdef ADC1_CANAL14_UTILIZADO
        #if (ADC1_CANAL14_UTILIZADO == Sim)
            ADC1_AN14_IO;   
        #endif
    #endif

    #ifdef ADC1_CANAL15_UTILIZADO
        #if (ADC1_CANAL15_UTILIZADO == Sim)
            ADC1_AN15_IO;    
        #endif
    #endif

    #ifdef ADC1_CANAL16_UTILIZADO
        #if (ADC1_CANAL16_UTILIZADO == Sim)
            ADC1_AN16_IO;    
        #endif
    #endif

    #ifdef ADC1_CANAL17_UTILIZADO
        #if (ADC1_CANAL17_UTILIZADO == Sim)
            ADC1_AN17_IO;    
        #endif
    #endif

    #ifdef ADC1_CANAL18_UTILIZADO
        #if (ADC1_CANAL18_UTILIZADO == Sim)
            ADC1_AN18_IO;   
        #endif
    #endif            
            
    #ifdef ADC1_CANAL19_UTILIZADO
        #if (ADC1_CANAL19_UTILIZADO == Sim)
            ADC1_AN19_IO;    
        #endif
    #endif            
            
    #ifdef ADC1_CANAL20_UTILIZADO
        #if (ADC1_CANAL20_UTILIZADO == Sim)
            ADC1_AN20_IO;    
        #endif
    #endif            
            
    #ifdef ADC1_CANAL21_UTILIZADO
        #if (ADC1_CANAL21_UTILIZADO == Sim)
            ADC1_AN21_IO; 
        #endif
    #endif            
            
    #ifdef ADC1_CANAL22_UTILIZADO
        #if (ADC1_CANAL22_UTILIZADO == Sim)
            ADC1_AN22_IO;    
        #endif
    #endif                
            
    #ifdef ADC1_CANAL23_UTILIZADO
        #if (ADC1_CANAL23_UTILIZADO == Sim)
            ADC1_AN23_IO; 
        #endif
    #endif                
            
    #ifdef ADC1_CANAL24_UTILIZADO
        #if (ADC1_CANAL24_UTILIZADO == Sim)
            ADC1_AN24_IO;  
        #endif
    #endif    

    #ifdef ADC1_CANAL25_UTILIZADO
        #if (ADC1_CANAL25_UTILIZADO == Sim)
            ADC1_AN25_IO;   
        #endif
    #endif    

    #ifdef ADC1_CANAL26_UTILIZADO
        #if (ADC1_CANAL26_UTILIZADO == Sim)
            ADC1_AN26_IO;  
        #endif
    #endif 
            
    #ifdef ADC1_CANAL27_UTILIZADO
        #if (ADC1_CANAL27_UTILIZADO == Sim)
            ADC1_AN27_IO;  
        #endif
    #endif                


    //Tensão de referência positiva
    ADCON1bits.PVCFG = ADC1_VREF_POSITIVA;            

    //Tensão de referência negativa
    ADCON1bits.NVCFG = ADC1_VREF_NEGATIVA;  
            
    //Trigger Event   
    ADCON1bits.TRIGSEL = ADC1_TRIGGER;

    //Formatação
    ADCON2bits.ADFM = ADC1_FORMATACAO;

    //Tempo de Amostra 
    ADCON2bits.ACQT = ADC1_ACQT;
    ADCON2bits.ADCS = ADC1_ADCS;    
        
    ADCON0bits.ADON = 1;
    
    #if (ADC1_USA_INTERRUPCAO == Sim)
        #if (ADC1_INTERRUPCAO_PRIORIDADE == Baixa)
            IPR1bits.ADIP = 0;
        #endif

        PIR1bits.ADIF = 0;  
        PIE1bits.ADIE= 1;            
    #endif
}


#if (ADC1_USA_INTERRUPCAO == Sim)
/*
 *  Adc1_ConverteCanal
 *  Efetua a conversão do canal analógico especificado e retorna o valor
 */
void Adc1_ConverteCanal(Uchar Canal)
{
    ADCON0bits.CHS = Canal;
    ADCON0bits.GO = 1;
}

#else
Uint Adc1_ConverteCanal(Uchar Canal)
{
    Uint16 ValorConvertido;
            
    ADCON0bits.CHS = Canal;
    ADCON0bits.GO = 1;
    
    while (ADCON0bits.GO) {};
    
    ValorConvertido.bytes.byte0 = ADRESL;
    ValorConvertido.bytes.byte1 = ADRESH;
    
    return ValorConvertido.valor;
}
#endif



#if (ADC1_USA_INTERRUPCAO == Sim)
/*
 * Adc1_ServicoDeInterrupcao
 * Executa o serviço de interrupção do modulo
 */
void Adc1_ServicoDeInterrupcao (void)
{
    if (PIE1bits.ADIE  && PIR1bits.ADIF)
    {
       PIR1bits.ADIF = 0; 


       //Funções do usuário

    }
}
#endif