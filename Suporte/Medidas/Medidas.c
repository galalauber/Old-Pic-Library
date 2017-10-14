/* 
 * Arquivo: Medidas.c
 * Autor:   JABNeto
 * Versao:  
 */


#include "Medidas.h"
#include "Adc 1.h"
#include "Eeprom.h"


//Alocação de memória para o módulo--------------------------------------------
_Aquisicao              Aquisicao;
_Medida                 Medidas[MEDIDAS_NUMERO_DE_GRANDEZAS];
_Alarmes                SinaisDeAlarmes, HabilitacaoDeAlarmes;



//Funções locais --------------------------------------------------------------

/*
 * Medida_ZeraMedidas
 * Zera os valores de todas as medidas
 */
void Medida_ZeraMedidas(void)
{
    _Medida *Pnt;
    unsigned char i;
    
    Pnt = &Medidas[0];
    
    for (i = 0; i < MEDIDAS_NUMERO_DE_GRANDEZAS; i++)
    {
        Pnt->Parametros.FatorDeConversao = 0;
        Pnt->Parametros.Histerese = 0;        
        Pnt->Parametros.ValorMaximo = 0;
        Pnt->Parametros.ValorMinimo = 0;
        Pnt->Parametros.Habilitacao.Valor = 0;  
        Pnt->MediaAmostras = 0;
        Pnt->ValorDecimal = 0;
        Pnt->Canal = 0;  
        Pnt++;
    }
}

/*
 * Medida_ZeraBuffer
 * Zera todos os bytes do buffer de quisição
 */
void Medida_ZeraBuffer (void)
{
    unsigned char i;
    
    for (i = 0; i < MEDIDAS_NUMERO_DE_AMOSTRAS; i++)
    {
        Aquisicao.Buffer[i] = 0;
    }
}

/*
 * Medida_CalculaEnderecoE2prom
 * Calcula o endereço de armazenamento dos parâmetros da Medida
 */
Uint Medida_CalculaEnderecoE2prom (Uchar IdMedida)
{
    return (EEPROM_PARAMETROS_MEDIDA_0 + (IdMedida * sizeof (_MedidaParametros)));
}


/*
 * Medida_Calibracao
 * Mediante a média dos valores adquiridos pelo conversor AD, calcula o
 * valor do fator de conversão para ajustar a medida ao valor for fornecido.
 * O fator de conversão calculado é armazenado na EEPROM.
 * 
 * IdMedida: Identificação da medida
 * NovoValor: Valor para o qual a medida deve ser ajustada
 * 
 * Ex.
     _Medida *Pnt;
    Pnt = Medida_RetornaPonteiro(_TENSAO_DE_BATERIA);
    Medida_Calibracao(Pnt, 220.0);
 */
void Medida_Calibracao (Uchar IdMedida,float NovoValor)
{
    Uint Endereco;
    _Medida *Pnt;
    
    Endereco = Medida_CalculaEnderecoE2prom(IdMedida);
    Pnt = &Medidas[IdMedida];
    
    if (Pnt->MediaAmostras != 0)
    {
        Pnt->Parametros.FatorDeConversao = (NovoValor / Pnt->MediaAmostras);
    }
    
    Medidas_EscreveParametros(IdMedida);
}


/*
 * Medida_Conversao
 * Calcula o valor médio do buffer de aquisição e calcula o valor da medida
 * utilizando o fator de conversão da medida fornecida.
 * 
 * IdMedida: Identificação da medida
 */
