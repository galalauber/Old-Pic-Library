/* 
 * Arquivo: Display lcd alfa.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include "Oscilador.h"
#include "Display lcd alfa.h"


//Alocação de memória para o módulo--------------------------------------------
_CtrlDisplay    CtrlDisplay;


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
 * Lcd_Atrasos_ms
 * 
 * Gera um atraso de n x ms. Se o valor fornecido for 0, o atraso não é gerado.
 * Atraso: valor de 1 a 255 (1 a 255ms)
 *****************************************************************************/
void Lcd_Atrasos_ms (unsigned char Atraso)
{
    while (Atraso > 0)
    {
        __delay_ms (1);        
        Atraso--;
    }
}

/*****************************************************************************
 * Lcd_GeraPulsoEnable
 * 
 * Gera pulso de 50us no pino ENABLE do display
 *****************************************************************************/
void Lcd_GeraPulsoEnable (void)
{
    _LCD_PINO_ENABLE_WR = 1;
    __delay_us (1);
    _LCD_PINO_ENABLE_WR = 0;    
}

/*****************************************************************************
 * Lcd_EscreveNibbleHigh
 * 
 * Envia o nibble high do byte fornecido para o display. Essa função é utili-
 * zada quando a interface do display opera no modo de 4 bits
 *****************************************************************************/
void Lcd_EscreveNibbleHigh (unsigned char Byte)
{
    #if (_LCD_INTERFACE_NIBBLE  == _HIGH)
       _LCD_REGISTRADOR_WR = ((_LCD_REGISTRADOR_WR & 0x0F)|(Byte & 0xF0));
        Lcd_GeraPulsoEnable();  
    #else
        _LCD_REGISTRADOR_WR = ((_LCD_REGISTRADOR_WR & 0xF0)|(char)(Byte >> 4));
        Lcd_GeraPulsoEnable();   
    #endif
}

/*****************************************************************************
 * Lcd_EscreveNibbleLow
 * 
 * Envia o nibble low do byte fornecido para o display. Essa função é utili-
 * zada quando a interface do display opera no modo de 4 bits
 *****************************************************************************/
void Lcd_EscreveNibbleLow (unsigned char Byte)
{
    #if (_LCD_INTERFACE_NIBBLE  == _HIGH)
        _LCD_REGISTRADOR_WR = ((_LCD_REGISTRADOR_WR & 0x0F)|(char)(Byte << 4));
        Lcd_GeraPulsoEnable(); 
    #else
        _LCD_REGISTRADOR_WR = ((_LCD_REGISTRADOR_WR & 0xF0)|(Byte & 0x0F));
        Lcd_GeraPulsoEnable(); 
    #endif
}

/*****************************************************************************
 * Lcd_EscreveByte
 * 
 * Envia o byte fornecido para o display.
 *****************************************************************************/
void Lcd_EscreveByte (unsigned char Byte)
{
#if (_LCD_INTERFACE == _8BITS)      
    _LCD_REGISTRADOR_WR = Byte;
    Lcd_GeraPulsoEnable();
#endif
    
#if (_LCD_INTERFACE == _4BITS)     
    Lcd_EscreveNibbleHigh (Byte);
    Lcd_EscreveNibbleLow (Byte);    
#endif    
}

/*****************************************************************************
 * Lcd_EnviaComando
 * 
 * Envia um comando para o display
 *****************************************************************************/
void Lcd_EnviaComando (unsigned char Comando)
{
    _LCD_PINO_RS_WR = 0;
    Lcd_EscreveByte (Comando);
}

/*****************************************************************************
 * Lcd_EscreveNaDDRAM
 * 
 * Escreve um byte na memória DDRAM do display
 *****************************************************************************/
void Lcd_EscreveNaDDRAM (unsigned char Dado)
{
    _LCD_PINO_RS_WR = 1;
    Lcd_EscreveByte (Dado);
    Lcd_Aguarda50us();
}

