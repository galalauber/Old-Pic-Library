/* 
 * Arquivo: DS1307.C
 * Autor:   JABNeto
 * Versao:  150710
 */

#include "Relogio.h"
#include "DS1307.h"


#if (DS1307_USA_MODULO_SERIAL == _I2C1)
#include "Mssp 1.h"
#elif (DS1307_USA_MODULO_SERIAL == _I2C2)
#include "Mssp 2.h"
#elif (DS1307_USA_MODULO_SERIAL == _I2C3)
#include "Mssp 3.h"
#elif (DS1307_USA_MODULO_SERIAL == _I2C4)
#include "Mssp 4.h"
#endif



//Alocação de memória para o módulo -------------------------------------------




//Funções locais --------------------------------------------------------------




//Funçoes públicas ------------------------------------------------------------

/*
 * RTCC_Inicializacao
 * Faz a Inicializacao do componente
 */
void DS1307_Inicializacao (void)
{
    #if (DS1307_USA_MODULO_SERIAL == _I2C1)
        MSSP1_Inicializacao();
    #elif (DS1307_USA_MODULO_SERIAL == _I2C2)
        MSSP2_Inicializacao();
    #elif (DS1307_USA_MODULO_SERIAL == _I2C3)
        MSSP3_Inicializacao();
    #elif (DS1307_USA_MODULO_SERIAL == _I2C4)
        MSSP4_Inicializacao();        
    #endif
}


/*
 * DS1307_LeDataHoras
 * Le Data e Horario no dispositivo e atualiza o registradores do Relogio
 */
void DS1307_LeDataHoras(_DataHoras *DataHoras)
{
    Uchar Dados[7];
    
    DS1307_PosicionaPonteiro(0);
    
    MSSP1_LeBytes((Uint)DS1307_ENDERECO, &Dados[0],7);
    
    DataHoras->Horario.Segundos = Dados[0] & 0x7F;
    DataHoras->Horario.Minutos = Dados[1];    
    DataHoras->Horario.Horas = Dados[2] & 0x3F;     
    DataHoras->Semana = Dados[3];
    DataHoras->Data.Dia = Dados[4];
    DataHoras->Data.Mes = Dados[5];    
    DataHoras->Data.Ano = Dados[6];      
}


/*
 * DS1307_EscreveDataHoras
 * Escreve o novo horario no dispositivo
 */
void DS1307_EscreveDataHoras(_DataHoras *DataHoras)
{
    Uchar Dados[9];
    
    Dados[0] = 0x00;
    Dados[1] = DataHoras->Horario.Segundos | 0x80;
    Dados[2] = DataHoras->Horario.Minutos;    
    Dados[3] = DataHoras->Horario.Horas | 0x40;        
    
    Dados[4] = DataHoras->Semana;       
    Dados[5] = DataHoras->Data.Dia;
    Dados[6] = DataHoras->Data.Mes;
    Dados[7] = DataHoras->Data.Ano; 
    
    Dados[8] = 0x90;     
    
    MSSP1_EscreveBytes((Uint)DS1307_ENDERECO,&Dados[0],9);
}


/*
 * DS1307_PosicionaPonteiro
 * Posiciona o ponteiro da memória RAM
 */
void DS1307_PosicionaPonteiro(Uchar Endereco)
{
    Uchar Dados[1];
    
    Dados[0] = Endereco;
    
    MSSP1_EscreveBytes((Uint)DS1307_ENDERECO,&Dados[0],1);
}

