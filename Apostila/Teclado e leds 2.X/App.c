/* 
 * Projeto: Teclado e leds 2
 * Arquivo: App.c
 * Autor:   JABNeto
 * Data:    10/02/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

        
//Defini��es do sistema
typedef unsigned char Uchar;

#define _S1             PORTAbits.RA0
#define _S2             PORTAbits.RA1
#define _S3             PORTAbits.RA3
#define _S4             PORTAbits.RA4
#define _S5             PORTAbits.RA5

#define Pressionada     0
#define NPressionada    1


//Prot�tipos das fun��es
void Leds_Inicializacao (Uchar Valor);
void Teclado_Inicializacao (void);


//Rotina Principal
int main(int argc, char** argv)
{
    Leds_Inicializacao(0);
    Teclado_Inicializacao();

    while(1)
    {
        if (_S3 == Pressionada)
        {
            LATB = 0b00001111;
        }
        else
        {
            LATB = 0b11110000; 
        }
    }

    return (EXIT_SUCCESS);
}


/* Leds_Inicializacao
 * Faz a inicializa��o dos leds atribuindo uma
 * condi��o inicial de partida (Valor)
 * O Latch e PORT B tamb�m s�o inicializados.
 */
void Leds_Inicializacao (Uchar Valor)
{
    //Inicializa��o do pino RD3
    //Latch (OE) = 1
    LATDbits.LATD3 = 1;    
    TRISDbits.TRISD3 = 0;     
    ANSELDbits.ANSD3 = 0;
    
    //Inicializa��o do pino RD2
    //Latch (CLK) = 0
    LATDbits.LATD2 = 0;    
    TRISDbits.TRISD2 = 0;     
    ANSELDbits.ANSD2 = 0;

    //Inicializa��o do PORT B
    LATB = 0b01000000;
    TRISB = 0;
    ANSELB = 0;
    
    //Escreve no latch
    LATDbits.LATD2 = 1;
    NOP();
    NOP();    
    NOP();    
    NOP();
    LATDbits.LATD2 = 0;
    
    //Leds partem apagados
    LATB = Valor;
    
    //Habilita sa�das do latch
    LATDbits.LATD3 = 0; 
}

/* Teclado_Inicializacao
 * Configura os pinos do PORT A que cont�m
 * as teclas.
 */

void Teclado_Inicializacao (void)
{
    ANSELA = 0b00000100;
}





