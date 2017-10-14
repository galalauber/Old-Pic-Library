/* 
 * File:    Base 1.h
 * Autor:   JABNeto
 * Data:    13/02/2016
 */

#ifndef BASE_1_H
#define	BASE_1_H

#include <xc.h>
#include "Definicoes Gerais.h"


//Teclado --------------------------------------------
#define _S1             PORTAbits.RA0
#define _S2             PORTAbits.RA1
#define _S3             PORTAbits.RA3
#define _S4             PORTAbits.RA4
#define _S5             PORTAbits.RA5

//Codigos de acionamentos dos digitos ----------------
//                      0b-L654321
#define _Digito1        0b00000001
#define _Digito2        0b00000010
#define _Digito3        0b00000100
#define _Digito4        0b00001000
#define _Digito5        0b00010000
#define _Digito6        0b00100000
#define _Leds           0b01000000

//Codigo 7 segmentos dos displays
//                      0bpgfedcba
#define _0              0b00111111  //0
#define _1              0b00000110  //1
#define _2              0b01011011  //2
#define _3              0b01001111  //3
#define _4              0b01100110  //4
#define _5              0b01101101  //5
#define _6              0b01111101  //6
#define _7              0b00000111  //7
#define _8              0b01111111  //8
#define _9              0b01101111  //9
#define _A              0b01110111  //10
#define _B              0b01111100  //11
#define _C              0b00111001  //12
#define _D              0b01011110  //13
#define _E              0b01111001  //14
#define _F              0b01110100  //15
#define _G              0b01111101  //16
#define _g              0b01101111  //17
#define _H              0b01110110  //18
#define _I              0b00000110  //19
#define _i              0b00000100  //20
#define _J              0b00001110  //21
#define _L              0b00111000  //22
#define _n              0b01010100  //23
#define _O              0b00111111  //24
#define _o              0b01011100  //25
#define _P              0b01110011  //26
#define _r              0b01010000  //27
#define _S              0b01101101  //28
#define _t              0b01111000  //29
#define _U              0b00111110  //30
#define _u              0b00011100  //31
#define _Z              0b01011001  //32
#define _sa             0b00000001  //33
#define _sb             0b00000010  //34
#define _sc             0b00000100  //35
#define _sd             0b00001000  //36
#define _se             0b00010000  //37
#define _sf             0b00100000  //38
#define _sg             0b01000000  //39
#define _sp             0b10000000  //40
#define _br             0b00000000  //41
#define _ponto          0b10000000  //42
#define _grau           0b01100011  //43


//Estruturas do módulo -------------------------------
typedef struct 
{
    Uchar Sequencia;
    
    union
    {
        Uchar Digitos [7];
        
        struct
        {
            Uchar   Digito1;
            Uchar   Digito2;
            Uchar   Digito3;
            Uchar   Digito4;
            Uchar   Digito5;        
            Uchar   Digito6;
            Uchar   Leds;
        };
    }Buffer;

    union
    {
        Uchar valor;
        
        struct
        {
            Uchar OmiteZeros:1;
            Uchar ExibePonto1:1;
            Uchar ExibePonto2:1; 
            Uchar ExibePonto3:1; 
            Uchar ExibePonto4:1; 
            Uchar ExibePonto5:1; 
            Uchar ExibePonto6:1; 
        };
    }Opcoes;
}Str_Varredura;


//Publicação das funções do Módulo -------------------
void Latch_Inicializacao (Uchar Valor);
void Latch_EscreveValor (Uchar Valor);
void Display_Inicializacao (Uchar Valor, Uchar Digito);
void Display_LigaDigito (Uchar Valor, Uchar Digito);
void Display_InicializaVarredura (void);
void Display_ExecutaVarredura (void);
void Display_ExibeNumero (Ulong Numero);
void Teclado_Inicializacao (void);


//Publicação das variáveis do módulo -----------------
Str_Varredura  Varredura;

#endif	/* BASE_1_H */

