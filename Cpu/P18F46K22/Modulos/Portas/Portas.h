/* 
 * Arquivo: Portas.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef PORTAS_IO_H
#define	PORTAS_IO_H

#include <xc.h>

#define _SAIDA                  0
#define _ENTRADA                1

#define _DIGITAL                0
#define _ANALOGICO              1


#define _PORTA                  1
#define _PORTB                  2
#define _PORTC                  3
#define _PORTD                  4
#define _PORTE                  5



#define _PORTA_0                1
#define _PORTA_1                2
#define _PORTA_2                3
#define _PORTA_3                4
#define _PORTA_4                5
#define _PORTA_5                6
#define _PORTA_6                7
#define _PORTA_7                8

#define _PORTB_0                9
#define _PORTB_1                10
#define _PORTB_2                11
#define _PORTB_3                12
#define _PORTB_4                13
#define _PORTB_5                14
#define _PORTB_6                15
#define _PORTB_7                16

#define _PORTC_0                17
#define _PORTC_1                18
#define _PORTC_2                19
#define _PORTC_3                20
#define _PORTC_4                21
#define _PORTC_5                22
#define _PORTC_6                23
#define _PORTC_7                24

#define _PORTD_0                25
#define _PORTD_1                26
#define _PORTD_2                27
#define _PORTD_3                28
#define _PORTD_4                29
#define _PORTD_5                30
#define _PORTD_6                31
#define _PORTD_7                32

#define _PORTE_0                33
#define _PORTE_1                34
#define _PORTE_2                35
#define _PORTE_3                36
#define _PORTE_4                37
#define _PORTE_5                38
#define _PORTE_6                39
#define _PORTE_7                40



//PORTA ----------------------------------------------------------------------
#define _PORTA_DIGITAL                      (ANSELA =  0b00000000)
#define _PORTA_NIBBLE_H_DIGITAL             (ANSELA &= 0b00001111)
#define _PORTA_NIBBLE_L_DIGITAL             (ANSELA &= 0b11110000)
#define _PORTA_0_DIGITAL                    (ANSELAbits.ANSA0 = _DIGITAL)
#define _PORTA_1_DIGITAL                    (ANSELAbits.ANSA1 = _DIGITAL)
#define _PORTA_2_DIGITAL                    (ANSELAbits.ANSA2 = _DIGITAL)
#define _PORTA_3_DIGITAL                    (ANSELAbits.ANSA3 = _DIGITAL)
#define _PORTA_5_DIGITAL                    (ANSELAbits.ANSA5 = _DIGITAL)

#define _PORTA_ANALOGICO                    (ANSELA =  0b11111111)
#define _PORTA_NIBBLE_H_ANALOGICO           (ANSELA |= 0b11110000)
#define _PORTA_NIBBLE_L_ANALOGICO           (ANSELA |= 0b00001111)
#define _PORTA_0_ANALOGICO                  (ANSELAbits.ANSA0 = _ANALOGICO)
#define _PORTA_1_ANALOGICO                  (ANSELAbits.ANSA1 = _ANALOGICO)
#define _PORTA_2_ANALOGICO                  (ANSELAbits.ANSA2 = _ANALOGICO)
#define _PORTA_3_ANALOGICO                  (ANSELAbits.ANSA3 = _ANALOGICO)
#define _PORTA_5_ANALOGICO                  (ANSELAbits.ANSA5 = _ANALOGICO)

#define _PORTA_ENTRADA                      (TRISA =  0b11111111)
#define _PORTA_NIBBLE_H_ENTRADA             (TRISA |= 0b11110000)
#define _PORTA_NIBBLE_L_ENTRADA             (TRISA |= 0b00001111)
#define _PORTA_0_ENTRADA                    (TRISAbits.TRISA0 = _ENTRADA)
#define _PORTA_1_ENTRADA                    (TRISAbits.TRISA1 = _ENTRADA)
#define _PORTA_2_ENTRADA                    (TRISAbits.TRISA2 = _ENTRADA)
#define _PORTA_3_ENTRADA                    (TRISAbits.TRISA3 = _ENTRADA)
#define _PORTA_4_ENTRADA                    (TRISAbits.TRISA4 = _ENTRADA)
#define _PORTA_5_ENTRADA                    (TRISAbits.TRISA5 = _ENTRADA)
#define _PORTA_6_ENTRADA                    (TRISAbits.TRISA6 = _ENTRADA)
#define _PORTA_7_ENTRADA                    (TRISAbits.TRISA7 = _ENTRADA)

#define _PORTA_SAIDA                        (TRISA =  0b00000000)
#define _PORTA_NIBBLE_H_SAIDA               (TRISA &= 0b00001111)
#define _PORTA_NIBBLE_L_SAIDA               (TRISA &= 0b11110000)
#define _PORTA_0_SAIDA                      (TRISAbits.TRISA0 = _SAIDA)
#define _PORTA_1_SAIDA                      (TRISAbits.TRISA1 = _SAIDA)
#define _PORTA_2_SAIDA                      (TRISAbits.TRISA2 = _SAIDA)
#define _PORTA_3_SAIDA                      (TRISAbits.TRISA3 = _SAIDA)
#define _PORTA_4_SAIDA                      (TRISAbits.TRISA4 = _SAIDA)
#define _PORTA_5_SAIDA                      (TRISAbits.TRISA5 = _SAIDA)
#define _PORTA_6_SAIDA                      (TRISAbits.TRISA6 = _SAIDA)
#define _PORTA_7_SAIDA                      (TRISAbits.TRISA7 = _SAIDA)

#define _PORTA_RD                           (PORTA)
#define _PORTA_0_RD                         (PORTAbits.RA0)
#define _PORTA_1_RD                         (PORTAbits.RA1)
#define _PORTA_2_RD                         (PORTAbits.RA2)
#define _PORTA_3_RD                         (PORTAbits.RA3)
#define _PORTA_4_RD                         (PORTAbits.RA4)
#define _PORTA_5_RD                         (PORTAbits.RA5)
#define _PORTA_6_RD                         (PORTAbits.RA6)
#define _PORTA_7_RD                         (PORTAbits.RA7)

#define _PORTA_WR                           (LATA)
#define _PORTA_0_WR                         (LATAbits.LATA0)
#define _PORTA_1_WR                         (LATAbits.LATA1)
#define _PORTA_2_WR                         (LATAbits.LATA2)
#define _PORTA_3_WR                         (LATAbits.LATA3)
#define _PORTA_4_WR                         (LATAbits.LATA4)
#define _PORTA_5_WR                         (LATAbits.LATA5)
#define _PORTA_6_WR                         (LATAbits.LATA6)
#define _PORTA_7_WR                         (LATAbits.LATA7)


//PORTB ----------------------------------------------------------------------
#define _PORTB_DIGITAL                      (ANSELB =  0b00000000)
#define _PORTB_NIBBLE_H_DIGITAL             (ANSELB &= 0b00001111)
#define _PORTB_NIBBLE_L_DIGITAL             (ANSELB &= 0b11110000)
#define _PORTB_0_DIGITAL                    (ANSELBbits.ANSB0 = _DIGITAL)
#define _PORTB_1_DIGITAL                    (ANSELBbits.ANSB1 = _DIGITAL)
#define _PORTB_2_DIGITAL                    (ANSELBbits.ANSB2 = _DIGITAL
#define _PORTB_3_DIGITAL                    (ANSELBbits.ANSB3 = _DIGITAL)
#define _PORTB_4_DIGITAL                    (ANSELBbits.ANSB4 = _DIGITAL)
#define _PORTB_5_DIGITAL                    (ANSELBbits.ANSB5 = _DIGITAL)

#define _PORTB_ANALOGICO                    (ANSELB =  0b11111111)
#define _PORTB_NIBBLE_H_ANALOGICO           (ANSELB |= 0b11110000)
#define _PORTB_NIBBLE_L_ANALOGICO           (ANSELB |= 0b00001111)
#define _PORTB_0_ANALOGICO                  (ANSELBbits.ANSB0 = _ANALOGICO)
#define _PORTB_1_ANALOGICO                  (ANSELBbits.ANSB1 = _ANALOGICO)
#define _PORTB_2_ANALOGICO                  (ANSELBbits.ANSB2 = _ANALOGICO)
#define _PORTB_3_ANALOGICO                  (ANSELBbits.ANSB3 = _ANALOGICO)
#define _PORTB_4_ANALOGICO                  (ANSELBbits.ANSB4 = _ANALOGICO)
#define _PORTB_5_ANALOGICO                  (ANSELBbits.ANSB5 = _ANALOGICO)

#define _PORTB_ENTRADA                      (TRISB =  0b11111111)
#define _PORTB_NIBBLE_H_ENTRADA             (TRISB |= 0b11110000)
#define _PORTB_NIBBLE_L_ENTRADA             (TRISB |= 0b00001111)
#define _PORTB_0_ENTRADA                    (TRISBbits.TRISB0 = _ENTRADA)
#define _PORTB_1_ENTRADA                    (TRISBbits.TRISB1 = _ENTRADA)
#define _PORTB_2_ENTRADA                    (TRISBbits.TRISB2 = _ENTRADA)
#define _PORTB_3_ENTRADA                    (TRISBbits.TRISB3 = _ENTRADA)
#define _PORTB_4_ENTRADA                    (TRISBbits.TRISB4 = _ENTRADA)
#define _PORTB_5_ENTRADA                    (TRISBbits.TRISB5 = _ENTRADA)
#define _PORTB_6_ENTRADA                    (TRISBbits.TRISB6 = _ENTRADA)
#define _PORTB_7_ENTRADA                    (TRISBbits.TRISB7 = _ENTRADA)

#define _PORTB_SAIDA                        (TRISB =  0b00000000)
#define _PORTB_NIBBLE_H_SAIDA               (TRISB &= 0b00001111)
#define _PORTB_NIBBLE_L_SAIDA               (TRISB &= 0b11110000)
#define _PORTB_0_SAIDA                      (TRISBbits.TRISB0 = _SAIDA)
#define _PORTB_1_SAIDA                      (TRISBbits.TRISB1 = _SAIDA)
#define _PORTB_2_SAIDA                      (TRISBbits.TRISB2 = _SAIDA)
#define _PORTB_3_SAIDA                      (TRISBbits.TRISB3 = _SAIDA)
#define _PORTB_4_SAIDA                      (TRISBbits.TRISB4 = _SAIDA)
#define _PORTB_5_SAIDA                      (TRISBbits.TRISB5 = _SAIDA)
#define _PORTB_6_SAIDA                      (TRISBbits.TRISB6 = _SAIDA)
#define _PORTB_7_SAIDA                      (TRISBbits.TRISB7 = _SAIDA)

#define _PORTB_RD                           (PORTB)
#define _PORTB_0_RD                         (PORTAbits.RB0)
#define _PORTB_1_RD                         (PORTAbits.RB1)
#define _PORTB_2_RD                         (PORTAbits.RB2)
#define _PORTB_3_RD                         (PORTAbits.RB3)
#define _PORTB_4_RD                         (PORTAbits.RB4)
#define _PORTB_5_RD                         (PORTAbits.RB5)
#define _PORTB_6_RD                         (PORTAbits.RB6)
#define _PORTB_7_RD                         (PORTAbits.RB7)

#define _PORTB_WR                           (LATB)
#define _PORTB_0_WR                         (LATBbits.LATB0)
#define _PORTB_1_WR                         (LATBbits.LATB1)
#define _PORTB_2_WR                         (LATBbits.LATB2)
#define _PORTB_3_WR                         (LATBbits.LATB3)
#define _PORTB_4_WR                         (LATBbits.LATB4)
#define _PORTB_5_WR                         (LATBbits.LATB5)
#define _PORTB_6_WR                         (LATBbits.LATB6)
#define _PORTB_7_WR                         (LATBbits.LATB7)

//PORTC ----------------------------------------------------------------------
#define _PORTC_DIGITAL                      (ANSELC =  0b00000000)
#define _PORTC_NIBBLE_H_DIGITAL             (ANSELC &= 0b00001111)
#define _PORTC_NIBBLE_L_DIGITAL             (ANSELC &= 0b11110000)
#define _PORTC_2_DIGITAL                    (ANSELCbits.ANSC2 = _DIGITAL)
#define _PORTC_3_DIGITAL                    (ANSELCbits.ANSC3 = _DIGITAL)
#define _PORTC_4_DIGITAL                    (ANSELCbits.ANSC2 = _DIGITAL)
#define _PORTC_5_DIGITAL                    (ANSELCbits.ANSC5 = _DIGITAL)
#define _PORTC_6_DIGITAL                    (ANSELCbits.ANSC6 = _DIGITAL)
#define _PORTC_7_DIGITAL                    (ANSELCbits.ANSC7 = _DIGITAL)

#define _PORTC_ANALOGICO                    (ANSELC =  0b11111111)
#define _PORTC_NIBBLE_H_ANALOGICO           (ANSELC |= 0b11110000)
#define _PORTC_NIBBLE_L_ANALOGICO           (ANSELC |= 0b00001111)
#define _PORTC_2_ANALOGICO                  (ANSELCbits.ANSC2 = _ANALOGICO)
#define _PORTC_3_ANALOGICO                  (ANSELCbits.ANSC3 = _ANALOGICO)
#define _PORTC_4_ANALOGICO                  (ANSELCbits.ANSC2 = _ANALOGICO)
#define _PORTC_5_ANALOGICO                  (ANSELCbits.ANSC5 = _ANALOGICO)
#define _PORTC_6_ANALOGICO                  (ANSELCbits.ANSC6 = _ANALOGICO)
#define _PORTC_7_ANALOGICO                  (ANSELCbits.ANSC7 = _ANALOGICO)

#define _PORTC_ENTRADA                      (TRISC =  0b11111111)
#define _PORTC_NIBBLE_H_ENTRADA             (TRISC |= 0b11110000)
#define _PORTC_NIBBLE_L_ENTRADA             (TRISC |= 0b00001111)
#define _PORTC_0_ENTRADA                    (TRISCbits.TRISC0 = _ENTRADA)
#define _PORTC_1_ENTRADA                    (TRISCbits.TRISC1 = _ENTRADA)
#define _PORTC_2_ENTRADA                    (TRISCbits.TRISC2 = _ENTRADA)
#define _PORTC_3_ENTRADA                    (TRISCbits.TRISC3 = _ENTRADA)
#define _PORTC_4_ENTRADA                    (TRISCbits.TRISC4 = _ENTRADA)
#define _PORTC_5_ENTRADA                    (TRISCbits.TRISC5 = _ENTRADA)
#define _PORTC_6_ENTRADA                    (TRISCbits.TRISC6 = _ENTRADA)
#define _PORTC_7_ENTRADA                    (TRISCbits.TRISC7 = _ENTRADA)

#define _PORTC_SAIDA                        (TRISC =  0b00000000)
#define _PORTC_NIBBLE_H_SAIDA               (TRISC &= 0b00001111)
#define _PORTC_NIBBLE_L_SAIDA               (TRISC &= 0b11110000)
#define _PORTC_0_SAIDA                      (TRISCbits.TRISC0 = _SAIDA)
#define _PORTC_1_SAIDA                      (TRISCbits.TRISC1 = _SAIDA)
#define _PORTC_2_SAIDA                      (TRISCbits.TRISC2 = _SAIDA)
#define _PORTC_3_SAIDA                      (TRISCbits.TRISC3 = _SAIDA)
#define _PORTC_4_SAIDA                      (TRISCbits.TRISC4 = _SAIDA)
#define _PORTC_5_SAIDA                      (TRISCbits.TRISC5 = _SAIDA)
#define _PORTC_6_SAIDA                      (TRISCbits.TRISC6 = _SAIDA)
#define _PORTC_7_SAIDA                      (TRISCbits.TRISC7 = _SAIDA)

#define _PORTC_RD                           (PORTC)
#define _PORTC_0_RD                         (PORTCbits.RC0)
#define _PORTC_1_RD                         (PORTCbits.RC1)
#define _PORTC_2_RD                         (PORTCbits.RC2)
#define _PORTC_3_RD                         (PORTCbits.RC3)
#define _PORTC_4_RD                         (PORTCbits.RC4)
#define _PORTC_5_RD                         (PORTCbits.RC5)
#define _PORTC_6_RD                         (PORTCbits.RC6)
#define _PORTC_7_RD                         (PORTCbits.RC7)

#define _PORTC_WR                           (LATC)
#define _PORTC_0_WR                         (LATCbits.LATC0)
#define _PORTC_1_WR                         (LATCbits.LATC1)
#define _PORTC_2_WR                         (LATCbits.LATC2)
#define _PORTC_3_WR                         (LATCbits.LATC3)
#define _PORTC_4_WR                         (LATCbits.LATC4)
#define _PORTC_5_WR                         (LATCbits.LATC5)
#define _PORTC_6_WR                         (LATCbits.LATC6)
#define _PORTC_7_WR                         (LATCbits.LATC7)

//PORTD ----------------------------------------------------------------------
#define _PORTD_DIGITAL                      (ANSELD =  0b00000000)
#define _PORTD_NIBBLE_H_DIGITAL             (ANSELD &= 0b00001111)
#define _PORTD_NIBBLE_L_DIGITAL             (ANSELD &= 0b11110000)
#define _PORTD_0_DIGITAL                    (ANSELDbits.ANSD0 = _DIGITAL)
#define _PORTD_1_DIGITAL                    (ANSELDbits.ANSD1 = _DIGITAL)
#define _PORTD_2_DIGITAL                    (ANSELDbits.ANSD2 = _DIGITAL)
#define _PORTD_3_DIGITAL                    (ANSELDbits.ANSD3 = _DIGITAL)
#define _PORTD_4_DIGITAL                    (ANSELDbits.ANSD4 = _DIGITAL)
#define _PORTD_5_DIGITAL                    (ANSELDbits.ANSD5 = _DIGITAL)
#define _PORTD_6_DIGITAL                    (ANSELDbits.ANSD6 = _DIGITAL)
#define _PORTD_7_DIGITAL                    (ANSELDbits.ANSD7 = _DIGITAL)

#define _PORTD_ANALOGICO                    (ANSELD =  0b11111111)
#define _PORTD_NIBBLE_H_ANALOGICO           (ANSELD |= 0b11110000)
#define _PORTD_NIBBLE_L_ANALOGICO           (ANSELD |= 0b00001111)
#define _PORTD_0_ANALOGICO                  (ANSELDbits.ANSD0 = _ANALOGICO)
#define _PORTD_1_ANALOGICO                  (ANSELDbits.ANSD1 = _ANALOGICO)
#define _PORTD_2_ANALOGICO                  (ANSELDbits.ANSD2 = _ANALOGICO)
#define _PORTD_3_ANALOGICO                  (ANSELDbits.ANSD3 = _ANALOGICO)
#define _PORTD_4_ANALOGICO                  (ANSELDbits.ANSD4 = _ANALOGICO)
#define _PORTD_5_ANALOGICO                  (ANSELDbits.ANSD5 = _ANALOGICO)
#define _PORTD_6_ANALOGICO                  (ANSELDbits.ANSD6 = _ANALOGICO)
#define _PORTD_7_ANALOGICO                  (ANSELDbits.ANSD7 = _ANALOGICO)

#define _PORTD_ENTRADA                      (TRISD =  0b11111111)
#define _PORTD_NIBBLE_H_ENTRADA             (TRISD |= 0b11110000)
#define _PORTD_NIBBLE_L_ENTRADA             (TRISD |= 0b00001111)
#define _PORTD_0_ENTRADA                    (TRISDbits.TRISD0 = _ENTRADA)
#define _PORTD_1_ENTRADA                    (TRISDbits.TRISD1 = _ENTRADA)
#define _PORTD_2_ENTRADA                    (TRISDbits.TRISD2 = _ENTRADA)
#define _PORTD_3_ENTRADA                    (TRISDbits.TRISD3 = _ENTRADA)
#define _PORTD_4_ENTRADA                    (TRISDbits.TRISD4 = _ENTRADA)
#define _PORTD_5_ENTRADA                    (TRISDbits.TRISD5 = _ENTRADA)
#define _PORTD_6_ENTRADA                    (TRISDbits.TRISD6 = _ENTRADA)
#define _PORTD_7_ENTRADA                    (TRISDbits.TRISD7 = _ENTRADA)

#define _PORTD_SAIDA                        (TRISD =  0b00000000)
#define _PORTD_NIBBLE_H_SAIDA               (TRISD &= 0b00001111)
#define _PORTD_NIBBLE_L_SAIDA               (TRISD &= 0b11110000)
#define _PORTD_0_SAIDA                      (TRISDbits.TRISD0 = _SAIDA)
#define _PORTD_1_SAIDA                      (TRISDbits.TRISD1 = _SAIDA)
#define _PORTD_2_SAIDA                      (TRISDbits.TRISD2 = _SAIDA)
#define _PORTD_3_SAIDA                      (TRISDbits.TRISD3 = _SAIDA)
#define _PORTD_4_SAIDA                      (TRISDbits.TRISD4 = _SAIDA)
#define _PORTD_5_SAIDA                      (TRISDbits.TRISD5 = _SAIDA)
#define _PORTD_6_SAIDA                      (TRISDbits.TRISD6 = _SAIDA)
#define _PORTD_7_SAIDA                      (TRISDbits.TRISD7 = _SAIDA)

#define _PORTD_RD                           (PORTD)
#define _PORTD_0_RD                         (PORTDbits.RD0)
#define _PORTD_1_RD                         (PORTDbits.RD1)
#define _PORTD_2_RD                         (PORTDbits.RD2)
#define _PORTD_3_RD                         (PORTDbits.RD3)
#define _PORTD_4_RD                         (PORTDbits.RD4)
#define _PORTD_5_RD                         (PORTDbits.RD5)
#define _PORTD_6_RD                         (PORTDbits.RD6)
#define _PORTD_7_RD                         (PORTDbits.RD7)

#define _PORTD_WR                           (LATD)
#define _PORTD_0_WR                         (LATDbits.LATD0)
#define _PORTD_1_WR                         (LATDbits.LATD1)
#define _PORTD_2_WR                         (LATDbits.LATD2)
#define _PORTD_3_WR                         (LATDbits.LATD3)
#define _PORTD_4_WR                         (LATDbits.LATD4)
#define _PORTD_5_WR                         (LATDbits.LATD5)
#define _PORTD_6_WR                         (LATDbits.LATD6)
#define _PORTD_7_WR                         (LATDbits.LATD7)

//PORTE ----------------------------------------------------------------------
#define _PORTE_DIGITAL                      (ANSELE =  0b00000000)
#define _PORTE_NIBBLE_H_DIGITAL             (ANSELE &= 0b00001111)
#define _PORTE_NIBBLE_L_DIGITAL             (ANSELE &= 0b11110000)
#define _PORTE_0_DIGITAL                    (ANSELEbits.ANSE0 = _DIGITAL)
#define _PORTE_1_DIGITAL                    (ANSELEbits.ANSE1 = _DIGITAL)
#define _PORTE_2_DIGITAL                    (ANSELEbits.ANSE2 = _DIGITAL)

#define _PORTE_ANALOGICO                    (ANSELE =  0b11111111)
#define _PORTE_NIBBLE_H_ANALOGICO           (ANSELE |= 0b11110000)
#define _PORTE_NIBBLE_L_ANALOGICO           (ANSELE |= 0b00001111)
#define _PORTE_0_ANALOGICO                  (ANSELEbits.ANSE0 = _ANALOGICO)
#define _PORTE_1_ANALOGICO                  (ANSELEbits.ANSE1 = _ANALOGICO)
#define _PORTE_2_ANALOGICO                  (ANSELEbits.ANSE2 = _ANALOGICO)

#define _PORTE_ENTRADA                      (TRISE =  0b11111111)
#define _PORTE_NIBBLE_H_ENTRADA             (TRISE |= 0b11110000)
#define _PORTE_NIBBLE_L_ENTRADA             (TRISE |= 0b00001111)
#define _PORTE_0_ENTRADA                    (TRISEbits.TRISE0 = _ENTRADA)
#define _PORTE_1_ENTRADA                    (TRISEbits.TRISE1 = _ENTRADA)
#define _PORTE_2_ENTRADA                    (TRISEbits.TRISE2 = _ENTRADA)

#define _PORTE_SAIDA                        (TRISE =  0b00000000)
#define _PORTE_NIBBLE_H_SAIDA               (TRISE &= 0b00001111)
#define _PORTE_NIBBLE_L_SAIDA               (TRISE &= 0b11110000)
#define _PORTE_0_SAIDA                      (TRISEbits.TRISE0 = _SAIDA)
#define _PORTE_1_SAIDA                      (TRISEbits.TRISE1 = _SAIDA)
#define _PORTE_2_SAIDA                      (TRISEbits.TRISE2 = _SAIDA)

#define _PORTE_RD                           (PORTE)
#define _PORTE_0_RD                         (PORTEbits.RE0)
#define _PORTE_1_RD                         (PORTEbits.RE1)
#define _PORTE_2_RD                         (PORTEbits.RE2)
#define _PORTE_3_RD                         (PORTEbits.RE3)

#define _PORTE_WR                           (LATE)
#define _PORTE_0_WR                         (LATEbits.LATE0)
#define _PORTE_1_WR                         (LATEbits.LATE1)
#define _PORTE_2_WR                         (LATEbits.LATE2)

#endif	/* PORTAS_IO_H */

