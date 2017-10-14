/* 
 * Arquivo: Display lcd alfa.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef LCD_H
#define	LCD_H

#include "Definicoes Gerais.h"
#include "Portas.h"
#include "Mensagens.h"

//Definicoes do módulo --------------------------------------------------------
#define _4BITS                              4
#define _8BITS                              8

#define _LOW                                0
#define _HIGH                               1

#define _LCD_ENDERECO_DDRAM_LINHA1          0x00
#define _LCD_ENDERECO_DDRAM_LINHA2          0x40
#define _LCD_ENDERECO_DDRAM_LINHA3          0x14
#define _LCD_ENDERECO_DDRAM_LINHA4          0x54


#include "Display lcd alfa config.h"

//Processamento das definicoes-------------------------------------------------
#if (_LCD_INTERFACE == _4BITS)

#if (_LCD_INTERFACE_NIBBLE == _HIGH)
    #if (_LCD_PORT == _PORTA)
        #ifdef _PORTA_NIBBLE_H_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTA_NIBBLE_H_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTA_WR
        #define _LCD_REGISTRADOR_RD   _PORTA_RD

    #elif (_LCD_PORT == _PORTB)
        #ifdef _PORTB_NIBBLE_H_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTB_NIBBLE_H_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTB_WR
        #define _LCD_REGISTRADOR_RD   _PORTB_RD

    #elif (_LCD_PORT == _PORTC)
        #ifdef _PORTC_NIBBLE_H_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTC_NIBBLE_H_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTC_WR
        #define _LCD_REGISTRADOR_RD   _PORTC_RD

    #elif (_LCD_PORT == _PORTD)
        #ifdef _PORTD_NIBBLE_H_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTD_NIBBLE_H_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTD_WR
        #define _LCD_REGISTRADOR_RD   _PORTD_RD

    #elif (_LCD_PORT == _PORTE)
        #ifdef _PORTE_NIBBLE_H_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTE_NIBBLE_H_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTE_WR
        #define _LCD_REGISTRADOR_RD   _PORTE_RD
    #endif
#endif

#if (_LCD_INTERFACE_NIBBLE == _LOW)
    #if (_LCD_PORT == _PORTA)
        #ifdef _PORTA_NIBBLE_L_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTA_NIBBLE_L_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTA_WR
        #define _LCD_REGISTRADOR_RD   _PORTA_RD

    #elif (_LCD_PORT == _PORTB)
        #ifdef _PORTB_NIBBLE_L_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTB_NIBBLE_L_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTB_WR
        #define _LCD_REGISTRADOR_RD   _PORTB_RD

    #elif (_LCD_PORT == _PORTC)
        #ifdef _PORTC_NIBBLE_L_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTC_NIBBLE_L_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTC_WR
        #define _LCD_REGISTRADOR_RD   _PORTC_RD

    #elif (_LCD_PORT == _PORTD)
        #ifdef _PORTBD_NIBBLE_L_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTD_NIBBLE_L_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTD_WR
        #define _LCD_REGISTRADOR_RD   _PORTD_RD

    #elif (_LCD_PORT == _PORTE)
        #ifdef _PORTE_NIBBLE_L_DIGITAL
        #define _LCD_CONFIGURA_IO     _PORTE_NIBBLE_L_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR   _PORTE_WR
        #define _LCD_REGISTRADOR_RD   _PORTE_RD
    #endif
#endif
#endif



#if (_LCD_INTERFACE == _8BITS)
    #if (_LCD_PORT == _PORTA)
        #ifdef _PORTA_DIGITAL
        #define _LCD_CONFIGURA_IO       _PORTA_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR     _PORTA_WR
        #define _LCD_REGISTRADOR_RD     _PORTA_RD

    #elif (_LCD_PORT == _PORTB)
        #ifdef _PORTB_DIGITAL
        #define _LCD_CONFIGURA_IO       _PORTB_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR     _PORTB_WR
        #define _LCD_REGISTRADOR_RD     _PORTB_RD

    #elif (_LCD_PORT == _PORTC)
        #ifdef _PORTC_DIGITAL
        #define _LCD_CONFIGURA_IO       _PORTC_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR     _PORTC_WR
        #define _LCD_REGISTRADOR_RD     _PORTC_RD

    #elif (_LCD_PORT == _PORTD)
        #ifdef _PORTD_DIGITAL
        #define _LCD_CONFIGURA_IO       _PORTD_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR     _PORTD_WR
        #define _LCD_REGISTRADOR_RD     _PORTD_RD

    #elif (_LCD_PORT == _PORTE)
        #ifdef _PORTE_DIGITAL
        #define _LCD_CONFIGURA_IO       _PORTE_DIGITAL
        #endif
        #define _LCD_REGISTRADOR_WR     _PORTE_WR
        #define _LCD_REGISTRADOR_RD     _PORTE_RD
    #endif
#endif

//_LCD_CONTROLE_PINO_ENABLE ---------------------------------------------------
#if (_LCD_CONTROLE_PINO_ENABLE  == _PORTA_0)
    #ifdef _PORTA_0_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTA_0_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTA_0_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTA_0_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTA_1)
    #ifdef _PORTA_1_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTA_1_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTA_1_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTA_1_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTA_2)
    #ifdef _PORTA_2_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTA_2_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTA_2_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTA_2_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTA_3)
    #ifdef _PORTA_3_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTA_3_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTA_3_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTA_3_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTA_4)
    #ifdef _PORTA_4_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTA_4_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTA_4_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTA_4_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTA_5)
    #ifdef _PORTA_5_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTA_5_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTA_5_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTA_5_SAIDA
    
#elif(_LCD_CONTROLE_PINO_ENABLE  == _PORTA_6)
    #ifdef _PORTA_6_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTA_6_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTA_6_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTA_6_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTA_7)
    #ifdef _PORTA_7_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTA_7_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTA_7_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTA_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_ENABLE  == _PORTB_0)
    #ifdef _PORTB_0_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTB_0_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTB_0_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTB_0_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTB_1)
    #ifdef _PORTB_1_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTB_1_DIGITAL
    #endif  
    #define _LCD_PINO_ENABLE_WR                     _PORTB_1_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTB_1_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTB_2)
    #ifdef _PORTB_2_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTB_2_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTB_2_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTB_2_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTB_3)
    #ifdef _PORTB_3_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTB_3_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTB_3_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTB_3_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTB_4)
    #ifdef _PORTB_4_DIGITAL
        #define _LCD_PINO_ENABLE_AD)                _PORTB_4_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTB_4_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTB_4_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTB_5)
    #ifdef _PORTB_5_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTB_5_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTB_5_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTB_5_SAIDA

#elif(_LCD_CONTROLE_PINO_ENABLE  == _PORTB_6)
    #ifdef _PORTB_6_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTB_6_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTB_6_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTB_6_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTB_7)
    #ifdef _PORTB_7_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTB_7_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTB_7_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTB_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_ENABLE  == _PORTC_0)
    #ifdef _PORTC_0_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTC_0_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTC_0_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTC_0_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTC_1)
    #ifdef _PORTC_1_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTC_1_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTC_1_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTC_1_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTC_2)
    #ifdef _PORTC_2_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTC_2_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTC_2_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTC_2_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTC_3)
    #ifdef _PORTC_3_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTC_3_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTC_3_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTC_3_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTC_4)
    #ifdef _PORTC_4_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTC_4_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTC_4_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTC_4_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTC_5)
    #ifdef _PORTC_5_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTC_5_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTC_5_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTC_5_SAIDA

#elif(_LCD_CONTROLE_PINO_ENABLE  == _PORTC_6)
    #ifdef _PORTC_6_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTC_6_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTC_6_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTC_6_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTC_7)
    #ifdef _PORTC_7_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTC_7_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTC_7_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTC_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_ENABLE  == _PORTD_0)
    #ifdef _PORTD_0_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTD_0_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTD_0_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTD_0_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTD_1)
    #ifdef _PORTD_1_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTD_1_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTD_1_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTD_1_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTD_2)
    #ifdef _PORTD_2_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTD_2_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTD_2_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTD_2_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTD_3)
    #ifdef _PORTD_3_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTD_3_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTD_3_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTD_3_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTD_4)
    #ifdef _PORTD_4_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTD_4_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTD_4_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTD_4_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTD_5)
    #ifdef _PORTD_5_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTD_5_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTD_5_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTD_5_SAIDA

#elif(_LCD_CONTROLE_PINO_ENABLE  == _PORTD_6)
    #ifdef _PORTD_6_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTD_6_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTD_6_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTD_6_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTD_7)
    #ifdef _PORTD_7_DIGITAL
        #define _LCD_PINO_ENABLE_AD                 _PORTD_7_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                     _PORTD_7_WR
    #define _LCD_PINO_ENABLE_SAIDA                  _PORTD_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_ENABLE  == _PORTE_0)
    #ifdef _PORTE_0_DIGITAL
        #define _LCD_PINO_ENABLE_AD               _PORTE_0_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                   _PORTE_0_WR
    #define _LCD_PINO_ENABLE_SAIDA                _PORTE_0_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTD_1)
    #ifdef _PORTE_1_DIGITAL
        #define _LCD_PINO_ENABLE_AD               _PORTE_1_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                   _PORTE_1_WR
    #define _LCD_PINO_ENABLE_SAIDA                _PORTE_1_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTE_2)
    #ifdef _PORTE_2_DIGITAL
        #define _LCD_PINO_ENABLE_AD               _PORTE_2_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                   _PORTE_2_WR
    #define _LCD_PINO_ENABLE_SAIDA                _PORTE_2_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTE_3)
    #ifdef _PORTE_3_DIGITAL
        #define _LCD_PINO_ENABLE_AD               _PORTE_3_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                   _PORTE_3_WR
    #define _LCD_PINO_ENABLE_SAIDA               _PORTE_3_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTE_4)
    #ifdef _PORTE_4_DIGITAL
        #define _LCD_PINO_ENABLE_AD               _PORTE_4_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                   _PORTE_4_WR
    #define _LCD_PINO_ENABLE_SAIDA                _PORTE_4_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTE_5)
    #ifdef _PORTE_5_DIGITAL
        #define _LCD_PINO_ENABLE_AD               _PORTE_5_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                   _PORTE_5_WR
    #define _LCD_PINO_ENABLE_SAIDA                _PORTE_5_SAIDA

#elif(_LCD_CONTROLE_PINO_ENABLE  == _PORTE_6)
    #ifdef _PORTE_6_DIGITAL
        #define _LCD_PINO_ENABLE_AD               _PORTE_6_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                   _PORTE_6_WR
    #define _LCD_PINO_ENABLE_SAIDA                _PORTE_6_SAIDA

#elif (_LCD_CONTROLE_PINO_ENABLE  == _PORTE_7)
    #ifdef _PORTE_7_DIGITAL
        #define _LCD_PINO_ENABLE_AD               _PORTE_7_DIGITAL
    #endif
    #define _LCD_PINO_ENABLE_WR                   _PORTE_7_WR
    #define _LCD_PINO_ENABLE_SAIDA                _PORTE_7_SAIDA
#endif


//_LCD_CONTROLE_PINO_RS -------------------------------------------------------
#if (_LCD_CONTROLE_PINO_RS  == _PORTA_0)
    #ifdef _PORTA_0_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTA_0_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTA_0_WR
    #define _LCD_PINO_RS_SAIDA                _PORTA_0_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTA_1)
    #ifdef _PORTA_1_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTA_1_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTA_1_WR
    #define _LCD_PINO_RS_SAIDA                _PORTA_1_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTA_2)
    #ifdef _PORTA_2_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTA_2_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTA_2_WR
    #define _LCD_PINO_RS_SAIDA                _PORTA_2_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTA_3)
    #ifdef _PORTA_3_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTA_3_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTA_3_WR
    #define _LCD_PINO_RS_SAIDA                _PORTA_3_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTA_4)
    #ifdef _PORTA_4_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTA_4_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTA_4_WR
    #define _LCD_PINO_RS_SAIDA                _PORTA_4_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTA_5)
    #ifdef _PORTA_5_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTA_5_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTA_5_WR
    #define _LCD_PINO_RS_SAIDA                _PORTA_5_SAIDA

#elif(_LCD_CONTROLE_PINO_RS  == _PORTA_6)
    #ifdef _PORTA_6_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTA_6_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTA_6_WR
    #define _LCD_PINO_RS_SAIDA                _PORTA_6_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTA_7)
    #ifdef _PORTA_7_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTA_7_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTA_7_WR
    #define _LCD_PINO_RS_SAIDA                _PORTA_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_RS  == _PORTB_0)
    #ifdef _PORTB_0_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTB_0_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTB_0_WR
    #define _LCD_PINO_RS_SAIDA                _PORTB_0_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTB_1)
    #ifdef _PORTB_1_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTB_1_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTB_1_WR
    #define _LCD_PINO_RS_SAIDA                _PORTB_1_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTB_2)
    #ifdef _PORTB_2_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTB_2_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTB_2_WR
    #define _LCD_PINO_RS_SAIDA                _PORTB_2_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTB_3)
    #ifdef _PORTB_3_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTB_3_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTB_3_WR
    #define _LCD_PINO_RS_SAIDA                _PORTB_3_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTB_4)
    #ifdef _PORTB_4_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTB_4_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTB_4_WR
    #define _LCD_PINO_RS_SAIDA                _PORTB_4_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTB_5)
    #ifdef _PORTB_5_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTB_5_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTB_5_WR
    #define _LCD_PINO_RS_SAIDA                _PORTB_5_SAIDA

#elif(_LCD_CONTROLE_PINO_RS  == _PORTB_6)
    #ifdef _PORTB_6_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTB_6_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTB_6_WR
    #define _LCD_PINO_RS_SAIDA                _PORTB_6_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTB_7)
    #ifdef _PORTB_7_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTB_7_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTB_7_WR
    #define _LCD_PINO_RS_SAIDA                _PORTB_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_RS  == _PORTC_0)
    #ifdef _PORTC_0_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTC_0_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTC_0_WR
    #define _LCD_PINO_RS_SAIDA                _PORTC_0_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTC_1)
    #ifdef _PORTC_1_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTC_1_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTC_1_WR
    #define _LCD_PINO_RS_SAIDA                _PORTC_1_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTC_2)
    #ifdef _PORTC_2_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTC_2_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTC_2_WR
    #define _LCD_PINO_RS_SAIDA                _PORTC_2_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTC_3)
    #ifdef _PORTC_3_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTC_3_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTC_3_WR
    #define _LCD_PINO_RS_SAIDA                _PORTC_3_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTC_4)
    #ifdef _PORTC_4_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTC_4_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTC_4_WR
    #define _LCD_PINO_RS_SAIDA                _PORTC_4_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTC_5)
    #ifdef _PORTC_5_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTC_5_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTC_5_WR
    #define _LCD_PINO_RS_SAIDA                _PORTC_5_SAIDA

#elif(_LCD_CONTROLE_PINO_RS  == _PORTC_6)
    #ifdef _PORTC_6_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTC_6_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTC_6_WR
    #define _LCD_PINO_RS_SAIDA                _PORTC_6_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTC_7)
    #ifdef _PORTC_7_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTC_7_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTC_7_WR
    #define _LCD_PINO_RS_SAIDA                _PORTC_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_RS  == _PORTD_0)
    #ifdef _PORTD_0_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTD_0_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTD_0_WR
    #define _LCD_PINO_RS_SAIDA                _PORTD_0_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTD_1)
    #ifdef _PORTD_1_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTD_1_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTD_1_WR
    #define _LCD_PINO_RS_SAIDA                _PORTD_1_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTD_2)
    #ifdef _PORTD_2_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTD_2_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTD_2_WR
    #define _LCD_PINO_RS_SAIDA                _PORTD_2_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTD_3)
    #ifdef _PORTD_3_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTD_3_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTD_3_WR
    #define _LCD_PINO_RS_SAIDA                _PORTD_3_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTD_4)
    #ifdef _PORTD_4_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTD_4_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTD_4_WR
    #define _LCD_PINO_RS_SAIDA                _PORTD_4_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTD_5)
    #ifdef _PORTD_5_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTD_5_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTD_5_WR
    #define _LCD_PINO_RS_SAIDA                _PORTD_5_SAIDA

#elif(_LCD_CONTROLE_PINO_RS  == _PORTD_6)
    #ifdef _PORTD_6_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTD_6_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTD_6_WR
    #define _LCD_PINO_RS_SAIDA                _PORTD_6_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTD_7)
    #ifdef _PORTD_7_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTD_7_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTD_7_WR
    #define _LCD_PINO_RS_SAIDA                _PORTD_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_RS  == _PORTE_0)
    #ifdef _PORTE_0_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTE_0_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTE_0_WR
    #define _LCD_PINO_RS_SAIDA                _PORTE_0_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTD_1)
    #ifdef _PORTE_1_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTE_1_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTE_1_WR
    #define _LCD_PINO_RS_SAIDA                _PORTE_1_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTE_2)
    #ifdef _PORTE_2_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTE_2_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTE_2_WR
    #define _LCD_PINO_RS_SAIDA                _PORTE_2_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTE_3)
    #ifdef _PORTE_3_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTE_3_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTE_3_WR
    #define _LCD_PINO_RS_SAIDA                _PORTE_3_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTE_4)
    #ifdef _PORTE_4_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTE_4_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTE_4_WR
    #define _LCD_PINO_RS_SAIDA                _PORTE_4_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTE_5)
    #ifdef _PORTE_5_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTE_5_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTE_5_WR
    #define _LCD_PINO_RS_SAIDA                _PORTE_5_SAIDA

#elif(_LCD_CONTROLE_PINO_RS  == _PORTE_6)
    #ifdef _PORTE_6_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTE_6_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTE_6_WR
    #define _LCD_PINO_RS_SAIDA                _PORTE_6_SAIDA

#elif (_LCD_CONTROLE_PINO_RS  == _PORTE_7)
    #ifdef _PORTE_7_DIGITAL
        #define _LCD_PINO_RS_AD               _PORTE_7_DIGITAL
    #endif
    #define _LCD_PINO_RS_WR                   _PORTE_7_WR
    #define _LCD_PINO_RS_SAIDA                _PORTE_7_SAIDA
#endif

//_LCD_CONTROLE_PINO_BACKLIGHT -----------------------------------------------
#if (_LCD_USA_BACKLIGHT == _SIM)

#if (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTA_0)
    #ifdef _PORTA_0_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTA_0_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTA_0_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTA_0_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTA_1)
    #ifdef _PORTA_1_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTA_1_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTA_1_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTA_1_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTA_2)
    #ifdef _PORTA_2_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTA_2_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTA_2_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTA_2_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTA_3)
    #ifdef _PORTA_3_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTA_3_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTA_3_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTA_3_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTA_4)
    #ifdef _PORTA_4_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTA_4_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTA_4_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTA_4_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTA_5)
    #ifdef _PORTA_5_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTA_5_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTA_5_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTA_5_SAIDA

#elif(_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTA_6)
    #ifdef _PORTA_6_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTA_6_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTA_6_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTA_6_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTA_7)
    #ifdef _PORTA_7_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTA_7_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTA_7_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTA_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTB_0)
    #ifdef _PORTB_0_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTB_0_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTB_0_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTB_0_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTB_1)
    #ifdef _PORTB_1_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTB_1_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTB_1_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTB_1_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTB_2)
    #ifdef _PORTB_2_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTB_2_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTB_2_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTB_2_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTB_3)
    #ifdef _PORTB_3_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTB_3_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTB_3_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTB_3_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTB_4)
    #ifdef _PORTB_4_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTB_4_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTB_4_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTB_4_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTB_5)
    #ifdef _PORTB_5_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTB_5_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTB_5_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTB_5_SAIDA

#elif(_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTB_6)
    #ifdef _PORTB_6_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTB_6_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTB_6_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTB_6_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTB_7)
    #ifdef _PORTB_7_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTB_7_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTB_7_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTB_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTC_0)
    #ifdef _PORTC_0_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTC_0_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTC_0_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTC_0_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTC_1)
    #ifdef _PORTC_1_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTC_1_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTC_1_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTC_1_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTC_2)
    #ifdef _PORTC_2_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTC_2_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTC_2_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTC_2_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTC_3)
    #ifdef _PORTC_3_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTC_3_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTC_3_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTC_3_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTC_4)
    #ifdef _PORTC_4_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTC_4_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTC_4_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTC_4_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTC_5)
    #ifdef _PORTC_5_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTC_5_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTC_5_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTC_5_SAIDA

#elif(_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTC_6)
    #ifdef _PORTC_6_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTC_6_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTC_6_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTC_6_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTC_7)
    #ifdef _PORTC_7_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTC_7_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTC_7_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTC_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTD_0)
    #ifdef _PORTD_0_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTD_0_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTD_0_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTD_0_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTD_1)
    #ifdef _PORTD_1_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTD_1_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTD_1_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTD_1_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTD_2)
    #ifdef _PORTD_2_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTD_2_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTD_2_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTD_2_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTD_3)
    #ifdef _PORTD_3_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTD_3_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTD_3_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTD_3_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTD_4)
    #ifdef _PORTD_4_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTD_4_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTD_4_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTD_4_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTD_5)
    #ifdef _PORTD_5_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTD_5_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTD_5_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTD_5_SAIDA

#elif(_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTD_6)
    #ifdef _PORTD_6_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTD_6_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTD_6_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTD_6_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTD_7)
    #ifdef _PORTD_7_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTD_7_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTD_7_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTD_7_SAIDA
#endif


#if (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTE_0)
    #ifdef _PORTE_0_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTE_0_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTE_0_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTE_0_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTE_1)
    #ifdef _PORTE_1_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTE_1_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTE_1_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTE_1_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTE_2)
    #ifdef _PORTE_2_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTE_2_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTE_2_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTE_2_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTE_3)
    #ifdef _PORTE_3_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTE_3_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTE_3_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTE_3_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTE_4)
    #ifdef _PORTE_4_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTE_4_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTE_4_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTE_4_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTE_5)
    #ifdef _PORTE_5_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTE_5_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTE_5_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTE_5_SAIDA

#elif(_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTE_6)
    #ifdef _PORTE_6_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTE_6_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTE_6_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTE_6_SAIDA

#elif (_LCD_CONTROLE_PINO_BACKLIGHT  == _PORTE_7)
    #ifdef _PORTE_7_DIGITAL
        #define _LCD_PINO_BACKLIGHT_AD               _PORTE_7_DIGITAL
    #endif
    #define _LCD_PINO_BACKLIGHT_WR                   _PORTE_7_WR
    #define _LCD_PINO_BACKLIGHT_SAIDA                _PORTE_7_SAIDA
#endif
#endif


#if (_LCD_NUMERO_DE_LINHAS == 1)
    #define _LCD_LINHA1
#elif (_LCD_NUMERO_DE_LINHAS == 2)
    #define _LCD_LINHA1
    #define _LCD_LINHA2
#elif (_LCD_NUMERO_DE_LINHAS == 4)
    #define _LCD_LINHA1
    #define _LCD_LINHA2
    #define _LCD_LINHA3
    #define _LCD_LINHA4
#endif



//Estruturas do modulo --------------------------------------------------------

typedef struct
{
    union 
    {
        Uchar   valor;

        struct
        {
            Uint :2;
            Uint F:1;
            Uint N:1;        
            Uint DL:1; 
            Uint id:1;        
            Uint :2;    
        };
    }Interface;
    
    union
    {
        Uchar   valor;

        struct
        {
            Uint SH:1;
            Uint ID:1;
            Uint id:1;        
            Uint :5;    
        };
    }ModoDeEntrada;    

    union
    {
        Uchar   valor;

        struct
        {
            Uint B:1;
            Uint C:1;
            Uint D:1;
            Uint id:1;        
            Uint :4;    
        };
    }Controle;

    union
    {
        Uchar   valor;

        struct
        {
            Uint :2;  
            Uint RL:1;
            Uint SC:1;
            Uint id:1;        
            Uint :3;    
        };
    }Deslocamento;

    
    #ifdef _LCD_LINHA1
        Uchar BufferLinha1[_LCD_NUMERO_DE_COLUNAS];
    #endif
    
    #ifdef _LCD_LINHA2
        Uchar BufferLinha2[_LCD_NUMERO_DE_COLUNAS];
    #endif    
    
    #ifdef _LCD_LINHA3
        Uchar BufferLinha3[_LCD_NUMERO_DE_COLUNAS];
    #endif
        
    #ifdef _LCD_LINHA4
        Uchar BufferLinha4[_LCD_NUMERO_DE_COLUNAS];
    #endif        

   
    struct
    {
        Uint   IntermitenciaLigada:1;
        Uint   IntermitenciaEvento:1;
        Uint   BackLightEvento1s:1;        
    }Sinais;

#if (_LCD_USA_BACKLIGHT == _SIM) && (_LCD_MODO_GREEN == _SIM)    
    struct
    {
        unsigned int    Tempo;
    }Backlight;
#endif
}_CtrlDisplay;



//Publicação das funções do módulo---------------------------------------------
void Lcd_Inicializacao(void);
void Lcd_LimpaBuffer (unsigned char Linha);
void Lcd_LimpaBuffers (void);
void Lcd_AtualizaDisplay (unsigned char Linha);
void Lcd_TransfereMensagemParaBuffer (Uchar Linha, Uchar Coluna,\
                                      const char *Mensagem);


void Lcd_LigaDisplay (void);
void Lcd_DesligaDisplay (void);
void Lcd_LimpaDisplay (void);
void Lcd_LigaCursor (void);
void Lcd_DesligaCursor (void);
void Lcd_LigaBlank (void);
void Lcd_DesligaBlank (void);
void Lcd_AtualizaIntermitencia(void);

void Lcd_Home (void);
void Lcd_DeslocaCursorParaEsquerda (void);
void Lcd_DeslocaCursorParaDireita (void);
void Lcd_DeslocaMensagemParaEsquerda (void);
void Lcd_DeslocaMensagemParaDireita (void);


#if (_LCD_USA_BACKLIGHT == _SIM)
void Lcd_InicializaBackLigth (void);
void Lcd_LigaBackLight (void);
void Lcd_DesligaBackLight (void);
void Lcd_LigaEventoBackLight (void);
void Lcd_ModoGreenRefresh (void);
#endif



//Funções da CGRAM ------------------------------------------------------------
#if (_LCD_FUNCOES_CGRAM == _SIM)

#define CGRAM_0         0
#define CGRAM_1         15
#define CGRAM_2         23
#define CGRAM_3         31
#define CGRAM_4         39
#define CGRAM_5         47
#define CGRAM_6         55
#define CGRAM_7         63


//Caracteres
#define _0_MINUSCULO   const char _0MIN[] = {0x00,0x00,0x0E,0x0A,\
                                             0x0A,0x0A,0x0E,0x00}
                                         
#define _1_MINUSCULO   const char _1MIN[] = {0x00,0x00,0x0C,0x04,\
                                             0x04,0x04,0x0E,0x00}                                         
                                         
#define _2_MINUSCULO   const char _2MIN[] = {0x00,0x00,0x0E,0x02,\
                                             0x0E,0x08,0x0E,0x00}  
                                             
                                             
#define _3_MINUSCULO   const char _3MIN[] = {0x00,0x00,0x0E,0x02,\
                                             0x0E,0x02,0x0E,0x00}                                               
                                             
                                             
#define _4_MINUSCULO   const char _4MIN[] = {0x00,0x00,0x0A,0x0A,\
                                             0x0E,0x02,0x02,0x00}                                             
                                             
#define _5_MINUSCULO   const char _5MIN[] = {0x00,0x00,0x0E,0x08,\
                                             0x0E,0x02,0x0E,0x00}                                               

#define _6_MINUSCULO   const char _6MIN[] = {0x00,0x00,0x0E,0x08,\
                                             0x0E,0x0A,0x0E,0x00}   

#define _7_MINUSCULO   const char _7MIN[] = {0x00,0x00,0x0E,0x02,\
                                             0x02,0x02,0x02,0x00}   

#define _8_MINUSCULO   const char _8MIN[] = {0x00,0x00,0x0E,0x0A,\
                                             0x0E,0x0A,0x0E,0x00}   

#define _9_MINUSCULO   const char _9MIN[] = {0x00,0x00,0x0E,0x0A,\
                                             0x0E,0x02,0x0E,0x00}   

//Publicação das funções da CGRAM ---------------------------------------------
void Lcd_CriaCaractereNaCGRAM (Uchar Local, Uchar *Caractere);

#endif




//Funções de exibição de data e horas -----------------------------------------
#if (_LCD_FUNCOES_RELOGIO == _SIM)
#include "Relogio.h"

//Modos de Exibição de horario
#define _HM                     0
#define _HMS                    1


//Modos de Exibição de Data
#define _DM                     0
#define _DMA                    1
#define _DMAA                   2


//Publicação das funções do relogio -------------------------------------------
void Lcd_ExibeHorario (Uchar Linha, Uchar Coluna,_Horario *Horario, Uchar Formato);
void Lcd_ExibeData (Uchar Linha, Uchar Coluna, _Data *Data, Uchar Formato);
void Lcd_ExibeDiaDaSemana (Uchar Linha, Uchar Coluna, Uchar DiaDaSemana);
#endif



//Publicação das variaveis do módulo -----------------------------------------



#endif	/* LCD_H */