void Medida_Conversao (Uchar IdMedida)
{
    _Medida *Pnt;
    
    Pnt = &Medidas[IdMedida];
    
    Aquisicao.Buffer[Aquisicao.NumeroDaAmostra] = ADC1_ConverteCanal(Pnt->Canal);
    
    if (++Aquisicao.NumeroDaAmostra == MEDIDAS_NUMERO_DE_AMOSTRAS)
    {
        unsigned char i;
        unsigned long Soma = 0;        
        
        Aquisicao.NumeroDaAmostra = 0;
        if(++Aquisicao.IdMedida >= MEDIDAS_NUMERO_DE_GRANDEZAS) Aquisicao.IdMedida = 0;
    
        //Calculo do valor da medida
        for (i = 0; i < MEDIDAS_NUMERO_DE_AMOSTRAS; i++)
        {
            Soma += Aquisicao.Buffer[i];        
        }
        
        Pnt->MediaAmostras = (float)(Soma / MEDIDAS_NUMERO_DE_AMOSTRAS);
            
        Pnt->ValorDecimal = Pnt->MediaAmostras * Pnt->Parametros.FatorDeConversao;        
    
        //Deteccao de Alarme Alto
        if (Pnt->Parametros.Habilitacao.AlarmeA == 1)
        {
            if (Pnt->Eventos.AlarmeA == 0)
            {
                if (Pnt->ValorDecimal >= Pnt->Parametros.ValorMaximo)
                {
                    Pnt->Eventos.AlarmeA = 1;
                }
            }
            else
            {
                if ((Pnt->ValorDecimal+ Pnt->Parametros.Histerese) <= Pnt->Parametros.ValorMaximo)
                {
                    Pnt->Eventos.AlarmeA = 0;
                }
            }
        }
        else Pnt->Eventos.AlarmeA = 0;
        
        
        //Deteccao de Alarme Baixo
        if (Pnt->Parametros.Habilitacao.AlarmeB == 1)
        {
            if (Pnt->Eventos.AlarmeB == 0)
            {
                if (Pnt->ValorDecimal <= Pnt->Parametros.ValorMaximo)
                {
                    Pnt->Eventos.AlarmeB = 1;
                }
            }
            else
            {
                if (Pnt->ValorDecimal >= (Pnt->Parametros.ValorMinimo + Pnt->Parametros.Histerese))
                {
                    Pnt->Eventos.AlarmeB = 0;
                }
            }
        }
        else Pnt->Eventos.AlarmeB = 0;        
    }
}

/*
 * Medidas_CarregaParametros
 * Carrega os parametros de configuração de uma medida armazenados na EEPROM
 * 
 * IdMedida: Identificação da medida
 */
void Medidas_CarregaParametros (Uchar IdMedida)
{
    Uint Endereco;
    _Medida *Pnt;
    
    Endereco = Medida_CalculaEnderecoE2prom(IdMedida);
    Pnt = &Medidas[IdMedida];
    
    Pnt->Parametros.FatorDeConversao = EEPROM_LeFloat32(Endereco);
    Pnt->Parametros.Histerese = EEPROM_LeFloat32(Endereco+4);
    Pnt->Parametros.ValorMaximo = EEPROM_LeFloat32(Endereco+8);
    Pnt->Parametros.ValorMinimo = EEPROM_LeFloat32(Endereco+12);
    Pnt->Parametros.Habilitacao.Valor = EEPROM_LeByte(Endereco+16);
}


/*
 * Medidas_EscreveParametros
 * Armazena os parametros de configuração de uma medida na EEPROM
 * 
 * IdMedida: Identificação da medida
 */
void Medidas_EscreveParametros (Uchar IdMedida)
{
    Uint Endereco;
    _Medida *Pnt;
    
    Endereco = Medida_CalculaEnderecoE2prom(IdMedida);
    Pnt = &Medidas[IdMedida];
    
    EEPROM_EscreveFloat32(Endereco,Pnt->Parametros.FatorDeConversao);
    EEPROM_EscreveFloat32(Endereco+4,Pnt->Parametros.Histerese);
    EEPROM_EscreveFloat32(Endereco+8,Pnt->Parametros.ValorMaximo);
    EEPROM_EscreveFloat32(Endereco+12,Pnt->Parametros.ValorMinimo);
    EEPROM_EscreveByte(Endereco+16,Pnt->Parametros.Habilitacao.Valor);
}


//Funções públicas ------------------------------------------------------------
/*
 * Medidas_Inicializacao
 * Faz a inicialização do módulo de medidas
 */
void Medidas_Inicializacao (void)
{
    Uchar i;
    Uint Endereco;
    
    for (i = 0; i < MEDIDAS_NUMERO_DE_GRANDEZAS; i++)
    {
        Endereco = Medida_CalculaEnderecoE2prom(i);
        Medidas_CarregaParametros (i);         
    }
    
    Medida_ZeraBuffer();
    Medida_ZeraMedidas();     

    Aquisicao.IdMedida = 0;
    Aquisicao.NumeroDaAmostra = 0;  
    SinaisDeAlarmes.Valor = 0;
}

/*
 * Medidas_Monitor
 * Executa o processo de aquisição, calculos e detecção de alarmes
 */
void Medidas_Monitor (void)
{
    Medida_Conversao(Aquisicao.IdMedida);    
}




