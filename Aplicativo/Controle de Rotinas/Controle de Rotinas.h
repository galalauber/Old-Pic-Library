/* 
 * Arquivo: Controle de Rotinas.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef CONTROLE_DE_ROTINAS_H
#define	CONTROLE_DE_ROTINAS_H

#include "Definicoes Gerais.h"

//Definicoes do m�dulo --------------------------------------------------------
#define _ROTINAS_TEMPO_DE_ATUALIZACAO_MS            250
#define _ROTINAS_TEMPO_RETORNO_HOME_S               120
#define _ROTINAS_NUMERO_DE_NIVEIS                   3


//Estruturas do m�dulo --------------------------------------------------------
typedef struct
{
    Uchar Valor;
    Uchar ValorMaximo;
    Uchar Memoria;
    
    union
    {
        Uchar Valor;
        
        struct
        {
            Uint ExecutarCabecalho:1;
        };
    }Controle;
}_Nivel;


typedef struct
{
    _Nivel  Nivel[_ROTINAS_NUMERO_DE_NIVEIS];    
    Ulong   TempoDeRetorno;
    
    struct
    {  
        Uint Tempo_ms;
        
        union
        {
            Uchar Valor;
            
            struct
            {
                Uint Atualizar:1;
            };            
        }Sinais;
    }Atualizacao;
}_CtrlRotinas;



//Publica��o das fun��es do m�dulo --------------------------------------------
void Rotinas_Inicializacao (void);
void Rotinas_Monitor (void);
void Rotinas_ArmazenaFluxo (void);
void Rotinas_RestauraFluxo (void);
void Rotinas_ObrigaAtualizacao(void);
void Rotinas_ConfiguraNivel (Uchar Nivel, Uchar Valor, Uchar Maximo);
void Rotinas_CarregaNivel (Uchar Nivel, Uchar Valor);
void Rotinas_IncrementaNivel (Uchar Nivel);
void Rotinas_DecrementaNivel (Uchar Nivel);

unsigned char Rotinas_ExecutarCabecalho (Uchar Nivel);
unsigned char Rotinas_Atualizacao (void);




//Publica��o das vari�veis do m�dulo ------------------------------------------
extern _CtrlRotinas    CtrlRotinas;

#endif	/* CONTROLE_DE_ROTINAS_H */

