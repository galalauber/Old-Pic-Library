/*
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 25 de Outubro de 2016, 22:03
 */


#include <xc.h>

#include "Definicoes Gerais.h"
#include "Oscilador.h"
#include "Display de Leds.h"



//Alocação de memória -------------------
struct
{
    Uchar   Sequencia;
    Uchar   Buffer[7];
}CtrlVarredura;


//Funções Locais ------------------------
//Timer0
void Timer0_CarregaValor (void)
{
    Uint16 Valor;
    
    Valor.valor = 43136;
    
    TMR0H = Valor.bytes.byte1;
    TMR0L = Valor.bytes.byte0;    
}

void Timer0_Inicializacao (void)
{
    T0CONbits.TMR0ON = 0;    
    T0CONbits.T08BIT = 0;
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 1;
    
    Timer0_CarregaValor();
    
    INTCONbits.TMR0IE = 1;
    T0CONbits.TMR0ON = 1;    
}

void Varredura_Monitor (void)
{
    Display_LigaDigito(0,0);
    
    switch (CtrlVarredura.Sequencia)
    {
        case 0:
            Display_LigaDigito(_Leds,CtrlVarredura.Buffer[0]);
            break;

        case 1:
            Display_LigaDigito(_Digito1,CtrlVarredura.Buffer[1]);
            break;
            
        case 2:
            Display_LigaDigito(_Digito2,CtrlVarredura.Buffer[2]);
            break;         

        case 3:
            Display_LigaDigito(_Digito3,CtrlVarredura.Buffer[3]);
            break;
            
        case 4:
            Display_LigaDigito(_Digito4,CtrlVarredura.Buffer[4]);
            break;

        case 5:
            Display_LigaDigito(_Digito5,CtrlVarredura.Buffer[5]);
            break; 

        case 6:
            Display_LigaDigito(_Digito6,CtrlVarredura.Buffer[6]);
            break; 
    }

    if (++CtrlVarredura.Sequencia == 7)CtrlVarredura.Sequencia = 0;
    
}

void Varredura_Inicializacao (void)
{
    Uchar i;
    
    CtrlVarredura.Sequencia = 0;
   
    for (i = 0; i < 7; i++ )
    {
        CtrlVarredura.Buffer[i] = 0;
    }
}


void main(void)
{
    Oscilador_Inicializacao();
    Display_Inicializacao();
    Timer0_Inicializacao();
    
    Varredura_Inicializacao();
    
    //Teste
    CtrlVarredura.Buffer[0] = 0b11000011;
    CtrlVarredura.Buffer[1] = _i;
    CtrlVarredura.Buffer[2] = _t;
    CtrlVarredura.Buffer[3] = _B;
    CtrlVarredura.Buffer[4] = _sg;
    CtrlVarredura.Buffer[5] = _1;
    CtrlVarredura.Buffer[6] = _6;
    
    
    INTCONbits.GIEH = 1;
    
    
    while(1)
    {

        
        
        
        
        
    }
}



void interrupt high_priority Isr (void)
{
   if (TMR0IE && TMR0IF)
   {
       TMR0IF = 0;
       Timer0_CarregaValor();
       
       //Tarefas do timer 0
       Varredura_Monitor();
   }
}