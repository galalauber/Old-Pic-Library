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
 * Opções: 
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
 * O parâmetro LCD_INTERFACE informa como deve ser configurada a interface
 * do display: 4 ou 8 bits
 * 
 * Opções:
 * _4bits   Interface de 4 bits
 * _8bits   Interface de 8 bits
 */
#define LCD_INTERFACE                              _4bits


/* 5. Nibble da Porta de IO dos dados
 * Quando a interface é configurada para troca de dados em 4 bits, deve ser 
 * informado se o nibble do port utilizado será o Msb (High) ou Lsb (Low).
 * 
 * Opções:
 * Low     bits de 0 a 3 do PORT
 * High    bits de 4 a 7 do PORT
 */
#define LCD_PORTA_NIBBLE                            High


/* 6. Controle do pino Enable
 * Define o pino do uC que irá controlar o sinal Enable do Lcd. A configuração
 * é feita no formato PinRpn onde p representa o port de IO (A,B,C...) e n o
 * bit do port (0 a 7).
 * 
 * Exemplos:    PinRB2 -> Pino RB2 do uC
 *              PinRC4 -> Pino RC4 do uC
 */
#define LCD_PINO_ENABLE                             PinRB2


/* 7. Controle do pino Rs
 * Define o pino do uC que irá controlar o sinal RS do Lcd. A configuração
 * é feita no formato PinRpn onde p representa o port de IO (A,B,C...) e n o
 * bit do port (0 a 7).
 *    
 * Exemplos:    PinRB2 -> Pino RB2 do uC
 *              PinRC4 -> Pino RC4 do uC
 */
#define LCD_PINO_RS                                 PinRB3



/* 8. Intermitência
 * Define o tempo da intermitencia em ms de um digito quando no modo de edição
 * Ex. 500 -> 500ms
 */
#define LCD_INTERMITENCIA_TEMPO                     500



/* 9. Controle do Backlight
 * - Define se o back light do LCD é utilizado ou não.
 * - Define o pino de controle do back light
 * - Permite a ativação da função Green mode
 * 
 * 9.1  LCD_USA_BACKLIGHT: Define se o back light do LCD é utilizado
 * Nao  Backlight não é usado
 * Sim  Backlight é usado
 * 
 * 9.2. LCD_CONTROLE_PINO_BACKLIGHT: define o pino de controle do back light.
 *                                   A definição do pino é feita na forma
 *                                   PinRpn.
 *                                   Essa definição é ignorada se o baclight não
 *                                   for utilizado (LCD_USA_BACKLIGHT = Nao).
 * 
 * 9.3. LCD_MODO_GREEN: No Modo Green o backlight do display é deslifgadon após
 *                      um tempo de ociosidade do teclado.
 * Nao  Modo green desativado
 * Sim  Modo green ativado 
 * 
 * 9.4. LCD_MODO_GREEN_TEMPO: Define o tempo de ociosidade do teclado em 
 *                            segundos para o desligamento do backlight no Modo
 *                            Green. Se o Modo Green estiver desativado, esse 
 *                            parâmetro é ignorado.
 */
#define LCD_USA_BACKLIGHT                               Sim
#define LCD_PINO_BACKLIGHT                              PinRB1
#define LCD_MODO_GREEN                                  Nao
#define LCD_MODO_GREEN_TEMPO                            60


/* 10. Funções da CGRAM
 * Define se as funções para criação de caracteres na CGRAM devem ser incluidas
 * 
 * 10.1. LCD_INCLUIR_FUNCOES_CGRAM
 * Nao  Funções não são incluidas
 * Sim  Funções são incluidas
 * 
 * 10.2. CGRAM_CARACTERE_ESPECIAL_xx 
 * Faz a alocação de memória para as matrizes de geração de caracteres especiais
 * da CGRAM.
 * Nao  A matriz do caractere não é alocada na memória
 * Sim  A matriz do caractere é alocada na memória e pode ser utilizada no
 *      momento da criação do caractere.
 * 
 * A função Lcd_CriaCaractereNaCGRAM (Local, Caractere) deve ser utilizada
 * para a criação do caracrere, onde:
 * 
 * Local        Corresponde a um dos 8 locais disponiveis na CGRAM
 *              (0:endereço 0x00 a 7:endereço 0x07)
 * Caractere:   Define o caractere CGRAM_CARACTERE_ESPECIAL_xx a ser criado
 *              na CGRAM do display. A matriz que contém os códigos de
 *              definição dos caracteres é alocada na flash do uC.
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
 * Define se as funções de exibição de horário e data, serão incluidas
 * no sistema
 * 
 * Nao Funções de exibição de horario e data não são incluidas
 * Sim Funções de exibição de horario e data são incluidas
 */ 
#define LCD_INCLUIR_FUNCOES_EXIBE_DATA_HORAS           Nao



#endif	/* LCDCONFIG_H */

