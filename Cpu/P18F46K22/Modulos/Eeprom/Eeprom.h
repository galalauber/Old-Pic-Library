/* 
 * Arquivo: EEPROM.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef EEPROM_H
#define	EEPROM_H

#include "Definicoes Gerais.h"


//Definições do módulo --------------------------------------------------------
#define EEPROM_NUMERO_DE_BYTES                      1024

#define EEPROM_INICIALIZACAO_BYTE1                  (Uchar)'#'
#define EEPROM_INICIALIZACAO_BYTE2                  (Uchar)'O'
#define EEPROM_INICIALIZACAO_BYTE3                  (Uchar)'K'
#define EEPROM_INICIALIZACAO_BYTE4                  (Uchar)'#'

#include "Eeprom Config.h"

//Estruturas do módulo --------------------------------------------------------




//Publicação das funções do módulo --------------------------------------------
void EEPROM_EscreveEndereco (Uint Endereco);
void EEPROM_IncrementaEndereco(void);
void EEPROM_EscreveByte(Uchar Byte);
void EEPROM_EscreveBytes (Uint Endereco, Uchar *Origem, Uchar NBytes);
void EEPROM_EscreveUchar (Uint Endereco, Uchar Dado);
void EEPROM_EscreveUint (Uint Endereco, Uint Dado);
void EEPROM_EscreveUlong (Uint Endereco, Ulong Dado);
void EEPROM_EscreveFloat32 (Uint Endereco, float Dado);
void EEPROM_EscreveHorario (Uint Endereco, ObjHorario *Horario);
void EEPROM_EscreveData (Uint Endereco, ObjData *Data);
void EEPROM_EscreveDataHoras (Uint Endereco, ObjDataHoras *DataHoras);


Uchar EEPROM_LeByte(void);
void  EEPROM_LeBytes (Uint Endereco, Uchar *Destino, Uchar NBytes);
Uchar EEPROM_LeUchar (Uint Endereco);
Uint  EEPROM_LeUint (Uint Endereco);
Ulong EEPROM_LeUlong (Uint Endereco);
float EEPROM_LeFloat32 (Uint Endereco);
void EEPROM_LeHorario (Uint Endereco, ObjHorario *Horario);
void EEPROM_LeData (Uint Endereco, ObjData *Data);
void EEPROM_LeDataHoras (Uint Endereco, ObjDataHoras *DataHoras);

Uchar EEPROM_DetectaInicializacao (void);
void  EEPROM_EscreveInicializacao (void);
void  EEPROM_ResetaInicializacao (void);

#endif	/* EEPROM_H */

