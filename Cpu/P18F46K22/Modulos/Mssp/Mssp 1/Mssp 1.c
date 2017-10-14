/* 
 * Arquivo: Mssp 1.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include "Mssp 1.h"
#include "Oscilador.h"



//Alocação de memória para o módulo -------------------------------------------
_MSSP1_Objeto   MSSP1_Objeto;


//Funções locais --------------------------------------------------------------
/*
 * MSSP1_Reset
 * Reseta modulo MSSP1.
 */
void MSSP1_Reset(void)
{
    SSP1CON1bits.SSPEN = 0;
    NOP();
    NOP();
    SSP1CON1bits.SSPEN = 1;    
}



//Funções públicas ------------------------------------------------------------
/*
 * MSSP1_Inicializacao
 * Faz a inicialização do módulo MSSP1
 */
void MSSP1_Inicializacao (void)
{
    #if (MSSP_INTERFACE == _I2C)
        SSP1CON1bits.SSPM = 8;
    #endif   
        
    #if (MSSP_INTERFACE == _SPI)
        SSP1CON1bits.SSPM = 10;
    #endif

        
    SSP1ADD = (_FOSC / (4 * MSSP_VELOCIDADE) - 1);        
    MSSP1_Reset();    
}


/*
 * MSSP1_EscreveBytes
 * Escreve n bytes no dispositivo.
 * 
 * Endereco: Endereco do dispositivo.
 * Dados:    Endereço de Origem dos dados
 * Nbytes:   Numero de bytes a serem lidos (Dados)
 */
void MSSP1_EscreveBytes(Uint Endereco, Uchar *Origem, Uchar Nbytes)
{
    MSSP1_Objeto.Endereco.Valor = Endereco;
    MSSP1_Objeto.Endereco.Bits.RW = 0;
    MSSP1_Objeto.Controle.Dados = Origem;
    MSSP1_Objeto.Controle.Nbytes = Nbytes;  
    
    //Start     
    SSP1IF = 0;
    SSP1CON2bits.SEN = 1;
    while (SSP1IF == 0){};
    SSP1IF = 0;    

    //Enderça Dispositivo    
    SSP1IF = 0;    
    SSP1BUF = MSSP1_Objeto.Endereco.Bytes.Lsb;
    while (SSP1IF == 0){};
    SSP1IF = 0;    

            
    #if (MSSP1_I2C_ENDERECO_BITS == _10BITS)
        SSP1IF = 0;    
        SSP1BUF = MSSP1_Objeto.Endereco.Bytes.Msb;
        while (SSP1IF == 0){};
        SSP1IF = 0;        
    #endif

    //Dados
    while (MSSP1_Objeto.Controle.Nbytes-- > 0)
    {
        SSP1IF = 0;
        SSP1BUF = *MSSP1_Objeto.Controle.Dados++;
        while (SSP1IF == 0){};
        SSP1IF = 0;
    }
    
    //Stop
    SSP1CON2bits.PEN = 1;    
    while (SSP1IF == 0){};
    SSP1IF = 0;         
}


/*
 * MSSP1_LeBytes
 * Le n bytes no dispositivo.
 * 
 * Endereco: Endereco do dispositivo.
 * Dados:    Endereço de destino dos dados
 * Nbytes:   Numero de bytes a serem lidos (Dados)
 */
void MSSP1_LeBytes(Uint Endereco, Uchar *Destino, Uchar Nbytes)
{
    MSSP1_Objeto.Endereco.Valor = Endereco;
    MSSP1_Objeto.Endereco.Bits.RW = 1;
    MSSP1_Objeto.Controle.Dados = Destino;
    MSSP1_Objeto.Controle.Nbytes = Nbytes;
    
    //Start     
    SSP1IF = 0;
    SSP1CON2bits.SEN = 1;
    while (SSP1IF == 0){};

    //Enderça Dispositivo    
    SSP1IF = 0;    
    SSP1BUF = MSSP1_Objeto.Endereco.Bytes.Lsb;
    while (SSP1IF == 0){};
            
    #if (MSSP1_I2C_ENDERECO_BITS == _10BITS)
        SSP1IF = 0;    
        SSP1BUF = MSSP1_Objeto.Endereco.Bytes.Msb;
        while (SSP1IF == 0){};
    #endif
        
    //Dados    
    while (MSSP1_Objeto.Controle.Nbytes-- > 0)
    {
        SSP1IF = 0;
        SSP1CON2bits.RCEN = 1;
        
        while (SSP1IF == 0){};
        SSP1IF = 0;
        *MSSP1_Objeto.Controle.Dados++ = SSP1BUF;          
      
        SSP1CON2bits.ACKDT = 1;
        while (SSP1IF == 0){};
        SSP1IF = 0;  
    }        
    
    //Stop
    SSP1CON2bits.PEN = 1;    
    while (SSP1IF == 0){};
    SSP1IF = 0;      
}