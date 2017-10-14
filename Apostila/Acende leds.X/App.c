/* 
 * File:   App.c
 * Author: JABNeto
 *
 * Created on 10 de Fevereiro de 2016, 09:05
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


typedef unsigned char Uchar;


int main(int argc, char** argv)
{
  
    
    //Escreve no latch
    LATBbits.LATB6 = 1;    
    LATDbits.LATD2 = 1;
    NOP();
    NOP();    
    NOP();    
    NOP();
    LATDbits.LATD2 = 0;
    
    //Define no PORT B os
    //Leds que devem acender
    LATB = 0b11110000;  
    
    //Retira as saídas do latch
    //do modo de alta impedância
    LATDbits.LATD3 = 0;
    
    while(1)
    {

        
    }

    return (EXIT_SUCCESS);
}


void Leds_Inicializacao (Uchar Valor)
{
    Latch_Inicializacao();
    Latch_Atualizacao(0b01000000);
    LATB = Valor;
    Latch_HabilitaSaidas();
}

void Leds_Atualizacao (Uchar Valor)
{
    LATB = Valor;
}

void Latch_Inicializacao (void)
{
    //Inicialização do pino RD3
    //Latch (OE) = 1
    LATDbits.LATD3 = 1;    
    TRISDbits.TRISD3 = 0;     
    ANSELDbits.ANSD3 = 0;

    //Inicialização do pino RD2
    //Latch (CLK) = 0
    LATDbits.LATD2 = 0;    
    TRISDbits.TRISD2 = 0;     
    ANSELDbits.ANSD2 = 0;
    
    PORTB_Inicializacao (0,0,0);
    
    Latch_Latch_Atualizacao(0);
}

void Latch_Atualizacao (Uchar Valor)
{
    LATB = Valor;
    
    LATDbits.LATD2 = 1;
    NOP();
    NOP();    
    NOP();    
    NOP();
    LATDbits.LATD2 = 0;
}

void Latch_HabilitaSaidas (void)
{
    LATDbits.LATD3 = 0;   
}

void Latch_DesabilitaSaidas (void)
{
    LATDbits.LATD3 = 1;   
}

void PORTB_Inicializacao (Uchar Lat, Uchar Tris,
                          Uchar Ansel)
{
    LATB = Lat;
    TRISB = Tris;
    ANSELB = Ansel;        
}

