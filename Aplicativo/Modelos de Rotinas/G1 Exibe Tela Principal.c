/* 
 * Arquivo: G1_ExibeTelaPrincipal.c
 * Autor:   JABNeto
 * Versao:  
 */

#include <stdio.h>
#include "Definicoes Gerais.h"
#include "Controle de Rotinas.h"
#include "Display lcd alfa.h"
#include "G1 Exibe Tela Principal.h"
#include "Controle do Forno.h"


//Aloca��o de mem�ria para o m�dulo -------------------------------------------



//Fun��es do m�dulo -----------------------------------------------------------

/*
 * G1_ExibeTelaPrincipal
 * Exibe a tela principla no display
 */
void G1_ExibeTelaPrincipal (void)
{
    //Cabe�alho//
    if (Rotinas_ExecutarCabecalho(2) == _SIM)
    {
        Lcd_CriaCaractereNaCGRAM(0,&CGRAM_EP[0]);

    }

    
    //Atualiza��o//
    if (Rotinas_Atualizacao() == _SIM)
    {
        Uchar Stream[4];
        Uchar *Pnt;
        
        Lcd_LimpaBuffers();
        


        Lcd_AtualizaDisplay();
    }    

    //Teclado//
//    if (Teclado_EventoDaTecla(UP) == _SIM){};     
//    Teclado_RemoveEventoDaTecla(DOWN);

}
