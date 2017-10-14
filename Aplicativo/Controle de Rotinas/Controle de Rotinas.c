/* 
 * Arquivo: Controle de Rotinas.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include "Definicoes Gerais.h"
#include "Controle de Rotinas.h"


//Aloca��o de mem�ria para o m�dulo -------------------------------------------
_CtrlRotinas    CtrlRotinas;



//Fun��es locais --------------------------------------------------------------





//Fun��es publicas ------------------------------------------------------------

/*
 * Rotinas_Inicializacao
 * Faz a inicializa��o do m�dulo de controle de rotinas. Todos os ponteiros de
 * controle de fluxo s�o zerados
 */
void Rotinas_Inicializacao (void)
{
    Rotinas_ConfiguraNivel (0,0,2);
    
    CtrlRotinas.Atualizacao.Tempo_ms = (Uint)_ROTINAS_TEMPO_DE_ATUALIZACAO_MS;
    CtrlRotinas.TempoDeRetorno = ((Ulong)_ROTINAS_TEMPO_RETORNO_HOME_S * 1000);
    CtrlRotinas.Nivel[0].Controle.ExecutarCabecalho = _SIM;

    Rotinas_ArmazenaFluxo();
}


/*
 * Rotinas_Monitor
 * Faz o monitoramento do controle das rotinas
 */
void Rotinas_Monitor (void)
{
    if (--CtrlRotinas.Atualizacao.Tempo_ms == 0)
    {
        CtrlRotinas.Atualizacao.Tempo_ms = _ROTINAS_TEMPO_DE_ATUALIZACAO_MS;
        CtrlRotinas.Atualizacao.Sinais.Atualizar = _SIM;
    }
    
    if (CtrlRotinas.TempoDeRetorno > 0)
    {
        if (--CtrlRotinas.TempoDeRetorno == 0)
        {
            Rotinas_Inicializacao();           
        }
    }
}

/*
 * Rotinas_ArmazenaFluxo
 * Faz o backup do controle de fluxo atual
 */
void Rotinas_ArmazenaFluxo (void)
{
    Uchar i;
    
    for (i = 0; i < _ROTINAS_NUMERO_DE_NIVEIS; i++)
    {
       CtrlRotinas.Nivel[i].Memoria = CtrlRotinas.Nivel[i].Valor; 
    }
}

/*
 * Rotinas_RestauraFluxo
 * Restaura o backup do fluxo
 */
void Rotinas_RestauraFluxo (void)
{
    Uchar i;
    
    for (i = 0; i < _ROTINAS_NUMERO_DE_NIVEIS; i++)
    {
       CtrlRotinas.Nivel[i].Valor = CtrlRotinas.Nivel[i].Memoria; 
    }
}

/*
 * Rotinas_ConfiguraNivel
 * Carrega os valores de determinado nivel do controle de fluxo.
 */
void Rotinas_ConfiguraNivel (Uchar Nivel, Uchar Valor, Uchar Maximo)
{
    CtrlRotinas.Nivel[Nivel].Valor = Valor;
    CtrlRotinas.Nivel[Nivel].ValorMaximo = Maximo;
    CtrlRotinas.Nivel[Nivel + 1].Controle.ExecutarCabecalho = _SIM; 
}

/*
 * Rotinas_CarregaNivel
 * Carrega o valor do nivel especificado
 */
void Rotinas_CarregaNivel (Uchar Nivel, Uchar Valor)
{
    CtrlRotinas.Nivel[Nivel].Valor = Valor;
    CtrlRotinas.Nivel[Nivel + 1].Controle.ExecutarCabecalho = _SIM;    
}

/*
 * Rotinas_IncrementaNivel
 * Incrementa o valor do nivel especificado do controle de fluxo impedindo
 * que o valor m�ximo seja ultrapassado.
 */
void Rotinas_IncrementaNivel (Uchar Nivel)
{
    if (CtrlRotinas.Nivel[Nivel].Valor < CtrlRotinas.Nivel[Nivel].ValorMaximo)
    {
        CtrlRotinas.Nivel[Nivel].Valor++;
        CtrlRotinas.Nivel[Nivel + 1].Controle.ExecutarCabecalho = _SIM;
    }
}

/*
 * Rotinas_DecrementaNivel
 * Decrementa o valor do nivel especificado do controle de fluxo impedindo
 * que o valor minimo seja menor que 1.
 */
void Rotinas_DecrementaNivel (Uchar Nivel)
{
    if (CtrlRotinas.Nivel[Nivel].Valor > 0)
    {
        CtrlRotinas.Nivel[Nivel].Valor--;
        CtrlRotinas.Nivel[Nivel + 1].Controle.ExecutarCabecalho = _SIM;
    }
}

/*    
 * Rotinas_ObrigaAtualizacao
 * For�a a tualiza��o da rotina
 */
void Rotinas_ObrigaAtualizacao (void)
{
    CtrlRotinas.Atualizacao.Sinais.Atualizar = _SIM;
}

/*
 * Rotinas_Atualizacao
 * Detecta se o corpo da rotina deve ou n�o ser atualizado. Se sim, retorna 1,
 * e remove o evento de atualiza��o. Se n�o, retorna 0. 
 */
unsigned char Rotinas_Atualizacao (void)
{
    if (CtrlRotinas.Atualizacao.Sinais.Atualizar == _SIM)
    {
        CtrlRotinas.Atualizacao.Sinais.Atualizar = _NAO;
        return 1;
    }
    else  return 0;
}

/*
 * Rotinas_ExecutarCabecalho
 * Detecta se o cabe�alho da rotina deve ou n�o ser executado.
 * Sempre que o controle de fluxo da rotina for igual a zero, o valor 1 �
 * retornado para indicar que o cabe�alho deve ser execurado. O byte que 
 * controla o fluxo da rotina � atualizado para 1 e um evento � gerado para
 * for�ar  a atualiza��o da rotina.
 */
unsigned char Rotinas_ExecutarCabecalho (Uchar Nivel)
{
    Uchar Retorno = _NAO;

    if (CtrlRotinas.Nivel[Nivel].Controle.ExecutarCabecalho == _SIM)
    {
        CtrlRotinas.Nivel[Nivel].Controle.ExecutarCabecalho = _NAO;
        Rotinas_ObrigaAtualizacao();
        Retorno = _SIM;        
    }
    return Retorno;
}


