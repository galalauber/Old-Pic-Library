/* 
 * File:    Base 1.c
 * Autor:   JABNeto
 * Data:    13/02/2016
 */

#include "Base_1.h"

//Alocação de Memória para o módulo ------------------





//Funções do módulo ----------------------------------

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








