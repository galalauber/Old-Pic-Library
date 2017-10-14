/* 
 * Arquivo: EEPROM Config.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef EEPROM_CONFIG_H
#define	EEPROM_CONFIG_H


//Definicoes das variáveis na EEPROM -----------------------------------------
//typedef struct
//{
//    float   FatorDeConversao; (4)
//    float   Histerese;        (4)
//    float   ValorMaximo;      (4)
//    float   ValorMinimo;      (4)
//   
//    union
//    {
//        Uchar Valor;          (1) = 17
//        
//        struct
//        {
//            Uint AlarmeA:1;
//            Uint AlarmeB:1; 
//        };         
//    }Habilitacao;
//}_MedidaParametros;
#define EEPROM_MEDIDAS_SIZE     17
#define EEPROM_MEDIDAS          0
#define EEPROM_MEDIDA_0         (0 * EEPROM_MEDIDAS_SIZE + EEPROM_MEDIDAS)
#define EEPROM_MEDIDA_1         (1 * EEPROM_MEDIDAS_SIZE + EEPROM_MEDIDAS)
#define EEPROM_MEDIDAS_FIM      (2 * EEPROM_MEDIDAS_SIZE + EEPROM_MEDIDAS)






//Bytes para identificação de Inicializacao -----------------------------------
#define E2P_BYTES_DE_INICIALIZACAO              (EEPROM_NUMERO_DE_BYTES - 4)


#endif	/* EEPROM_CONFIG_H */

