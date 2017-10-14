/* 
 * Arquivo: Lcd.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include <stdio.h>

#include "Oscilador.h"
#include "Atrasos.h"
#include "Lcd.h"


//Alocação de memória para o módulo--------------------------------------------
ObjLcd    Lcd;


//Funções locais --------------------------------------------------------------    

/*****************************************************************************
 * Lcd_Aguarda50us
 * 
 * Aguarda tempo de 50us para execução dos comandos
 *****************************************************************************/
void Lcd_Aguarda50us (void)
{
    __delay_us (50);
}


/*****************************************************************************
 * Lcd_GeraPulsoEnable
 * 
 * Gera pulso de 50us no pino ENABLE do display
 *****************************************************************************/
void Lcd_GeraPulsoEnable (void)
{
    LCD_PINO_ENABLE_WR = 1;
    __delay_us (1);
    LCD_PINO_ENABLE_WR = 0;    
}

#if (LCD_INTERFACE == _4bits)
/*****************************************************************************
 * Lcd_EscreveNibbleHigh
 * Envia o nibble high do byte fornecido para o display. Essa função é utili-
 * zada quando a interface do display opera no modo de 4 bits
 *****************************************************************************/
void Lcd_EscreveNibbleHigh (Uchar Byte)
{
    #if (LCD_PORTA_NIBBLE  == High)
        LCD_PORTA_WR = ((LCD_PORTA_WR & 0x0F)|(Byte & 0xF0));
        Lcd_GeraPulsoEnable();  
    #else
        LCD_PORTA_WR = ((LCD_PORTA_WR & 0xF0)|(char)(Byte >> 4));
        Lcd_GeraPulsoEnable();   
    #endif
}

/*****************************************************************************
 * Lcd_EscreveNibbleLow
 * Envia o nibble low do byte fornecido para o display. Essa função é utili-
 * zada quando a interface do display opera no modo de 4 bits
 *****************************************************************************/
void Lcd_EscreveNibbleLow (Uchar Byte)
{
    #if (LCD_PORTA_NIBBLE  == High)
        LCD_PORTA_WR = ((LCD_PORTA_WR & 0x0F)|(char)(Byte << 4));
        Lcd_GeraPulsoEnable(); 
    #else
        LCD_PORTA_WR = ((LCD_PORTA_WR & 0xF0)|(Byte & 0x0F));
        Lcd_GeraPulsoEnable(); 
    #endif
}

/*****************************************************************************
 * Lcd_EscreveByte
 * Envia o byte fornecido para o display.
 *****************************************************************************/
void Lcd_EscreveByte (Uchar Byte)
{
    Lcd_EscreveNibbleHigh (Byte);
    Lcd_EscreveNibbleLow (Byte);    
}
#endif



#if (LCD_INTERFACE == _8bits)
/*****************************************************************************
 * Lcd_EscreveByte
 * 
 * Envia o byte fornecido para o display.
 *****************************************************************************/
void Lcd_EscreveByte (Uchar Byte)
{
    LCD_PORTA_WR = Byte;
    Lcd_GeraPulsoEnable();
}
#endif


/*****************************************************************************
 * Lcd_EnviaComando
 * Envia um comando para o display
 *****************************************************************************/
void Lcd_EnviaComando (Uchar Comando)
{
    LCD_PINO_RS_WR = 0;
    Lcd_EscreveByte (Comando);
}


/*****************************************************************************
 * Lcd_EscreveNaDDRAM
 * Escreve um byte na memória DDRAM do display
 *****************************************************************************/
void Lcd_EscreveNaDDRAM (Uchar Dado)
{
    LCD_PINO_RS_WR = 1;
    Lcd_EscreveByte (Dado);
    Lcd_Aguarda50us();
}
   
/*****************************************************************************
 * Lcd_PosicionaCursorNaDDRAM
 * Posiciona o cursor num endereço da DDRAM
 *****************************************************************************/
