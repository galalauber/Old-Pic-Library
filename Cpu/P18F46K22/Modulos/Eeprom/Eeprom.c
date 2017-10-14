/* 
 * Arquivo: EEPROM.C
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include "Eeprom.h"


//Aloca��o de mem�ria para o m�dulo ------------------------------------------




//Fun��es locais -------------------------------------------------------------





//Fun��es p�blicas -----------------------------------------------------------

/*
 * EEPROM_EscreveByte
 * Escreve 1 byte na mem�ria EEPROM interna do uC. O endere�o � incrementado.
 * Endereco: local onde o Dado vai ser armazenado
 * Dado: valor que ser� armazenado
 */
void EEPROM_EscreveByte(Uint Endereco, Uchar Dado)
{
    Uchar BackupGIE = 0;
    Uint16 _Endereco;
            
    if (INTCONbits.GIE == 1) BackupGIE = 1;
    
    _Endereco.valor = Endereco;
    EEADR = _Endereco.bytes.byte0;
    EEADRH = _Endereco.bytes.byte1; 
    EEDATA = Dado;
 
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;    
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;
    
    EECON2 = 0x55;
    EECON2 = 0xAA;    
    EECON1bits.WR = 1;
    while (EECON1bits.WR == 1){};
    
    EECON1bits.WREN = 0;

    if (BackupGIE == 1) INTCONbits.GIE = 1;    
}


/*
 * EEPROM_EscreveUint16
 * Escreve um numero de 16 bits na mem�ria EEPROM a partir do endere�o
 * especificado
 * 
 * Endere�o: Endere�o da EEPROM para onde os dados ser�o transferidos
 * Dado:     Numero de 16 bits para ser armazenado
 */
void EEPROM_EscreveUint (Uint Endereco, Uint Dado)
{
    Uint16 _Dado;
    Uchar Bytes[2];
    
    _Dado.valor = Dado;
    
    Bytes[0] = _Dado.bytes.byte0;
    Bytes[1] = _Dado.bytes.byte1;

    EEPROM_EscreveBytes(Endereco, &Bytes[0],2);  
}

/*
 * EEPROM_EscreveUint
 * Escreve um numero de 32 bits na mem�ria EEPROM a partir do endere�o
 * especificado
 * 
 * Endere�o: Endere�o da EEPROM para onde os dados ser�o transferidos
 * Dado:     Numero de 32 bits para ser armazenado
 */
void EEPROM_EscreveUlong (Uint Endereco, Ulong Dado)
{
    Uint32 _Dado;
    Uchar Bytes[4];
    
    _Dado.valor = Dado;
    
    Bytes[0] = _Dado.bytes.byte0;
    Bytes[1] = _Dado.bytes.byte1;
    Bytes[2] = _Dado.bytes.byte2;
    Bytes[3] = _Dado.bytes.byte3;

    EEPROM_EscreveBytes(Endereco, &Bytes[0],4);    
}

/*
 * EEPROM_EscreveFloat32
 * Escreve um numero flutuante de 32 bits na mem�ria EEPROM a partir do
 * endere�o especificado
 * 
 * Endere�o: Endere�o da EEPROM para onde os dados ser�o transferidos
 * Dado:     Numero de 32 bits para ser armazenado
 */
void EEPROM_EscreveFloat32 (Uint Endereco, float Dado)
{
    Float32 _Dado;
    Uchar Bytes[4];
    
    _Dado.valor = Dado;
    
    Bytes[0] = _Dado.bytes.byte0;
    Bytes[1] = _Dado.bytes.byte1;
    Bytes[2] = _Dado.bytes.byte2;
    Bytes[3] = _Dado.bytes.byte3;
    
    EEPROM_EscreveBytes(Endereco, &Bytes[0],4);
}

/*
 * EEPROM_EscreveBytes
 * Escreve n bytes na EEPROM interna a partir do endere�o fornecido.
 * 
 * Endere�o: Endere�o da EEPROM para onde os dados ser�o transferidos
 * Origem:   Define o local de onde onde os dados ser�o transferidos.
 * NBytes:   Define a quantidade de bytes que ser�o transferidos.
 */
void EEPROM_EscreveBytes (Uint Endereco, Uchar *Origem, Uchar NBytes)
{
    while (NBytes-- > 0)
    {
        EEPROM_EscreveByte(Endereco++, *Origem++);
    }
}


/*
 * EEPROM_LeByte
 * Le um byte na EEPROM interna do uC.
 * Endereco: local onde o Dado est� armazenado
 */
