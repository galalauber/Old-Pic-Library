/* 
 * Arquivo: Oscilador Config.h
 * Autor:   JABNeto
 * Data:    17/08/2015
 */

#ifndef OSCILADOR_CONFIG_H
#define	OSCILADOR_CONFIG_H


/*  1. Oscilador Primario - Habilitação, Tipo e frequencia
 * 
 *  _SISTEMA_USA_OSCILADOR_PRIMARIO: Define se o sistema utiliza o oscilador
 *                                   primário. Se a opção for não será utilizado
 *                                   o oscilador interno como fonte do clock
 *                                   primário.
 *  Opções:
 *  _NAO -> Sistema não utiliza o oscilador primario.
 *  _SIM -> Sistema utiliza o oscilador primario.
 * 
 * 
 *  _OSC_PRIMARIO_TIPO: Define o tipo do oscilador primário. Somente tem efeito
 *                      se a opção _SISTEMA_USA_OSCILADOR_PRIMARIO for _SIM
 * Opções:
 * _XTAL_LP: Cristal (Oscilador com ganho baixo, XTAL tuning fork)
 * _XTAL_XT: Cristal (Oscilador com ganho medio, até 4.0MHz)
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
 *  _OSC_PRIMARIO_FREQUENCIA: Define a frequencia de operação do oscilador
 *                            primário. Somente tem efeito se a opção
 *                            _SISTEMA_USA_OSCILADOR_PRIMARIO for _SIM.
 *                            Valor em MHz.
 */
#define _SISTEMA_USA_OSCILADOR_PRIMARIO                 _NAO
#define _OSC_PRIMARIO_TIPO                              _XTAL_HS_HP
#define _OSC_PRIMARIO_FREQUENCIA                        8000000


/*  2. Oscilador Interno - Habilitação, Frequencia
 * 
 * Obs. Se os osciladores interno e primario forem habilitados, a preferência
 * será dada para o oscilador primário e será habilitada a função de chaveamen
 * to caso haja falha no oscilador primário.
 * 
 * _OSC_INTERNO_TIPO: Define se o pino OSC2 fornece a Freq/4 ou não
 * _INTOSC: Oscilador interno
 * _INTOSC_CLOCK_OUT_OSC2: Oscilador interno com Freq/4 no pino OSC2
 * 
 *  _OSC_INTERNO_FREQUENCIA: Define a frequencia de operação do oscilador inter
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


/*  3. Oscilador Secundário - Habilitação e frequencia
 * 
 *  _SISTEMA_USA_OSCILADOR_SECUNDARIO: Define se o sistema utiliza o oscilador
 *                                     secundário.
 *  _NAO -> Sistema não utiliza o oscilador secundário.
 *  _SIM -> Sistema utiliza o oscilador secundário.
 * 
 *  _OSC_SECUNDARIO_FREQUENCIA: Define a frequencia de operação do oscilador
 *                              secundário. Somente tem efeito se a opção
 *                              _SISTEMA_USA_OSCILADOR_SECUNDARIO for _SIM.
 *                              Valor em KHz.
 */
#define _SISTEMA_USA_OSCILADOR_SECUNDARIO               _NAO
#define _OSC_SECUNDARIO_FREQUENCIA                      32768



/*  4. OSC_PRIMARIO_PLL - Habilitação
 * 
 *  _OSC_PRIMARIO_PLL_ATIVADO: Define se o modulo pll (x4) está ativado ou não.
 * 
 *  _NAO -> PLL não ativado
 *  _SIM -> PLL ativado
 * 
 * Obs. Para o oscilador interno, o PLL somente será ativado se uma das opções
 *      _HF_16MHz ou _HF_8MHz for escolhida.
 */
#define _OSC_PRIMARIO_PLL_ATIVADO                       _SIM


#endif	/* OSCILADOR_CONFIG_H */

