/* 
 * Arquivo: Relogio.C
 * Autor:   JABNeto
 * Versao:  150710
 */

#include "Relogio.h"

#if (RELOGIO_DISPOSITIVO == _RTCC )
#include "RTCC.h"
#elif (RELOGIO_DISPOSITIVO == _DS1307)
#include "DS1307.h"
#elif (RELOGIO_DISPOSITIVO == _MCP7940)
#include "MCP7940.h"
#endif


//Alocação de memória para o módulo -------------------------------------------
ObjRelogio     Relogio;




//Funções locais --------------------------------------------------------------





//Funções públicas ------------------------------------------------------------

/*
 * Relogio_Inicializacao
 * Faz a inicialização do módulo do relogio
 */
void Relogio_Inicializacao (void)
{
    #if (RELOGIO_DISPOSITIVO == _RTCC )
        RTCC_Inicializacaos();
    #elif (RELOGIO_DISPOSITIVO == _DS1307)
        DS1307_Inicializacao();
    #elif (RELOGIO_DISPOSITIVO == _MCP7940)
        MCP7940_Inicializacao();
    #endif  
    
    Relogio.DataHoras.Horario.Horas = 0x00;
    Relogio.DataHoras.Horario.Minutos = 0x00;    
    Relogio.DataHoras.Horario.Segundos= 0x00;

    Relogio.DataHoras.Data.Dia = 0x01;
    Relogio.DataHoras.Data.Mes = 0x01;    
    Relogio.DataHoras.Data.Ano = 0x16;
    Relogio.DataHoras.Semana = _SEX;
    
    Relogio.Status.Stualizar = _NAO;
}


/*
 * Relogio_Monitor
 * Faz a inicialização do módulo do relogio
 */
void Relogio_Monitor (void)
{
    if (Relogio.Status.Stualizar == _SIM)
    {
        Relogio.Status.Stualizar = _NAO;
        
        #if (RELOGIO_DISPOSITIVO == _RTCC )
            RTCC_LeDataHoras(&Relogio.DataHoras);
        #elif (RELOGIO_DISPOSITIVO == _DS1307)
            DS1307_LeDataHoras(&Relogio.DataHoras);
        #elif (RELOGIO_DISPOSITIVO == _MCP7940)
            MCP7940_LeDataHoras(&Relogio.DataHoras);
        #endif         
    }
    
    
    
}

/*
 * Relogio_ComparaHorario
 * Compara dois horarios e retorna Resposta.
 * 
 * Retorno:
 * 0: Horarios iguais
 * 1: Horario1 > Horario2
 * 2: Horario1 < Horario2
 */
Uchar Relogio_ComparaHorario (ObjHorario *Horario1,ObjHorario *Horario2)
{
    Uchar Retorno = 0;
    
    if (Horario1->Horas > Horario2->Horas) Retorno = 1;
    else if (Horario1->Horas < Horario2->Horas) Retorno = 2;
    else
    {
        if (Horario1->Minutos > Horario2->Minutos) Retorno = 1;
        else if (Horario1->Minutos < Horario2->Minutos) Retorno = 2;
        else
        {
            if (Horario1->Segundos > Horario2->Segundos) Retorno = 1;
            else if (Horario1->Segundos < Horario2->Segundos) Retorno = 2;
            else Retorno = 0;            
        }
    }

    return Retorno;
}


/*
 * Relogio_ComparaDatas
 * Compara duas Datas e retorna Resposta.
 * 
 * Retorno:
 * 0: Datas iguais
 * 1: Data1 > Horario2
 * 2: Data2 < Data2
 */
Uchar Relogio_ComparaDatas (ObjData *Data1,ObjData *Data2)
{
    Uchar Retorno = 0;
    
    if (Data1->Ano > Data2->Ano) Retorno = 1;
    else if (Data1->Ano < Data2->Ano) Retorno = 2;
    else
    {
        if (Data1->Mes > Data2->Mes) Retorno = 1;
        else if (Data1->Mes < Data2->Mes) Retorno = 2;
        else
        {
            if (Data1->Dia > Data2->Dia) Retorno = 1;
            else if (Data1->Dia < Data2->Dia) Retorno = 2;
            else Retorno = 0;            
        }
    }

    return Retorno;
}



