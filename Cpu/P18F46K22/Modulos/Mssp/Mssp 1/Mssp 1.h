/* 
 * Arquivo: Mssp 1.h
 * Autor:   JABNeto
 * Versao:  150710
 */


#ifndef MSSP_1_H
#define	MSSP_1_H

#include "Definicoes Gerais.h"


//Modulo serial
#define MSSP_INTERFACE                      _I2C
#define MSSP_VELOCIDADE                     400000
#define MSSP_MODO_DE_ENDERECAMENTO          _8BITS
#define MSSP_MESTRE_ESCRAVO                 _MESTRE


//Estruturas e enumeracoes do m�dulo --------------------------------------------------------
typedef struct
{
    union
    {
        Uint Valor;

        struct
        {
            Uchar   Lsb;
            Uchar   Msb;
        }Bytes;

        struct
        {
            Uint    RW:1;
        }Bits;
    }Endereco;    
   
    struct
    {
        Uint    Mestre_Escravo:1;
        Uint    ModoEnderecamento:1;
    }Configuracoes;
    
    struct
    {
        Uchar   Nbytes;        
        Uchar   Processo;         
        Uchar   *Dados;        
    }Controle;
}_MSSP1_Objeto;



//Publica��o das fun��es do m�dulo --------------------------------------------
void MSSP1_Inicializacao (void);
void MSSP1_EscreveBytes(Uint Endereco, Uchar *Origem, Uchar Nbytes);
void MSSP1_LeBytes(Uint Endereco, Uchar *Destino, Uchar Nbytes);
#endif	/* MSSP_1_H */

