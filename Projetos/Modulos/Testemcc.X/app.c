/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 13 de Outubro de 2016, 16:26
 */


#include <xc.h>
#include "Definicoes Gerais.h"
#include "app.h"

#define Fop             8000000
#define TEMPO           12.6e-3
#define PRESCALER       1.0


#define CONTAGEM        (Uint)(65536.0 - (TEMPO * (float)Fop / PRESCALER));


void Timer0_Inicializacao(void)
{
    Uint16 ValorDeCarga;
    
    ValorDeCarga.valor = (Uint) CONTAGEM;
    
    TMR0H = ValorDeCarga.bytes.byte1;        
    TMR0L = ValorDeCarga.bytes.byte0;     
 
    ValorDeCarga.valor = 0;
}



void main(void)
{
    Timer0_Inicializacao();
}