Uchar EEPROM_LeByte (Uint Endereco)
{
    Uint16 _Endereco;
            
    _Endereco.valor = Endereco;
    EEADR = _Endereco.bytes.byte0;
    EEADRH = _Endereco.bytes.byte1; 

    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;     
    EECON1bits.RD = 1;
    
    return EEDATA;
}

/*
 * EEPROM_LeUint
 * Le um n�mero de 16 bits na EEPROM interna do uC a partir do endere�o
 * especificado
 * Endereco: local onde o Dado est� armazenado
 */
Uint EEPROM_LeUint (Uint Endereco)
{
    Uint16 _Dado;
    Uchar Bytes[2];
    
    EEPROM_LeBytes(Endereco, &Bytes[0],2);
     
    _Dado.bytes.byte0 = Bytes[0];
    _Dado.bytes.byte1 = Bytes[1];
    
    return _Dado.valor;
}

/*
 * EEPROM_LeUlong
 * Le um n�mero de 32 bits na EEPROM interna do uC a partir do endere�o
 * especificado
 * Endereco: local onde o Dado est� armazenado
 */
Ulong EEPROM_LeUlong (Uint Endereco)
{
    Uint32 _Dado;
    Uchar Bytes[4];
    
    EEPROM_LeBytes(Endereco, &Bytes[0],4);
     
    _Dado.bytes.byte0 = Bytes[0];
    _Dado.bytes.byte1 = Bytes[1];
    _Dado.bytes.byte2 = Bytes[2];
    _Dado.bytes.byte3 = Bytes[3];  
    
    return _Dado.valor;
}

/*
 * EEPROM_LeFloat32
 * Le um n�mero de 32 bits na EEPROM interna do uC a partir do endere�o
 * especificado
 * Endereco: local onde o Dado est� armazenado
 */
float EEPROM_LeFloat32 (Uint Endereco)
{
    Float32 _Dado;
    Uchar Bytes[4];
    
    EEPROM_LeBytes(Endereco, &Bytes[0],4);

    _Dado.bytes.byte0 = Bytes[0];
    _Dado.bytes.byte1 = Bytes[1];
    _Dado.bytes.byte2 = Bytes[2];
    _Dado.bytes.byte3 = Bytes[3];         

    return _Dado.valor;
}


/*
 * EEPROM_LeBytes
 * Le n bytes na EEPROM interna do uC a aprtir do endere�o fornecido. Os 
 * dados lidos s�o sequencialmente transferidos para o local de destino
 * definido atrav�s do ponteiro *Destino.
 * 
 * Endere�o: Endere�o da EEPROM de onde os dados ser�o transferidos
 * Destino:  Define o local para onde os dados ser�o treansferidos
 * NBytes:  Define a quantidade de bytes que ser�o transferidos.
 */
void EEPROM_LeBytes (Uint Endereco, Uchar *Destino, Uchar NBytes)
{
    while (NBytes-- > 0)
    {
        *Destino++ = EEPROM_LeByte(Endereco++);
    }
}

/*
 * EEPROM_DetectaInicializacao
 * Verifica se a mem�ria EEPROM j� foi inicializada.
 * Retorno:
 * 0: A mem�ria EEPROM n�o foi inicializada e os dados n�o s�o confiaveis
 * 1: A mem�ria EEPROM j� foi inicializada
 */
Uchar EEPROM_DetectaInicializacao (void)
{
    Uchar  Bytes[4];
    
    EEPROM_LeBytes(E2P_BYTES_DE_INICIALIZACAO,&Bytes[0],4);
    
    if ((Bytes[0] == EEPROM_INICIALIZACAO_BYTE1)&&
        (Bytes[1] == EEPROM_INICIALIZACAO_BYTE2)&& 
        (Bytes[2] == EEPROM_INICIALIZACAO_BYTE3)&&   
        (Bytes[3] == EEPROM_INICIALIZACAO_BYTE4)) return 1;
    else return 0;
}
     
/*
 * EEPROM_InicializacaoOk
 * Escreve os bytes de Inicializa��o na mem�ria EEPROM
 */
void EEPROM_InicializacaoOk (void)
{
    Uchar  Bytes[4];
    
    Bytes[0] = EEPROM_INICIALIZACAO_BYTE1;
    Bytes[1] = EEPROM_INICIALIZACAO_BYTE2;
    Bytes[2] = EEPROM_INICIALIZACAO_BYTE3;
    Bytes[3] = EEPROM_INICIALIZACAO_BYTE4;    
    
    EEPROM_EscreveBytes(E2P_BYTES_DE_INICIALIZACAO,&Bytes[0],4);
}