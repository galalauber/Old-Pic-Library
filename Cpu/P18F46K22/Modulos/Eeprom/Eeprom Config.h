/* 
 * Arquivo: EEPROM Config.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef EEPROM_CONFIG_H
#define	EEPROM_CONFIG_H


//Definicoes das variáveis na EEPROM -----------------------------------------
/* Parametros das medidas (13 bytes)
 * 
 * typedef struct
{
    float   FatorDeConversao;   (4)
    float   Histerese;          (4) 
    float   ValorMaximo;        (4)
    float   ValorMinimo;        (4)
   
    struct
    {
        Uint AlarmeA:1;
        Uint AlarmeB:1; 
    }Habilitacao;               (1)
}_MedidaParametros;
 */
#define EEPROM_PARAMETROS_MEDIDAS            0
#define EEPROM_PARAMETROS_MEDIDA_0          (0 * 13 + EEPROM_PARAMETROS_MEDIDAS)
#define EEPROM_PARAMETROS_MEDIDA_1          (1 * 13 + EEPROM_PARAMETROS_MEDIDAS)












//Bytes para identificação de Inicializacao -----------------------------------
#define E2P_BYTES_DE_INICIALIZACAO              (EEPROM_NUMERO_DE_BYTES - 5)


#endif	/* EEPROM_CONFIG_H */

