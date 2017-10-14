/*
 * File:   App.c
 * Author: Glauber
 *
 * Created on 17 de Setembro de 2017, 17:51
 */


#include <xc.h>
#include "Base_1.h"
#include "Definicoes Gerais.h"
#include "Interrupcoes.h"
#include "Oscilador.h"
#include "Timer0.h"

void main(void) {
    Ulong numero = 0;
    Display_Inicializacao(_Digito6,_br);
    Teclado_Inicializacao();
    Oscilador_Inicializacao();
    Timer0_Inicializacao();
    Habilita_Interrupcoes();
    Display_InicializaVarredura();
    
    while (1) {
        Display_ExibeNumero(numero);
        Display_ExecutaVarredura();
        
        if (Eventos1s.Evento1 == _SIM)
        {
            Eventos1s.Evento1 = _NAO;
            numero++;            
        }
        
    }

    return;
}