/*****************************************************************************
 * Lcd_PosicionaCursorNaDDRAM
 * 
 * Posiciona o cursor num endereço da DDRAM
 *****************************************************************************/
void Lcd_PosicionaCursorNaDDRAM (unsigned char Linha,unsigned char Coluna)
{
    unsigned char Posicao;
    
    switch (Linha)
    {
        #ifdef _LCD_LINHA1
            case 1:
            Posicao = _LCD_ENDERECO_DDRAM_LINHA1;
            break;
        #endif

        #ifdef _LCD_LINHA2
            case 2:
            Posicao = _LCD_ENDERECO_DDRAM_LINHA2;
            break;
        #endif

        #ifdef _LCD_LINHA3
            case 3:
            Posicao = _LCD_ENDERECO_DDRAM_LINHA3;
            break;
        #endif

        #ifdef _LCD_LINHA4
            case 4:
            Posicao = _LCD_ENDERECO_DDRAM_LINHA4;
        #endif            
    }
    
    Posicao += Coluna;
    Posicao |= 0x80;
    
    Lcd_EnviaComando (Posicao);
    Lcd_Aguarda50us();
}


/******************************************************************************
 * Lcd_ApontaParaLinha
 * 
 * Retorna o endereço do buffer da linha especificada
 *****************************************************************************/
unsigned char *Lcd_ApontaParaLinha (unsigned char Linha)
{
    unsigned char *Pnt;
    
    switch (Linha)
        {
            #ifdef _LCD_LINHA1
                case 1:
                    Pnt = &CtrlDisplay.BufferLinha1[0];
                    break;
            #endif

            #ifdef _LCD_LINHA2
                case 2:
                    Pnt = &CtrlDisplay.BufferLinha2[0];
                    break;
            #endif        

            #ifdef _LCD_LINHA3
                case 3:
                    Pnt = &CtrlDisplay.BufferLinha3[0];
                    break;
            #endif        

            #ifdef _LCD_LINHA4
                case 4:
                    Pnt = &CtrlDisplay.BufferLinha4[0];
                    break;
            #endif        
        }
    
    return Pnt;
}



//Funções publicas ------------------------------------------------------------

/******************************************************************************
 * Lcd_Inicializacao
 * 
 * Faz a inicialização do display de acordo com as definições feitas no arquivo
 * Display lcd alfa config.h
 *****************************************************************************/
