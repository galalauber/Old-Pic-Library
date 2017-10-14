/* 
 * Arquivo: Controle de Rotinas.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include "Definicoes Gerais.h"
#include "Controle de Rotinas.h"


//Alocação de memória para o módulo -------------------------------------------
_CtrlRotinas    CtrlRotinas;



//Funções locais --------------------------------------------------------------





//Funções publicas ------------------------------------------------------------

/*
 * Rotinas_Inicializacao
 * Faz a inicialização do módulo de controle de rotinas. Todos os ponteiros de
 * controle de fluxo são zerados
 */
void Rotinas_Inicializacao (void)
{
    CtrlRotinas.Controle.Cabecalho1 = _SIM;
    Rotinas_ArmazenaFluxo();
}


/*
 * Rotinas_ArmazenaFluxo
 * Faz o backup do controle de fluxo atual
 */
void Rotinas_ArmazenaFluxo (void)
{
    CtrlRotinas.Retorno.Nivel1.Valor = CtrlRotinas.Fluxo.Nivel1.Valor;
    CtrlRotinas.Retorno.Nivel1.ValorMaximo = CtrlRotinas.Fluxo.Nivel1.ValorMaximo;      
    
    CtrlRotinas.Retorno.Nivel2.Valor = CtrlRotinas.Fluxo.Nivel2.Valor;
    CtrlRotinas.Retorno.Nivel2.ValorMaximo = CtrlRotinas.Fluxo.Nivel2.ValorMaximo;    
    
    CtrlRotinas.Retorno.Nivel3.Valor = CtrlRotinas.Fluxo.Nivel3.Valor;
    CtrlRotinas.Retorno.Nivel3.ValorMaximo = CtrlRotinas.Fluxo.Nivel3.ValorMaximo;    
    
    CtrlRotinas.Retorno.Nivel4.Valor = CtrlRotinas.Fluxo.Nivel4.Valor;
    CtrlRotinas.Retorno.Nivel4.ValorMaximo = CtrlRotinas.Fluxo.Nivel4.ValorMaximo;
}

/*
 * Rotinas_RestauraFluxo
 * Restaura o backup do fluxo
 */
void Rotinas_RestauraFluxo (void)
{
    CtrlRotinas.Fluxo.Nivel1.Valor = CtrlRotinas.Retorno.Nivel1.Valor;
    CtrlRotinas.Fluxo.Nivel1.ValorMaximo= CtrlRotinas.Retorno.Nivel1.ValorMaximo;    

    CtrlRotinas.Fluxo.Nivel2.Valor = CtrlRotinas.Retorno.Nivel2.Valor;
    CtrlRotinas.Fluxo.Nivel2.ValorMaximo= CtrlRotinas.Retorno.Nivel2.ValorMaximo;      
    
    CtrlRotinas.Fluxo.Nivel3.Valor = CtrlRotinas.Retorno.Nivel3.Valor;
    CtrlRotinas.Fluxo.Nivel3.ValorMaximo= CtrlRotinas.Retorno.Nivel3.ValorMaximo;      

    CtrlRotinas.Fluxo.Nivel4.Valor = CtrlRotinas.Retorno.Nivel4.Valor;
    CtrlRotinas.Fluxo.Nivel4.ValorMaximo= CtrlRotinas.Retorno.Nivel4.ValorMaximo;      
}

/*
 * Rotinas_CarregaNivel
 * Carrega os valores de determinado nivel do controle de fluxo.
 */
void Rotinas_CarregaNivel (_Nivel *Nivel, Uchar Valor, Uchar Maximo)
{
    Nivel->Valor = Valor;
    Nivel->ValorMaximo = Maximo;
}

/*
 * Rotinas_IncrementaNivel
 * Incrementa o valor do nivel especificado do controle de fluxo impedindo
 * que o valor máximo seja ultrapassado.
 */
void Rotinas_IncrementaNivel (_Nivel *Nivel)
{
    Nivel->Valor++;
    
    if (Nivel->Valor > Nivel->ValorMaximo)
    {
        Nivel->Valor = Nivel->ValorMaximo;
    } 
}

/*
 * Rotinas_DecrementaNivel
 * Decrementa o valor do nivel especificado do controle de fluxo impedindo
 * que o valor minimo seja menor que 1.
 */
void Rotinas_DecrementaNivel (_Nivel *Nivel)
{
    Nivel->Valor--;
    
    if (Nivel->Valor < 1)
    {
        Nivel->Valor = 1;
    } 
}

/*
 * Rotinas_PedidoDeAtualizacao
 * Força a tualização da rotina
 */
void Rotinas_PedidoDeAtualizacao (void)
{
    CtrlRotinas.Controle.Atualizacao = _SIM;
}

/*
 * Rotinas_Atualizacao
 * Detecta se o corpo da rotina deve ou não ser atualizado. Se sim, retorna 1,
 * e remove o evento de atualização. Se não, retorna 0. 
 */
unsigned char Rotinas_Atualizacao (void)
{
    if (CtrlRotinas.Controle.Atualizacao == _SIM)
    {
        CtrlRotinas.Controle.Atualizacao = _NAO;
        return 1;
    }
    else  return 0;
}

/*
 * Rotinas_ExecutarCabecalho
 * Detecta se o cabeçalho da rotina deve ou não ser executado.
 * Sempre que o controle de fluxo da rotina for igual a zero, o valor 1 é
 * retornado para indicar que o cabeçalho deve ser execurado. O byte que 
 * controla o fluxo da rotina é atualizado para 1 e um evento é gerado para
 * forçar  a atualização da rotina.
 */
unsigned char Rotinas_ExecutarCabecalho (unsigned char Nivel)
{
    unsigned char Retorno;
    
    Retorno = _NAO;
    
    switch (Nivel)
    {
        case 1:
            if (CtrlRotinas.Controle.Cabecalho1 == 1)
            {
                CtrlRotinas.Controle.Cabecalho1 = 0;
                Rotinas_PedidoDeAtualizacao();
                Retorno = _SIM;
            }
            break;
        
        case 2:
            if (CtrlRotinas.Controle.Cabecalho2 == 1)
            {
                CtrlRotinas.Controle.Cabecalho2 = 0;
                Rotinas_PedidoDeAtualizacao();
                Retorno = _SIM;
            }
            break;
            
        case 3:
            if (CtrlRotinas.Controle.Cabecalho3 == 1)
            {
                CtrlRotinas.Controle.Cabecalho3 = 0;
                Rotinas_PedidoDeAtualizacao();
                Retorno = _SIM;
            }
            break;

        case 4:
            if (CtrlRotinas.Controle.Cabecalho4 == 1)
            {
                CtrlRotinas.Controle.Cabecalho4 = 0;
                Rotinas_PedidoDeAtualizacao();
                Retorno = _SIM;
            }
    }
    
    return Retorno;
}


