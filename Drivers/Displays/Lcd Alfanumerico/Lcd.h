/* 
 * Arquivo: Lcd.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef LCD_H
#define	LCD_H

#include "Definicoes Gerais.h"
#include "Portas.h"


//Definicoes do módulo --------------------------------------------------------
#define _4bits                              4
#define _8bits                              8

#define LCD_ENDERECO_DDRAM_LINHA1           0x00
#define LCD_ENDERECO_DDRAM_LINHA2           0x40
#define LCD_ENDERECO_DDRAM_LINHA3           0x14
#define LCD_ENDERECO_DDRAM_LINHA4           0x54


#include "Lcd Config.h"

//Processamento das definicoes-------------------------------------------------
#if (LCD_INTERFACE == _4bits)

    #if (LCD_PORTA_NIBBLE == Low)

        #ifdef PortA
            #if (LCD_PORTA == PortA)
                #ifdef  PORTA_NIBBLE_LOW_DIGITAL
                #define LCD_PORTA_AD   PORTA_NIBBLE_LOW_DIGITAL
                #warning "Lcd configurado para operar no nibble Low do Port A"
                #endif

                #ifdef PORTA_NIBBLE_LOW_SAIDAS
                #define LCD_PORTA_IO    PORTA_NIBBLE_LOW_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTA_RD
                #define LCD_PORTA_WR    PORTA_WR
            #endif
        #endif

        #ifdef PortB
            #if (LCD_PORTA == PortB)
                #ifdef  PORTB_NIBBLE_LOW_DIGITAL
                #define LCD_PORTA_AD   PORTB_NIBBLE_LOW_DIGITAL
                #warning "Lcd configurado para operar no nibble Low do Port B"
                #endif

                #ifdef PORTB_NIBBLE_LOW_SAIDAS
                #define LCD_PORTA_IO    PORTB_NIBBLE_LOW_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTB_RD
                #define LCD_PORTA_WR    PORTB_WR
            #endif
        #endif

        #ifdef Portc
            #if (LCD_PORTA == Portc)
                #ifdef  PORTC_NIBBLE_LOW_DIGITAL
                #define LCD_PORTA_AD   PORTC_NIBBLE_LOW_DIGITAL
                #warning "Lcd configurado para operar no nibble Low do Port C"
                #endif

                #ifdef PORTC_NIBBLE_LOW_SAIDAS
                #define LCD_PORTA_IO    PORTC_NIBBLE_LOW_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTC_RD
                #define LCD_PORTA_WR    PORTC_WR
            #endif
        #endif

        #ifdef PortD
            #if (LCD_PORTA == PortD)
                #ifdef  PORTD_NIBBLE_LOW_DIGITAL
                #define LCD_PORTA_AD   PORTD_NIBBLE_LOW_DIGITAL
                #warning "Lcd configurado para operar no nibble Low do Port D"
                #endif

                #ifdef PORTD_NIBBLE_LOW_SAIDAS
                #define LCD_PORTA_IO    PORTD_NIBBLE_LOW_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTD_RD
                #define LCD_PORTA_WR    PORTD_WR
            #endif
        #endif

        #ifdef PortE
            #if (LCD_PORTA == PortE)
                #ifdef  PORTE_NIBBLE_LOW_DIGITAL
                #define LCD_PORTA_AD   PORTE_NIBBLE_LOW_DIGITAL
                #warning "Lcd configurado para operar no nibble Low do Port E"
                #endif

                #ifdef PORTE_NIBBLE_LOW_SAIDAS
                #define LCD_PORTA_IO    PORTE_NIBBLE_LOW_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTE_RD
                #define LCD_PORTA_WR    PORTE_WR
            #endif
        #endif

        #ifdef PortF
            #if (LCD_PORTA == PortF)
                #ifdef  PORTF_NIBBLE_LOW_DIGITAL
                #define LCD_PORTA_AD   PORTF_NIBBLE_LOW_DIGITAL
                #warning "Lcd configurado para operar no nibble Low do Port F"
                #endif

                #ifdef PORTF_NIBBLE_LOW_SAIDAS
                #define LCD_PORTA_IO    PORTF_NIBBLE_LOW_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTF_RD
                #define LCD_PORTA_WR    PORTF_WR
            #endif
        #endif

        #ifdef PortG
            #if (LCD_PORTA == PortG)
                #ifdef  PORTG_NIBBLE_LOW_DIGITAL
                #define LCD_PORTA_AD   PORTG_NIBBLE_LOW_DIGITAL
                #warning "Lcd configurado para operar no nibble Low do Port G"
                #endif

                #ifdef PORTG_NIBBLE_LOW_SAIDAS
                #define LCD_PORTA_IO    PORTG_NIBBLE_LOW_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTG_RD
                #define LCD_PORTA_WR    PORTG_WR
            #endif
        #endif


    #elif (LCD_PORTA_NIBBLE == High)

        #ifdef PortA
            #if (LCD_PORTA == PortA)
                #ifdef  PORTA_NIBBLE_HIGH_DIGITAL
                #define LCD_PORTA_AD   PORTA_NIBBLE_HIGH_DIGITAL
                #warning "Lcd configurado para operar no nibble High do Port A"
                #endif

                #ifdef PORTA_NIBBLE_HIGH_SAIDAS
                #define LCD_PORTA_IO    PORTA_NIBBLE_HIGH_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTA_RD
                #define LCD_PORTA_WR    PORTA_WR
            #endif
        #endif

        #ifdef PortB
            #if (LCD_PORTA == PortB)
                #ifdef  PORTB_NIBBLE_HIGH_DIGITAL
                #define LCD_PORTA_AD   PORTB_NIBBLE_HIGH_DIGITAL
                #warning "Lcd configurado para operar no nibble High do Port B"
                #endif

                #ifdef PORTB_NIBBLE_HIGH_SAIDAS
                #define LCD_PORTA_IO    PORTB_NIBBLE_HIGH_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTB_RD
                #define LCD_PORTA_WR    PORTB_WR
            #endif
        #endif

        #ifdef PortC
            #if (LCD_PORTA == PortC)
                #ifdef  PORTC_NIBBLE_HIGH_DIGITAL
                #define LCD_PORTA_AD   PORTC_NIBBLE_HIGH_DIGITAL
                #warning "Lcd configurado para operar no nibble High do Port C"
                #endif

                #ifdef PORTC_NIBBLE_HIGH_SAIDAS
                #define LCD_PORTA_IO    PORTC_NIBBLE_HIGH_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTC_RD
                #define LCD_PORTA_WR    PORTC_WR
            #endif
        #endif

        #ifdef PortD
            #if (LCD_PORTA == PortD)
                #ifdef  PORTD_NIBBLE_HIGH_DIGITAL
                #define LCD_PORTA_AD   PORTD_NIBBLE_HIGH_DIGITAL
                #warning "Lcd configurado para operar no nibble High do Port D"
                #endif

                #ifdef PORTD_NIBBLE_HIGH_SAIDAS
                #define LCD_PORTA_IO    PORTD_NIBBLE_HIGH_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTD_RD
                #define LCD_PORTA_WR    PORTD_WR
            #endif
        #endif

        #ifdef PortE
            #if (LCD_PORTA == PortE)
                #ifdef  PORTE_NIBBLE_HIGH_DIGITAL
                #define LCD_PORTA_AD   PORTE_NIBBLE_HIGH_DIGITAL
                #warning "Lcd configurado para operar no nibble High do Port E"
                #endif

                #ifdef PORTE_NIBBLE_HIGH_SAIDAS
                #define LCD_PORTA_IO    PORTE_NIBBLE_HIGH_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTE_RD
                #define LCD_PORTA_WR    PORTE_WR
            #endif
        #endif

        #ifdef PortF
            #if (LCD_PORTA == PortF)
                #ifdef  PORTF_NIBBLE_HIGH_DIGITAL
                #define LCD_PORTA_AD   PORTF_NIBBLE_HIGH_DIGITAL
                #warning "Lcd configurado para operar no nibble High do Port F"
                #endif

                #ifdef PORTF_NIBBLE_HIGH_SAIDAS
                #define LCD_PORTA_IO    PORTF_NIBBLE_HIGH_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTF_RD
                #define LCD_PORTA_WR    PORTF_WR
            #endif
        #endif

        #ifdef PortG
            #if (LCD_PORTA == PortG)
                #ifdef  PORTG_NIBBLE_HIGH_DIGITAL
                #define LCD_PORTA_AD   PORTG_NIBBLE_HIGH_DIGITAL
                #warning "Lcd configurado para operar no nibble High do Port G"
                #endif

                #ifdef PORTG_NIBBLE_HIGH_SAIDAS
                #define LCD_PORTA_IO    PORTG_NIBBLE_HIGH_SAIDAS
                #endif

                #define LCD_PORTA_RD    PORTG_RD
                #define LCD_PORTA_WR    PORTG_WR
            #endif
        #endif
    #endif


#elif (LCD_INTERFACE == _8bits)

    #ifdef PortA
        #if (LCD_PORTA == PortA)
            #ifdef  PORTA_DIGITAL 
            #define LCD_PORTA_AD   PORTA_DIGITAL
            #warning "Lcd configurado para operar no Port A"
            #endif

            #ifdef PORTA_SAIDAS
            #define LCD_PORTA_IO    PORTA_SAIDAS
            #endif

            #define LCD_PORTA_RD    PORTA_RD
            #define LCD_PORTA_WR    PORTA_WR
        #endif
    #endif

    #ifdef PortB
        #if (LCD_PORTA == PortB)
            #ifdef  PORTB_DIGITAL 
            #define LCD_PORTA_AD   PORTB_DIGITAL
            #warning "Lcd configurado para operar no Port B"
            #endif

            #ifdef PORTB_SAIDAS
            #define LCD_PORTA_IO    PORTB_SAIDAS
            #endif

            #define LCD_PORTA_RD    PORTB_RD
            #define LCD_PORTA_WR    PORTB_WR
        #endif
    #endif

    #ifdef PortC
        #if (LCD_PORTA == PortC)
            #ifdef  PORTC_DIGITAL 
            #define LCD_PORTA_AD   PORTC_DIGITAL
            #warning "Lcd configurado para operar no Port C"
            #endif

            #ifdef PORTC_SAIDAS
            #define LCD_PORTA_IO    PORTC_SAIDAS
            #endif

            #define LCD_PORTA_RD    PORTC_RD
            #define LCD_PORTA_WR    PORTC_WR
        #endif
    #endif

    #ifdef PortD
        #if (LCD_PORTA == PortD)
            #ifdef  PORTD_DIGITAL 
            #define LCD_PORTA_AD   PORTD_DIGITAL
            #warning "Lcd configurado para operar no Port D"
            #endif

            #ifdef PORTD_SAIDAS
            #define LCD_PORTA_IO    PORTD_SAIDAS
            #endif

            #define LCD_PORTA_RD    PORTD_RD
            #define LCD_PORTA_WR    PORTD_WR
        #endif
    #endif

    #ifdef PortE
        #if (LCD_PORTA == PortE)
            #ifdef  PORTE_DIGITAL 
            #define LCD_PORTA_AD   PORTE_DIGITAL
            #warning "Lcd configurado para operar no Port E"
            #endif

            #ifdef PORTE_SAIDAS
            #define LCD_PORTA_IO    PORTE_SAIDAS
            #endif

            #define LCD_PORTA_RD    PORTE_RD
            #define LCD_PORTA_WR    PORTE_WR
        #endif
    #endif

    #ifdef PortF
        #if (LCD_PORTA == PortF)
            #ifdef  PORTF_DIGITAL 
            #define LCD_PORTA_AD   PORTF_DIGITAL 
            #warning "Lcd configurado para operar no Port F"
            #endif

            #ifdef PORTF_SAIDAS
            #define LCD_PORTA_IO    PORTF_SAIDAS
            #endif

            #define LCD_PORTA_RD    PORTF_RD
            #define LCD_PORTA_WR    PORTF_WR
        #endif
    #endif

    #ifdef PortG
        #if (LCD_PORTA == PortG)
            #ifdef  PORTG_DIGITAL 
            #define LCD_PORTA_AD   PORTG_DIGITAL
            #warning "Lcd configurado para operar no Port G"
            #endif

            #ifdef PORTG_SAIDAS
            #define LCD_PORTA_IO    PORTG_SAIDAS
            #endif

            #define LCD_PORTA_RD    PORTG_RD
            #define LCD_PORTA_WR    PORTG_WR
        #endif
    #endif
#endif



//LCD_PINO_ENABLE -------------------------------------------------------------
#ifdef PortA
    #ifdef PinRA0
        #if (LCD_PINO_ENABLE  == PinRA0)
            #warning "Lcd: Pino Enable controlado pelo pino RA0"

            #ifdef RA0_AD
                #define LCD_PINO_ENABLE_AD      RA0_AD
            #endif

            #ifdef RA0_WR
                #define LCD_PINO_ENABLE_IO          RA0_IO          
                #define LCD_PINO_ENABLE_WR          RA0_WR
            #endif
        #endif
    #endif

    #ifdef PinRA1
        #if (LCD_PINO_ENABLE == PinRA1)
            #warning "Lcd: Pino Enable controlado pelo pino RA1"

            #ifdef RA1_AD
                #define LCD_PINO_ENABLE_AD          RA1_AD
            #endif

            #ifdef RA1_WR
                #define LCD_PINO_ENABLE_IO          RA1_IO          
                #define LCD_PINO_ENABLE_WR          RA1_WR
            #endif
        #endif
    #endif

    #ifdef PinRA2
        #if (LCD_PINO_ENABLE == PinRA2)
            #warning "Lcd: Pino Enable controlado pelo pino RA2"

            #ifdef RA2_AD
                #define LCD_PINO_ENABLE_AD      RA2_AD
            #endif

            #ifdef RA2_WR
                #define LCD_PINO_ENABLE_IO          RA2_IO          
                #define LCD_PINO_ENABLE_WR          RA2_WR
            #endif
        #endif
    #endif

    #ifdef PinRA3
        #if (LCD_PINO_ENABLE == PinRA3)
            #warning "Lcd: Pino Enable controlado pelo pino RA3"

            #ifdef RA3_AD
                #define LCD_PINO_ENABLE_AD          RA3_AD
            #endif

            #ifdef RA3_WR
                #define LCD_PINO_ENABLE_IO          RA3_IO          
                #define LCD_PINO_ENABLE_WR          RA3_WR
            #endif
        #endif
    #endif

    #ifdef PinRA4
        #if (LCD_PINO_ENABLE == PinRA4)
            #warning "Lcd: Pino Enable controlado pelo pino RA4"

            #ifdef RA4_AD
                #define LCD_PINO_ENABLE_AD          RA4_AD
            #endif

            #ifdef RA4_WR
                #define LCD_PINO_ENABLE_IO          RA4_IO          
                #define LCD_PINO_ENABLE_WR          RA4_WR
            #endif
        #endif
    #endif

    #ifdef PinRA5
        #if (LCD_PINO_ENABLE == PinRA5)
            #warning "Lcd: Pino Enable controlado pelo pino RA5"

            #ifdef RA5_AD
                #define LCD_PINO_ENABLE_AD          RA5_AD
            #endif

            #ifdef RA5_WR
                #define LCD_PINO_ENABLE_IO          RA5_IO          
                #define LCD_PINO_ENABLE_WR          RA5_WR
            #endif
        #endif
    #endif

    #ifdef PinRA6
        #if (LCD_PINO_ENABLE == PinRA6)
            #warning "Lcd: Pino Enable controlado pelo pino RA6"

            #ifdef RA6_AD
                #define LCD_PINO_ENABLE_AD          RA6_AD
            #endif

            #ifdef RA6_WR
                #define LCD_PINO_ENABLE_IO          RA6_IO          
                #define LCD_PINO_ENABLE_WR          RA6_WR
            #endif
        #endif
    #endif

    #ifdef PinRA7
        #if (LCD_PINO_ENABLE == PinRA7)
            #warning "Lcd: Pino Enable controlado pelo pino RA7"

            #ifdef RA7_AD
                #define LCD_PINO_ENABLE_AD          RA7_AD
            #endif

            #ifdef RA7_WR
                #define LCD_PINO_ENABLE_IO          RA7_IO          
                #define LCD_PINO_ENABLE_WR          RA7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortB
    #ifdef PinRB0
        #if (LCD_PINO_ENABLE  == PinRB0)
            #warning "Lcd: Pino Enable controlado pelo pino RB0"

            #ifdef RB0_AD
                #define LCD_PINO_ENABLE_AD          RB0_AD
            #endif

            #ifdef RB0_WR
                #define LCD_PINO_ENABLE_IO          RB0_IO          
                #define LCD_PINO_ENABLE_WR          RB0_WR
            #endif
        #endif
    #endif

    #ifdef PinRB1
        #if (LCD_PINO_ENABLE == PinRB1)
            #warning "Lcd: Pino Enable controlado pelo pino RB1"
            #ifdef RB1_AD
                #define LCD_PINO_ENABLE_AD          RB1_AD
            #endif

            #ifdef RB1_WR
                #define LCD_PINO_ENABLE_IO          RB1_IO          
                #define LCD_PINO_ENABLE_WR          RB1_WR
            #endif
        #endif
    #endif

    #ifdef PinRB2
        #if (LCD_PINO_ENABLE == PinRB2)
            #warning "Lcd: Pino Enable controlado pelo pino RB2"

            #ifdef RB2_AD
                #define LCD_PINO_ENABLE_AD          RB2_AD
            #endif

            #ifdef RB2_WR
                #define LCD_PINO_ENABLE_IO          RB2_IO          
                #define LCD_PINO_ENABLE_WR          RB2_WR
            #endif
        #endif
    #endif

    #ifdef PinRB3
        #if (LCD_PINO_ENABLE == PinRB3)
            #warning "Lcd: Pino Enable controlado pelo pino RB3"

            #ifdef RB3_AD
                #define LCD_PINO_ENABLE_AD          RB3_AD
            #endif

            #ifdef RB3_WR
                #define LCD_PINO_ENABLE_IO          RB3_IO          
                #define LCD_PINO_ENABLE_WR          RB3_WR
            #endif
        #endif
    #endif

    #ifdef PinRB4
        #if (LCD_PINO_ENABLE == PinRB4)
            #warning "Lcd: Pino Enable controlado pelo pino RB4"
            #ifdef RB4_AD
                #define LCD_PINO_ENABLE_AD          RB4_AD
            #endif

            #ifdef RB4_WR
                #define LCD_PINO_ENABLE_IO          RB4_IO          
                #define LCD_PINO_ENABLE_WR          RB4_WR
            #endif
        #endif
    #endif

    #ifdef PinRB5
        #if (LCD_PINO_ENABLE == PinRB5)
            #warning "Lcd: Pino Enable controlado pelo pino RB5"

            #ifdef RB5_AD
                #define LCD_PINO_ENABLE_AD          RB5_AD
            #endif

            #ifdef RB5_WR
                #define LCD_PINO_ENABLE_IO          RB5_IO          
                #define LCD_PINO_ENABLE_WR          RB5_WR
            #endif
        #endif
    #endif

    #ifdef PinRB6
        #if (LCD_PINO_ENABLE == PinRB6)
            #warning "Lcd: Pino Enable controlado pelo pino RB6"

            #ifdef RB6_AD
                #define LCD_PINO_ENABLE_AD          RB6_AD
            #endif

            #ifdef RB6_WR
                #define LCD_PINO_ENABLE_IO          RB6_IO          
                #define LCD_PINO_ENABLE_WR          RB6_WR
            #endif
        #endif
    #endif

    #ifdef PinRB7
        #if (LCD_PINO_ENABLE == PinRB7)
            #warning "Lcd: Pino Enable controlado pelo pino RB7"

            #ifdef RB7_AD
                #define LCD_PINO_ENABLE_AD          RB7_AD
            #endif

            #ifdef RB7_WR
                #define LCD_PINO_ENABLE_IO          RB7_IO          
                #define LCD_PINO_ENABLE_WR          RB7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortC
    #ifdef PinRC0
        #if (LCD_PINO_ENABLE  == PinRC0)
            #warning "Lcd: Pino Enable controlado pelo pino RC0"

            #ifdef RC0_AD
                #define LCD_PINO_ENABLE_AD          RC0_AD
            #endif

            #ifdef RC0_WR
                #define LCD_PINO_ENABLE_IO          RC0_IO          
                #define LCD_PINO_ENABLE_WR          RC0_WR
            #endif
        #endif
    #endif

    #ifdef PinRC1
        #if (LCD_PINO_ENABLE == PinRC1)
            #warning "Lcd: Pino Enable controlado pelo pino RC1"
            #ifdef RC1_AD
                #define LCD_PINO_ENABLE_AD          RC1_AD
            #endif

            #ifdef RC1_WR
                #define LCD_PINO_ENABLE_IO          RC1_IO          
                #define LCD_PINO_ENABLE_WR          RC1_WR
            #endif
        #endif
    #endif

    #ifdef PinRC2
        #if (LCD_PINO_ENABLE == PinRC2)
            #warning "Lcd: Pino Enable controlado pelo pino RC2"

            #ifdef RC2_AD
                #define LCD_PINO_ENABLE_AD          RC2_AD
            #endif

            #ifdef RC2_WR
                #define LCD_PINO_ENABLE_IO          RC2_IO          
                #define LCD_PINO_ENABLE_WR          RC2_WR
            #endif
        #endif
    #endif

    #ifdef PinRC3
        #if (LCD_PINO_ENABLE == PinRC3)
            #warning "Lcd: Pino Enable controlado pelo pino RC3"

            #ifdef RC3_AD
                #define LCD_PINO_ENABLE_AD          RC3_AD
            #endif

            #ifdef RC3_WR
                #define LCD_PINO_ENABLE_IO          RC3_IO          
                #define LCD_PINO_ENABLE_WR          RC3_WR
            #endif
        #endif
    #endif

    #ifdef PinRC4
        #if (LCD_PINO_ENABLE == PinRC4)
            #warning "Lcd: Pino Enable controlado pelo pino RC4"
            #ifdef RC4_AD
                #define LCD_PINO_ENABLE_AD          RC4_AD
            #endif

            #ifdef RC4_WR
                #define LCD_PINO_ENABLE_IO          RC4_IO          
                #define LCD_PINO_ENABLE_WR          RC4_WR
            #endif
        #endif
    #endif

    #ifdef PinRC5
        #if (LCD_PINO_ENABLE == PinRC5)
            #warning "Lcd: Pino Enable controlado pelo pino RC5"

            #ifdef RC5_AD
                #define LCD_PINO_ENABLE_AD          RC5_AD
            #endif

            #ifdef RC5_WR
                #define LCD_PINO_ENABLE_IO          RC5_IO          
                #define LCD_PINO_ENABLE_WR          RC5_WR
            #endif
        #endif
    #endif

    #ifdef PinRC6
        #if (LCD_PINO_ENABLE == PinRC6)
            #warning "Lcd: Pino Enable controlado pelo pino RC6"

            #ifdef RC6_AD
                #define LCD_PINO_ENABLE_AD          RC6_AD
            #endif

            #ifdef RC6_WR
                #define LCD_PINO_ENABLE_IO          RC6_IO          
                #define LCD_PINO_ENABLE_WR          RC6_WR
            #endif
        #endif
    #endif

    #ifdef PinRC7
        #if (LCD_PINO_ENABLE == PinRC7)
            #warning "Lcd: Pino Enable controlado pelo pino RC7"

            #ifdef RC7_AD
                #define LCD_PINO_ENABLE_AD          RC7_AD
            #endif

            #ifdef RC7_WR
                #define LCD_PINO_ENABLE_IO          RC7_IO          
                #define LCD_PINO_ENABLE_WR          RC7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortD
    #ifdef PinRD0
        #if (LCD_PINO_ENABLE  == PinRD0)
            #warning "Lcd: Pino Enable controlado pelo pino RD0"

            #ifdef RD0_AD
                #define LCD_PINO_ENABLE_AD          RD0_AD
            #endif

            #ifdef RD0_WR
                #define LCD_PINO_ENABLE_IO          RD0_IO          
                #define LCD_PINO_ENABLE_WR          RD0_WR
            #endif
        #endif
    #endif

    #ifdef PinRD1
        #if (LCD_PINO_ENABLE == PinRD1)
            #warning "Lcd: Pino Enable controlado pelo pino RD1"
            #ifdef RD1_AD
                #define LCD_PINO_ENABLE_AD          RD1_AD
            #endif

            #ifdef RD1_WR
                #define LCD_PINO_ENABLE_IO          RD1_IO          
                #define LCD_PINO_ENABLE_WR          RD1_WR
            #endif
        #endif
    #endif

    #ifdef PinRD2
        #if (LCD_PINO_ENABLE == PinRD2)
            #warning "Lcd: Pino Enable controlado pelo pino RD2"

            #ifdef RD2_AD
                #define LCD_PINO_ENABLE_AD          RD2_AD
            #endif

            #ifdef RD2_WR
                #define LCD_PINO_ENABLE_IO          RD2_IO          
                #define LCD_PINO_ENABLE_WR          RD2_WR
            #endif
        #endif
    #endif

    #ifdef PinRD3
        #if (LCD_PINO_ENABLE == PinRD3)
            #warning "Lcd: Pino Enable controlado pelo pino RD3"

            #ifdef RD3_AD
                #define LCD_PINO_ENABLE_AD          RD3_AD
            #endif

            #ifdef RD3_WR
                #define LCD_PINO_ENABLE_IO          RD3_IO          
                #define LCD_PINO_ENABLE_WR          RD3_WR
            #endif
        #endif
    #endif

    #ifdef PinRD4
        #if (LCD_PINO_ENABLE == PinRD4)
            #warning "Lcd: Pino Enable controlado pelo pino RD4"
            #ifdef RD4_AD
                #define LCD_PINO_ENABLE_AD          RD4_AD
            #endif

            #ifdef RD4_WR
                #define LCD_PINO_ENABLE_IO          RD4_IO          
                #define LCD_PINO_ENABLE_WR          RD4_WR
            #endif
        #endif
    #endif

    #ifdef PinRD5
        #if (LCD_PINO_ENABLE == PinRD5)
            #warning "Lcd: Pino Enable controlado pelo pino RD5"

            #ifdef RD5_AD
                #define LCD_PINO_ENABLE_AD          RD5_AD
            #endif

            #ifdef RD5_WR
                #define LCD_PINO_ENABLE_IO          RD5_IO          
                #define LCD_PINO_ENABLE_WR          RD5_WR
            #endif
        #endif
    #endif

    #ifdef PinRD6
        #if (LCD_PINO_ENABLE == PinRD6)
            #warning "Lcd: Pino Enable controlado pelo pino RD6"

            #ifdef RD6_AD
                #define LCD_PINO_ENABLE_AD          RD6_AD
            #endif

            #ifdef RD6_WR
                #define LCD_PINO_ENABLE_IO          RD6_IO          
                #define LCD_PINO_ENABLE_WR          RD6_WR
            #endif
        #endif
    #endif

    #ifdef PinRD7
        #if (LCD_PINO_ENABLE == PinRD7)
            #warning "Lcd: Pino Enable controlado pelo pino RD7"

            #ifdef RD7_AD
                #define LCD_PINO_ENABLE_AD          RD7_AD
            #endif

            #ifdef RD7_WR
                #define LCD_PINO_ENABLE_IO          RD7_IO          
                #define LCD_PINO_ENABLE_WR          RD7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortE
    #ifdef PinRE0
        #if (LCD_PINO_ENABLE  == PinRE0)
            #warning "Lcd: Pino Enable controlado pelo pino RE0"

            #ifdef RE0_AD
                #define LCD_PINO_ENABLE_AD          RE0_AD
            #endif

            #ifdef RE0_WR
                #define LCD_PINO_ENABLE_IO          RE0_IO          
                #define LCD_PINO_ENABLE_WR          RE0_WR
            #endif
        #endif
    #endif

    #ifdef PinRE1
        #if (LCD_PINO_ENABLE == PinRE1)
            #warning "Lcd: Pino Enable controlado pelo pino RE1"

            #ifdef RE1_AD
                #define LCD_PINO_ENABLE_AD          RE1_AD
            #endif

            #ifdef RE1_WR
                #define LCD_PINO_ENABLE_IO          RE1_IO          
                #define LCD_PINO_ENABLE_WR          RE1_WR
            #endif
        #endif
    #endif

    #ifdef PinRE2
        #if (LCD_PINO_ENABLE == PinRE2)
            #warning "Lcd: Pino Enable controlado pelo pino RE2"

            #ifdef RE2_AD
                #define LCD_PINO_ENABLE_AD          RE2_AD
            #endif

            #ifdef RE2_WR
                #define LCD_PINO_ENABLE_IO          RE2_IO          
                #define LCD_PINO_ENABLE_WR          RE2_WR
            #endif
        #endif
    #endif

    #ifdef PinRE3
        #if (LCD_PINO_ENABLE == PinRE3)
            #warning "Lcd: Pino Enable controlado pelo pino RE3"

            #ifdef RE3_AD
                #define LCD_PINO_ENABLE_AD          RE3_AD
            #endif

            #ifdef RE3_WR
                #define LCD_PINO_ENABLE_IO          RE3_IO          
                #define LCD_PINO_ENABLE_WR          RE3_WR
            #endif
        #endif
    #endif

    #ifdef PinRE4
        #if (LCD_PINO_ENABLE == PinRE4)
            #warning "Lcd: Pino Enable controlado pelo pino RE4"
            #ifdef RE4_AD
                #define LCD_PINO_ENABLE_AD          RE4_AD
            #endif

            #ifdef RE4_WR
                #define LCD_PINO_ENABLE_IO          RE4_IO          
                #define LCD_PINO_ENABLE_WR          RE4_WR
            #endif
        #endif
    #endif

    #ifdef PinRE5
        #if (LCD_PINO_ENABLE == PinRE5)
            #warning "Lcd: Pino Enable controlado pelo pino RE5"

            #ifdef RE5_AD
                #define LCD_PINO_ENABLE_AD          RE5_AD
            #endif

            #ifdef RE5_WR
                #define LCD_PINO_ENABLE_IO          RE5_IO          
                #define LCD_PINO_ENABLE_WR          RE5_WR
            #endif
        #endif
    #endif

    #ifdef PinRE6
        #if (LCD_PINO_ENABLE == PinRE6)
            #warning "Lcd: Pino Enable controlado pelo pino RE6"

            #ifdef RE6_AD
                #define LCD_PINO_ENABLE_AD          RE6_AD
            #endif

            #ifdef RE6_WR
                #define LCD_PINO_ENABLE_IO          RE6_IO          
                #define LCD_PINO_ENABLE_WR          RE6_WR
            #endif
        #endif
    #endif

    #ifdef PinRE7
        #if (LCD_PINO_ENABLE == PinRE7)
            #warning "Lcd: Pino Enable controlado pelo pino RE7"

            #ifdef RE7_AD
                #define LCD_PINO_ENABLE_AD          RE7_AD
            #endif

            #ifdef RE7_WR
                #define LCD_PINO_ENABLE_IO          RE7_IO          
                #define LCD_PINO_ENABLE_WR          RE7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortF
    #ifdef PinRF0
        #if (LCD_PINO_ENABLE  == PinRF0)
            #warning "Lcd: Pino Enable controlado pelo pino RF0"

            #ifdef RF0_AD
                #define LCD_PINO_ENABLE_AD          RF0_AD
            #endif

            #ifdef RF0_WR
                #define LCD_PINO_ENABLE_IO          RF0_IO          
                #define LCD_PINO_ENABLE_WR          RF0_WR
            #endif
        #endif
    #endif

    #ifdef PinRF1
        #if (LCD_PINO_ENABLE == PinRF1)
            #warning "Lcd: Pino Enable controlado pelo pino RF1"
            #ifdef RF1_AD
                #define LCD_PINO_ENABLE_AD          RF1_AD
            #endif

            #ifdef RF1_WR
                #define LCD_PINO_ENABLE_IO          RF1_IO          
                #define LCD_PINO_ENABLE_WR          RF1_WR
            #endif
        #endif
    #endif

    #ifdef PinRF2
        #if (LCD_PINO_ENABLE == PinRF2)
            #warning "Lcd: Pino Enable controlado pelo pino RF2"

            #ifdef RF2_AD
                #define LCD_PINO_ENABLE_AD      RF2_AD
            #endif

            #ifdef RF2_WR
            #define LCD_PINO_ENABLE_IO          RF2_IO          
            #define LCD_PINO_ENABLE_WR          RF2_WR
            #endif
        #endif
    #endif

    #ifdef PinRF3
        #if (LCD_PINO_ENABLE == PinRF3)
            #warning "Lcd: Pino Enable controlado pelo pino RF3"

            #ifdef RF3_AD
                #define LCD_PINO_ENABLE_AD          RF3_AD
            #endif

            #ifdef RF3_WR
                #define LCD_PINO_ENABLE_IO          RF3_IO          
                #define LCD_PINO_ENABLE_WR          RF3_WR
            #endif
        #endif
    #endif

    #ifdef PinRF4
        #if (LCD_PINO_ENABLE == PinRF4)
            #warning "Lcd: Pino Enable controlado pelo pino RF4"

            #ifdef RF4_AD
                #define LCD_PINO_ENABLE_AD          RF4_AD
            #endif

            #ifdef RF4_WR
                #define LCD_PINO_ENABLE_IO          RF4_IO          
                #define LCD_PINO_ENABLE_WR          RF4_WR
            #endif
        #endif
    #endif

    #ifdef PinRF5
        #if (LCD_PINO_ENABLE == PinRF5)
            #warning "Lcd: Pino Enable controlado pelo pino RF5"

            #ifdef RF5_AD
                #define LCD_PINO_ENABLE_AD          RF5_AD
            #endif

            #ifdef RF5_WR
                #define LCD_PINO_ENABLE_IO          RF5_IO          
                #define LCD_PINO_ENABLE_WR          RF5_WR
            #endif
        #endif
    #endif

    #ifdef PinRF6
        #if (LCD_PINO_ENABLE == PinRF6)
            #warning "Lcd: Pino Enable controlado pelo pino RF6"

            #ifdef RF6_AD
                #define LCD_PINO_ENABLE_AD          RF6_AD
            #endif

            #ifdef RF6_WR
                #define LCD_PINO_ENABLE_IO          RF6_IO          
                #define LCD_PINO_ENABLE_WR          RF6_WR
            #endif
        #endif
    #endif

    #ifdef PinRF7
        #if (LCD_PINO_ENABLE == PinRF7)
            #warning "Lcd: Pino Enable controlado pelo pino RF7"

            #ifdef RF7_AD
                #define LCD_PINO_ENABLE_AD          RF7_AD
            #endif

            #ifdef RF7_WR
                #define LCD_PINO_ENABLE_IO          RF7_IO          
                #define LCD_PINO_ENABLE_WR          RF7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortG
    #ifdef PinRG0
        #if (LCD_PINO_ENABLE  == PinRG0)
            #warning "Lcd: Pino Enable controlado pelo pino RG0"

            #ifdef RG0_AD
                #define LCD_PINO_ENABLE_AD          RG0_AD
            #endif

            #ifdef RG0_WR
                #define LCD_PINO_ENABLE_IO          RG0_IO          
                #define LCD_PINO_ENABLE_WR          RG0_WR
            #endif
        #endif
    #endif

    #ifdef PinRG1
        #if (LCD_PINO_ENABLE == PinRG1)
            #warning "Lcd: Pino Enable controlado pelo pino RG1"
            #ifdef RG1_AD
                #define LCD_PINO_ENABLE_AD          RG1_AD
            #endif

            #ifdef RG1_WR
                #define LCD_PINO_ENABLE_IO          RG1_IO          
                #define LCD_PINO_ENABLE_WR          RG1_WR
            #endif
        #endif
    #endif

    #ifdef PinRG2
        #if (LCD_PINO_ENABLE == PinRG2)
            #warning "Lcd: Pino Enable controlado pelo pino RG2"

            #ifdef RG2_AD
                #define LCD_PINO_ENABLE_AD          RG2_AD
            #endif

            #ifdef RG2_WR
                #define LCD_PINO_ENABLE_IO          RG2_IO          
                #define LCD_PINO_ENABLE_WR          RG2_WR
            #endif
        #endif
    #endif

    #ifdef PinRG3
        #if (LCD_PINO_ENABLE == PinRG3)
            #warning "Lcd: Pino Enable controlado pelo pino RG3"

            #ifdef RG3_AD
                #define LCD_PINO_ENABLE_AD          RG3_AD
            #endif

            #ifdef RG3_WR
                #define LCD_PINO_ENABLE_IO          RG3_IO          
                #define LCD_PINO_ENABLE_WR          RG3_WR
            #endif
        #endif
    #endif

    #ifdef PinRG4
        #if (LCD_PINO_ENABLE == PinRG4)
            #warning "Lcd: Pino Enable controlado pelo pino RG4"
            #ifdef RG4_AD
                #define LCD_PINO_ENABLE_AD          RG4_AD
            #endif

            #ifdef RG4_WR
                #define LCD_PINO_ENABLE_IO          RG4_IO          
                #define LCD_PINO_ENABLE_WR          RG4_WR
            #endif
        #endif
    #endif

    #ifdef PinRG5
        #if (LCD_PINO_ENABLE == PinRG5)
            #warning "Lcd: Pino Enable controlado pelo pino RG5"

            #ifdef RG5_AD
                #define LCD_PINO_ENABLE_AD          RG5_AD
            #endif

            #ifdef RG5_WR
                #define LCD_PINO_ENABLE_IO          RG5_IO          
                #define LCD_PINO_ENABLE_WR          RG5_WR
            #endif
        #endif
    #endif

    #ifdef PinRG6
        #if (LCD_PINO_ENABLE == PinRG6)
            #warning "Lcd: Pino Enable controlado pelo pino RG6"

            #ifdef RG6_AD
                #define LCD_PINO_ENABLE_AD          RG6_AD
            #endif

            #ifdef RG6_WR
                #define LCD_PINO_ENABLE_IO          RG6_IO          
                #define LCD_PINO_ENABLE_WR          RG6_WR
            #endif
        #endif
    #endif

    #ifdef PinRG7
        #if (LCD_PINO_ENABLE == PinRG7)
            #warning "Lcd: Pino Enable controlado pelo pino RG7"

            #ifdef RG7_AD
                #define LCD_PINO_ENABLE_AD          RG7_AD
            #endif

            #ifdef RG7_WR
                #define LCD_PINO_ENABLE_IO          RG7_IO          
                #define LCD_PINO_ENABLE_WR          RG7_WR
            #endif
        #endif
    #endif
#endif



 //LCD_PINO_RS -----------------------------------------------------------------
#ifdef PortA
    #ifdef PinRA0
        #if (LCD_PINO_RS  == PinRA0)
            #warning "Lcd: Pino RS controlado pelo pino RA0"

            #ifdef RA0_AD
                #define LCD_PINO_RS_AD          RA0_AD
            #endif

            #ifdef RA0_WR
                #define LCD_PINO_RS_IO          RA0_IO          
                #define LCD_PINO_RS_WR          RA0_WR
            #endif
        #endif
    #endif

    #ifdef PinRA1
        #if (LCD_PINO_RS == PinRA1)
            #warning "Lcd: Pino RS controlado pelo pino RA1"

            #ifdef RA1_AD
                #define LCD_PINO_RS_AD          RA1_AD
            #endif

            #ifdef RA1_WR
                #define LCD_PINO_RS_IO          RA1_IO          
                #define LCD_PINO_RS_WR          RA1_WR
            #endif
        #endif
    #endif

    #ifdef PinRA2
        #if (LCD_PINO_RS == PinRA2)
            #warning "Lcd: Pino RS controlado pelo pino RA2"

            #ifdef RA2_AD
                #define LCD_PINO_RS_AD          RA2_AD
            #endif

            #ifdef RA2_WR
                #define LCD_PINO_RS_IO          RA2_IO          
                #define LCD_PINO_RS_WR          RA2_WR
            #endif
        #endif
    #endif

    #ifdef PinRA3
        #if (LCD_PINO_RS == PinRA3)
            #warning "Lcd: Pino RS controlado pelo pino RA3"

            #ifdef RA3_AD
                #define LCD_PINO_RS_AD          RA3_AD
            #endif

            #ifdef RA3_WR
                #define LCD_PINO_RS_IO          RA3_IO          
                #define LCD_PINO_RS_WR          RA3_WR
            #endif
        #endif
    #endif

    #ifdef PinRA4
        #if (LCD_PINO_RS == PinRA4)
            #warning "Lcd: Pino RS controlado pelo pino RA4"

            #ifdef RA4_AD
                #define LCD_PINO_RS_AD          RA4_AD
            #endif

            #ifdef RA4_WR
                #define LCD_PINO_RS_IO          RA4_IO          
                #define LCD_PINO_RS_WR          RA4_WR
            #endif
        #endif
    #endif

    #ifdef PinRA5
        #if (LCD_PINO_RS == PinRA5)
            #warning "Lcd: Pino RS controlado pelo pino RA5"

            #ifdef RA5_AD
                #define LCD_PINO_RS_AD          RA5_AD
            #endif

            #ifdef RA5_WR
                #define LCD_PINO_RS_IO          RA5_IO          
                #define LCD_PINO_RS_WR          RA5_WR
            #endif
        #endif
    #endif

    #ifdef PinRA6
        #if (LCD_PINO_RS == PinRA6)
            #warning "Lcd: Pino RS controlado pelo pino RA6"

            #ifdef RA6_AD
                #define LCD_PINO_RS_AD          RA6_AD
            #endif

            #ifdef RA6_WR
                #define LCD_PINO_RS_IO          RA6_IO          
                #define LCD_PINO_RS_WR          RA6_WR
            #endif
        #endif
    #endif

    #ifdef PinRA7
        #if (LCD_PINO_RS == PinRA7)
            #warning "Lcd: Pino RS controlado pelo pino RA7"

            #ifdef RA7_AD
                #define LCD_PINO_RS_AD          RA7_AD
            #endif

            #ifdef RA7_WR
                #define LCD_PINO_RS_IO          RA7_IO          
                #define LCD_PINO_RS_WR          RA7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortB
    #ifdef PinRB0
        #if (LCD_PINO_RS  == PinRB0)
            #warning "Lcd: Pino RS controlado pelo pino RB0"

            #ifdef RB0_AD
                #define LCD_PINO_RS_AD          RB0_AD
            #endif

            #ifdef RB0_WR
                #define LCD_PINO_RS_IO          RB0_IO          
                #define LCD_PINO_RS_WR          RB0_WR
            #endif
        #endif
    #endif

    #ifdef PinRB1
        #if (LCD_PINO_RS == PinRB1)
            #warning "Lcd: Pino RS controlado pelo pino RB1"
            #ifdef RB1_AD
                #define LCD_PINO_RS_AD          RB1_AD
            #endif

            #ifdef RB1_WR
                #define LCD_PINO_RS_IO          RB1_IO          
                #define LCD_PINO_RS_WR          RB1_WR
            #endif
        #endif
    #endif

    #ifdef PinRB2
        #if (LCD_PINO_RS == PinRB2)
            #warning "Lcd: Pino RS controlado pelo pino RB2"

            #ifdef RB2_AD
                #define LCD_PINO_RS_AD          RB2_AD
            #endif

            #ifdef RB2_WR
                #define LCD_PINO_RS_IO          RB2_IO          
                #define LCD_PINO_RS_WR          RB2_WR
            #endif
        #endif
    #endif

    #ifdef PinRB3
        #if (LCD_PINO_RS == PinRB3)
            #warning "Lcd: Pino RS controlado pelo pino RB3"

            #ifdef RB3_AD
                #define LCD_PINO_RS_AD          RB3_AD
            #endif

            #ifdef RB3_WR
                #define LCD_PINO_RS_IO          RB3_IO          
                #define LCD_PINO_RS_WR          RB3_WR
            #endif
        #endif
    #endif

    #ifdef PinRB4
        #if (LCD_PINO_RS == PinRB4)
            #warning "Lcd: Pino RS controlado pelo pino RB4"
            #ifdef RB4_AD
                #define LCD_PINO_RS_AD          RB4_AD
            #endif

            #ifdef RB4_WR
                #define LCD_PINO_RS_IO          RB4_IO          
                #define LCD_PINO_RS_WR          RB4_WR
            #endif
        #endif
    #endif

    #ifdef PinRB5
        #if (LCD_PINO_RS == PinRB5)
            #warning "Lcd: Pino RS controlado pelo pino RB5"

            #ifdef RB5_AD
                #define LCD_PINO_RS_AD          RB5_AD
            #endif

            #ifdef RB5_WR
                #define LCD_PINO_RS_IO          RB5_IO          
                #define LCD_PINO_RS_WR          RB5_WR
            #endif
        #endif
    #endif

    #ifdef PinRB6
        #if (LCD_PINO_RS == PinRB6)
            #warning "Lcd: Pino RS controlado pelo pino RB6"

            #ifdef RB6_AD
                #define LCD_PINO_RS_AD          RB6_AD
            #endif

            #ifdef RB6_WR
                #define LCD_PINO_RS_IO          RB6_IO          
                #define LCD_PINO_RS_WR          RB6_WR
            #endif
        #endif
    #endif

    #ifdef PinRB7
        #if (LCD_PINO_RS == PinRB7)
            #warning "Lcd: Pino RS controlado pelo pino RB7"

            #ifdef RB7_AD
                #define LCD_PINO_RS_AD          RB7_AD
            #endif

            #ifdef RB7_WR
                #define LCD_PINO_RS_IO          RB7_IO          
                #define LCD_PINO_RS_WR          RB7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortC
    #ifdef PinRC0
        #if (LCD_PINO_RS  == PinRC0)
            #warning "Lcd: Pino RS controlado pelo pino RC0"

            #ifdef RC0_AD
                #define LCD_PINO_RS_AD          RC0_AD
            #endif

            #ifdef RC0_WR
                #define LCD_PINO_RS_IO          RC0_IO          
                #define LCD_PINO_RS_WR          RC0_WR
            #endif
        #endif
    #endif

    #ifdef PinRC1
        #if (LCD_PINO_RS == PinRC1)
            #warning "Lcd: Pino RS controlado pelo pino RC1"
            #ifdef RC1_AD
                #define LCD_PINO_RS_AD          RC1_AD
            #endif

            #ifdef RC1_WR
                #define LCD_PINO_RS_IO          RC1_IO          
                #define LCD_PINO_RS_WR          RC1_WR
            #endif
        #endif
    #endif

    #ifdef PinRC2
        #if (LCD_PINO_RS == PinRC2)
            #warning "Lcd: Pino RS controlado pelo pino RC2"

            #ifdef RC2_AD
                #define LCD_PINO_RS_AD          RC2_AD
            #endif

            #ifdef RC2_WR
                #define LCD_PINO_RS_IO          RC2_IO          
                #define LCD_PINO_RS_WR          RC2_WR
            #endif
        #endif
    #endif

    #ifdef PinRC3
        #if (LCD_PINO_RS == PinRC3)
            #warning "Lcd: Pino RS controlado pelo pino RC3"

            #ifdef RC3_AD
                #define LCD_PINO_RS_AD          RC3_AD
            #endif

            #ifdef RC3_WR
                #define LCD_PINO_RS_IO          RC3_IO          
                #define LCD_PINO_RS_WR          RC3_WR
            #endif
        #endif
    #endif

    #ifdef PinRC4
        #if (LCD_PINO_RS == PinRC4)
            #warning "Lcd: Pino RS controlado pelo pino RC4"
            #ifdef RC4_AD
                #define LCD_PINO_RS_AD          RC4_AD
            #endif

            #ifdef RC4_WR
                #define LCD_PINO_RS_IO          RC4_IO          
                #define LCD_PINO_RS_WR          RC4_WR
            #endif
        #endif
    #endif

    #ifdef PinRC5
        #if (LCD_PINO_RS == PinRC5)
            #warning "Lcd: Pino RS controlado pelo pino RC5"

            #ifdef RC5_AD
                #define LCD_PINO_RS_AD          RC5_AD
            #endif

            #ifdef RC5_WR
                #define LCD_PINO_RS_IO          RC5_IO          
                #define LCD_PINO_RS_WR          RC5_WR
            #endif
        #endif
    #endif

    #ifdef PinRC6
        #if (LCD_PINO_RS == PinRC6)
            #warning "Lcd: Pino RS controlado pelo pino RC6"

            #ifdef RC6_AD
                #define LCD_PINO_RS_AD          RC6_AD
            #endif

            #ifdef RC6_WR
                #define LCD_PINO_RS_IO          RC6_IO          
                #define LCD_PINO_RS_WR          RC6_WR
            #endif
        #endif
    #endif

    #ifdef PinRC7
        #if (LCD_PINO_RS == PinRC7)
            #warning "Lcd: Pino RS controlado pelo pino RC7"

            #ifdef RC7_AD
                #define LCD_PINO_RS_AD          RC7_AD
            #endif

            #ifdef RC7_WR
                #define LCD_PINO_RS_IO          RC7_IO          
                #define LCD_PINO_RS_WR          RC7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortD
    #ifdef PinRD0
        #if (LCD_PINO_RS  == PinRD0)
            #warning "Lcd: Pino RS controlado pelo pino RD0"

            #ifdef RD0_AD
                #define LCD_PINO_RS_AD          RD0_AD
            #endif

            #ifdef RD0_WR
                #define LCD_PINO_RS_IO          RD0_IO          
                #define LCD_PINO_RS_WR          RD0_WR
            #endif
        #endif
    #endif

    #ifdef PinRD1
        #if (LCD_PINO_RS == PinRD1)
            #warning "Lcd: Pino RS controlado pelo pino RD1"
            #ifdef RD1_AD
                #define LCD_PINO_RS_AD          RD1_AD
            #endif

            #ifdef RD1_WR
                #define LCD_PINO_RS_IO          RD1_IO          
                #define LCD_PINO_RS_WR          RD1_WR
            #endif
        #endif
    #endif

    #ifdef PinRD2
        #if (LCD_PINO_RS == PinRD2)
            #warning "Lcd: Pino RS controlado pelo pino RD2"

            #ifdef RD2_AD
                #define LCD_PINO_RS_AD          RD2_AD
            #endif

            #ifdef RD2_WR
                #define LCD_PINO_RS_IO          RD2_IO          
                #define LCD_PINO_RS_WR          RD2_WR
            #endif
        #endif
    #endif

    #ifdef PinRD3
        #if (LCD_PINO_RS == PinRD3)
            #warning "Lcd: Pino RS controlado pelo pino RD3"

            #ifdef RD3_AD
                #define LCD_PINO_RS_AD          RD3_AD
            #endif

            #ifdef RD3_WR
                #define LCD_PINO_RS_IO          RD3_IO          
                #define LCD_PINO_RS_WR          RD3_WR
            #endif
        #endif
    #endif

    #ifdef PinRD4
        #if (LCD_PINO_RS == PinRD4)
            #warning "Lcd: Pino RS controlado pelo pino RD4"
            #ifdef RD4_AD
                #define LCD_PINO_RS_AD          RD4_AD
            #endif

            #ifdef RD4_WR
                #define LCD_PINO_RS_IO          RD4_IO          
                #define LCD_PINO_RS_WR          RD4_WR
            #endif
        #endif
    #endif

    #ifdef PinRD5
        #if (LCD_PINO_RS == PinRD5)
            #warning "Lcd: Pino RS controlado pelo pino RD5"

            #ifdef RD5_AD
                #define LCD_PINO_RS_AD          RD5_AD
            #endif

            #ifdef RD5_WR
                #define LCD_PINO_RS_IO          RD5_IO          
                #define LCD_PINO_RS_WR          RD5_WR
            #endif
        #endif
    #endif

    #ifdef PinRD6
        #if (LCD_PINO_RS == PinRD6)
            #warning "Lcd: Pino RS controlado pelo pino RD6"

            #ifdef RD6_AD
                #define LCD_PINO_RS_AD          RD6_AD
            #endif

            #ifdef RD6_WR
                #define LCD_PINO_RS_IO          RD6_IO          
                #define LCD_PINO_RS_WR          RD6_WR
            #endif
        #endif
    #endif

    #ifdef PinRD7
        #if (LCD_PINO_RS == PinRD7)
            #warning "Lcd: Pino RS controlado pelo pino RD7"

            #ifdef RD7_AD
                #define LCD_PINO_RS_AD          RD7_AD
            #endif

            #ifdef RD7_WR
                #define LCD_PINO_RS_IO          RD7_IO          
                #define LCD_PINO_RS_WR          RD7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortE
    #ifdef PinRE0
        #if (LCD_PINO_RS  == PinRE0)
            #warning "Lcd: Pino RS controlado pelo pino RE0"

            #ifdef RE0_AD
                #define LCD_PINO_RS_AD          RE0_AD
            #endif

            #ifdef RE0_WR
                #define LCD_PINO_RS_IO          RE0_IO          
                #define LCD_PINO_RS_WR          RE0_WR
            #endif
        #endif
    #endif

    #ifdef PinRE1
        #if (LCD_PINO_RS == PinRE1)
            #warning "Lcd: Pino RS controlado pelo pino RE1"

            #ifdef RE1_AD
                #define LCD_PINO_RS_AD          RE1_AD
            #endif

            #ifdef RE1_WR
                #define LCD_PINO_RS_IO          RE1_IO          
                #define LCD_PINO_RS_WR          RE1_WR
            #endif
        #endif
    #endif

    #ifdef PinRE2
        #if (LCD_PINO_RS == PinRE2)
            #warning "Lcd: Pino RS controlado pelo pino RE2"

            #ifdef RE2_AD
                #define LCD_PINO_RS_AD          RE2_AD
            #endif

            #ifdef RE2_WR
                #define LCD_PINO_RS_IO          RE2_IO          
                #define LCD_PINO_RS_WR          RE2_WR
            #endif
        #endif
    #endif

    #ifdef PinRE3
        #if (LCD_PINO_RS == PinRE3)
            #warning "Lcd: Pino RS controlado pelo pino RE3"

            #ifdef RE3_AD
                #define LCD_PINO_RS_AD          RE3_AD
            #endif

            #ifdef RE3_WR
                #define LCD_PINO_RS_IO          RE3_IO          
                #define LCD_PINO_RS_WR          RE3_WR
            #endif
        #endif
    #endif

    #ifdef PinRE4
        #if (LCD_PINO_RS == PinRE4)
            #warning "Lcd: Pino RS controlado pelo pino RE4"
            #ifdef RE4_AD
                #define LCD_PINO_RS_AD          RE4_AD
            #endif

            #ifdef RE4_WR
                #define LCD_PINO_RS_IO          RE4_IO          
                #define LCD_PINO_RS_WR          RE4_WR
            #endif
        #endif
    #endif

    #ifdef PinRE5
        #if (LCD_PINO_RS == PinRE5)
            #warning "Lcd: Pino RS controlado pelo pino RE5"

            #ifdef RE5_AD
                #define LCD_PINO_RS_AD          RE5_AD
            #endif

            #ifdef RE5_WR
                #define LCD_PINO_RS_IO          RE5_IO          
                #define LCD_PINO_RS_WR          RE5_WR
            #endif
        #endif
    #endif

    #ifdef PinRE6
        #if (LCD_PINO_RS == PinRE6)
            #warning "Lcd: Pino RS controlado pelo pino RE6"

            #ifdef RE6_AD
                #define LCD_PINO_RS_AD          RE6_AD
            #endif

            #ifdef RE6_WR
                #define LCD_PINO_RS_IO          RE6_IO          
                #define LCD_PINO_RS_WR          RE6_WR
            #endif
        #endif
    #endif

    #ifdef PinRE7
        #if (LCD_PINO_RS == PinRE7)
            #warning "Lcd: Pino RS controlado pelo pino RE7"

            #ifdef RE7_AD
                #define LCD_PINO_RS_AD          RE7_AD
            #endif

            #ifdef RE7_WR
                #define LCD_PINO_RS_IO          RE7_IO          
                #define LCD_PINO_RS_WR          RE7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortF
    #ifdef PinRF0
        #if (LCD_PINO_RS  == PinRF0)
            #warning "Lcd: Pino RS controlado pelo pino RF0"

            #ifdef RF0_AD
                #define LCD_PINO_RS_AD          RF0_AD
            #endif

            #ifdef RF0_WR
                #define LCD_PINO_RS_IO          RF0_IO          
                #define LCD_PINO_RS_WR          RF0_WR
            #endif
        #endif
    #endif

    #ifdef PinRF1
        #if (LCD_PINO_RS == PinRF1)
            #warning "Lcd: Pino RS controlado pelo pino RF1"
            #ifdef RF1_AD
                #define LCD_PINO_RS_AD          RF1_AD
            #endif

            #ifdef RF1_WR
                #define LCD_PINO_RS_IO          RF1_IO          
                #define LCD_PINO_RS_WR          RF1_WR
            #endif
        #endif
    #endif

    #ifdef PinRF2
        #if (LCD_PINO_RS == PinRF2)
            #warning "Lcd: Pino RS controlado pelo pino RF2"

            #ifdef RF2_AD
                #define LCD_PINO_RS_AD      RF2_AD
            #endif

            #ifdef RF2_WR
            #define LCD_PINO_RS_IO          RF2_IO          
            #define LCD_PINO_RS_WR          RF2_WR
            #endif
        #endif
    #endif

    #ifdef PinRF3
        #if (LCD_PINO_RS == PinRF3)
            #warning "Lcd: Pino RS controlado pelo pino RF3"

            #ifdef RF3_AD
                #define LCD_PINO_RS_AD          RF3_AD
            #endif

            #ifdef RF3_WR
                #define LCD_PINO_RS_IO          RF3_IO          
                #define LCD_PINO_RS_WR          RF3_WR
            #endif
        #endif
    #endif

    #ifdef PinRF4
        #if (LCD_PINO_RS == PinRF4)
            #warning "Lcd: Pino RS controlado pelo pino RF4"

            #ifdef RF4_AD
                #define LCD_PINO_RS_AD          RF4_AD
            #endif

            #ifdef RF4_WR
                #define LCD_PINO_RS_IO          RF4_IO          
                #define LCD_PINO_RS_WR          RF4_WR
            #endif
        #endif
    #endif

    #ifdef PinRF5
        #if (LCD_PINO_RS == PinRF5)
            #warning "Lcd: Pino RS controlado pelo pino RF5"

            #ifdef RF5_AD
                #define LCD_PINO_RS_AD          RF5_AD
            #endif

            #ifdef RF5_WR
                #define LCD_PINO_RS_IO          RF5_IO          
                #define LCD_PINO_RS_WR          RF5_WR
            #endif
        #endif
    #endif

    #ifdef PinRF6
        #if (LCD_PINO_RS == PinRF6)
            #warning "Lcd: Pino RS controlado pelo pino RF6"

            #ifdef RF6_AD
                #define LCD_PINO_RS_AD          RF6_AD
            #endif

            #ifdef RF6_WR
                #define LCD_PINO_RS_IO          RF6_IO          
                #define LCD_PINO_RS_WR          RF6_WR
            #endif
        #endif
    #endif

    #ifdef PinRF7
        #if (LCD_PINO_RS == PinRF7)
            #warning "Lcd: Pino RS controlado pelo pino RF7"

            #ifdef RF7_AD
                #define LCD_PINO_RS_AD          RF7_AD
            #endif

            #ifdef RF7_WR
                #define LCD_PINO_RS_IO          RF7_IO          
                #define LCD_PINO_RS_WR          RF7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortG
    #ifdef PinRG0
        #if (LCD_PINO_RS  == PinRG0)
            #warning "Lcd: Pino RS controlado pelo pino RG0"

            #ifdef RG0_AD
                #define LCD_PINO_RS_AD          RG0_AD
            #endif

            #ifdef RG0_WR
                #define LCD_PINO_RS_IO          RG0_IO          
                #define LCD_PINO_RS_WR          RG0_WR
            #endif
        #endif
    #endif

    #ifdef PinRG1
        #if (LCD_PINO_RS == PinRG1)
            #warning "Lcd: Pino RS controlado pelo pino RG1"
            #ifdef RG1_AD
                #define LCD_PINO_RS_AD          RG1_AD
            #endif

            #ifdef RG1_WR
                #define LCD_PINO_RS_IO          RG1_IO          
                #define LCD_PINO_RS_WR          RG1_WR
            #endif
        #endif
    #endif

    #ifdef PinRG2
        #if (LCD_PINO_RS == PinRG2)
            #warning "Lcd: Pino RS controlado pelo pino RG2"

            #ifdef RG2_AD
                #define LCD_PINO_RS_AD          RG2_AD
            #endif

            #ifdef RG2_WR
                #define LCD_PINO_RS_IO          RG2_IO          
                #define LCD_PINO_RS_WR          RG2_WR
            #endif
        #endif
    #endif

    #ifdef PinRG3
        #if (LCD_PINO_RS == PinRG3)
            #warning "Lcd: Pino RS controlado pelo pino RG3"

            #ifdef RG3_AD
                #define LCD_PINO_RS_AD          RG3_AD
            #endif

            #ifdef RG3_WR
                #define LCD_PINO_RS_IO          RG3_IO          
                #define LCD_PINO_RS_WR          RG3_WR
            #endif
        #endif
    #endif

    #ifdef PinRG4
        #if (LCD_PINO_RS == PinRG4)
            #warning "Lcd: Pino RS controlado pelo pino RG4"
            #ifdef RG4_AD
                #define LCD_PINO_RS_AD          RG4_AD
            #endif

            #ifdef RG4_WR
                #define LCD_PINO_RS_IO          RG4_IO          
                #define LCD_PINO_RS_WR          RG4_WR
            #endif
        #endif
    #endif

    #ifdef PinRG5
        #if (LCD_PINO_RS == PinRG5)
            #warning "Lcd: Pino RS controlado pelo pino RG5"

            #ifdef RG5_AD
                #define LCD_PINO_RS_AD          RG5_AD
            #endif

            #ifdef RG5_WR
                #define LCD_PINO_RS_IO          RG5_IO          
                #define LCD_PINO_RS_WR          RG5_WR
            #endif
        #endif
    #endif

    #ifdef PinRG6
        #if (LCD_PINO_RS == PinRG6)
            #warning "Lcd: Pino RS controlado pelo pino RG6"

            #ifdef RG6_AD
                #define LCD_PINO_RS_AD          RG6_AD
            #endif

            #ifdef RG6_WR
                #define LCD_PINO_RS_IO          RG6_IO          
                #define LCD_PINO_RS_WR          RG6_WR
            #endif
        #endif
    #endif

    #ifdef PinRG7
        #if (LCD_PINO_RS == PinRG7)
            #warning "Lcd: Pino RS controlado pelo pino RG7"

            #ifdef RG7_AD
                #define LCD_PINO_RS_AD          RG7_AD
            #endif

            #ifdef RG7_WR
                #define LCD_PINO_RS_IO          RG7_IO          
                #define LCD_PINO_RS_WR          RG7_WR
            #endif
        #endif
    #endif
#endif


//LCD_PINO_BACKLIGHT ----------------------------------------------------------
#ifdef PortA
    #ifdef PinRA0
        #if (LCD_PINO_BACKLIGHT  == PinRA0)
            #warning "Lcd: Pino Backlight controlado pelo pino RA0"

            #ifdef RA0_AD
                #define LCD_PINO_BACKLIGHT_AD          RA0_AD
            #endif

            #ifdef RA0_WR
                #define LCD_PINO_BACKLIGHT_IO          RA0_IO          
                #define LCD_PINO_BACKLIGHT_WR          RA0_WR
            #endif
        #endif
    #endif

    #ifdef PinRA1
        #if (LCD_PINO_BACKLIGHT == PinRA1)
            #warning "Lcd: Pino Backlight controlado pelo pino RA1"

            #ifdef RA1_AD
                #define LCD_PINO_BACKLIGHT_AD          RA1_AD
            #endif

            #ifdef RA1_WR
                #define LCD_PINO_BACKLIGHT_IO          RA1_IO          
                #define LCD_PINO_BACKLIGHT_WR          RA1_WR
            #endif
        #endif
    #endif

    #ifdef PinRA2
        #if (LCD_PINO_BACKLIGHT == PinRA2)
            #warning "Lcd: Pino Backlight controlado pelo pino RA2"

            #ifdef RA2_AD
                #define LCD_PINO_BACKLIGHT_AD          RA2_AD
            #endif

            #ifdef RA2_WR
                #define LCD_PINO_BACKLIGHT_IO          RA2_IO          
                #define LCD_PINO_BACKLIGHT_WR          RA2_WR
            #endif
        #endif
    #endif

    #ifdef PinRA3
        #if (LCD_PINO_BACKLIGHT == PinRA3)
            #warning "Lcd: Pino Backlight controlado pelo pino RA3"

            #ifdef RA3_AD
                #define LCD_PINO_BACKLIGHT_AD          RA3_AD
            #endif

            #ifdef RA3_WR
                #define LCD_PINO_BACKLIGHT_IO          RA3_IO          
                #define LCD_PINO_BACKLIGHT_WR          RA3_WR
            #endif
        #endif
    #endif

    #ifdef PinRA4
        #if (LCD_PINO_BACKLIGHT == PinRA4)
            #warning "Lcd: Pino Backlight controlado pelo pino RA4"

            #ifdef RA4_AD
                #define LCD_PINO_BACKLIGHT_AD          RA4_AD
            #endif

            #ifdef RA4_WR
                #define LCD_PINO_BACKLIGHT_IO          RA4_IO          
                #define LCD_PINO_BACKLIGHT_WR          RA4_WR
            #endif
        #endif
    #endif

    #ifdef PinRA5
        #if (LCD_PINO_BACKLIGHT == PinRA5)
            #warning "Lcd: Pino Backlight controlado pelo pino RA5"

            #ifdef RA5_AD
                #define LCD_PINO_BACKLIGHT_AD          RA5_AD
            #endif

            #ifdef RA5_WR
                #define LCD_PINO_BACKLIGHT_IO          RA5_IO          
                #define LCD_PINO_BACKLIGHT_WR          RA5_WR
            #endif
        #endif
    #endif

    #ifdef PinRA6
        #if (LCD_PINO_BACKLIGHT == PinRA6)
            #warning "Lcd: Pino Backlight controlado pelo pino RA6"

            #ifdef RA6_AD
                #define LCD_PINO_BACKLIGHT_AD          RA6_AD
            #endif

            #ifdef RA6_WR
                #define LCD_PINO_BACKLIGHT_IO          RA6_IO          
                #define LCD_PINO_BACKLIGHT_WR          RA6_WR
            #endif
        #endif
    #endif

    #ifdef PinRA7
        #if (LCD_PINO_BACKLIGHT == PinRA7)
            #warning "Lcd: Pino Backlight controlado pelo pino RA7"

            #ifdef RA7_AD
                #define LCD_PINO_BACKLIGHT_AD          RA7_AD
            #endif

            #ifdef RA7_WR
                #define LCD_PINO_BACKLIGHT_IO          RA7_IO          
                #define LCD_PINO_BACKLIGHT_WR          RA7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortB
    #ifdef PinRB0
        #if (LCD_PINO_BACKLIGHT  == PinRB0)
            #warning "Lcd: Pino Backlight controlado pelo pino RB0"

            #ifdef RB0_AD
                #define LCD_PINO_BACKLIGHT_AD          RB0_AD
            #endif

            #ifdef RB0_WR
                #define LCD_PINO_BACKLIGHT_IO          RB0_IO          
                #define LCD_PINO_BACKLIGHT_WR          RB0_WR
            #endif
        #endif
    #endif

    #ifdef PinRB1
        #if (LCD_PINO_BACKLIGHT == PinRB1)
            #warning "Lcd: Pino Backlight controlado pelo pino RB1"
            #ifdef RB1_AD
                #define LCD_PINO_BACKLIGHT_AD          RB1_AD
            #endif

            #ifdef RB1_WR
                #define LCD_PINO_BACKLIGHT_IO          RB1_IO          
                #define LCD_PINO_BACKLIGHT_WR          RB1_WR
            #endif
        #endif
    #endif

    #ifdef PinRB2
        #if (LCD_PINO_BACKLIGHT == PinRB2)
            #warning "Lcd: Pino Backlight controlado pelo pino RB2"

            #ifdef RB2_AD
                #define LCD_PINO_BACKLIGHT_AD          RB2_AD
            #endif

            #ifdef RB2_WR
                #define LCD_PINO_BACKLIGHT_IO          RB2_IO          
                #define LCD_PINO_BACKLIGHT_WR          RB2_WR
            #endif
        #endif
    #endif

    #ifdef PinRB3
        #if (LCD_PINO_BACKLIGHT == PinRB3)
            #warning "Lcd: Pino Backlight controlado pelo pino RB3"

            #ifdef RB3_AD
                #define LCD_PINO_BACKLIGHT_AD          RB3_AD
            #endif

            #ifdef RB3_WR
                #define LCD_PINO_BACKLIGHT_IO          RB3_IO          
                #define LCD_PINO_BACKLIGHT_WR          RB3_WR
            #endif
        #endif
    #endif

    #ifdef PinRB4
        #if (LCD_PINO_BACKLIGHT == PinRB4)
            #warning "Lcd: Pino Backlight controlado pelo pino RB4"
            #ifdef RB4_AD
                #define LCD_PINO_BACKLIGHT_AD          RB4_AD
            #endif

            #ifdef RB4_WR
                #define LCD_PINO_BACKLIGHT_IO          RB4_IO          
                #define LCD_PINO_BACKLIGHT_WR          RB4_WR
            #endif
        #endif
    #endif

    #ifdef PinRB5
        #if (LCD_PINO_BACKLIGHT == PinRB5)
            #warning "Lcd: Pino Backlight controlado pelo pino RB5"

            #ifdef RB5_AD
                #define LCD_PINO_BACKLIGHT_AD          RB5_AD
            #endif

            #ifdef RB5_WR
                #define LCD_PINO_BACKLIGHT_IO          RB5_IO          
                #define LCD_PINO_BACKLIGHT_WR          RB5_WR
            #endif
        #endif
    #endif

    #ifdef PinRB6
        #if (LCD_PINO_BACKLIGHT == PinRB6)
            #warning "Lcd: Pino Backlight controlado pelo pino RB6"

            #ifdef RB6_AD
                #define LCD_PINO_BACKLIGHT_AD          RB6_AD
            #endif

            #ifdef RB6_WR
                #define LCD_PINO_BACKLIGHT_IO          RB6_IO          
                #define LCD_PINO_BACKLIGHT_WR          RB6_WR
            #endif
        #endif
    #endif

    #ifdef PinRB7
        #if (LCD_PINO_BACKLIGHT == PinRB7)
            #warning "Lcd: Pino Backlight controlado pelo pino RB7"

            #ifdef RB7_AD
                #define LCD_PINO_BACKLIGHT_AD          RB7_AD
            #endif

            #ifdef RB7_WR
                #define LCD_PINO_BACKLIGHT_IO          RB7_IO          
                #define LCD_PINO_BACKLIGHT_WR          RB7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortC
    #ifdef PinRC0
        #if (LCD_PINO_BACKLIGHT  == PinRC0)
            #warning "Lcd: Pino Backlight controlado pelo pino RC0"

            #ifdef RC0_AD
                #define LCD_PINO_BACKLIGHT_AD          RC0_AD
            #endif

            #ifdef RC0_WR
                #define LCD_PINO_BACKLIGHT_IO          RC0_IO          
                #define LCD_PINO_BACKLIGHT_WR          RC0_WR
            #endif
        #endif
    #endif

    #ifdef PinRC1
        #if (LCD_PINO_BACKLIGHT == PinRC1)
            #warning "Lcd: Pino Backlight controlado pelo pino RC1"
            #ifdef RC1_AD
                #define LCD_PINO_BACKLIGHT_AD          RC1_AD
            #endif

            #ifdef RC1_WR
                #define LCD_PINO_BACKLIGHT_IO          RC1_IO          
                #define LCD_PINO_BACKLIGHT_WR          RC1_WR
            #endif
        #endif
    #endif

    #ifdef PinRC2
        #if (LCD_PINO_BACKLIGHT == PinRC2)
            #warning "Lcd: Pino Backlight controlado pelo pino RC2"

            #ifdef RC2_AD
                #define LCD_PINO_BACKLIGHT_AD          RC2_AD
            #endif

            #ifdef RC2_WR
                #define LCD_PINO_BACKLIGHT_IO          RC2_IO          
                #define LCD_PINO_BACKLIGHT_WR          RC2_WR
            #endif
        #endif
    #endif

    #ifdef PinRC3
        #if (LCD_PINO_BACKLIGHT == PinRC3)
            #warning "Lcd: Pino Backlight controlado pelo pino RC3"

            #ifdef RC3_AD
                #define LCD_PINO_BACKLIGHT_AD          RC3_AD
            #endif

            #ifdef RC3_WR
                #define LCD_PINO_BACKLIGHT_IO          RC3_IO          
                #define LCD_PINO_BACKLIGHT_WR          RC3_WR
            #endif
        #endif
    #endif

    #ifdef PinRC4
        #if (LCD_PINO_BACKLIGHT == PinRC4)
            #warning "Lcd: Pino Backlight controlado pelo pino RC4"
            #ifdef RC4_AD
                #define LCD_PINO_BACKLIGHT_AD          RC4_AD
            #endif

            #ifdef RC4_WR
                #define LCD_PINO_BACKLIGHT_IO          RC4_IO          
                #define LCD_PINO_BACKLIGHT_WR          RC4_WR
            #endif
        #endif
    #endif

    #ifdef PinRC5
        #if (LCD_PINO_BACKLIGHT == PinRC5)
            #warning "Lcd: Pino Backlight controlado pelo pino RC5"

            #ifdef RC5_AD
                #define LCD_PINO_BACKLIGHT_AD          RC5_AD
            #endif

            #ifdef RC5_WR
                #define LCD_PINO_BACKLIGHT_IO          RC5_IO          
                #define LCD_PINO_BACKLIGHT_WR          RC5_WR
            #endif
        #endif
    #endif

    #ifdef PinRC6
        #if (LCD_PINO_BACKLIGHT == PinRC6)
            #warning "Lcd: Pino Backlight controlado pelo pino RC6"

            #ifdef RC6_AD
                #define LCD_PINO_BACKLIGHT_AD          RC6_AD
            #endif

            #ifdef RC6_WR
                #define LCD_PINO_BACKLIGHT_IO          RC6_IO          
                #define LCD_PINO_BACKLIGHT_WR          RC6_WR
            #endif
        #endif
    #endif

    #ifdef PinRC7
        #if (LCD_PINO_BACKLIGHT == PinRC7)
            #warning "Lcd: Pino Backlight controlado pelo pino RC7"

            #ifdef RC7_AD
                #define LCD_PINO_BACKLIGHT_AD          RC7_AD
            #endif

            #ifdef RC7_WR
                #define LCD_PINO_BACKLIGHT_IO          RC7_IO          
                #define LCD_PINO_BACKLIGHT_WR          RC7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortD
    #ifdef PinRD0
        #if (LCD_PINO_BACKLIGHT  == PinRD0)
            #warning "Lcd: Pino Backlight controlado pelo pino RD0"

            #ifdef RD0_AD
                #define LCD_PINO_BACKLIGHT_AD          RD0_AD
            #endif

            #ifdef RD0_WR
                #define LCD_PINO_BACKLIGHT_IO          RD0_IO          
                #define LCD_PINO_BACKLIGHT_WR          RD0_WR
            #endif
        #endif
    #endif

    #ifdef PinRD1
        #if (LCD_PINO_BACKLIGHT == PinRD1)
            #warning "Lcd: Pino Backlight controlado pelo pino RD1"
            #ifdef RD1_AD
                #define LCD_PINO_BACKLIGHT_AD          RD1_AD
            #endif

            #ifdef RD1_WR
                #define LCD_PINO_BACKLIGHT_IO          RD1_IO          
                #define LCD_PINO_BACKLIGHT_WR          RD1_WR
            #endif
        #endif
    #endif

    #ifdef PinRD2
        #if (LCD_PINO_BACKLIGHT == PinRD2)
            #warning "Lcd: Pino Backlight controlado pelo pino RD2"

            #ifdef RD2_AD
                #define LCD_PINO_BACKLIGHT_AD          RD2_AD
            #endif

            #ifdef RD2_WR
                #define LCD_PINO_BACKLIGHT_IO          RD2_IO          
                #define LCD_PINO_BACKLIGHT_WR          RD2_WR
            #endif
        #endif
    #endif

    #ifdef PinRD3
        #if (LCD_PINO_BACKLIGHT == PinRD3)
            #warning "Lcd: Pino Backlight controlado pelo pino RD3"

            #ifdef RD3_AD
                #define LCD_PINO_BACKLIGHT_AD          RD3_AD
            #endif

            #ifdef RD3_WR
                #define LCD_PINO_BACKLIGHT_IO          RD3_IO          
                #define LCD_PINO_BACKLIGHT_WR          RD3_WR
            #endif
        #endif
    #endif

    #ifdef PinRD4
        #if (LCD_PINO_BACKLIGHT == PinRD4)
            #warning "Lcd: Pino Backlight controlado pelo pino RD4"
            #ifdef RD4_AD
                #define LCD_PINO_BACKLIGHT_AD          RD4_AD
            #endif

            #ifdef RD4_WR
                #define LCD_PINO_BACKLIGHT_IO          RD4_IO          
                #define LCD_PINO_BACKLIGHT_WR          RD4_WR
            #endif
        #endif
    #endif

    #ifdef PinRD5
        #if (LCD_PINO_BACKLIGHT == PinRD5)
            #warning "Lcd: Pino Backlight controlado pelo pino RD5"

            #ifdef RD5_AD
                #define LCD_PINO_BACKLIGHT_AD          RD5_AD
            #endif

            #ifdef RD5_WR
                #define LCD_PINO_BACKLIGHT_IO          RD5_IO          
                #define LCD_PINO_BACKLIGHT_WR          RD5_WR
            #endif
        #endif
    #endif

    #ifdef PinRD6
        #if (LCD_PINO_BACKLIGHT == PinRD6)
            #warning "Lcd: Pino Backlight controlado pelo pino RD6"

            #ifdef RD6_AD
                #define LCD_PINO_BACKLIGHT_AD          RD6_AD
            #endif

            #ifdef RD6_WR
                #define LCD_PINO_BACKLIGHT_IO          RD6_IO          
                #define LCD_PINO_BACKLIGHT_WR          RD6_WR
            #endif
        #endif
    #endif

    #ifdef PinRD7
        #if (LCD_PINO_BACKLIGHT == PinRD7)
            #warning "Lcd: Pino Backlight controlado pelo pino RD7"

            #ifdef RD7_AD
                #define LCD_PINO_BACKLIGHT_AD          RD7_AD
            #endif

            #ifdef RD7_WR
                #define LCD_PINO_BACKLIGHT_IO          RD7_IO          
                #define LCD_PINO_BACKLIGHT_WR          RD7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortE
    #ifdef PinRE0
        #if (LCD_PINO_BACKLIGHT  == PinRE0)
            #warning "Lcd: Pino Backlight controlado pelo pino RE0"

            #ifdef RE0_AD
                #define LCD_PINO_BACKLIGHT_AD          RE0_AD
            #endif

            #ifdef RE0_WR
                #define LCD_PINO_BACKLIGHT_IO          RE0_IO          
                #define LCD_PINO_BACKLIGHT_WR          RE0_WR
            #endif
        #endif
    #endif

    #ifdef PinRE1
        #if (LCD_PINO_BACKLIGHT == PinRE1)
            #warning "Lcd: Pino Backlight controlado pelo pino RE1"

            #ifdef RE1_AD
                #define LCD_PINO_BACKLIGHT_AD          RE1_AD
            #endif

            #ifdef RE1_WR
                #define LCD_PINO_BACKLIGHT_IO          RE1_IO          
                #define LCD_PINO_BACKLIGHT_WR          RE1_WR
            #endif
        #endif
    #endif

    #ifdef PinRE2
        #if (LCD_PINO_BACKLIGHT == PinRE2)
            #warning "Lcd: Pino Backlight controlado pelo pino RE2"

            #ifdef RE2_AD
                #define LCD_PINO_BACKLIGHT_AD          RE2_AD
            #endif

            #ifdef RE2_WR
                #define LCD_PINO_BACKLIGHT_IO          RE2_IO          
                #define LCD_PINO_BACKLIGHT_WR          RE2_WR
            #endif
        #endif
    #endif

    #ifdef PinRE3
        #if (LCD_PINO_BACKLIGHT == PinRE3)
            #warning "Lcd: Pino Backlight controlado pelo pino RE3"

            #ifdef RE3_AD
                #define LCD_PINO_BACKLIGHT_AD          RE3_AD
            #endif

            #ifdef RE3_WR
                #define LCD_PINO_BACKLIGHT_IO          RE3_IO          
                #define LCD_PINO_BACKLIGHT_WR          RE3_WR
            #endif
        #endif
    #endif

    #ifdef PinRE4
        #if (LCD_PINO_BACKLIGHT == PinRE4)
            #warning "Lcd: Pino Backlight controlado pelo pino RE4"
            #ifdef RE4_AD
                #define LCD_PINO_BACKLIGHT_AD          RE4_AD
            #endif

            #ifdef RE4_WR
                #define LCD_PINO_BACKLIGHT_IO          RE4_IO          
                #define LCD_PINO_BACKLIGHT_WR          RE4_WR
            #endif
        #endif
    #endif

    #ifdef PinRE5
        #if (LCD_PINO_BACKLIGHT == PinRE5)
            #warning "Lcd: Pino Backlight controlado pelo pino RE5"

            #ifdef RE5_AD
                #define LCD_PINO_BACKLIGHT_AD          RE5_AD
            #endif

            #ifdef RE5_WR
                #define LCD_PINO_BACKLIGHT_IO          RE5_IO          
                #define LCD_PINO_BACKLIGHT_WR          RE5_WR
            #endif
        #endif
    #endif

    #ifdef PinRE6
        #if (LCD_PINO_BACKLIGHT == PinRE6)
            #warning "Lcd: Pino Backlight controlado pelo pino RE6"

            #ifdef RE6_AD
                #define LCD_PINO_BACKLIGHT_AD          RE6_AD
            #endif

            #ifdef RE6_WR
                #define LCD_PINO_BACKLIGHT_IO          RE6_IO          
                #define LCD_PINO_BACKLIGHT_WR          RE6_WR
            #endif
        #endif
    #endif

    #ifdef PinRE7
        #if (LCD_PINO_BACKLIGHT == PinRE7)
            #warning "Lcd: Pino Backlight controlado pelo pino RE7"

            #ifdef RE7_AD
                #define LCD_PINO_BACKLIGHT_AD          RE7_AD
            #endif

            #ifdef RE7_WR
                #define LCD_PINO_BACKLIGHT_IO          RE7_IO          
                #define LCD_PINO_BACKLIGHT_WR          RE7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortF
    #ifdef PinRF0
        #if (LCD_PINO_BACKLIGHT  == PinRF0)
            #warning "Lcd: Pino Backlight controlado pelo pino RF0"

            #ifdef RF0_AD
                #define LCD_PINO_BACKLIGHT_AD          RF0_AD
            #endif

            #ifdef RF0_WR
                #define LCD_PINO_BACKLIGHT_IO          RF0_IO          
                #define LCD_PINO_BACKLIGHT_WR          RF0_WR
            #endif
        #endif
    #endif

    #ifdef PinRF1
        #if (LCD_PINO_BACKLIGHT == PinRF1)
            #warning "Lcd: Pino Backlight controlado pelo pino RF1"
            #ifdef RF1_AD
                #define LCD_PINO_BACKLIGHT_AD          RF1_AD
            #endif

            #ifdef RF1_WR
                #define LCD_PINO_BACKLIGHT_IO          RF1_IO          
                #define LCD_PINO_BACKLIGHT_WR          RF1_WR
            #endif
        #endif
    #endif

    #ifdef PinRF2
        #if (LCD_PINO_BACKLIGHT == PinRF2)
            #warning "Lcd: Pino Backlight controlado pelo pino RF2"

            #ifdef RF2_AD
                #define LCD_PINO_BACKLIGHT_AD      RF2_AD
            #endif

            #ifdef RF2_WR
            #define LCD_PINO_BACKLIGHT_IO          RF2_IO          
            #define LCD_PINO_BACKLIGHT_WR          RF2_WR
            #endif
        #endif
    #endif

    #ifdef PinRF3
        #if (LCD_PINO_BACKLIGHT == PinRF3)
            #warning "Lcd: Pino Backlight controlado pelo pino RF3"

            #ifdef RF3_AD
                #define LCD_PINO_BACKLIGHT_AD          RF3_AD
            #endif

            #ifdef RF3_WR
                #define LCD_PINO_BACKLIGHT_IO          RF3_IO          
                #define LCD_PINO_BACKLIGHT_WR          RF3_WR
            #endif
        #endif
    #endif

    #ifdef PinRF4
        #if (LCD_PINO_BACKLIGHT == PinRF4)
            #warning "Lcd: Pino Backlight controlado pelo pino RF4"

            #ifdef RF4_AD
                #define LCD_PINO_BACKLIGHT_AD          RF4_AD
            #endif

            #ifdef RF4_WR
                #define LCD_PINO_BACKLIGHT_IO          RF4_IO          
                #define LCD_PINO_BACKLIGHT_WR          RF4_WR
            #endif
        #endif
    #endif

    #ifdef PinRF5
        #if (LCD_PINO_BACKLIGHT == PinRF5)
            #warning "Lcd: Pino Backlight controlado pelo pino RF5"

            #ifdef RF5_AD
                #define LCD_PINO_BACKLIGHT_AD          RF5_AD
            #endif

            #ifdef RF5_WR
                #define LCD_PINO_BACKLIGHT_IO          RF5_IO          
                #define LCD_PINO_BACKLIGHT_WR          RF5_WR
            #endif
        #endif
    #endif

    #ifdef PinRF6
        #if (LCD_PINO_BACKLIGHT == PinRF6)
            #warning "Lcd: Pino Backlight controlado pelo pino RF6"

            #ifdef RF6_AD
                #define LCD_PINO_BACKLIGHT_AD          RF6_AD
            #endif

            #ifdef RF6_WR
                #define LCD_PINO_BACKLIGHT_IO          RF6_IO          
                #define LCD_PINO_BACKLIGHT_WR          RF6_WR
            #endif
        #endif
    #endif

    #ifdef PinRF7
        #if (LCD_PINO_BACKLIGHT == PinRF7)
            #warning "Lcd: Pino Backlight controlado pelo pino RF7"

            #ifdef RF7_AD
                #define LCD_PINO_BACKLIGHT_AD          RF7_AD
            #endif

            #ifdef RF7_WR
                #define LCD_PINO_BACKLIGHT_IO          RF7_IO          
                #define LCD_PINO_BACKLIGHT_WR          RF7_WR
            #endif
        #endif
    #endif
#endif


#ifdef PortG
    #ifdef PinRG0
        #if (LCD_PINO_BACKLIGHT  == PinRG0)
            #warning "Lcd: Pino Backlight controlado pelo pino RG0"

            #ifdef RG0_AD
                #define LCD_PINO_BACKLIGHT_AD          RG0_AD
            #endif

            #ifdef RG0_WR
                #define LCD_PINO_BACKLIGHT_IO          RG0_IO          
                #define LCD_PINO_BACKLIGHT_WR          RG0_WR
            #endif
        #endif
    #endif

    #ifdef PinRG1
        #if (LCD_PINO_BACKLIGHT == PinRG1)
            #warning "Lcd: Pino Backlight controlado pelo pino RG1"
            #ifdef RG1_AD
                #define LCD_PINO_BACKLIGHT_AD          RG1_AD
            #endif

            #ifdef RG1_WR
                #define LCD_PINO_BACKLIGHT_IO          RG1_IO          
                #define LCD_PINO_BACKLIGHT_WR          RG1_WR
            #endif
        #endif
    #endif

    #ifdef PinRG2
        #if (LCD_PINO_BACKLIGHT == PinRG2)
            #warning "Lcd: Pino Backlight controlado pelo pino RG2"

            #ifdef RG2_AD
                #define LCD_PINO_BACKLIGHT_AD          RG2_AD
            #endif

            #ifdef RG2_WR
                #define LCD_PINO_BACKLIGHT_IO          RG2_IO          
                #define LCD_PINO_BACKLIGHT_WR          RG2_WR
            #endif
        #endif
    #endif

    #ifdef PinRG3
        #if (LCD_PINO_BACKLIGHT == PinRG3)
            #warning "Lcd: Pino Backlight controlado pelo pino RG3"

            #ifdef RG3_AD
                #define LCD_PINO_BACKLIGHT_AD          RG3_AD
            #endif

            #ifdef RG3_WR
                #define LCD_PINO_BACKLIGHT_IO          RG3_IO          
                #define LCD_PINO_BACKLIGHT_WR          RG3_WR
            #endif
        #endif
    #endif

    #ifdef PinRG4
        #if (LCD_PINO_BACKLIGHT == PinRG4)
            #warning "Lcd: Pino Backlight controlado pelo pino RG4"
            #ifdef RG4_AD
                #define LCD_PINO_BACKLIGHT_AD          RG4_AD
            #endif

            #ifdef RG4_WR
                #define LCD_PINO_BACKLIGHT_IO          RG4_IO          
                #define LCD_PINO_BACKLIGHT_WR          RG4_WR
            #endif
        #endif
    #endif

    #ifdef PinRG5
        #if (LCD_PINO_BACKLIGHT == PinRG5)
            #warning "Lcd: Pino Backlight controlado pelo pino RG5"

            #ifdef RG5_AD
                #define LCD_PINO_BACKLIGHT_AD          RG5_AD
            #endif

            #ifdef RG5_WR
                #define LCD_PINO_BACKLIGHT_IO          RG5_IO          
                #define LCD_PINO_BACKLIGHT_WR          RG5_WR
            #endif
        #endif
    #endif

    #ifdef PinRG6
        #if (LCD_PINO_BACKLIGHT == PinRG6)
            #warning "Lcd: Pino Backlight controlado pelo pino RG6"

            #ifdef RG6_AD
                #define LCD_PINO_BACKLIGHT_AD          RG6_AD
            #endif

            #ifdef RG6_WR
                #define LCD_PINO_BACKLIGHT_IO          RG6_IO          
                #define LCD_PINO_BACKLIGHT_WR          RG6_WR
            #endif
        #endif
    #endif

    #ifdef PinRG7
        #if (LCD_PINO_BACKLIGHT == PinRG7)
            #warning "Lcd: Pino Backlight controlado pelo pino RG7"

            #ifdef RG7_AD
                #define LCD_PINO_BACKLIGHT_AD          RG7_AD
            #endif

            #ifdef RG7_WR
                #define LCD_PINO_BACKLIGHT_IO          RG7_IO          
                #define LCD_PINO_BACKLIGHT_WR          RG7_WR
            #endif
        #endif
    #endif
#endif






#if (LCD_NUMERO_DE_LINHAS == 1)
    #define LCD_LINHA1
#elif (LCD_NUMERO_DE_LINHAS == 2)
    #define LCD_LINHA1
    #define LCD_LINHA2
#elif (LCD_NUMERO_DE_LINHAS == 4)
    #define LCD_LINHA1
    #define LCD_LINHA2
    #define LCD_LINHA3
    #define LCD_LINHA4
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

    
    #ifdef LCD_LINHA1
        Uchar BufferLinha1[LCD_NUMERO_DE_COLUNAS];
    #endif
    
    #ifdef LCD_LINHA2
        Uchar BufferLinha2[LCD_NUMERO_DE_COLUNAS];
    #endif    
    
    #ifdef LCD_LINHA3
        Uchar BufferLinha3[LCD_NUMERO_DE_COLUNAS];
    #endif
        
    #ifdef LCD_LINHA4
        Uchar BufferLinha4[LCD_NUMERO_DE_COLUNAS];
    #endif        

    struct
    {
        Uchar  Intermitencia;
        Uint   BackLight;
    }Temporizadores;
        
    struct
    {
        Uint   IntermitenciaAtivada:1;
        Uint   IntermitenciaEstado:1;
        Uint   ModoGreenAtivado:1;
    }Sinais;
}ObjLcd;


//Funções da CGRAM ------------------------------------------------------------
#if (LCD_INCLUIR_FUNCOES_CGRAM == Sim)

//Endereços da CGRAM
#define CGRAM_0         0
#define CGRAM_1         8
#define CGRAM_2         16
#define CGRAM_3         24
#define CGRAM_4         32
#define CGRAM_5         40
#define CGRAM_6         48
#define CGRAM_7         56


//Caracteres especiais
#if (_CGRAM_CARACTERE_ESPECIAL_0P == _Sim)
#define ALOCA_CGRAM_0P      const char CGRAM_0P[] = {0x00,0x00,0x0E,0x0A,\
                                                     0x0A,0x0A,0x0E,0x00}
extern const char CGRAM_0P[];
#endif 

#if (_CGRAM_CARACTERE_ESPECIAL_1P == _Sim)
#define ALOCA_CGRAM_1P      const char CGRAM_1P[] = {0x00,0x00,0x0C,0x04,\
                                                     0x04,0x04,0x0E,0x00}
extern const char CGRAM_1P[];
#endif 

#if (_CGRAM_CARACTERE_ESPECIAL_2P == _Sim)
#define ALOCA_CGRAM_2P      const char CGRAM_2P[] = {0x00,0x00,0x0E,0x02,\
                                                     0x0E,0x08,0x0E,0x00}
extern const char CGRAM_2P[];
#endif  
                                             
#if (_CGRAM_CARACTERE_ESPECIAL_3P == _Sim)                                             
#define ALOCA_CGRAM_3P      const char CGRAM_3P[] = {0x00,0x00,0x0E,0x02,\
                                                     0x0E,0x02,0x0E,0x00}
extern const char CGRAM_3P[];
#endif  

#if (_CGRAM_CARACTERE_ESPECIAL_4P == _Sim)
#define ALOCA_CGRAM_4P      const char CGRAM_4P[] = {0x00,0x00,0x0A,0x0A,\
                                                     0x0E,0x02,0x02,0x00}
extern const char CGRAM_4P[];
#endif  

#if (_CGRAM_CARACTERE_ESPECIAL_5P == _Sim)
#define ALOCA_CGRAM_5P      const char CGRAM_5P[] = {0x00,0x00,0x0E,0x08,\
                                                     0x0E,0x02,0x0E,0x00}
extern const char CGRAM_5P[];
#endif 

#if (_CGRAM_CARACTERE_ESPECIAL_6P == _Sim)
#define ALOCA_CGRAM_8P      const char CGRAM_6P[] = {0x00,0x00,0x0E,0x08,\
                                                     0x0E,0x0A,0x0E,0x00}
extern const char CGRAM_6P[];
#endif 

#if (_CGRAM_CARACTERE_ESPECIAL_7P == _Sim)
#define ALOCA_CGRAM_7P       const char CGRAM_7P[] = {0x00,0x00,0x0E,0x02,\
                                                     0x02,0x02,0x02,0x00}
extern const char CGRAM_7P[];
#endif 

#if (_CGRAM_CARACTERE_ESPECIAL_8P == _Sim)
#define ALOCA_CGRAM_8P      const char CGRAM_8P[] = {0x00,0x00,0x0e,0x0a,\
                                                     0x0A,0x0E,0x0A,0x0E}
extern const char CGRAM_8P[];
#endif 

#if (_CGRAM_CARACTERE_ESPECIAL_9P == _Sim)
#define ALOCA_CGRAM_9P      const char CGRAM_9P[] = {0x00,0x00,0x00,0x0E,\
                                                     0x0E,0x02,0x0E,0x00}   
extern const char CGRAM_9P[];
#endif 

#if (_CGRAM_CARACTERE_ESPECIAL_EP == _Sim)
#define ALOCA_CGRAM_EP      const char CGRAM_EP[] = {0x00,0x00,0x0E,0x08,\
                                                     0x0C,0x08,0x0E,0x00}
extern const char CGRAM_EP[];
#endif 


//Publicação das funções da CGRAM ---------------------------------------------
void Lcd_CriaCaractereNaCGRAM (Uchar Local, Cchar *Caractere);
#endif



//Funções de exibição de data e horas -----------------------------------------
#if (_LCD_INCLUIR_FUNCOES_EXIBE_DATA_HORAS == Sim)

//Modos de Exibição de horario
#define _HM                     0
#define _HMS                    1


//Modos de Exibição de Data
#define _DM                     0
#define _DMA                    1
#define _DMAA                   2


//Publicação das funções do relogio -------------------------------------------
void Lcd_ExibeHorario (Uchar *Buffer,ObjHorario *Horario, Uchar Formato);
void Lcd_ExibeData (Uchar *Buffer, ObjData *Data, Uchar Formato);
void Lcd_ExibeDiaDaSemana (Uchar *Buffer, Uchar DiaDaSemana);

//Publicação das variáveis do módulo  -----------------------------------------
extern const char _Dom[];
extern const char _Seg[];
extern const char _Ter[];
extern const char _Qua[];
extern const char _Qui[];
extern const char _Sex[];
extern const char _Sab[];
#endif



//Publicação das funções do módulo---------------------------------------------
void Lcd_Inicializacao(void);
void Lcd_LimpaBuffer (Uchar Linha);
void Lcd_LimpaBuffers (void);
void Lcd_AtualizaLinha (Uchar Linha);
void Lcd_AtualizaLinhas (void);
void Lcd_PosicionaCursorNaDDRAM (Uchar Linha,Uchar Coluna);
void Lcd_Monitor (void);
void Lcd_LigaDisplay (void);
void Lcd_DesligaDisplay (void);
void Lcd_LigaCursor (void);
void Lcd_DesligaCursor (void);
void Lcd_LigaBlink (void);
void Lcd_DesligaBlink (void);
void Lcd_Home (void);
void Lcd_ApagaMensagens (void);
void Lcd_DeslocaCursorParaEsquerda (void);
void Lcd_DeslocaCursorParaDireita (void);
void Lcd_DeslocaMensagemParaEsquerda (void);
void Lcd_DeslocaMensagemParaDireita (void);

Uchar *Lcd_CarregaPonteiroDoBuffer (Uchar Linha, Uchar Coluna);
Uchar *Lcd_TransfereMensagemParaBuffer (Uchar *Buffer, Cchar *Mensagem);
Uchar *Lcd_TransfereStreamParaBuffer (Uchar *Buffer, Uchar *Stream);




//Publicação das variáveis do módulo ------------------------------------------
extern ObjLcd    Lcd;


#endif	/* LCD_H */