void Lcd_Inicializacao (void)
{
    unsigned char i;
    
    //Configuração do pino Enable
    #ifdef _LCD_PINO_ENABLE_AD
        _LCD_PINO_ENABLE_AD;
    #endif    
    _LCD_PINO_ENABLE_WR = 0;
    _LCD_PINO_ENABLE_SAIDA;

   
    //Configuração do pino RS
    #ifdef _LCD_PINO_RS_AD
        _LCD_PINO_RS_AD;
    #endif    
    _LCD_PINO_RS_WR = 0;
    _LCD_PINO_RS_SAIDA;

     
    i = 8;
    
    while (i-- > 0 )
    {
      Lcd_Atrasos_ms(250);
    }
    
    
    //Inicialização das funções
    CtrlDisplay.Controle.valor = 0b00001000;   
    CtrlDisplay.Interface.valor = 0b00100000;       
    CtrlDisplay.ModoDeEntrada.valor = 0b00000110;            
    CtrlDisplay.Deslocamento.valor = 0b00010000;    
    
    #if (_LCD_INTERFACE == _4BITS)

        //Porta de IO
        _LCD_CONFIGURA_IO;
        _LCD_PINO_RS_WR = 0;

        Lcd_EscreveNibbleHigh(0x30);
        Lcd_Atrasos_ms(5);        

        Lcd_EscreveNibbleHigh(0x30);        
        Lcd_Atrasos_ms(1);

        Lcd_EscreveNibbleHigh(0x30);        
        Lcd_Atrasos_ms(1);       

        Lcd_EscreveNibbleHigh(0x20);        
        Lcd_Atrasos_ms(1);    
    
        //Função set
        CtrlDisplay.Interface.DL = 0;    

        #if (_LCD_NUMERO_DE_LINHAS == 1)
            CtrlDisplay.Interface.N = 0;    
        #else
            CtrlDisplay.Interface.N = 1;   
        #endif    

        Lcd_EnviaComando(CtrlDisplay.Interface.valor);
        Lcd_Aguarda50us;

        Lcd_EnviaComando(CtrlDisplay.ModoDeEntrada.valor);
        Lcd_Aguarda50us;    

        Lcd_LimpaDisplay();
        Lcd_Home();    
        Lcd_LigaDisplay();

        Lcd_LimpaBuffers();
    
    #else

    // Interface de 8 bits ---------------------------------------------------
        
        //Porta de IO
        _LCD_CONFIGURA_IO;
        _LCD_PINO_RS_WR = 0;

        Lcd_EnviaComando(0x30);
        Lcd_Atrasos_ms(5); 

        Lcd_EnviaComando(0x30);        
        Lcd_Atrasos_ms(1); 

        Lcd_EnviaComando(0x30);        
        Lcd_Atrasos_ms(1); 

        //Função set
        CtrlDisplay.Interface.DL = 1;    

        #if (_LCD_NUMERO_DE_LINHAS == 1)
            CtrlDisplay.Interface.N = 0;    
        #else
            CtrlDisplay.Interface.N = 1;   
        #endif    

        Lcd_EnviaComando(CtrlDisplay.Interface.valor);
        Lcd_Aguarda50us;

        Lcd_EnviaComando(CtrlDisplay.ModoDeEntrada.valor);
        Lcd_Aguarda50us;    

        Lcd_LimpaDisplay();
        Lcd_Home();    
        Lcd_LigaDisplay();

        Lcd_LimpaBuffers();

#endif

    //Backlight    
    #if (_LCD_USA_BACKLIGHT == _SIM)
        Lcd_InicializaBackLigth();
    #endif            
}

/******************************************************************************
 * Lcd_LimpaBuffer
 * 
 * Limpa o buffer da linha especificada
 *****************************************************************************/
void Lcd_LimpaBuffer (unsigned char Linha)
{
    unsigned char *Pnt, *PntFinal;
    
    Pnt = Lcd_ApontaParaLinha(Linha);
    PntFinal = Pnt + _LCD_NUMERO_DE_COLUNAS;
    
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
    #ifdef _LCD_LINHA1
        Lcd_LimpaBuffer(1);
    #endif
    
    #ifdef _LCD_LINHA2
        Lcd_LimpaBuffer(2);
    #endif

    #ifdef _LCD_LINHA3
        Lcd_LimpaBuffer(3);
    #endif

    #ifdef _LCD_LINHA4
        Lcd_LimpaBuffer(4);
    #endif        
}

/******************************************************************************
 * Lcd_TransfereMensagemParaBuffer
 * 
 * Transfere uma mensagem contida na memória Flash para um dos buffer do
 * display 
 *****************************************************************************/
void Lcd_TransfereMensagemParaBuffer (Uchar Linha, Uchar Coluna,
                                      const char *Mensagem)
{
    unsigned char *Pnt;
    
    Pnt = Lcd_ApontaParaLinha(Linha)+ Coluna;

    while (*Mensagem != '\0')
    {
        *Pnt++ = *Mensagem++;
    }    
}

/******************************************************************************
 * Lcd_AtualizaDisplay
 * 
 * Envia os dados do buffer da linha especificada
 * para o display
 *****************************************************************************/
void Lcd_AtualizaDisplay (unsigned char Linha)
{
    unsigned char *Pnt,*FinalDoBuffer;

    Lcd_PosicionaCursorNaDDRAM(Linha,0);
    
    Pnt = Lcd_ApontaParaLinha(Linha);
    FinalDoBuffer = Pnt + _LCD_NUMERO_DE_COLUNAS;
    
    while (Pnt < FinalDoBuffer)
    {
        Lcd_EscreveNaDDRAM (*Pnt++);
    }    
}