void Lcd_PosicionaCursorNaDDRAM (Uchar Linha,Uchar Coluna)
{
    unsigned char Posicao;
    
    switch (Linha)
    {
        #ifdef LCD_LINHA1
            case 1:
            Posicao = LCD_ENDERECO_DDRAM_LINHA1;
            break;
        #endif

        #ifdef LCD_LINHA2
            case 2:
            Posicao = LCD_ENDERECO_DDRAM_LINHA2;
            break;
        #endif

        #ifdef LCD_LINHA3
            case 3:
            Posicao = LCD_ENDERECO_DDRAM_LINHA3;
            break;
        #endif

        #ifdef LCD_LINHA4
            case 4:
            Posicao = LCD_ENDERECO_DDRAM_LINHA4;
        #endif            
    }
    
    Posicao += Coluna;
    Posicao |= 0x80;
    
    Lcd_EnviaComando (Posicao);
    Lcd_Aguarda50us();
}

#if (LCD_USA_BACKLIGHT == Sim)
/*
 *  Lcd_LigaBackLight
 *  Liga o backlight do display.
 */
void Lcd_LigaBackLight (void)
{
    LCD_PINO_BACKLIGHT_WR = 1;
}

/*
 *  Lcd_LigaBackLight
 *  DesLiga o backlight do display.
 */
void Lcd_DesligaBacklight (void)
{
    LCD_PINO_BACKLIGHT_WR = 0;
}


/*
 *  Lcd_ResetaTemporizadorBackLight
 *  Reseta o temporizador que desliga o backlight do display no modo green.
 */
void Lcd_ResetaTemporizadorBackLight (void)
{
    Lcd.Temporizadores.BackLight = LCD_MODO_GREEN_TEMPO * 100;
    Lcd_LigaBackLight();
}
#endif



//Funções publicas ------------------------------------------------------------
/******************************************************************************
 * Lcd_Inicializacao
 * Faz a inicialização do display de acordo com as definições feitas no arquivo
 * Lcd Lcd alfa config.h
 *****************************************************************************/
void Lcd_Inicializacao (void)
{
    //Configuração do pino Enable
    #ifdef LCD_PINO_ENABLE_AD
        LCD_PINO_ENABLE_AD = DIGITAL;
    #endif
    LCD_PINO_ENABLE_WR = 0;
    LCD_PINO_ENABLE_IO = SAIDA;

    //Configuração do pino RS
    #ifdef LCD_PINO_RS_AD
        LCD_PINO_RS_AD = DIGITAL;
    #endif    
    LCD_PINO_RS_WR = 0;
    LCD_PINO_RS_IO = SAIDA;     

    //Configuração do pino BackLight   
    #if (LCD_USA_BACKLIGHT == Sim)
        #ifdef LCD_PINO_BACKLIGHT_AD
            LCD_PINO_BACKLIGHT_AD = DIGITAL;
        #endif
        LCD_PINO_BACKLIGHT_WR = 0;
        LCD_PINO_BACKLIGHT_IO = SAIDA;

        
        #if (LCD_MODO_GREEN == Sim)
        Lcd.Sinais.ModoGreenAtivado = Sim;
        Lcd_ResetaTemporizadorBackLight();
        #else
        Lcd.Sinais.ModoGreenAtivado = Nao;
        Lcd_LigaBackLight();
        #endif
    #endif

    Atrasos_1ms (250);
    
    //Inicialização das funções
    Lcd.Controle.valor = 0b00001000;   
    Lcd.Interface.valor = 0b00100000;       
    Lcd.ModoDeEntrada.valor = 0b00000100;            
    Lcd.Deslocamento.valor = 0b00010100;    
    
    Lcd.Temporizadores.Intermitencia = 3;
    Lcd.Sinais.IntermitenciaAtivada = Nao; 
    
    #if (LCD_INTERFACE == _4bits)

        //Porta de IO
        LCD_PORTA_AD;     
        LCD_PORTA_IO;    
        LCD_PINO_RS_WR = 0;

        Lcd_EscreveNibbleHigh(0x30);
        Atrasos_1ms (5);        

        Lcd_EscreveNibbleHigh(0x30);        
        Atrasos_1ms (5);

        Lcd_EscreveNibbleHigh(0x30);        
        Atrasos_1ms(5);       

        Lcd_EscreveNibbleHigh(0x20);        
        Atrasos_1ms (5);           
    
        //Função set
        Lcd.Interface.DL = 0;    

        #if (LCD_NUMERO_DE_LINHAS == 1)
            Lcd.Interface.N = 0;    
        #else
            Lcd.Interface.N = 1;   
        #endif    

        Lcd_EnviaComando(Lcd.Interface.valor);
        Lcd_Aguarda50us;

        Lcd_EnviaComando(Lcd.ModoDeEntrada.valor);
        Lcd_Aguarda50us; 
        
        Lcd_EnviaComando(Lcd.Deslocamento.valor);
        Lcd_Aguarda50us;    

        Lcd_LimpaBuffers();        
        Lcd_ApagaMensagens();
        Lcd_LigaDisplay();

    #endif


    #if (LCD_INTERFACE == _8bits)
        
        //Porta de IO
        LCD_PORTA_IO;
        LCD_PINO_RS_WR = 0;

        Lcd_EnviaComando(0x30);
        Atrasos_1ms(5); 

        Lcd_EnviaComando(0x30);        
        Atrasos_1ms(5); 

        Lcd_EnviaComando(0x30);        
        Atrasos_1ms(5); 

        //Função set
        Lcd.Interface.DL = 1;    

        #if (LCD_NUMERO_DE_LINHAS == 1)
            Lcd.Interface.N = 0;    
        #else
            Lcd.Interface.N = 1;   
        #endif    

        Lcd_EnviaComando(Lcd.Interface.valor);
        Lcd_Aguarda50us;

        Lcd_EnviaComando(Lcd.ModoDeEntrada.valor);
        Lcd_Aguarda50us;    

        Lcd_LimpaBuffers();        
        Lcd_ApagaMensagens();
        Lcd_LigaDisplay();
    #endif

}


