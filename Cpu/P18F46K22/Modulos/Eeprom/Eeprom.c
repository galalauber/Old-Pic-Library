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
 * EEPROM_EscreveEndereco
 * Escreve o endere�o fornecido nos registradores ADDRH:ADDR da eeprom.
 * 
 * Endereco: Endere�o da mem�ria
 */
void EEPROM_EscreveEndereco (Uint Endereco)
{
    Uint16 _Endereco;
    
    _Endereco.valor = Endereco;
    
    EEADR = _Endereco.bytes.byte0;
    EEADRH = _Endereco.bytes.byte1; 
}


/*
 * EEPROM_IncrementaEndereco
 * Soma 1 ao endere�o da mem�ria (ADDRH:ADDR = ADDRH:ADDR + 1)
 */
void EEPROM_IncrementaEndereco(void)
{
    if(++EEADR == 0) EEADRH++;
}


/*
 * EEPROM_EscreveByte
 * Escreve 1 byte na mem�ria EEPROM interna do uC cujo endere�o est� definido
 * nos registradores ADDRH:ADDR.
 * A rotina tamb�m incrementa o endere�o  ADDRH:ADDR + 1 antes de ser
 * enderrada.
 * 
 * Byte: Correspone ao valor que ser� armazenado no endere�o ADDRH:ADDR
 */
void EEPROM_EscreveByte(Uchar Byte)
{
    EEDATA = Byte;
 
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;    
    EECON1bits.WREN = 1;
    
    INTCONbits.GIE = 0;
    
    EECON2 = 0x55;
    EECON2 = 0xAA;    
    EECON1bits.WR = 1;
    
    while (EECON1bits.WR == 1){};
    
    EECON1bits.WREN = 0;
    INTCONbits.GIE = 1;

    EEPROM_IncrementaEndereco();    
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
    EEPROM_EscreveEndereco(Endereco);
    
    while (NBytes-- > 0)
    {
        EEPROM_EscreveByte(*Origem++);
    }
}


/*
 * EEPROM_EscreveUchar
 * Escreve um dados do tipo Uchar na mem�ria
 * 
 * Endere�o: Endere�o da EEPROM onde o dado vai ser armazanado
 * Dado:     Dado do tipo do tipo char que vai ser armazenado
 */
void EEPROM_EscreveUchar (Uint Endereco, Uchar Dado)
{
    EEPROM_EscreveEndereco(Endereco);
    EEPROM_EscreveByte (Dado);
}

/*
 * EEPROM_EscreveUint
 * Escreve um dados do tipo Uint na mem�ria
 * 
 * Endere�o: Endere�o da EEPROM onde o dado vai ser armazanado
 * Dado:     Dado do tipo do tipo Uint que vai ser armazenado
 */
void EEPROM_EscreveUint (Uint Endereco, Uint Dado)
{
    Uint16 _Dado;
    
    _Dado.valor = Dado;
    
    EEPROM_EscreveEndereco(Endereco);
    EEPROM_EscreveByte (_Dado.bytes.byte0);
    EEPROM_EscreveByte (_Dado.bytes.byte1);    
}

/*
 * EEPROM_EscreveUlong
 * Escreve um dados do tipo Ulong na mem�ria
 * 
 * Endere�o: Endere�o da EEPROM onde o dado vai ser armazanado
 * Dado:     Dado do tipo do tipo Ulong que vai ser armazenado
 */
void EEPROM_EscreveUlong (Uint Endereco, Ulong Dado)
{
    Uint32 _Dado;
    
    _Dado.valor = Dado;
    
    EEPROM_EscreveEndereco(Endereco);
    EEPROM_EscreveByte (_Dado.bytes.byte0);
    EEPROM_EscreveByte (_Dado.bytes.byte1);
    EEPROM_EscreveByte (_Dado.bytes.byte2);
    EEPROM_EscreveByte (_Dado.bytes.byte3);   
}

/*
 * EEPROM_EscreveFloat32
 * Escreve um dados do tipo Float na mem�ria
 * 
 * Endere�o: Endere�o da EEPROM onde o dado vai ser armazanado
 * Dado:     Dado do tipo do tipo Float que vai ser armazenado
 */
void EEPROM_EscreveFloat32 (Uint Endereco, float Dado)
{
    Float32 _Dado;
    
    _Dado.valor = Dado;
    
    EEPROM_EscreveEndereco(Endereco);
    EEPROM_EscreveByte (_Dado.bytes.byte0);
    EEPROM_EscreveByte (_Dado.bytes.byte1);
    EEPROM_EscreveByte (_Dado.bytes.byte2);
    EEPROM_EscreveByte (_Dado.bytes.byte3);   
}

