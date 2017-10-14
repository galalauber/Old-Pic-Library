/*
 * File:   app.c
 * Author: jose_010573
 *
 * Created on 3 de Outubro de 2016, 19:33
 */


#include <xc.h>

#include "Display de Leds.h"
#include "Oscilador.h"


//Alocação de memória
Schar Contador;
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
    
    Contador = 9;
    
    while (1)
    {
        Display_ExibeCaractere(Codigo7segmentos[Contador]);
        
        Atrasos_1ms(1000);
        
        Contador--;
        if (Contador == -1) Contador = 9;

    }
}
