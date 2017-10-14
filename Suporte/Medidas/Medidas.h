/* 
 * Arquivo: Medidas.h
 * Autor:   JABNeto
 * Versao:  
 */

#ifndef MEDIDAS_H
#define	MEDIDAS_H

#include "Definicoes Gerais.h"
#include "Medidas Config.h"


//Estruturas do m�dulo --------------------------------------------------------
typedef struct
{
    Uint    Buffer[MEDIDAS_NUMERO_DE_AMOSTRAS];    
    Uchar   NumeroDaAmostra;
    Uchar   IdMedida; 
}_Aquisicao;


typedef struct
{
    float   FatorDeConversao;
    float   Histerese; 
    float   ValorMaximo;
    float   ValorMinimo;
   
    union
    {
        Uchar Valor;
        
        struct
        {
            Uint AlarmeA:1;
            Uint AlarmeB:1; 
        };         
    }Habilitacao;
}_MedidaParametros;


typedef struct
{
    _MedidaParametros   Parametros;      
    unsigned char       Canal;
    float               MediaAmostras;
    float               ValorDecimal;

    union
    {
        Uchar Valor;
        
        struct
        {
            Uint AlarmeA:1;
            Uint AlarmeB:1; 
        };         
    }Eventos;   
}_Medida;


typedef struct
{
    Uint Valor;
    
    struct
    {
        Uint TensaoDeEntradaAlta:1;
        Uint TensaoDeEntradaBaixa:1;        
        Uint TensaoDeBateriaAlta:1;
        Uint TensaoDeBateriaBaixa:1;          
    };
}_Alarmes;


//Processamento das definicoes do m�dulo --------------------------------------



//Publica��o das fun��es do m�dulo --------------------------------------------
void Medidas_Inicializacao (void);
void Medidas_Monitor (void);
void Medidas_CarregaParametros (Uchar IdMedida);
void Medidas_EscreveParametros (Uchar IdMedida);
void Medida_Calibracao (Uchar IdMedida,float NovoValor);

Uint Medida_CalculaEnderecoE2prom (Uchar IdMedida);
//Publica��o das vari�veis do m�dulo ------------------------------------------


#endif	/* MEDIDAS_H */

