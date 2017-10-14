/* 
 * Projeto: Teclado e Display 1
 * Arquivo: App.c
 * Autor:   JABNeto
 * Data:    10/02/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "Base_1.h"
#include "Oscilador.h"


//Prot�tipos das fun��es -----------------------------
void Timer0_Inicializacao (void);
void Timer0_Recarga (void);


//Aloca��o de mem�ria para o m�dulo-------------------
Ulong Contador;

struct
{
    Uchar   Temporizador100ms;

    union
    {
        Uchar Valor;
        
        struct
        {
            Uchar Contador:1;            
            
        };
    }EventosDe100ms;
}TMR0_Eventos;


//Fun��es do m�dulo ----------------------------------
int main(int argc, char** argv)
{
    Oscilador_Inicializacao();
    Display_InicializaVarredura();
    Timer0_Inicializacao();
    
    Contador = 0;
    Varredura.Opcoes.OmiteZeros = _SIM;
    Varredura.Opcoes.ExibePonto5 = _SIM;
    Display_ExibeNumero(Contador);
    
    INTCONbits.GIEH = 1;
    
    while(1)
    {
        if(TMR0_Eventos.EventosDe100ms.Contador == 1)
        {
            TMR0_Eventos.EventosDe100ms.Contador = 0;
            
            if (++Contador == 10000) Contador = 0;
            Display_ExibeNumero(Contador);
        }
    }
        
    return (EXIT_SUCCESS);
}


/* Interrupt_High
 * Atendimento das interrup��es de alta prioridade
 */
void interrupt high_priority Interrupt_High(void)
{
    
    if ((INTCONbits.TMR0IE == 1) &&
        (INTCONbits.TMR0IF == 1))
    {
        Timer0_Recarga();
        
        if(--TMR0_Eventos.Temporizador100ms == 0)
        {
            TMR0_Eventos.Temporizador100ms = 100;
            TMR0_Eventos.EventosDe100ms.Valor = 0xFF;
        }
        
        //Fun��es do usu�rio -------------------------
        Display_ExecutaVarredura();
    }
}

