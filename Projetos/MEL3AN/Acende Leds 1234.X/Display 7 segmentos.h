/* 
 * File:   Display 7 segmentos.h
 * Author: jose_010573
 *
 * Created on 6 de Setembro de 2016, 22:15
 */

#ifndef DISPLAY_7_SEGMENTOS_H
#define	DISPLAY_7_SEGMENTOS_H


//Codigos dos digitos do display
#define _Digito1    0b00000001
#define _Digito2    0b00000010
#define _Digito3    0b00000100
#define _Digito4    0b00001000
#define _Digito5    0b00010000
#define _Digito6    0b00100000
#define _Leds       0b01000000


//Codigos de 7 segmentos
//                  0bpgfedcba
#define _0          0b00111111
#define _1          0b00000110
#define _2          0b01011011
#define _3          0b01001111


//Publicação das funções do módulo
void Display_LigaDigito(unsigned char Digito,\
                        unsigned char Caractere);
void Display_Inicializacao (void);



#endif	/* DISPLAY_7_SEGMENTOS_H */

