/* 
 * Arquivo: Teclado.h
 * Autor:   JABNeto
 * Versao:  
 */

#ifndef TECLADO_H
#define	TECLADO_H

#include <xc.h>
#include "Definicoes Gerais.h"


//Definições do módulo --------------------------------------------------------

#define TECLADO_NUMERO_DE_COLUNAS           4
#define TECLADO_COLUNA_1                    LATAbits.LATA0
#define TECLADO_COLUNA_2                    LATAbits.LATA1
#define TECLADO_COLUNA_3                    LATAbits.LATA2
#define TECLADO_COLUNA_4                    LATAbits.LATA3


#define TECLADO_NUMERO_DE_LINHAS            4
#define TECLADO_LINHA_1                     PORTCbits.RC0
#define TECLADO_LINHA_2                     PORTCbits.RC1
#define TECLADO_LINHA_3                     PORTCbits.RC5
#define TECLADO_LINHA_4                     PORTCbits.RC6



//Estruturas do módulo --------------------------------------------------------
typedef struct
{
    struct
    {
        Uchar   Sequencia;
        Uint8   Amostras[4];
        
        union
        {
            Uchar Valor;
            
            struct
            {
                Uchar Recuo:1;
            };
        }Sinais;
    }Varredura;
    

    union
    {
        Uint Valor;
        
        struct
        {
            Uint    Tecla1:1;
            Uint    Tecla2:1;
            Uint    Tecla3:1;
            Uint    Tecla4:1;            
            Uint    Tecla5:1;            
            Uint    Tecla6:1;            
            Uint    Tecla7:1;   
            Uint    Tecla8:1; 
            Uint    Tecla9:1; 
            Uint    Tecla10:1; 
            Uint    Tecla11:1; 
            Uint    Tecla12:1; 
            Uint    Tecla13:1; 
            Uint    Tecla14:1; 
            Uint    Tecla15:1; 
            Uint    Tecla16:1;             
        };
    }Eventos;

}ObjTeclado;



#endif	/* TECLADO_H */

