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
void EEPROM_EscreveByte (Uint Endereco, Uchar Dado);
void EEPROM_EscreveUint (Uint Endereco, Uint Dado);
void EEPROM_EscreveUlong (Uint Endereco, Ulong Dado);
void EEPROM_EscreveFloat32 (Uint Endereco, float Dado);
void EEPROM_EscreveBytes (Uint Endereco, Uchar *Origem, Uchar NBytes);

Uchar EEPROM_LeByte (Uint Endereco);
Uint EEPROM_LeUint (Uint Endereco);
Ulong EEPROM_LeUlong (Uint Endereco);
float EEPROM_LeFloat32 (Uint Endereco);
void EEPROM_LeBytes (Uint Endereco, Uchar *Destino, Uchar NBytes);

Uchar EEPROM_DetectaInicializacao (void);
void EEPROM_InicializacaoOk (void);




#endif	/* EEPROM_H */

