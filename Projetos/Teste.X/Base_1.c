/* 
 * File:    Base 1.c
 * Autor:   JABNeto
 * Data:    13/02/2016
 */

#include <stdio.h>
#include "Base_1.h"


//Alocação de Memória para o módulo ------------------
const char Converte_Bcd_7seg[] = {_0,_1,_2,_3,_4,
                                  _5,_6,_7,_8,_9};

Str_Varredura  Varredura;



//Funções do módulo ----------------------------------

/*
 * Latch_Inicializacao
 * Faz a inicialização do Latch MC74HC574 com valor
 * de saída fornecido.
 * A rotina também faz a inicialização do PORT B.
 * No retorno da rotina PORTB = 0.
 * Valor: representa o estado inicial das saídas
 */
void Latch_Inicializacao (Uchar Valor)
{
    //Inicialização do pino RD3
    //Latch (OE) = 1
    LATDbits.LATD3 = 1;    
    TRISDbits.TRISD3 = 0;     
    ANSELDbits.ANSD3 = 0;
    
    //Inicialização do pino RD2
    //Latch (CLK) = 0
    LATDbits.LATD2 = 0;    
    TRISDbits.TRISD2 = 0;     
    ANSELDbits.ANSD2 = 0;

    //Inicialização do PORT B
    LATB = 0;
    TRISB = 0;
    ANSELB = 0;
    
    Latch_EscreveValor(Valor);
    
    LATB = 0;
    LATDbits.LATD3 = 0;   
}

/*
 * Latch_EscreveValor
 * Escreve um novo valor no latch MC74HC574
 */
void Latch_EscreveValor (Uchar Valor)
{
    LATB = Valor;

    //Escreve no latch
    LATDbits.LATD2 = 1;
    NOP();
    NOP();    
    NOP();    
    NOP();
    LATDbits.LATD2 = 0;
    
    LATB = 0;
}

/* Display_Inicializacao
 * Faz a inicialização do display
 */
void Display_Inicializacao (Uchar Valor, Uchar Digito)
{
    Latch_Inicializacao(0);
    Display_LigaDigito(Valor,Digito);
}

/* Display_LigaDigito
 * Exibe um valor no digito do display especificado.
 * Valor:  Codigo 7 segmentos do caractere a ser
 *         exibido
 * Digito: Codigo de seleção do digito 
 */
void Display_LigaDigito (Uchar Valor, Uchar Digito)
{
    LATDbits.LATD3 = 1;
    Latch_EscreveValor (Digito);
    LATB = Valor;
    LATDbits.LATD3 = 0;    
}

/* Display_InicializaVarredura
 * Faz a inicialização da varredura do display.
 * A sequencia é inicializada em 0 e os segmentos
 * dos digitos do display apagados.
 * Os leds também partem apagados.
 */
void Display_InicializaVarredura (void)
{
    Latch_Inicializacao (0);
    
    Varredura.Sequencia = 0;
    Varredura.Buffer.Digito1 = 0;
    Varredura.Buffer.Digito2 = 0;  
    Varredura.Buffer.Digito3 = 0;  
    Varredura.Buffer.Digito4 = 0;  
    Varredura.Buffer.Digito5 = 0;  
    Varredura.Buffer.Digito6 = 0;  
    Varredura.Buffer.Leds = 0;
    
    Varredura.Opcoes.valor = 0;
}

/* Display_ExecutaVarredura
 * Faz a o controle da varredura dos digitos do
 * display. Essa função deve ser chamada pela
 * rotina que temporiza a avrredura.
 */
void Display_ExecutaVarredura (void)
{
    switch (Varredura.Sequencia)
    {
        case 0:
            Display_LigaDigito(Varredura.Buffer.Leds,_Leds);
            break;
        case 1:
            Display_LigaDigito(Varredura.Buffer.Digito1,_Digito1);
            break;            
        case 2:
            Display_LigaDigito(Varredura.Buffer.Digito2,_Digito2);
            break;              
        case 3:
            Display_LigaDigito(Varredura.Buffer.Digito3,_Digito3);
            break;          
        case 4:
            Display_LigaDigito(Varredura.Buffer.Digito4,_Digito4);
            break;          
        case 5:
            Display_LigaDigito(Varredura.Buffer.Digito5,_Digito5);
            break;
        case 6:
            Display_LigaDigito(Varredura.Buffer.Digito6,_Digito6);
   }
   if (++Varredura.Sequencia == 7) Varredura.Sequencia = 0;
}

/* Display_ExibeNumero
 * Exibe um valor numérico no display.
 */
void Display_ExibeNumero (Ulong Numero)
{
    Uchar Contagem[6];
    Uchar i;
    
    sprintf (&Contagem[0],"%6lu",Numero);
    
    for (i = 0; i < 6;i++)
    {
        if (Varredura.Opcoes.OmiteZeros == _SIM)
        {
            if (Contagem[i]== ' ')
            {
                Varredura.Buffer.Digitos[i] = _br;
            }
            else
            {
                Contagem[i] -= 0x30;
                Varredura.Buffer.Digitos[i] = Converte_Bcd_7seg[Contagem[i]];                
            }
        }
        else
        {
            if (Contagem[i]== ' ')
            {
                Varredura.Buffer.Digitos[i] = _0;
            }
            else
            {
                Contagem[i] -= 0x30;
                Varredura.Buffer.Digitos[i] = Converte_Bcd_7seg[Contagem[i]];                
            }            
        }
    }
    
    if (Varredura.Opcoes.ExibePonto1 == _SIM)
    {
        Varredura.Buffer.Digito1 |= 0x80;
    }
    if (Varredura.Opcoes.ExibePonto2 == _SIM)
    {
        Varredura.Buffer.Digito2 |= 0x80;
    }
    if (Varredura.Opcoes.ExibePonto3 == _SIM)
    {
        Varredura.Buffer.Digito3 |= 0x80;
    }
    if (Varredura.Opcoes.ExibePonto4 == _SIM)
    {
        Varredura.Buffer.Digito4 |= 0x80;
    }    
    if (Varredura.Opcoes.ExibePonto5 == _SIM)
    {
        Varredura.Buffer.Digito5 |= 0x80;
    }
    if (Varredura.Opcoes.ExibePonto6 == _SIM)
    {
        Varredura.Buffer.Digito6 |= 0x80;
    }    
}

/* Teclado_Inicializacao
 * Configura os pinos do PORT A que contém
 * as teclas.
 */
void Teclado_Inicializacao (void)
{
    ANSELA = 0b00000100;
}









