/* 
 * Arquivo: Teclado.h
 * Autor:   JABNeto
 * Versao:  
 */


#include "Teclado.h"


//Alocação de memória para o módulo -------------------------------------------
ObjTeclado  Teclado;



//Funções locais -------------------------------------------------------------
void Teclado_ColunasEmNL1 (void)
{
    TECLADO_COLUNA_1 = 1;
    TECLADO_COLUNA_2 = 1;    
    TECLADO_COLUNA_3 = 1;    
    TECLADO_COLUNA_4 = 1;
}

void Teclado_ResetaAmostras (void)
{
    Uchar i;
    
    for (i = 0; i < 4; i++)
    {
        Teclado.Varredura.Amostras[i].valor = 0;          
    }
}

//Funções públicas -----------------------------------------------------------

/*
 * Teclado_Inicializacao
 * Faz a Inicializacao do teclado
 */
void Teclado_Inicializacao (void)
{
    ANSELAbits.ANSA0 = 0;
    TRISAbits.TRISA0 = 0;
    
    ANSELAbits.ANSA1 = 0;
    TRISAbits.TRISA1 = 0;    

    ANSELAbits.ANSA2 = 0;
    TRISAbits.TRISA2 = 0;    
    
    ANSELAbits.ANSA3 = 0;
    TRISAbits.TRISA4 = 0;
    
    ANSELCbits.ANSC5 = 0;    
    ANSELCbits.ANSC6 = 0;
    
    Teclado_ColunasEmNL1();
    
    Teclado.Varredura.Sequencia = 0;
    Teclado_ResetaAmostras();
    
    Teclado.Eventos.Valor = 0; 
}


/*
 * Teclado_CapturaLinha 
 * Faz a captura dos estados lógicos das linhas do teclado
*/
Uchar Teclado_CapturaLinha (void)
{
    Uint8 Captura;
    
    Captura.valor = 0;
    
    if (TECLADO_LINHA_1 == 0) Captura.bits.bit0 = 1;
    if (TECLADO_LINHA_2 == 0) Captura.bits.bit1 = 1;    
    if (TECLADO_LINHA_3 == 0) Captura.bits.bit2 = 1;
    if (TECLADO_LINHA_4 == 0) Captura.bits.bit3 = 1;

    return Captura.valor;
}


/*
 * Teclado_Monitor
 * Faz o monitoramento do teclado.
 */
void Teclado_Monitor (void)
{
    Teclado_ColunasEmNL1();
    
    switch (Teclado.Varredura.Sequencia)
    {
        case 0:
            TECLADO_COLUNA_1 = 0;
            Teclado.Varredura.Amostras[0].valor= Teclado_CapturaLinha();
            break;
            
        case 1:
            TECLADO_COLUNA_2 = 0;
            Teclado.Varredura.Amostras[1].valor= Teclado_CapturaLinha();
            break;            
            
        case 2:
            TECLADO_COLUNA_3 = 0;
            Teclado.Varredura.Amostras[2].valor= Teclado_CapturaLinha();
            break;            
            
        case 3:
            TECLADO_COLUNA_4 = 0;
            Teclado.Varredura.Amostras[3].valor= Teclado_CapturaLinha();
            break;
            
        case 4:
            if ((Teclado.Varredura.Amostras[0].valor == 0) &&
                (Teclado.Varredura.Amostras[1].valor == 0) &&
                (Teclado.Varredura.Amostras[2].valor == 0) &&            
                (Teclado.Varredura.Amostras[3].valor == 0)) 
            {
                Teclado.Varredura.Sinais.Recuo = 1;
            }
            else
            {
                if (Teclado.Varredura.Sinais.Recuo == 1)
                {
                    Teclado.Varredura.Sinais.Recuo = 0;
                    
                    if (Teclado.Varredura.Amostras[0].valor != 0)
                    {
                        if (Teclado.Varredura.Amostras[0].bits.bit0 == 0)
                        {
                            Teclado.Eventos.Tecla1 = 1;
                        }                        
                        else if (Teclado.Varredura.Amostras[0].bits.bit1 == 0)
                        {
                            Teclado.Eventos.Tecla2 = 1;
                        }                         
                        else if (Teclado.Varredura.Amostras[0].bits.bit2 == 0)
                        {
                            Teclado.Eventos.Tecla3 = 1;
                        }
                        else if (Teclado.Varredura.Amostras[0].bits.bit3 == 0)
                        {
                            Teclado.Eventos.Tecla4 = 1;
                        } 
                    }
                    else if (Teclado.Varredura.Amostras[1].valor != 0)
                    {
                        if (Teclado.Varredura.Amostras[1].bits.bit0 == 0)
                        {
                            Teclado.Eventos.Tecla5 = 1;
                        }                        
                        else if (Teclado.Varredura.Amostras[1].bits.bit1 == 0)
                        {
                            Teclado.Eventos.Tecla6 = 1;
                        }                         
                        else if (Teclado.Varredura.Amostras[1].bits.bit2 == 0)
                        {
                            Teclado.Eventos.Tecla7 = 1;
                        }
                        else if (Teclado.Varredura.Amostras[1].bits.bit3 == 0)
                        {
                            Teclado.Eventos.Tecla8 = 1;
                        }                         
                    }
                    else if (Teclado.Varredura.Amostras[2].valor != 0)
                    {
                        if (Teclado.Varredura.Amostras[2].bits.bit0 == 0)
                        {
                            Teclado.Eventos.Tecla9 = 1;
                        }                        
                        else if (Teclado.Varredura.Amostras[2].bits.bit1 == 0)
                        {
                            Teclado.Eventos.Tecla10 = 1;
                        }                         
                        else if (Teclado.Varredura.Amostras[2].bits.bit2 == 0)
                        {
                            Teclado.Eventos.Tecla11 = 1;
                        }
                        else if (Teclado.Varredura.Amostras[2].bits.bit3 == 0)
                        {
                            Teclado.Eventos.Tecla12 = 1;
                        }                         
                    }                    
                    else if (Teclado.Varredura.Amostras[3].valor != 0)
                    {
                        if (Teclado.Varredura.Amostras[3].bits.bit0 == 0)
                        {
                            Teclado.Eventos.Tecla13 = 1;
                        }                        
                        else if (Teclado.Varredura.Amostras[3].bits.bit1 == 0)
                        {
                            Teclado.Eventos.Tecla14 = 1;
                        }                         
                        else if (Teclado.Varredura.Amostras[3].bits.bit2 == 0)
                        {
                            Teclado.Eventos.Tecla15 = 1;
                        }
                        else if (Teclado.Varredura.Amostras[3].bits.bit3 == 0)
                        {
                            Teclado.Eventos.Tecla16 = 1;
                        }                         
                    }  
                }
            }
    }

    if (++Teclado.Varredura.Sequencia > 4)
    {
        Teclado.Varredura.Sequencia = 0;
        Teclado_ResetaAmostras();
    }
}