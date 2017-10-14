/* 
 * Arquivo: Medidas.c
 * Autor:   JABNeto
 * Versao:  
 */


#include "Medidas.h"
#include "Adc 1.h"
#include "Eeprom.h"


//Aloca��o de mem�ria para o m�dulo--------------------------------------------
ObjAquisicao              Aquisicao;
ObjMedida                 Medidas[MEDIDAS_NUMERO_DE_GRANDEZAS];




//Fun��es locais --------------------------------------------------------------

/*
 * Medida_ZeraMedidas
 * Zera os valores de todas as medidas
 */
void Medida_ZeraMedidas(void)
{
    ObjMedida *Pnt;
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
 * Zera todos os bytes do buffer de quisi��o
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
 * Calcula o endere�o de armazenamento dos par�metros da Medida
 */
Uint Medida_CalculaEnderecoE2prom (Uchar IdMedida)
{
    return ((Uint)EEPROM_MEDIDAS + (IdMedida * sizeof (ObjMedidaParametros)));
}


/*
 * Medida_Calibracao
 * Mediante a m�dia dos valores adquiridos pelo conversor AD, calcula o
 * valor do fator de convers�o para ajustar a medida ao valor for fornecido.
 * O fator de convers�o calculado � armazenado na EEPROM.
 * 
 * IdMedida: Identifica��o da medida
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
    ObjMedida *Pnt;
    
    Endereco = Medida_CalculaEnderecoE2prom(IdMedida);
    Pnt = &Medidas[IdMedida];
    
    if (Pnt->MediaAmostras != 0)
    {
        Pnt->Parametros.FatorDeConversao = (NovoValor / Pnt->MediaAmostras);
    }
    
    Medidas_SalvaParametros(IdMedida);
}


/*
 * Medida_Monitor
 * Faz a aquisi��o dos valores das grandezas, calculam o valor m�dio e efetua
 * a convers�o do valor decomal utilizando o fator de convers�o.
 * Essa rotina faz tamb�m a detec�ao dos alarmes alto e baixo se estiverem
 * habilitados.
 */
void Medidas_Monitor (void)
{
    ObjMedida *Pnt;
    
    Pnt = &Medidas[Aquisicao.IdMedida];
    
    Aquisicao.Buffer[Aquisicao.NumeroDaAmostra++] = ADC1_ConverteCanal(Pnt->Canal);
    
    if (Aquisicao.NumeroDaAmostra == MEDIDAS_NUMERO_DE_AMOSTRAS)
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
        
        Pnt->MediaAmostras = (float)Soma / (Uchar)MEDIDAS_NUMERO_DE_AMOSTRAS;
            
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
                if (Pnt->ValorDecimal <= Pnt->Parametros.ValorMinimo)
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
 * Medidas_RecuperaParametros
 * recupera os parametros de uma grandeza armazenados na EEPROM
 * 
 * IdMedida: Identifica��o da medida
 */
void Medidas_RecuperaParametros (Uchar IdMedida)
{
    Uint Endereco;
    ObjMedida *Pnt;
    
    Endereco = Medida_CalculaEnderecoE2prom(IdMedida);
    
    Pnt = &Medidas[IdMedida];
    
    Pnt->Parametros.FatorDeConversao = EEPROM_LeFloat32(Endereco);
    Pnt->Parametros.Histerese = EEPROM_LeFloat32(Endereco+4);
    Pnt->Parametros.ValorMaximo = EEPROM_LeFloat32(Endereco+8);
    Pnt->Parametros.ValorMinimo = EEPROM_LeFloat32(Endereco+12);
    Pnt->Parametros.Habilitacao.Valor = EEPROM_LeUchar(Endereco+16);
}

/*
 * Medidas_SalvaParametros
 * Armazena os parametros de configura��o de uma medida na EEPROM
 * 
 * IdMedida: Identifica��o da medida
 */
void Medidas_SalvaParametros (Uchar IdMedida)
{
    Uint Endereco;
    ObjMedida *Pnt;
    
    Endereco = Medida_CalculaEnderecoE2prom(IdMedida);
    Pnt = &Medidas[IdMedida];
    
    EEPROM_EscreveFloat32(Endereco,Pnt->Parametros.FatorDeConversao);
    EEPROM_EscreveFloat32(Endereco+4,Pnt->Parametros.Histerese);
    EEPROM_EscreveFloat32(Endereco+8,Pnt->Parametros.ValorMaximo);
    EEPROM_EscreveFloat32(Endereco+12,Pnt->Parametros.ValorMinimo);
    EEPROM_EscreveUchar(Endereco+16,Pnt->Parametros.Habilitacao.Valor);
}


//Fun��es p�blicas ------------------------------------------------------------
/*
 * Medidas_Inicializacao
 * Faz a inicializa��o do m�dulo de medidas
 */
void Medidas_Inicializacao (void)
{
    Uchar i;
    Uint Endereco;
    
    for (i = 0; i < MEDIDAS_NUMERO_DE_GRANDEZAS; i++)
    {
        Endereco = Medida_CalculaEnderecoE2prom(i);
        Medidas_RecuperaParametros (i);         
    }
    
    Medida_ZeraBuffer();
    Medida_ZeraMedidas();     

    Aquisicao.IdMedida = 0;
    Aquisicao.NumeroDaAmostra = 0;  

}

/*
 * Medidas_ResetaParametros
 * Reseta as configura��es das medidas armazenadas na E2prom
 */
void Medidas_ResetaParametros (void)
{
    Uchar i;
    
    Medida_ZeraMedidas();
    
    for (i = 0; i < MEDIDAS_NUMERO_DE_GRANDEZAS; i++)
    {
        Medidas_SalvaParametros(i);        
    }
}