/*
 * EEPROM_EscreveHorario
 * Escreve um dados do tipo Horario na mem�ria (seg,min,hor)
 * 
 * Endere�o: Endere�o da EEPROM onde o hor�rio vai ser armazanado
 * Horario:  Aponta para a estrutura Horario a ser armazenado
 */
void EEPROM_EscreveHorario (Uint Endereco, ObjHorario *Horario)
{
    EEPROM_EscreveEndereco(Endereco);
    EEPROM_EscreveByte (Horario->Segundos);
    EEPROM_EscreveByte (Horario->Minutos);
    EEPROM_EscreveByte (Horario->Horas);
}

/*
 * EEPROM_EscreveData
 * Escreve um dados do tipo Data na mem�ria (dia, mes, ano)
 * 
 * Endere�o: Endere�o da EEPROM onde a a data vai ser armazenada
 * Data:     Aponta para a estrutura Data a ser armazenada
 */
void EEPROM_EscreveData (Uint Endereco, ObjData *Data)
{
    EEPROM_EscreveEndereco(Endereco);
    EEPROM_EscreveByte (Data->Dia);
    EEPROM_EscreveByte (Data->Mes);
    EEPROM_EscreveByte (Data->Ano);
}

/*
 * EEPROM_EscreveDataHoras
 * Escreve um dados do tipo DataHoras na mem�ria (Data completa)
 * 
 * Endere�o:    Endere�o da EEPROM onde a a data vai ser armazenada
 * DataHoras:   Aponta para a estrutura DataHoras que vai ser armazenada
 */
void EEPROM_EscreveDataHoras (Uint Endereco, ObjDataHoras *DataHoras)
{
    EEPROM_EscreveHorario(Endereco,&DataHoras->Horario);
    EEPROM_EscreveData(Endereco+3,&DataHoras->Data);    
    EEPROM_EscreveUchar(Endereco+6,DataHoras->Semana);
}


/*
 * EEPROM_LeByte
 * Le 1 byte na mem�ria EEPROM interna do uC cujo endere�o est� definido
 * nos registradores ADDRH:ADDR.
 * A rotina tamb�m incrementa o endere�o  ADDRH:ADDR + 1 antes de ser
 * enderrada.
 * 
 * Byte: Correspone ao valor que ser� armazenado no endere�o ADDRH:ADDR
 */
Uchar EEPROM_LeByte(void)
{
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;   
    EECON1bits.RD = 1;
    
    EEPROM_IncrementaEndereco();
    return EEDATA;
}

/*
 * EEPROM_LeBytes
 * Le n bytes na EEPROM interna do uC a partir do endere�o fornecido. Os 
 * dados lidos s�o sequencialmente transferidos para o local de destino
 * definido atrav�s do ponteiro *Destino.
 * 
 * Endere�o: Endere�o da EEPROM de onde os dados ser�o transferidos
 * Destino:  Define o local para onde os dados ser�o treansferidos
 * NBytes:  Define a quantidade de bytes que ser�o transferidos.
 */
void EEPROM_LeBytes (Uint Endereco, Uchar *Destino, Uchar NBytes)
{
    EEPROM_EscreveEndereco(Endereco);
    
    while (NBytes-- > 0)
    {
        *Destino++ = EEPROM_LeByte();
    }
}

/*
 * EEPROM_LeUchar
 * Le dado do tipo Uchar na mem�ria EEPROM interna do uC.
 * 
 * Endere�o: Endere�o da mem�ria eeprom onde o dado est� armazenado
 */
Uchar EEPROM_LeUchar (Uint Endereco)
{
    EEPROM_EscreveEndereco(Endereco);
    
    return EEPROM_LeByte();
}
            
/*
 * EEPROM_LeUint
 * Le dado do tipo Uint na mem�ria EEPROM interna do uC.
 * 
 * Endere�o: Endere�o da mem�ria eeprom onde o dado est� armazenado
 */
Uint EEPROM_LeUint (Uint Endereco)
{
    Uint16 Dado;
    
    EEPROM_EscreveEndereco(Endereco);
    
    Dado.bytes.byte0 = EEPROM_LeByte();
    Dado.bytes.byte1 = EEPROM_LeByte();    
    
    return Dado.valor;
}

/*
 * EEPROM_LeUlong
 * Le dado do tipo Ulong na mem�ria EEPROM interna do uC.
 * 
 * Endere�o: Endere�o da mem�ria eeprom onde o dado est� armazenado
 */
