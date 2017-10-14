/* 
 * Arquivo: G1_ExibeTelaPrincipal.c
 * Autor:   JABNeto
 * Versao:  
 */

#include "Definicoes Gerais.h"
#include "Controle de Rotinas.h"
#include "Display lcd alfa.h"
#include "Atrasos.h"
#include "G1 Exibe Nome do Produto.h"


//Alocação de memória para o módulo -------------------------------------------
const char Msg_Produto[]=      "[Produto]";


//Funções do módulo -----------------------------------------------------------

/*
 * G1_ExibeNomeDoProduto
 * Exibe o nome do produto no display
 */
void G1_ExibeNomeDoProduto (void)
{
    //Cabeçalho//
    if (Rotinas_ExecutarCabecalho(2) == _SIM)
    {


    }

    
    //Atualização//
    if (Rotinas_Atualizacao() == _SIM)
    {
        Lcd_LimpaBuffers();
        
        //Linha1
        Lcd_TransfereMensagemParaBuffer(&CtrlDisplay.BufferLinha1[3],
                                        &Msg_Produto[0]);
        
        Lcd_AtualizaDisplay();        

        Atrasos_1ms(5000);
        Rotinas_CarregaNivel(1,0);
    }    

    //Teclado//
    //Teclado_RemoveEventosDasTeclas();
}
