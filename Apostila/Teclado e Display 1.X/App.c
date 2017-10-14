/* 
 * Projeto: Teclado e Display 1
 * Arquivo: App.c
 * Autor:   JABNeto
 * Data:    10/02/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


//Definições do sistema
typedef unsigned char Uchar;

#define _S1             PORTAbits.RA0
#define _S2             PORTAbits.RA1
#define _S3             PORTAbits.RA3
#define _S4             PORTAbits.RA4
#define _S5             PORTAbits.RA5

#define Pressionada     0
#define NPressionada    1

//Codigo 7 segmentos dos displays
//                      0bpgfedcba
#define _1              0b00000110
#define _2              0b01011011
#define _3              0b01001111
#define _4              0b01100110
#define _5              0b01101101
#define _sg             0b01000000

//Displays              0b-L654321
#define _Digito1        0b00000001
#define _Digito2        0b00000010
#define _Digito3        0b00000100
#define _Digito4        0b00001000
#define _Digito5        0b00010000
#define _Digito6        0b00100000
#define _Leds           0b01000000

//Protótipos das funções
void Display_Inicializacao (Uchar Valor, Uchar Digito);
void Display_LigaDigito (Uchar Valor, Uchar Digito);
void Latch_Inicializacao (Uchar Valor);
void Latch_EscreveValor (Uchar Valor);
void Teclado_Inicializacao (void);


//Rotina Principal
int main(int argc, char** argv)
{
    Display_Inicializacao(0,_Digito1);
    Teclado_Inicializacao();

    while(1)
    {
        if (_S1 == Pressionada) LATB = _1;
        else if (_S2 == Pressionada) LATB = _2;
        else if (_S3 == Pressionada) LATB = _3;        
        else if (_S4 == Pressionada) LATB = _4;          
        else if (_S5 == Pressionada) LATB = _5;          
        else LATB = _sg;
    }

    return (EXIT_SUCCESS);
}

/*
 * Latch_Inicializacao
 * Faz a inicialização do Latch MC74HC574 com valor
 * de saída fornecido.
 * A rotina também faz a inicialização do PORT B.
 * No retorno da rotina PORTB = 0.
 * Valor: representa o estado inicial das saídas
 */
void Latch_Inicializacao (Uchar Valor)
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

    //Inicialização do PORT B
    LATB = 0;
    TRISB = 0;
    ANSELB = 0;
    
    Latch_EscreveValor(Valor);
    
    LATB = 0;
    LATDbits.LATD3 = 0;    
}

/*
 * Latch_EscreveValor
 * Escreve um novo valor no latch MC74HC574
 */
void Latch_EscreveValor (Uchar Valor)
{
    LATB = Valor;
    
    //Escreve no latch
    LATDbits.LATD2 = 1;
    NOP();
    NOP();    
    NOP();    
    NOP();
    LATDbits.LATD2 = 0;     
}

/* Display_Inicializacao
 * Faz a inicialização do display
 */
void Display_Inicializacao (Uchar Valor, Uchar Digito)
{
    Latch_Inicializacao(0);
    Display_LigaDigito(Valor,Digito);
}

/* Display_LigaDigito
 * Exibe um valor no digito do display especificado.
 * Valor:  Codigo 7 segmentos do caractere a ser
 *         exibido
 * Digito: Codigo de se leção do digito 
 */
void Display_LigaDigito (Uchar Valor, Uchar Digito)
{
    LATDbits.LATD3 = 1;
    Latch_EscreveValor (Digito);
    LATB = Valor;
    LATDbits.LATD3 = 0;    
}

/* Teclado_Inicializacao
 * Configura os pinos do PORT A que contém
 * as teclas.
 */
void Teclado_Inicializacao (void)
{
    ANSELA = 0b00000100;
}





