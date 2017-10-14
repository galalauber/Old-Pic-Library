/* 
 * Arquivo: Lcd.h
 * Autor:   JABNeto
 * Versao:  150710
 */


#ifndef LCD_CONFIG_H
#define	LCD_CONFIG_H

#include "Portas.h"


/* 1. Numero de linhas do display
 * 1 = 1 linha
 * 2 = 2 linhas
 * 4 = 4 linhas
 */
#define LCD_NUMERO_DE_LINHAS                       2


/* 2. Numero de colunas do display
 *  8 =  8 colunas
 * 16 = 16 colunas
 * 20 = 20 colunas
 */
#define LCD_NUMERO_DE_COLUNAS                      16


/* 3. Porta de IO dos dados
 * Porta de IO do uC que envia os dados para o display.
 * 
 * Op��es: 
 * PortA    Usar o port A
 * PortB    Usar o port B
 * PortC    Usar o port C
 * PortD    Usar o port D
 * PortE    Usar o port E
 * PortF    Usar o port F
 * PortG    Usar o port G
 */
#define LCD_PORTA                                  PortB


/* 4. Interface
 * O modulo Lcd pode trocar dados com o uC tanto em 4 bits quanto em 8 bits.
 * O par�metro LCD_INTERFACE informa como deve ser configurada a interface
 * do display: 4 ou 8 bits
 * 
 * Op��es:
 * _4bits   Interface de 4 bits
 * _8bits   Interface de 8 bits
 */
#define LCD_INTERFACE                              _4bits


/* 5. Nibble da Porta de IO dos dados
 * Quando a interface � configurada para troca de dados em 4 bits, deve ser 
 * informado se o nibble do port utilizado ser� o Msb (High) ou Lsb (Low).
 * 
 * Op��es:
 * Low     bits de 0 a 3 do PORT
 * High    bits de 4 a 7 do PORT
 */
#define LCD_PORTA_NIBBLE                            High


/* 6. Controle do pino Enable
 * Define o pino do uC que ir� controlar o sinal Enable do Lcd. A configura��o
 * � feita no formato PinRpn onde p representa o port de IO (A,B,C...) e n o
 * bit do port (0 a 7).
 * 
 * Exemplos:    PinRB2 -> Pino RB2 do uC
 *              PinRC4 -> Pino RC4 do uC
 */
#define LCD_PINO_ENABLE                             PinRB2


/* 7. Controle do pino Rs
 * Define o pino do uC que ir� controlar o sinal RS do Lcd. A configura��o
 * � feita no formato PinRpn onde p representa o port de IO (A,B,C...) e n o
 * bit do port (0 a 7).
 *    
 * Exemplos:    PinRB2 -> Pino RB2 do uC
 *              PinRC4 -> Pino RC4 do uC
 */
#define LCD_PINO_RS                                 PinRB3



/* 8. Intermit�ncia
 * Define o tempo da intermitencia em ms de um digito quando no modo de edi��o
 * Ex. 500 -> 500ms
 */
#define LCD_INTERMITENCIA_TEMPO                     500



/* 9. Controle do Backlight
 * - Define se o back light do LCD � utilizado ou n�o.
 * - Define o pino de controle do back light
 * - Permite a ativa��o da fun��o Green mode
 * 
 * 9.1  LCD_USA_BACKLIGHT: Define se o back light do LCD � utilizado
 * Nao  Backlight n�o � usado
 * Sim  Backlight � usado
 * 
 * 9.2. LCD_CONTROLE_PINO_BACKLIGHT: define o pino de controle do back light.
 *                                   A defini��o do pino � feita na forma
 *                                   PinRpn.
 *                                   Essa defini��o � ignorada se o baclight n�o
 *                                   for utilizado (LCD_USA_BACKLIGHT = Nao).
 * 
 * 9.3. LCD_MODO_GREEN: No Modo Green o backlight do display � deslifgadon ap�s
 *                      um tempo de ociosidade do teclado.
 * Nao  Modo green desativado
 * Sim  Modo green ativado 
 * 
 * 9.4. LCD_MODO_GREEN_TEMPO: Define o tempo de ociosidade do teclado em 
 *                            segundos para o desligamento do backlight no Modo
 *                            Green. Se o Modo Green estiver desativado, esse 
 *                            par�metro � ignorado.
 */
#define LCD_USA_BACKLIGHT                               Sim
#define LCD_PINO_BACKLIGHT                              PinRB1
#define LCD_MODO_GREEN                                  Nao
#define LCD_MODO_GREEN_TEMPO                            60


/* 10. Fun��es da CGRAM
 * Define se as fun��es para cria��o de caracteres na CGRAM devem ser incluidas
 * 
 * 10.1. LCD_INCLUIR_FUNCOES_CGRAM
 * Nao  Fun��es n�o s�o incluidas
 * Sim  Fun��es s�o incluidas
 * 
 * 10.2. CGRAM_CARACTERE_ESPECIAL_xx 
 * Faz a aloca��o de mem�ria para as matrizes de gera��o de caracteres especiais
 * da CGRAM.
 * Nao  A matriz do caractere n�o � alocada na mem�ria
 * Sim  A matriz do caractere � alocada na mem�ria e pode ser utilizada no
 *      momento da cria��o do caractere.
 * 
 * A fun��o Lcd_CriaCaractereNaCGRAM (Local, Caractere) deve ser utilizada
 * para a cria��o do caracrere, onde:
 * 
 * Local        Corresponde a um dos 8 locais disponiveis na CGRAM
 *              (0:endere�o 0x00 a 7:endere�o 0x07)
 * Caractere:   Define o caractere CGRAM_CARACTERE_ESPECIAL_xx a ser criado
 *              na CGRAM do display. A matriz que cont�m os c�digos de
 *              defini��o dos caracteres � alocada na flash do uC.
 */ 
#define LCD_INCLUIR_FUNCOES_CGRAM                      Nao
#define CGRAM_CARACTERE_ESPECIAL_0P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_1P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_2P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_3P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_4P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_5P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_6P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_7P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_8P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_9P                    Nao
#define CGRAM_CARACTERE_ESPECIAL_EP                    Nao



/* 11. LCD_INCLUIR_FUNCOES_EXIBE_DATA_HORAS
 * Define se as fun��es de exibi��o de hor�rio e data, ser�o incluidas
 * no sistema
 * 
 * Nao Fun��es de exibi��o de horario e data n�o s�o incluidas
 * Sim Fun��es de exibi��o de horario e data s�o incluidas
 */ 
#define LCD_INCLUIR_FUNCOES_EXIBE_DATA_HORAS           Nao



#endif	/* LCDCONFIG_H */

