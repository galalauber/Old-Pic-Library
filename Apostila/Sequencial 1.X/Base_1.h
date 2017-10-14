/* 
 * File:    Base 1.h
 * Autor:   JABNeto
 * Data:    13/02/2016
 */

#ifndef BASE_1_H
#define	BASE_1_H

#include <xc.h>
#include "../../Geral/Definicoes_Gerais.h"


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
#define _0              0b00111111
#define _1              0b00000110
#define _2              0b01011011
#define _3              0b01001111
#define _4              0b01100110
#define _5              0b01101101
#define _6              0b01111101
#define _7              0b00000111
#define _8              0b01111111
#define _9              0b01101111
#define _A              0b01110111
#define _B              0b01111100
#define _C              0b00111001
#define _D              0b01011110
#define _E              0b01111001
#define _F              0b01110100
#define _G              0b01111101
#define _g              0b01101111
#define _H              0b01110110
#define _I              0b00000110
#define _i              0b00000100
#define _J              0b00001110
#define _L              0b00111000
#define _n              0b01010100
#define _O              0b00111111
#define _o              0b01011100
#define _P              0b01110011
#define _r              0b01010000
#define _S              0b01101101
#define _t              0b01111000
#define _U              0b00111110
#define _u              0b00011100
#define _Z              0b01011001
#define _sa             0b00000001
#define _sb             0b00000010
#define _sc             0b00000100
#define _sd             0b00001000
#define _se             0b00010000
#define _sf             0b00100000
#define _sg             0b01000000
#define _sp             0b10000000
#define _br             0b00000000
#define _ponto          0b10000000
#define _grau           0b01100011


//Estruturas do módulo -------------------------------



//Publicação das funções do Módulo -------------------
void Latch_Inicializacao (Uchar Valor);
void Latch_EscreveValor (Uchar Valor);
void Display_Inicializacao (Uchar Valor, Uchar Digito);
void Display_LigaDigito (Uchar Valor, Uchar Digito);
void Teclado_Inicializacao (void);


//Publicação das variáveis do módulo -----------------





#endif	/* BASE_1_H */

