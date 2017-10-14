/* 
 * Arquivo: Teclado.c
 * Autor:   JABNeto
 * Versao:  150710
 */

#include <xc.h>
#include "Teclado.h"
#include "Portas.h"


//Alocação de memória para o módulo--------------------------------------------
_Ctrl_Teclado Ctrl_Teclado;


//Funções locais --------------------------------------------------------------





//Funções publicas ------------------------------------------------------------

/*
 * Teclado_Inicializacao
 * Faz a inicialização do teclado, levando em conta as definições do usuário
 */
void Teclado_Inicializacao(void)
{
    #ifdef _TECLA1_AD
        _TECLA1_AD = _DIGITAL;
    #endif

    #ifdef _TECLA2_AD
        _TECLA2_AD = _DIGITAL;
    #endif        
        
    #ifdef _TECLA3_AD
        _TECLA3_AD = _DIGITAL;
    #endif             
        
    #ifdef _TECLA4_AD
        _TECLA4_AD = _DIGITAL;
    #endif              
        
    #ifdef _TECLA5_AD
        _TECLA5_AD = _DIGITAL;
    #endif              
        
    #ifdef _TECLA6_AD
        _TECLA6_AD = _DIGITAL;
    #endif           

    #ifdef _TECLA7_AD
        _TECLA7_AD = _DIGITAL;
    #endif   

    #ifdef _TECLA8_AD
        _TECLA8_AD = _DIGITAL;
    #endif   
        
        
    Ctrl_Teclado.Controle.Recuo = _NAO;
    Ctrl_Teclado.Controle.Disparo = _NAO;
    Ctrl_Teclado.Eventos.valor = 0;
}

/*
 * Teclado_Monitor
 * Monitora o teclado e detecta o pressionamento das teclas.
 */
void Teclado_Monitor(void)
{
    #if (_TECLADO_MODO_DE_OPERACAO == _RECUO)
    Uint8 Status;
    
    Status.valor = 0;
    
    if (--Ctrl_Teclado.Temporizadores.Amostras == 0)
    {
        Ctrl_Teclado.Temporizadores.Amostras = _TECLADO_TEMPORIZADOR_AMOSTRAS;

        #ifdef _TECLA1
            if (_TECLA1 == _PRESSIONADA) Status.bits.bit0 = 1;
        #endif

        #ifdef _TECLA2
            if (_TECLA2 == _PRESSIONADA) Status.bits.bit1 = 1;
        #endif        
        
        #ifdef _TECLA3
            if (_TECLA3 == _PRESSIONADA) Status.bits.bit2 = 1;
        #endif          

        #ifdef _TECLA4
            if (_TECLA4 == _PRESSIONADA) Status.bits.bit3 = 1;
        #endif          

        #ifdef _TECLA5
            if (_TECLA5 == _PRESSIONADA) Status.bits.bit4 = 1;
        #endif          
        
        #ifdef _TECLA6
            if (_TECLA6 == _PRESSIONADA) Status.bits.bit5 = 1;
        #endif  

        #ifdef _TECLA7
            if (_TECLA7 == _PRESSIONADA) Status.bits.bit6 = 1;
        #endif  

        #ifdef _TECLA8
            if (_TECLA8 == _PRESSIONADA) Status.bits.bit7 = 1;
        #endif  

        if (Status.valor == 0) Ctrl_Teclado.Controle.Recuo = _SIM;
        else
        {
            if(Ctrl_Teclado.Controle.Recuo == _SIM)
            {
                Ctrl_Teclado.Controle.Recuo = _NAO;
                
                Ctrl_Teclado.Eventos.valor = Status.valor;
            }
        }
    }

    #elif (_TECLADO_MODO_DE_OPERACAO == _TRANSPARENTE)
        #ifdef _TECLA1
            Ctrl_Teclado.Eventos.Tecla1 = _TECLA1;
        #endif

        #ifdef _TECLA2
            Ctrl_Teclado.Eventos.Tecla2 = _TECLA2;
        #endif

        #ifdef _TECLA3
            Ctrl_Teclado.Eventos.Tecla3 = _TECLA3;
        #endif   
    
        #ifdef _TECLA4
            Ctrl_Teclado.Eventos.Tecla4 = _TECLA4;
        #endif    
    
        #ifdef _TECLA5
            Ctrl_Teclado.Eventos.Tecla5 = _TECLA5;
        #endif   
    
        #ifdef _TECLA6
            Ctrl_Teclado.Eventos.Tecla6 = _TECLA6;
        #endif
            
        #ifdef _TECLA7
            Ctrl_Teclado.Eventos.Tecla7 = _TECLA7;
        #endif            
            
        #ifdef _TECLA8
            Ctrl_Teclado.Eventos.Tecla8 = _TECLA8;
        #endif
            
    #elif (_TECLADO_MODO_DE_OPERACAO == _DISPARO)




    #else
    #error  Modo de operação do teclado não definida

    #endif
}



/*
 * Tecla_Pressionada
 * Testa se existe o evento de tecla pressionada e caso afirmativo, retorna 1.
 * O evento é removido.
 */
unsigned char Tecla_Pressionada (unsigned char Tecla)
{
    unsigned char Retorno = 0;
    
    switch (Tecla)
    {
        #ifdef _TECLA1
        case 1:
            if (Ctrl_Teclado.Eventos.Tecla1 == 1)
            {
                Ctrl_Teclado.Eventos.Tecla1 = 0;
                Retorno = 1;
            }            
            break;
        #endif

        #ifdef _TECLA2
        case 2:
            if (Ctrl_Teclado.Eventos.Tecla2 == 1)
            {
                Ctrl_Teclado.Eventos.Tecla2 = 0;
                Retorno = 1;
            }            
            break;
        #endif       
        
        #ifdef _TECLA3
        case 3:
            if (Ctrl_Teclado.Eventos.Tecla3 == 1)
            {
                Ctrl_Teclado.Eventos.Tecla3 = 0;
                Retorno = 1;
            }            
            break;
        #endif
            
        #ifdef _TECLA4
        case 4:
            if (Ctrl_Teclado.Eventos.Tecla4 == 1)
            {
                Ctrl_Teclado.Eventos.Tecla4 = 0;
                Retorno = 1;
            }            
            break;
        #endif            

        #ifdef _TECLA5
        case 5:
            if (Ctrl_Teclado.Eventos.Tecla5 == 1)
            {
                Ctrl_Teclado.Eventos.Tecla5 = 0;
                Retorno = 1;
            }            
            break;
        #endif            
            
        #ifdef _TECLA6
        case 6:
            if (Ctrl_Teclado.Eventos.Tecla6 == 1)
            {
                Ctrl_Teclado.Eventos.Tecla6 = 0;
                Retorno = 1;
            }            
            break;
        #endif            
            
        #ifdef _TECLA7
        case 7:
            if (Ctrl_Teclado.Eventos.Tecla7 == 1)
            {
                Ctrl_Teclado.Eventos.Tecla7 = 0;
                Retorno = 1;
            }            
            break;
        #endif

        #ifdef _TECLA8
        case 8:
            if (Ctrl_Teclado.Eventos.Tecla8 == 1)
            {
                Ctrl_Teclado.Eventos.Tecla8 = 0;
                Retorno = 1;
            }            
            break;
        #endif
    }
    return Retorno;
}



