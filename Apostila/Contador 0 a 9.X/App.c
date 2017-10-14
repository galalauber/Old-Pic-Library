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
#include "Atrasos.h"

//Alocação de memória para o Módulo-------------------
const char Codigo_7seg[] = {_0,_1,_2,_3,_4,
                            _5,_6,_7,_8,_9};  

Ulong   Contador;

int main(int argc, char** argv)
{
    Oscilador_Inicializacao();
    Display_Inicializacao(0,_Digito6);
    Contador = 0;
    
    while(1)
    {
       LATB = Codigo_7seg[Contador];
       
       Atrasos_1ms(1000);
       
       if(++Contador == 10) Contador = 0;
    }
        
    return (EXIT_SUCCESS);
}

