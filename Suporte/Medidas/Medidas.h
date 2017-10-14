/* 
 * Arquivo: Medidas.h
 * Autor:   JABNeto
 * Versao:  
 */

#ifndef MEDIDAS_H
#define	MEDIDAS_H

#include "Definicoes Gerais.h"
#include "Medidas Config.h"


//Estruturas do módulo --------------------------------------------------------
typedef struct
{
    Uint    Buffer[MEDIDAS_NUMERO_DE_AMOSTRAS];    
    Uchar   NumeroDaAmostra;
    Uchar   IdMedida; 
}ObjAquisicao;


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
}ObjMedidaParametros;


typedef struct
{
    ObjMedidaParametros     Parametros;      
    Uchar                   Canal;
    float                   MediaAmostras;
    float                   ValorDecimal;

    union
    {
        Uchar Valor;
        
        struct
        {
            Uint AlarmeA:1;
            Uint AlarmeB:1; 
        };         
    }Eventos;   
}ObjMedida;



//Processamento das definicoes do módulo --------------------------------------



//Publicação das funções do módulo --------------------------------------------
void Medidas_Inicializacao (void);
void Medidas_Monitor (void);
void Medidas_RecuperaParametros (Uchar IdMedida);
void Medidas_SalvaParametros (Uchar IdMedida);
void Medidas_ResetaParametros (void);
void Medida_Calibracao (Uchar IdMedida,float NovoValor);
Uint Medida_CalculaEnderecoE2prom (Uchar IdMedida);


//Publicação das variáveis do módulo ------------------------------------------
extern ObjMedida   Medidas[];

#endif	/* MEDIDAS_H */

