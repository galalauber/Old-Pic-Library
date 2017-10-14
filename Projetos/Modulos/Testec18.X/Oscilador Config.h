/* 
 * Arquivo: Oscilador Config.h
 * Autor:   JABNeto
 * Data:    17/08/2015
 */

#ifndef OSCILADOR_CONFIG_H
#define	OSCILADOR_CONFIG_H


/*  1. Oscilador Primario - Habilita��o, Tipo e frequencia
 * 
 *  _SISTEMA_USA_OSCILADOR_PRIMARIO: Define se o sistema utiliza o oscilador
 *                                   prim�rio. Se a op��o for n�o ser� utilizado
 *                                   o oscilador interno como fonte do clock
 *                                   prim�rio.
 *  Op��es:
 *  _NAO -> Sistema n�o utiliza o oscilador primario.
 *  _SIM -> Sistema utiliza o oscilador primario.
 * 
 * 
 *  _OSC_PRIMARIO_TIPO: Define o tipo do oscilador prim�rio. Somente tem efeito
 *                      se a op��o _SISTEMA_USA_OSCILADOR_PRIMARIO for _SIM
 * Op��es:
 * _XTAL_LP: Cristal (Oscilador com ganho baixo, XTAL tuning fork)
 * _XTAL_XT: Cristal (Oscilador com ganho medio, at� 4.0MHz)
 * _XTAL_HS_MP: Cristal (Oscilador com ganho elevado, 4.0MHz a 16MHz)
 * _XTAL_HS_HP: Cristal (Oscilador com ganho elevado, >16MHz)
 * _EC_LP: Clock externo <= 500KHz (low Power) 
 * _EC_LP_CLOCK_OUT_OSC2: Clock externo <= 500KHz com Freq/4 no pino OSC2
 * _EC_MP: Clock externo 500KHz a 16 MHz 
 * _EC_MP_CLOCK_OUT_OSC2: Clock externo 500KHz a 16 MHz com Freq/4 no pino OSC2
 * _EC_HP: Clock externo > 16 MHz (high power)
 * _EC_HP_CLOCK_OUT_OSC2: Clock externo > 16 MHz com Freq/4 no pino OSC2
 * _RC: Resistor/Capacitor externo
 * _RC_CLOCK_OUT_OSC2: Resistor/Capacitor externo com Freq/4 no pino OSC2
 * 
 *  _OSC_PRIMARIO_FREQUENCIA: Define a frequencia de opera��o do oscilador
 *                            prim�rio. Somente tem efeito se a op��o
 *                            _SISTEMA_USA_OSCILADOR_PRIMARIO for _SIM.
 *                            Valor em MHz.
 */
#define _SISTEMA_USA_OSCILADOR_PRIMARIO                 _NAO
#define _OSC_PRIMARIO_TIPO                              _XTAL_HS_HP
#define _OSC_PRIMARIO_FREQUENCIA                        8000000


/*  2. Oscilador Interno - Habilita��o, Frequencia
 * 
 * Obs. Se os osciladores interno e primario forem habilitados, a prefer�ncia
 * ser� dada para o oscilador prim�rio e ser� habilitada a fun��o de chaveamen
 * to caso haja falha no oscilador prim�rio.
 * 
 * _OSC_INTERNO_TIPO: Define se o pino OSC2 fornece a Freq/4 ou n�o
 * _INTOSC: Oscilador interno
 * _INTOSC_CLOCK_OUT_OSC2: Oscilador interno com Freq/4 no pino OSC2
 * 
 *  _OSC_INTERNO_FREQUENCIA: Define a frequencia de opera��o do oscilador inter
 *                           no.
 * HF (Oscilador interno de alta frequencia)
 * _HF_16MHz 
 * _HF_8MHz
 * _HF_4MHz 
 * _HF_2MHz
 * _HF_1MHz
 * _HF_500KHz
 * _HF_250KHz
 * _HF_31KHz
 * 
 * MF (Oscilador interno de media frequencia)
 * _MF_500KHz
 * _MF_250KHz
 * _MF_31KHz
 * 
 * LF (Oscilador interno de baixa frequencia)
 * _LF_31KHz
 */
#define _OSC_INTERNO_TIPO                               _INTOSC
#define _OSC_INTERNO_FREQUENCIA                         _HF_8MHz


/*  3. Oscilador Secund�rio - Habilita��o e frequencia
 * 
 *  _SISTEMA_USA_OSCILADOR_SECUNDARIO: Define se o sistema utiliza o oscilador
 *                                     secund�rio.
 *  _NAO -> Sistema n�o utiliza o oscilador secund�rio.
 *  _SIM -> Sistema utiliza o oscilador secund�rio.
 * 
 *  _OSC_SECUNDARIO_FREQUENCIA: Define a frequencia de opera��o do oscilador
 *                              secund�rio. Somente tem efeito se a op��o
 *                              _SISTEMA_USA_OSCILADOR_SECUNDARIO for _SIM.
 *                              Valor em KHz.
 */
#define _SISTEMA_USA_OSCILADOR_SECUNDARIO               _NAO
#define _OSC_SECUNDARIO_FREQUENCIA                      32768



/*  4. OSC_PRIMARIO_PLL - Habilita��o
 * 
 *  _OSC_PRIMARIO_PLL_ATIVADO: Define se o modulo pll (x4) est� ativado ou n�o.
 * 
 *  _NAO -> PLL n�o ativado
 *  _SIM -> PLL ativado
 * 
 * Obs. Para o oscilador interno, o PLL somente ser� ativado se uma das op��es
 *      _HF_16MHz ou _HF_8MHz for escolhida.
 */
#define _OSC_PRIMARIO_PLL_ATIVADO                       _SIM


#endif	/* OSCILADOR_CONFIG_H */

