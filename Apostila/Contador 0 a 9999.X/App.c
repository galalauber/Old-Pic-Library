/* 
 * Projeto: Teclado e Display 1
 * Arquivo: App.c
 * Autor:   JABNeto
 * Data:    10/02/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "Base_1.h"
#include "Oscilador.h"


//Protótipos das funções -----------------------------
void Timer0_Inicializacao (void);
void Timer0_Recarga (void);


//Alocação de memória para o módulo-------------------
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


//Funções do módulo ----------------------------------
int main(int argc, char** argv)
{
    Oscilador_Inicializacao();
    Display_InicializaVarredura();
    Timer0_Inicializacao();
    
    Contador = 0;
    Varredura.Opcoes.OmiteZeros = Sim;
    Varredura.Opcoes.ExibePonto5 = Sim;
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

/* Timer0_Inicializacao
 * Carrega os registradores TMR0H:TMR0L
 * TMR0H:TMR0L = 65536 - ((Tempo * Fop)/Prescaler))
 */
void Timer0_Inicializacao (void)
{
    T0CON = 0;
    T0CONbits.PSA = 1;
    Timer0_Recarga();
    INTCONbits.T0IE = 1;
    TMR0_Eventos.Temporizador100ms = 100;
    TMR0_Eventos.EventosDe100ms.Valor = 0;
    T0CONbits.TMR0ON = 1;
}

/* Timer0_Recarga
 * Carrega os registradores TMR0H:TMR0L
 * TMR0H:TMR0L = 65536 - ((Tempo * Fop)/Prescaler))
 * Tempo = 1ms
 * Fop = 8MHz
 * Prescaler = 1;
 * TMR0H:TMR0L = 57536
 */
void Timer0_Recarga (void)
{
    Uint16 ValorDeCarga;
    
    INTCONbits.TMR0IF = 0;    

    ValorDeCarga.valor = 57536;
    
    TMR0H = ValorDeCarga.bytes.byte1;
    TMR0L = ValorDeCarga.bytes.byte0;
}

/* Interrupt_High
 * Atendimento das interrupções de alta prioridade
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
        
        //Funções do usuário -------------------------
        Display_ExecutaVarredura();
    }
}

