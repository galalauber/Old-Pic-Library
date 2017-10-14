/* 
 * Arquivo: Relogio.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef RELOGIO_H
#define	RELOGIO_H

#include "Definicoes Gerais.h"

//Defini��es do m�dulo -------------------------------------------------------
//RTCCS
#define _SOFTWARE               0
#define _RTCC                   1
#define _DS1307                 2
#define _MCP7940                3

//Tipos de Alarmes --------------
#define _DESLIGADO              0
#define _DIARIO                 1
#define _SEMANAL                2 
#define _MENSAL                 3                         
#define _ANUAL                  4 

//Dias da Semana
#define _DOM                    1
#define _SEG                    2
#define _TER                    3
#define _QUA                    4
#define _QUI                    5
#define _SEX                    6
#define _SAB                    7

#include "Relogio Config.h"

//Estruturas do m�dulo -------------------------------------------------------
typedef struct
{
    Uchar Segundos;
    Uchar Minutos;
    Uchar Horas;
}ObjHorario;


typedef struct
{
    Uchar Dia;
    Uchar Mes;
    Uchar Ano;
}ObjData;

typedef struct
{
    ObjHorario  Horario;
    ObjData     Data;
    Uchar       Semana;   
}ObjDataHoras;

typedef struct
{
    ObjDataHoras    DataHoras;
    Uchar           Modo;
    
    struct
    {
        Uint    Ligado:1;        
    }Sinais;
}ObjAlarme;


typedef struct     
{
    ObjDataHoras  DataHoras;
    ObjAlarme     Alarmes[RELOGIO_EVENTOS_DE_ALARMES];
    
    union
    {
        Uchar Valor;
        
        struct
        {
            Uint Stualizar:1;
            
        }Status;
    };
}ObjRelogio;



//Processamento das definic�oes do m�dulo ------------------------------------





//publica��o das fun��es do m�dulo --------------------------------------------
void Relogio_Inicializacao (void);
void Relogio_Monitor (void);
Uchar Relogio_ComparaHorario (ObjHorario *Horario1,ObjHorario *Horario2);
Uchar Relogio_ComparaDatas (ObjData *Data1,ObjData *Data2);



//Publica��o das vari�veis do m�dulo ------------------------------------------
extern ObjRelogio     Relogio;


#endif	/* RELOGIO_H */

