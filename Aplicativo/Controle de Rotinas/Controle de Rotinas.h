/* 
 * Arquivo: Controle de Rotinas.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef CONTROLE_DE_ROTINAS_H
#define	CONTROLE_DE_ROTINAS_H

#include "Definicoes Gerais.h"

//Definicoes do módulo --------------------------------------------------------




//Estruturas do módulo --------------------------------------------------------
typedef struct
{
    Uchar Valor;
    Uchar ValorMaximo;     
}_Nivel;


typedef struct
{
    struct
    {
        _Nivel Nivel1;
        _Nivel Nivel2;
        _Nivel Nivel3;
        _Nivel Nivel4;
    }Fluxo;
    
    struct
    {
        _Nivel Nivel1;
        _Nivel Nivel2;
        _Nivel Nivel3;
        _Nivel Nivel4;
    }Retorno;
    
    union
    {  
        Uchar valor;
        
        struct
        {
            Uint Cabecalho1:1;
            Uint Cabecalho2:1;
            Uint Cabecalho3:1; 
            Uint Cabecalho4:1;             
            Uint Atualizacao:1;
        };
    }Controle;
}_CtrlRotinas;



//Publicação das funções do módulo --------------------------------------------
void Rotinas_Inicializacao (void);
void Rotinas_ArmazenaFluxo (void);
void Rotinas_RestauraFluxo (void);
void Rotinas_PedidoDeAtualizacao (void);
void Rotinas_CarregaNivel (_Nivel *Nivel, Uchar Valor, Uchar Maximo);
void Rotinas_IncrementaNivel (_Nivel *Nivel);
void Rotinas_DecrementaNivel (_Nivel *Nivel);

unsigned char Rotinas_ExecutarCabecalho (unsigned char Nivel);
unsigned char Rotinas_Atualizacao (void);




//Publicação das variáveis do módulo ------------------------------------------
_CtrlRotinas    CtrlRotinas;

#endif	/* CONTROLE_DE_ROTINAS_H */

