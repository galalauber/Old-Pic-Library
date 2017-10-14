/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 3 de Outubro de 2016, 19:33
 */


#include <xc.h>

#include "Display de Leds.h"
#include "Oscilador.h"


//Definições do aplicativo
#define CRESCENTE   0
#define DECRESCENTE 1


//Alocação de memória
Uchar   Contador;
Uchar   SentidoDaContagem;
_Codigo7segmentos;


void Atrasos_1ms (Uint Tempo)
{
    while (Tempo-- > 0)
    {
        __delay_ms(1);
    }
}


void main(void)
{
    Oscilador_Inicializacao();
    Display_Inicializacao();
    Display_LigaDigito(_Digito6,_br);
    
    Contador = 0;
    SentidoDaContagem = CRESCENTE;
    
    while (1)
    {
        Display_ExibeCaractere(Codigo7segmentos[Contador]);
        
        Atrasos_1ms(1000);
        
        if (SentidoDaContagem == CRESCENTE)
        {
            Contador++;
            if (Contador == 9)SentidoDaContagem = DECRESCENTE;
        }
        else
        {
            Contador--;
            if (Contador == 0)SentidoDaContagem = CRESCENTE;
        }
    }
      }