/******************************************************************************
 * Lcd_CarregaPonteiroDoBuffer
 * 
 * Retorna o endereço do buffer do display mediante os valores da linha e
 * da coluna fornecidos
 *****************************************************************************/
Uchar *Lcd_CarregaPonteiroDoBuffer (Uchar Linha, Uchar Coluna)
{
    unsigned char *Pnt;
    
    switch (Linha)
        {
            #ifdef LCD_LINHA1
                case 1:
                    Pnt = &Lcd.BufferLinha1[0];
                    break;
            #endif

            #ifdef LCD_LINHA2
                case 2:
                    Pnt = &Lcd.BufferLinha2[0];
                    break;
            #endif        

            #ifdef LCD_LINHA3
                case 3:
                    Pnt = &Lcd.BufferLinha3[0];
                    break;
            #endif        

            #ifdef LCD_LINHA4
                case 4:
                    Pnt = &Lcd.BufferLinha4[0];
                    break;
            #endif        
        }
    
    return (Pnt + Coluna);
}


/******************************************************************************
 * Lcd_LimpaBuffer
 * 
 * Limpa o buffer da linha especificada
 *****************************************************************************/
void Lcd_LimpaBuffer (Uchar Linha)
{
    unsigned char *Pnt, *PntFinal;
    
    Pnt = Lcd_CarregaPonteiroDoBuffer(Linha,0);
    PntFinal = Pnt + LCD_NUMERO_DE_COLUNAS;
    
    while (Pnt < PntFinal)
    {
        *Pnt++ = ' ';
    }
}

/******************************************************************************
 * Lcd_LimpaBuffer
 * 
 * Limpa todos os buffers das linhas do display
 *****************************************************************************/
void Lcd_LimpaBuffers (void)
{
    #ifdef LCD_LINHA1
        Lcd_LimpaBuffer(1);
    #endif
    
    #ifdef LCD_LINHA2
        Lcd_LimpaBuffer(2);
    #endif

    #ifdef LCD_LINHA3
        Lcd_LimpaBuffer(3);
    #endif

    #ifdef LCD_LINHA4
        Lcd_LimpaBuffer(4);
    #endif        
}


/******************************************************************************
 * Lcd_TransfereMensagemParaBuffer
 * Transfere uma mensagem contida na memória Flash para um dos buffer do
 * display. Após a transferência o conteúdo do ponteiro *Buffer é retornado
 * para a função que fez a chamada da função.
 * *Buffer:     Aponta para o local no buffer do display, onde a mensagem será
 *              transferida.
 * *Mensagem:   Aponta para a mensagem que será transferida.
 * 
 * Ex. Lcd_TransfereMensagemParaBuffer(&Lcd.BufferLinha1[0], &Msg[0]);
 *     Transfere a mensagem Msg para o buffer da linha 1 do Display. A mensagem
 *     é colocada no buffer, a partir da coluna 0.
 *****************************************************************************/
Uchar *Lcd_TransfereMensagemParaBuffer (Uchar *Buffer, Cchar *Mensagem)
{
    while (*Mensagem != '\0')
    {
        *Buffer++ = *Mensagem++;
    }
    
    return Buffer;
}