/******************************************************************************
 * Lcd_AtualizaIntermitencia
 * Troca o nivel lógico do sinal de intermitencia 
 *****************************************************************************/
void Lcd_AtualizaIntermitencia(void)
{
    ~CtrlDisplay.Sinais.IntermitenciaEvento;
}

//Controle do backlight -------------------------------------------------------
#if (_LCD_USA_BACKLIGHT == _SIM)
/******************************************************************************
 * Lcd_InicializaBackLigth
 * 
 * Faz a inicialização do backligth do display
 *****************************************************************************/
void Lcd_InicializaBackLigth (void)
{
    #ifdef _LCD_PINO_BACKLIGHT_AD
        _LCD_PINO_BACKLIGHT_AD;
    #endif
    _LCD_PINO_BACKLIGHT_WR = 1;
    _LCD_PINO_BACKLIGHT_SAIDA;

    #if (_LCD_MODO_GREEN == _SIM)
        Lcd_ModoGreenRefresh ();
    #endif
}

/******************************************************************************
 * Lcd_LigaBackLight
 * 
 * Liga o backlight do display.
 *****************************************************************************/
void Lcd_LigaBackLight (void)
{
    _LCD_PINO_BACKLIGHT_WR = 1;
}

/******************************************************************************
 * Lcd_DesligaBackLight
 * 
 * Desliga o backlight do display.
 *****************************************************************************/
void Lcd_DesligaBackLight (void)
{
    _LCD_PINO_BACKLIGHT_WR = 0;
}

/******************************************************************************
 * Lcd_LigaEventoBackLight
 * 
 * Sinaliza evento de 1s para o backlight do display
 *****************************************************************************/
void Lcd_LigaEventoBackLight (void)
{
    CtrlDisplay.Sinais.BackLightEvento1s = 1;
}

#if (_LCD_MODO_GREEN == _SIM)
/******************************************************************************
 * Lcd_ModoGreen_Refresh
 * 
 * Recarrega o temporizador do modo green.
 *****************************************************************************/
void Lcd_ModoGreenRefresh (void)
{
    CtrlDisplay.Backlight.Tempo = _LCD_MODO_GREEN_TEMPO;
    Lcd_LigaBackLight();
}
#endif
#endif



//Funções do display-----------------------------------------------------------
/******************************************************************************
 * Lcd_LimpaDisplay
 * 
 * Apaga todas as linhas do display e coloca o cursor na posição 0
 *****************************************************************************/
void Lcd_LimpaDisplay (void)
{
    Lcd_EnviaComando (0x01);
    Lcd_Atrasos_ms(1);
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
    Lcd_Atrasos_ms(1);
}

/******************************************************************************
 * Lcd_DesligaDisplay
 * 
 * Desliga o display mantendo mensagem
 *****************************************************************************/
