/* 
 * Arquivo: Teclado.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef TECLADO_H
#define	TECLADO_H

#include <xc.h>
#include "Definicoes Gerais.h"


//Definicoes do m�dulo --------------------------------------------------------
#define _RECUO              0       
#define _TRANSPARENTE       1
#define _DISPARO            2


//Configura��es do usu�rio ----------------------------------------------------
#include "Teclado Config.h"



//Processamento das configura��es do usu�rio ----------------------------------




//Estruturas do m�dulo --------------------------------------------------------
typedef struct
{
    struct
    {
        Uchar Amostras;
        Uchar Disparos;
        Uint  Aguardo;
    }Temporizadores;
    
    union
    {
        Uchar valor;
        
        struct
        {
            Uint Recuo:1;
            Uint Disparo:1;
            Uint Amostras:1;            
        };
    }Controle;
    
    union
    {
        Uchar valor;
        
        struct
        {
            Uint Tecla1:1;
            Uint Tecla2:1;
            Uint Tecla3:1;
            Uint Tecla4:1;            
            Uint Tecla5:1;
            Uint Tecla6:1;            
            Uint Tecla7:1;
            Uint Tecla8:1;            
        };
    }Eventos;
}_Ctrl_Teclado;


//Publica��o das fun��es do m�dulo --------------------------------------------
void Teclado_Inicializacao (void);
void Teclado_Monitor (void);
unsigned char Tecla_Pressionada (unsigned char Tecla);


//Pubilca��o das vari�veis do m�dulo ------------------------------------------
extern _Ctrl_Teclado Ctrl_Teclado;

#endif	/* TECLADO_H */