/******************************************************************************
 * Lcd_TransfereStreamParaBuffer
 * Transfere a quantidade de caracteres do estream para o buffer do display.
 * O endereço contido no ponteiro é retornado permitido a continuidade da
 * escrita.
 * 
 * *Buffer: Aponta para o local do buffer para onde os caracteres serão
 *          transferidos.
 * *Stream: Aponta para o Stream onde os caracteres estão armazenados.
 * 
 * Para utilizar essa função o Stream deve ser carregado com os caracteres 
 * formatados. O exemplo abaixo mostra como transferir um numero na forma de
 * ponto flutuante para o Stream.
 * Ex.  Uchar Stream[8];
 *      Float Medida = 125.89;
 *      sprintf(&Stream[0],"%u", (Uint)Medidas)
 *****************************************************************************/
Uchar *Lcd_TransfereStreamParaBuffer (Uchar *Buffer, Uchar *Stream)
{
    while (*Stream != '\0')
    {
        *Buffer++ = *Stream++;
    }
    
    return Buffer;
}


/******************************************************************************
 * Lcd_AtualizaLinha
 * Envia os dados do buffer da linha especificada para o display
 *****************************************************************************/
void Lcd_AtualizaLinha (Uchar Linha)
{
    unsigned char *Pnt,*FinalDoBuffer;

    Lcd_PosicionaCursorNaDDRAM(Linha,0);
    
    Pnt = Lcd_CarregaPonteiroDoBuffer(Linha,0);
    FinalDoBuffer = Pnt + LCD_NUMERO_DE_COLUNAS;
    
    while (Pnt < FinalDoBuffer)
    {
        Lcd_EscreveNaDDRAM (*Pnt++);
    }    
}


/******************************************************************************
 * Lcd_AtualizaLinhas
 * Envia todos os dados contidos nos buffers para o display
 *****************************************************************************/
void Lcd_AtualizaLinhas(void)
{
    #ifdef LCD_LINHA1
        Lcd_AtualizaLinha(1);
    #endif
    
    #ifdef LCD_LINHA2
        Lcd_AtualizaLinha(2);
    #endif    
    
    #ifdef LCD_LINHA3
        Lcd_AtualizaLinha(3);
    #endif
        
    #ifdef LCD_LINHA4
        Lcd_AtualizaLinha(4);
    #endif 
}


/******************************************************************************
 * Lcd_Monitor
 * Monitora as funções do Lcd como intermitencia e Backlight. Essa função
 * deve ser chamada periodicamente em intervalos de 10ms. Geralmente o Timer 0.
 *****************************************************************************/
void Lcd_Monitor (void)
{
    if (--Lcd.Temporizadores.Intermitencia == 0)
    {
        Lcd.Temporizadores.Intermitencia = (LCD_INTERMITENCIA_TEMPO / 10);

        if (Lcd.Sinais.IntermitenciaEstado) Lcd.Sinais.IntermitenciaEstado = 0;
        else Lcd.Sinais.IntermitenciaEstado = 1;
    }

    #if (LCD_MODO_GREEN == Sim)
    if(Lcd.Temporizadores.BackLight > 0)
    {
        if(--Lcd.Temporizadores.BackLight == 0)
        {
            Lcd_DesligaBacklight();
        }
    }
    #endif   
}


//Funções do display-----------------------------------------------------------
/******************************************************************************
 * void Lcd_ApagaMensagens
 * 
 * Apaga todas as mensagens de tela do display. Escreve 0x20 em todas os ende-
 * reços da DDRAM
 *****************************************************************************/
void Lcd_ApagaMensagens (void)
{
    Lcd_EnviaComando (0x01);
    Atrasos_1ms(2);
}

/******************************************************************************
 * Lcd_Home
 * 
 * Seta o endereço da DDRAM para o endereço 0x00 e coloca o cursor nessa
 * posição. O conteúdo da DDRAM não é alterado.
 *****************************************************************************/
void Lcd_Home (void)
{
    Lcd_EnviaComando (0x02);
    Atrasos_1ms(2);
}

/******************************************************************************
 * Lcd_DesligaLcd
 * 
 * Desliga o display mantendo o conteúdo da memória.
 *****************************************************************************/