void Lcd_DesligaDisplay (void)
{
    CtrlDisplay.Controle.D = 0;
    Lcd_EnviaComando(CtrlDisplay.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_LigaDisplay
 * 
 * Liga o display
 *****************************************************************************/
void Lcd_LigaDisplay (void)
{
    CtrlDisplay.Controle.D = 1;
    Lcd_EnviaComando(CtrlDisplay.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_LigaCursor
 * 
 * Liga o cursor
 *****************************************************************************/
void Lcd_LigaCursor (void)
{
    CtrlDisplay.Controle.C = 1;
    Lcd_EnviaComando(CtrlDisplay.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_DesligaCursor
 * 
 * Desliga o cursor
 *****************************************************************************/
void Lcd_DesligaCursor (void)
{
    CtrlDisplay.Controle.C = 0;
    Lcd_EnviaComando(CtrlDisplay.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_DeslocaCursorParaEsquerda
 * 
 * Desloca o cursor para a esquerda após a entrada de um caractere
 *****************************************************************************/
void Lcd_DeslocaCursorParaEsquerda (void)
{
    CtrlDisplay.Deslocamento.SC = 0;
    CtrlDisplay.Deslocamento.RL = 0;
    Lcd_EnviaComando(CtrlDisplay.Deslocamento.valor);
    Lcd_Aguarda50us();   
}

/******************************************************************************
 * Lcd_DeslocaCursorParaDireita
 * 
 * Desloca o cursor para a direita após a entrada de um cactere
 *****************************************************************************/
void Lcd_DeslocaCursorParaDireita (void)
{
    CtrlDisplay.Deslocamento.SC = 0;
    CtrlDisplay.Deslocamento.RL = 1;
    Lcd_EnviaComando(CtrlDisplay.Deslocamento.valor);
    Lcd_Aguarda50us();   
}

/******************************************************************************
 * Lcd_DeslocaMensagemParaEsquerda
 * 
 * Desloca a mensagem para a esquerda após a entrada de um caractere
 *****************************************************************************/
void Lcd_DeslocaMensagemParaEsquerda (void)
{
    CtrlDisplay.Deslocamento.SC = 1;
    CtrlDisplay.Deslocamento.RL = 0;
    Lcd_EnviaComando(CtrlDisplay.Deslocamento.valor);
    Lcd_Aguarda50us();  
}

/******************************************************************************
 * Lcd_DeslocaMensagemParaDireita
 * 
 * Desloca a mensagem para a direita após entrada de um caractere
 *****************************************************************************/
void Lcd_DeslocaMensagemParaDireita (void)
{
    CtrlDisplay.Deslocamento.SC = 1;
    CtrlDisplay.Deslocamento.RL = 1;
    Lcd_EnviaComando(CtrlDisplay.Deslocamento.valor);
    Lcd_Aguarda50us();    
}

/******************************************************************************
 * Lcd_LigaBlank
 * 
 * Liga o cursor no modo blank
 *****************************************************************************/
void Lcd_LigaBlank (void)
{
    CtrlDisplay.Controle.B = 1;    
    Lcd_EnviaComando(CtrlDisplay.Controle.valor);
    Lcd_Aguarda50us();
}

/******************************************************************************
 * Lcd_LigaBlank
 * 
 * Liga o cursor no modo blank
 *****************************************************************************/
void Lcd_DesLigaBlank (void)
{
    CtrlDisplay.Controle.B = 0;    
    Lcd_EnviaComando(CtrlDisplay.Controle.valor);
    Lcd_Aguarda50us();
}




//Funções de exibição de dada e hora ------------------------------------------
#if (_LCD_FUNCOES_CGRAM == _SIM)
_0_MINUSCULO;
_1_MINUSCULO;
_2_MINUSCULO;
_3_MINUSCULO;
_4_MINUSCULO;
_5_MINUSCULO;
_6_MINUSCULO;


/*
 * Lcd_CriaCaractereNaCGRAM
 * Cria um caractere ou simbolo na CGRAM.
 * 
 * Local: Define o endereço de armazenamento (CGRAM_0 a CGRAM_7)
 * Caractere: Endereço da matriz do caractere.
 */
void Lcd_CriaCaractereNaCGRAM (Uchar Local, Uchar *Caractere)
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
#if (_LCD_FUNCOES_RELOGIO == _SIM)

const char _Domingo[] = "DOM";
const char _Segunda[] = "SEG";
const char _Terca[] =   "TER";
const char _Quarta[] =  "QUA";
const char _Quinta[] =  "QUI";
const char _Sexta[] =   "SEX";
const char _Sabado[] =  "SAB";


/*
 * Lcd_ConverteBcdEmAscii
 * Converte um numero Bcd no seu correspondente valor Ascii
 */
Uint Lcd_ConverteBcdEmAscii (Uchar Bcd)
{
    Uint16 Ascii;
    
    Ascii.bytes.byte0 = (Bcd & 0x0F) + 0x30;
    Ascii.bytes.byte1 = ((Bcd & 0xF0) >> 4) + 0x30;    
    
    return Ascii.valor;
}


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
void Lcd_ExibeHorario (Uchar Linha, Uchar Coluna, _Horario *Horario, Uchar Formato)
{
    Uchar   *Pnt;
    Uint16  Ascii;
    
    Pnt = Lcd_ApontaParaLinha(Linha) + Coluna;
    
    Ascii.valor = Lcd_ConverteBcdEmAscii (Horario->Horas);
    *Pnt++ = Ascii.bytes.byte1;
    *Pnt++ = Ascii.bytes.byte0;    
    *Pnt++ = ':';
    
    Ascii.valor = Lcd_ConverteBcdEmAscii (Horario->Minutos);
    *Pnt++ = Ascii.bytes.byte1;
    *Pnt++ = Ascii.bytes.byte0;    
    *Pnt++ = ':';
    
    if (Formato == _HMS)
    {
        Ascii.valor = Lcd_ConverteBcdEmAscii (Horario->Segundos);
        *Pnt++ = Ascii.bytes.byte1;
        *Pnt++ = Ascii.bytes.byte0;    
    }
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
void Lcd_ExibeData (Uchar Linha, Uchar Coluna, _Data *Data, Uchar Formato)
{
    Uchar   *Pnt;
    Uint16  Ascii;
    
    Pnt = Lcd_ApontaParaLinha(Linha) + Coluna;
    
    Ascii.valor = Lcd_ConverteBcdEmAscii (Data->Dia);
    *Pnt++ = Ascii.bytes.byte1;
    *Pnt++ = Ascii.bytes.byte0;    
    *Pnt++ = '/';
    
    Ascii.valor = Lcd_ConverteBcdEmAscii (Data->Mes);
    *Pnt++ = Ascii.bytes.byte1;
    *Pnt++ = Ascii.bytes.byte0;    
    *Pnt++ = '/';
    
    if (Formato != _DM)
    {
        if (Formato == _DMAA)
        {
            Ascii.valor = Lcd_ConverteBcdEmAscii (0x20);
            *Pnt++ = Ascii.bytes.byte1;
            *Pnt++ = Ascii.bytes.byte0;    
        }
        
        Ascii.valor = Lcd_ConverteBcdEmAscii (Data->Ano);
        *Pnt++ = Ascii.bytes.byte1;
        *Pnt++ = Ascii.bytes.byte0;    
    }
}

/*
 * Lcd_ExibeDiaDaSemana
 * Exibe o dia da semana no display.
 * 
 * Linha:       Linha em que a data deve ser exibida
 * Coluna:      Coluna a partir do qual a data deve ser exibida
 * DiaDaSemana: Valor do dia da semana (Dom=1, ... Sab=7)
 */
void Lcd_ExibeDiaDaSemana (Uchar Linha, Uchar Coluna, Uchar DiaDaSemana)
{
    Uchar   *BufferDisplay;
    const char *Msg;
    
    BufferDisplay = Lcd_ApontaParaLinha(Linha) + Coluna;
    
    switch (DiaDaSemana)
    {
        case 1:
            Msg = &_Domingo[0];
            break;
            
        case 2:
            Msg = &_Segunda[0];
            break;            
            
        case 3:
            Msg = &_Terca[0];
            break;            
            
        case 4:
            Msg = &_Quarta[0];
            break;            
            
        case 5:
            Msg = &_Quinta[0];
            break;            
            
        case 6:
            Msg = &_Sexta[0];
            break;
            
        case 7:
            Msg = &_Sabado[0];
          
    }
    
    *BufferDisplay++ = *Msg++;
    *BufferDisplay++ = *Msg++;    
    *BufferDisplay++ = *Msg++;    
}




#endif






