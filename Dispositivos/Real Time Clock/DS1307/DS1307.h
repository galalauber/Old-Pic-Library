/* 
 * Arquivo: DS1307.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef DS1307_H
#define	DS1307_H


#define _I2C1            1
#define _I2C2            2
#define _I2C3            3
#define _I2C4            4


//Definições do módulo -------------------------------------------------------
#define DS1307_ENDERECO                     0b11010000
#define DS1307_USA_MODULO_SERIAL            _I2C1



//Publicação das funções do módulo -------------------------------------------
void DS1307_Inicializacao (void);
void DS1307_PosicionaPonteiro(Uchar Endereco);
void DS1307_LeDataHoras(ObjDataHoras *DataHoras);
void DS1307_EscreveDataHoras(ObjDataHoras *DataHoras);


#endif	/* DS1307_H */