Ulong EEPROM_LeUlong (Uint Endereco)
{
    Uint32 Dado;
    
    EEPROM_EscreveEndereco(Endereco);
    
    Dado.bytes.byte0 = EEPROM_LeByte();
    Dado.bytes.byte1 = EEPROM_LeByte();
    Dado.bytes.byte2 = EEPROM_LeByte();
    Dado.bytes.byte3 = EEPROM_LeByte();      
    
    return Dado.valor;
}

/*
 * EEPROM_LeFloat32
 * Le dado do tipo float na mem�ria EEPROM interna do uC.
 * 
 * Endere�o: Endere�o da mem�ria eeprom onde o dado est� armazenado
 */
float EEPROM_LeFloat32 (Uint Endereco)
{
    Float32 Dado;
    
    EEPROM_EscreveEndereco(Endereco);
    
    Dado.bytes.byte0 = EEPROM_LeByte();
    Dado.bytes.byte1 = EEPROM_LeByte();
    Dado.bytes.byte2 = EEPROM_LeByte();
    Dado.bytes.byte3 = EEPROM_LeByte();      
    
    return Dado.valor;
}

/*
 * EEPROM_LeHorario
 * Le um dados do tipo Horario na mem�ria (seg,min,hor)
 * 
 * Endere�o: Endere�o da EEPROM onde o hor�rio a ser lido est� armazenado
 * Horaio:   Aponta para a estrutura do tipo Horario para onde os dados lidos
 *           ser�o transferidos.
 */
void EEPROM_LeHorario (Uint Endereco, ObjHorario *Horario)
{
    EEPROM_EscreveEndereco(Endereco);
    Horario->Segundos = EEPROM_LeByte();
    Horario->Minutos = EEPROM_LeByte();
    Horario->Horas = EEPROM_LeByte();
}

/*
 * EEPROM_LeData
 * Le um dados do tipo Data na mem�ria (dia,mes,ano)
 * 
 * Endere�o: Endere�o da EEPROM onde a data a ser lida est� armazenada
 * Data:     Aponta para a estrutura do tipo Data para onde os dados lidos
 *           ser�o transferidos.
 */
void EEPROM_LeData (Uint Endereco, ObjData *Data)
{
    EEPROM_EscreveEndereco(Endereco);
    Data->Dia = EEPROM_LeByte();
    Data->Mes = EEPROM_LeByte();
    Data->Ano = EEPROM_LeByte();
}

/*
 * EEPROM_LeDataHoras
 * Le um dados do tipo DataHora na mem�ria (Data Completa)
 * 
 * Endere�o: Endere�o da EEPROM onde a DataHoras a ser lida est� armazenada
 * Data:     Aponta para a estrutura DataHoras para onde os dados lidos ser�o
 *           transferidos.
 */
void EEPROM_LeDataHoras (Uint Endereco, ObjDataHoras *DataHoras)
{
    EEPROM_EscreveEndereco(Endereco);
    DataHoras->Horario.Segundos = EEPROM_LeByte();
    DataHoras->Horario.Minutos = EEPROM_LeByte();    
    DataHoras->Horario.Horas = EEPROM_LeByte();
    DataHoras->Data.Dia = EEPROM_LeByte();
    DataHoras->Data.Mes = EEPROM_LeByte();    
    DataHoras->Data.Ano = EEPROM_LeByte();    
    DataHoras->Semana = EEPROM_LeByte();
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
    
    if ((Bytes[0] == 0xFF)&&
        (Bytes[1] == 0xFF)&& 
        (Bytes[2] == 0xFF)&&   
        (Bytes[3] == 0xFF)) return 0;
    else return 1;
}
     
/*
 * EEPROM_EscreveInicializacao
 * Escreve os bytes de Inicializa��o na mem�ria EEPROM
 */
void EEPROM_EscreveInicializacao (void)
{
    Uchar  Bytes[4];
    
    Bytes[0] = EEPROM_INICIALIZACAO_BYTE1;
    Bytes[1] = EEPROM_INICIALIZACAO_BYTE2;
    Bytes[2] = EEPROM_INICIALIZACAO_BYTE3;
    Bytes[3] = EEPROM_INICIALIZACAO_BYTE4;    
    
    EEPROM_EscreveBytes(E2P_BYTES_DE_INICIALIZACAO,&Bytes[0],4);
}

/*
 * EEPROM_ResetaInicializacao
 * Reseta a inicializacao da E2prom
 */
void EEPROM_ResetaInicializacao (void)
{
    Uchar  Bytes[4];
    
    Bytes[0] = 0xFF;
    Bytes[1] = 0xFF;
    Bytes[2] = 0xFF;
    Bytes[3] = 0xFF;    
    
    EEPROM_EscreveBytes(E2P_BYTES_DE_INICIALIZACAO,&Bytes[0],4);
}