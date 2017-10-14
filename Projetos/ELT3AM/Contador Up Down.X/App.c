/*
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 21 de Setembro de 2016, 07:12
 */


#include <xc.h>

#include "Oscilador.h"
#include "Display de Leds.h"
#include "Atrasos.h"



#define CRESCENTE   0
#define DECRESCENTE 1


//Alocação de memória
Uchar   Contador;
Uchar   SentidoDaContagem;
_Codigo7segmentos;

void main(void)
{
    Oscilador_Inicializacao();
    Display_Inicializacao();
    Display_LigaDigito(_Digito6,_br);
    
    SentidoDaContagem = CRESCENTE;
    Contador = 0;

    while(1)
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
           if (Contador == 0) SentidoDaContagem = CRESCENTE;
       }
           }
}
