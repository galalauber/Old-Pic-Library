  /* 
 * Arquivo: Display de Leds.h
 * Autor:   JABNeto
 * Data:    17/08/2015
 */

#ifndef DISPLAY_DE_LEDS_H
#define	DISPLAY_DE_LEDS_H

#include "Definicoes Gerais.h"

//Condições dos leds e segmentos
#define _APAGADO        0
#define _ACESO          1


//Codigos de acionamentos dos digitos
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


#define _Codigo7segmentos   const char Codigo7segmentos[]= {_0,_1,_2,_3,_4,_5,_6,_7,_8,_9}





//Publicação das funções do módulo -------------------------------------------
void Display_Inicializacao (void);
void Display_LigaDigito (Uchar CodigoDoDigito, Uchar Caractere);
void Display_ExibeCaractere (Uchar Caractere);
#endif

