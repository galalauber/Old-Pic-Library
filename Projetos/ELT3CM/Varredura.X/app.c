/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 9 de Novembro de 2016, 07:45
 */


#include <xc.h>



//Estruturas


//Alocação de memoria


//Funções Locais

void Timer0_Carga (Uint Valor)
{
    Uint16 ValorDeCarga;
    
    ValorDeCarga.valor = Valor;
    
    TMR0H = ValorDeCarga.bytes.byte1;
    TMR0L = ValorDeCarga.bytes.byte0;    
}

void Timer0_Inicializacao (void)
{
    
    
    
    
}

void main(void)
{
    

    
    while (1)
    {
        
        
        
    }
}
