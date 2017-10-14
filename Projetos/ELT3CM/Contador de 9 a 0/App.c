         /*
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 1 de Junho de 2016, 11:09
 */


#include <xc.h>

#include "Display de Leds.h"
#include "Teclado.h"
#include "Oscilador.h"

_Codigo7segmentos;
signed char Contador;


//Funções Locais
void Atrasos_1ms (unsigned int Atraso)
{
    while (Atraso-- > 0)
    {
        __delay_ms(1);
    }
}

void main(void)
{
    Oscilador_Inicializacao();
    Display_Inicializacao();
    Teclado_Inicializacao();
    Display_LigaDigito(_Digito6,_br);

    Contador = 9;
    
    while (1)
    {
        Display_ExibeCaractere(Codigo7segmentos[Contador]);
        
        Atrasos_1ms(1000);
        
        Contador--;
        
        if (Contador == -1    ) Contador = 9;
        
    }
}