void Lcd_DesligaDisplay (void)
{
    Lcd.Controle.D = 0;
    Lcd_EnviaComando(Lcd.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_LigaDisplaY
 * 
 * Liga o display.
 *****************************************************************************/
void Lcd_LigaDisplay (void)
{
    Lcd.Controle.D = 1;
    Lcd_EnviaComando(Lcd.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_LigaCursor
 * 
 * Liga o cursor
 *****************************************************************************/
void Lcd_LigaCursor (void)
{
    Lcd.Controle.C = 1;
    Lcd_EnviaComando(Lcd.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_DesligaCursor
 * 
 * Desliga o cursor
 *****************************************************************************/
void Lcd_DesligaCursor (void)
{
    Lcd.Controle.C = 0;
    Lcd_EnviaComando(Lcd.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_DeslocaCursorParaEsquerda
 * 
 * Desloca o cursor para a esquerda após a entrada de um caractere
 *****************************************************************************/
void Lcd_DeslocaCursorParaEsquerda (void)
{
    Lcd.Deslocamento.SC = 0;
    Lcd.Deslocamento.RL = 0;
    Lcd_EnviaComando(Lcd.Deslocamento.valor);
    Lcd_Aguarda50us();   
}

/******************************************************************************
 * Lcd_DeslocaCursorParaDireita
 * 
 * Desloca o cursor para a direita após a entrada de um cactere
 *****************************************************************************/
void Lcd_DeslocaCursorParaDireita (void)
{
    Lcd.Deslocamento.SC = 0;
    Lcd.Deslocamento.RL = 1;
    Lcd_EnviaComando(Lcd.Deslocamento.valor);
    Lcd_Aguarda50us();   
}

/******************************************************************************
 * Lcd_DeslocaMensagemParaEsquerda
 * 
 * Desloca a mensagem para a esquerda após a entrada de um caractere
 *****************************************************************************/
void Lcd_DeslocaMensagemParaEsquerda (void)
{
    Lcd.Deslocamento.SC = 1;
    Lcd.Deslocamento.RL = 0;
    Lcd_EnviaComando(Lcd.Deslocamento.valor);
    Lcd_Aguarda50us();  
}

/******************************************************************************
 * Lcd_DeslocaMensagemParaDireita
 * 
 * Desloca a mensagem para a direita após entrada de um caractere
 *****************************************************************************/
void Lcd_DeslocaMensagemParaDireita (void)
{
    Lcd.Deslocamento.SC = 1;
    Lcd.Deslocamento.RL = 1;
    Lcd_EnviaComando(Lcd.Deslocamento.valor);
    Lcd_Aguarda50us();    
}

/******************************************************************************
 * Lcd_LigaBlink
 * Liga modo Blink do cursor (Cursor piscando)
 *****************************************************************************/
void Lcd_LigaBlink (void)
{
    Lcd.Controle.B = 1;    
    Lcd_EnviaComando(Lcd.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_DesligaBlink
 * Desliga o modo blink (cursor piscando).
 *****************************************************************************/
void Lcd_DesLigaBlink (void)
{
    Lcd.Controle.B = 0;    
    Lcd_EnviaComando(Lcd.Controle.valor);
    Lcd_Aguarda50us();
}


//Funções da CGRAM ------------------------------------------------------------
#if (LCD_INCLUIR_FUNCOES_CGRAM == Sim)
#ifdef ALOCA_CGRAM_0P
ALOCA_CGRAM_0P;
#endif

#ifdef ALOCA_CGRAM_1P
ALOCA_CGRAM_1P;
#endif

#ifdef ALOCA_CGRAM_2P
ALOCA_CGRAM_2P;
#endif

#ifdef ALOCA_CGRAM_3P
ALOCA_CGRAM_3P;
#endif

#ifdef ALOCA_CGRAM_4P
ALOCA_CGRAM_4P;
#endif

#ifdef ALOCA_CGRAM_5P
ALOCA_CGRAM_5P;
#endif

#ifdef ALOCA_CGRAM_6P
ALOCA_CGRAM_6P;
#endif

#ifdef ALOCA_CGRAM_7P
ALOCA_CGRAM_7P;
#endif

#ifdef ALOCA_CGRAM_8P
ALOCA_CGRAM_8P;
#endif

#ifdef ALOCA_CGRAM_9P
ALOCA_CGRAM_9P;
#endif

#ifdef ALOCA_CGRAM_EP
ALOCA_CGRAM_EP;
#endif


/*
 * Lcd_CriaCaractereNaCGRAM
 * Cria um caractere ou simbolo na CGRAM.
 * 
 * Local      Define o endereço de armazenamento (CGRAM_0 a CGRAM_7)
 * Caractere  Endereço da matriz do caractere.
 */
void Lcd_CriaCaractereNaCGRAM (Uchar Local, Cchar *Caractere)
{
    Uchar i;
    
    Local |= 0x40;
    Lcd_EnviaComando (Local);
    Lcd_Aguarda50us();
    
    for (i = 0; i < 8; i++)
    {
        Lcd_EscreveNaDDRAM (*Caractere++);
    }
}
#endif



//Funções de exibição de dada e hora ------------------------------------------
#if (LCD_INCLUIR_FUNCOES_EXIBE_DATA_HORAS == Sim)

const char _Dom[] = "Dom";
const char _Seg[] = "Seg";
const char _Ter[] = "Ter";
const char _Qua[] = "Qua";
const char _Qui[] = "Qui";
const char _Sex[] = "Sex";
const char _Sab[] = "Sab";

/*
 * Lcd_ExibeHorario
 * Exibe horario no display.
 * 
 * Linha:   Linha em que o horario deve ser exibido
 * Coluna:  Coluna a partir do qual o horario deve ser exibido
 * *Horario: Endereço do buffer do relogio
 * Formato: Formatação do modo de exibição do horario
 *   _HMS: Exibe HH:MM:SS
 *   _HM:  Exibe HH:MM     
 */
void Lcd_ExibeHorario (Uchar *Buffer, ObjHorario *Horario, Uchar Formato)
{
    Uchar Stream[9];
    
    sprintf(&Stream[0],"%02u",Horario->Horas);
    Stream[2]= ':';
    sprintf(&Stream[3],"%02u",Horario->Minutos);    

    if (Formato == _HMS)
    {
        Stream[5]= ':';
        sprintf(&Stream[6],"%02u",Horario->Segundos);   
    }
    
    Lcd_TransfereStreamParaBuffer(Buffer,&Stream[0]);
}

/*
 * Lcd_ExibeData
 * Exibe data no display.
 * 
 * Linha:   Linha em que a data deve ser exibida
 * Coluna:  Coluna a partir do qual a data deve ser exibida
 * *Data:   Endereço do buffer da data
 * Formato: Formatação do modo de exibição da data
 *   _DM:   Exibe DD/MM
 *   _DMA:  Exibe DD/MM/AA
 *   _DMAA: Exibe DD/MM/20AA    
 */
void Lcd_ExibeData (Uchar *Buffer, ObjData *Data, Uchar Formato)
{
    Uchar Stream[11];
    
    sprintf(&Stream[0],"%u",Data->Dia);
    Stream[2]= '/';
    sprintf(&Stream[3],"%u",Data->Mes);    

    
    if (Formato != _DM)
    {
        Stream[5]= '/';
        
        if (Formato == _DMAA)
        {
            Stream[6]= 0x32;
            Stream[7]= 0x30;
            sprintf(&Stream[8],"%u",Data->Ano);  
        }    
        else
        {
            sprintf(&Stream[6],"%u",Data->Ano);  
        }
    }
    
    Lcd_TransfereStreamParaBuffer(Buffer,&Stream[0]);
}

/*
 * Lcd_ExibeDiaDaSemana
 * Exibe o dia da semana no display.
 * 
 * Buffer: Aponta para o local onde a Data será escrita
 * DiaDaSemana: Valor do dia da semana (Dom=1, ... Sab=7)
 */
void Lcd_ExibeDiaDaSemana (Uchar *Buffer, Uchar DiaDaSemana)
{
    const char *Msg;
    
    switch (DiaDaSemana)
    {
        case 1:
            Msg = &_Dom[0];
            break;
            
        case 2:
            Msg = &_Seg[0];
            break;            
            
        case 3:
            Msg = &_Ter[0];
            break;            
            
        case 4:
            Msg = &_Qua[0];
            break;            
            
        case 5:
            Msg = &_Qui[0];
            break;            
            
        case 6:
            Msg = &_Sex[0];
            break;
            
        case 7:
            Msg = &_Sab[0];
    }
    
    *Buffer++ = *Msg++;
    *Buffer++ = *Msg++;    
    *Buffer++ = *Msg++;    
}

#endif




