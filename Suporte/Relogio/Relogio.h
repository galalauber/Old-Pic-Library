/* 
 * Arquivo: Relogio.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef RELOGIO_H
#define	RELOGIO_H

#include "Definicoes Gerais.h"

//Definições do módulo -------------------------------------------------------

//Tipos de Alarmes --------------
#define _DIARIO                 0
#define _SEMANAL                1 
#define _MENSAL                 2                         
#define _ANUAL                  3 

//RTCCS
#define _SOFTWARE               0
#define _RTCC                   1
#define _DS1307                 2
#define _MCP7940                3

//Dias da Semana
#define _DOM                    1
#define _SEG                    2
#define _TER                    3
#define _QUA                    4
#define _QUI                    5
#define _SEX                    6
#define _SAB                    7

#include "Relogio Config.h"

//Estruturas do módulo -------------------------------------------------------
typedef struct
{
    Uchar Segundos;
    Uchar Minutos;
    Uchar Horas;
}_Horario;


typedef struct
{
    Uchar Dia;
    Uchar Mes;
    Uchar Ano;
}_Data;


typedef struct
{
    _Horario  Horario;
    _Data     Data;
    Uchar     Semana;   
}_DataHoras;

typedef struct
{
    _DataHoras  DataHoras;

    struct
    {
        Uint    Ativado:1;        
    }Sinais;
}_Alarmes;


typedef struct     
{
    _DataHoras  DataHoras;
    _Alarmes    Alarme[RELOGIO_EVENTOS_DE_ALARMES];
}_Relogio;



//Processamento das definicçoes do módulo ------------------------------------





//publicação das funções do módulo --------------------------------------------
void Relogio_Inicializacao (void);
void Relogio_Atualizacao (void);
Uchar Relogio_ComparaHorario (_Horario *Horario1,_Horario *Horario2);
Uchar Relogio_ComparaDatas (_Data *Data1,_Data *Data2);



//Publicação das variáveis do módulo ------------------------------------------
extern _Relogio     Relogio;


#endif	/* RELOGIO_H */

