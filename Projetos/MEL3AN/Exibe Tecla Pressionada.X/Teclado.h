/* 
 * Arquivo: Teclado.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef TECLADO_H
#define	TECLADO_H

#include <xc.h>
#include "Definicoes Gerais.h"

//Modos de opera��o do teclado
#define _MANUAL             0
#define _PERIODICO          1
#define _DIRETO             2
#define _RECUO              3


//Defini��e do m�dulo --------------------------------------------------------
#define _S1                 PORTAbits.RA0
#define _S2                 PORTAbits.RA1
#define _S3                 PORTAbits.RA3
#define _S4                 PORTAbits.RA4
#define _S5                 PORTAbits.RA5


#define _PRESSIONADA        0
#define _NPRESSIONADA       1



#include "Teclado Config.h"
//Estruturas do m�dulo --------------------------------------------------------




//Publica��o das fun��es do m�dulo -------------------------------------------
void Teclado_Inicializacao (void);



//Publica��o das vari�veis do m�dulo -----------------------------------------



//Fun��es estendidas ---------------------------------------------------------
#if (TECLADO_FUNCOES_ESTENDIDAS == _SIM)

typedef struct
{
    struct
    {
        union
        {
            Uint Valor;
            
            struct
            {
                Uint Recuo:1;
                
            };
        };
    }Controle;
        
    struct
    {
        union
        {
            Uint Valor;
            
            struct
            {
                Uint S1:1;
                Uint S2:1;
                Uint S3:1;
                Uint S4:1;
                Uint S5:1;
            };
        };
    }Eventos;
}_Ctrl_Teclado;


//Publica��o das fun��es do m�dulo --------------------------------------------
void Teclado_Monitor(void);
Uchar Tecla_Pressionada (Uchar Tecla);

//Publica��o das vari�veis do m�dulo ------------------------------------------
extern _Ctrl_Teclado       Ctrl_Teclado;
#endif

#endif	/* TECLADO_H */

