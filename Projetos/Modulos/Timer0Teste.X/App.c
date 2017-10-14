/*
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 25 de Outubro de 2016, 16:53
 */


#include <xc.h>

#include "Oscilador.h"
#include "Display de Leds.h"
#include "Timer0.h"


struct
{
    Uchar   Sequencia;
    Uchar   Digito[7];
    
}CtrlVarredura;



void Varredura_Controle (void)
{
    Display_LigaDigito(0,0);
    
    switch (CtrlVarredura.Sequencia)
    {
        case 0:
            Display_LigaDigito(_Leds,CtrlVarredura.Digito[0]);
            CtrlVarredura.Sequencia++;
            break;
        
        case 1:
            Display_LigaDigito(_Digito1,CtrlVarredura.Digito[1]);
            CtrlVarredura.Sequencia++;
            break;
            
        case 2:
            Display_LigaDigito(_Digito2,CtrlVarredura.Digito[2]);
            CtrlVarredura.Sequencia++;
            break;               
            
        case 3:
            Display_LigaDigito(_Digito3,CtrlVarredura.Digito[3]);
            CtrlVarredura.Sequencia++;
            break;              
 
        case 4:
            Display_LigaDigito(_Digito4,CtrlVarredura.Digito[4]);
            CtrlVarredura.Sequencia++;
            break;              
            
        case 5:
            Display_LigaDigito(_Digito5,CtrlVarredura.Digito[5]);
            CtrlVarredura.Sequencia++;
            break;              
            
        case 6:
            Display_LigaDigito(_Digito6,CtrlVarredura.Digito[6]);
            CtrlVarredura.Sequencia = 0;
    }
}



void interrupt high_priority Isr_High (void)
{
    if (T0IE && T0IF)
    {
        T0IF = 0;
        Timer0_CarregaValor();
        
        //Serviço de interrupção do Timer0
        Varredura_Controle();
        
    }
}



void main(void)
{
    Oscilador_Inicializacao();
    Display_Inicializacao();
    Timer0_Inicializacao();
    
    Display_LigaDigito(_Leds,0b11000011);
    
    CtrlVarredura.Sequencia = 0;
    
    INTCONbits.PEIE_GIEL = 1;
    INTCONbits.GIE_GIEH = 1;    
    
    while (1)
    {
        CtrlVarredura.Digito[0] = 0b11000011;
        CtrlVarredura.Digito[1] = _1;        
        CtrlVarredura.Digito[2] = _2;         
        CtrlVarredura.Digito[3] = _3;        
        CtrlVarredura.Digito[4] = _4;         
        CtrlVarredura.Digito[5] = _5;        
        CtrlVarredura.Digito[6] = _6;           
    }
}
