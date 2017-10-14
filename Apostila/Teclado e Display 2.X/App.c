/* 
 * Projeto: Teclado e Display 2
 * Arquivo: App.c
 * Autor:   JABNeto
 * Data:    10/02/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "Base_1.h"

//Alocação de memória para o Módulo-------------------
const char Codigo_7seg[] = {_0,_1,_2,_3,_4,_5};

Uchar   Contador;


//Rotina Principal
int main(int argc, char** argv)
{
    Display_Inicializacao(0,_Digito1);
    Teclado_Inicializacao();
    
    Contador = 0;

    while(1)
    {
        if (_S1==Pressionada) Contador++;
        if (_S2==Pressionada) Contador++;
        if (_S3==Pressionada) Contador++;
        if (_S4==Pressionada) Contador++;
        if (_S5==Pressionada) Contador++;
        
        LATB = Codigo_7seg[Contador];
        Contador = 0;
    }

    return (EXIT_SUCCESS);
}









