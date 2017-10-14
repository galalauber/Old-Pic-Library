/* 
 * Arquivo: Display lcd alfa config.h
 * Autor:   JABNeto
 * Versao:  150710
 */


#ifndef LCDCONFIG_H
#define	LCDCONFIG_H

/* 1. Numero de linhas do display
 * 1 = 1 linha
 * 2 = 2 linhas
 * 4 = 4 linhas
 */
#define _LCD_NUMERO_DE_LINHAS               2


/* 2. Numero de colunas do display
 *  8 =  8 colunas
 * 16 = 16 colunas
 * 20 = 20 colunas
 */
#define _LCD_NUMERO_DE_COLUNAS              16


/* 3. Interface 
 * _4BITS = Interface de 4 bits
 * _8BITS = Interface de 8 bits
 */
#define _LCD_INTERFACE                      _4BITS


/* 4. Porta de IO dos dados
 *  Porta de IO do uC que envia os dados para o display. 
 * _PORTA = Usar o port A
 * _PORTB = Usar o port B
 * _PORTC = Usar o port C
 * _PORTD = Usar o port D
 * _PORTE = Usar o port E
 */
#define _LCD_PORT                           _PORTD


/* 5. Nibble da Porta de IO dos dados
 *  Esse parâmetro se aplica somente para interface de 4 bits.
 * _LOW  = bits de 0 a 3 do PORT
 * _HIGH = bits de 4 a 7 do PORT
 */
#define _LCD_INTERFACE_NIBBLE               _HIGH


/* 6. Controle do pino Enable
 *    Define o pino do uC que controla o sinal Enable do Lcd.
 *    A definição é feita na forma:
 *    PORT_bit
 * Ex. (Pino RB2 do PORT B)
 * _PORTB_2 
 */
#define _LCD_CONTROLE_PINO_ENABLE           _PORTD_3



/* 7. Controle do pino Rs
 *    Define o pino do uC que controla o sinal RS do Lcd.
 *    A definição é feita na forma:
 *    PORT_bit
 * Ex. (Pino RB3 do PORTB B)
 * PORTB_3 
 */
#define _LCD_CONTROLE_PINO_RS               _PORTD_2


/* 8. Backlight
 * - Define se o back light do LCD é utilizado.
 * - Define o pino de controle do back light
 * - Permite a ativação da função Green mode
 * 
 * _LCD_USA_BACKLIGHT: Define se o back light do LCD é utilizado
 * _NAO = Backlight não é usado
 * _SIM = Backlight é usado
 * 
 * _LCD_CONTROLE_PINO_BACKLIGHT: define o pino de controle do back light. A
 * definição do pino é feita na forma PORT_bit. Essa definição é ignorada se
 * _LCD_USA_BACKLIGHT for _NAO.
 * Exemplo: PORTB_1 (define RB1 como pino de controle).
 * 
 * _LCD_MODO_GREEN: No Modo Green o display desliga a tela após um tempo de
 * ociosidade do teclado.
 * _NAO = Modo green desativado
 * _SIM = Modo green ativado 
 * 
 * _LCD_MODO_GREEN_TEMPO: Define o tempo de ociosidade em segundos para o
 * desligamento do display caso o Modo Green esteja habilitado.
 */
#define _LCD_USA_BACKLIGHT                  _SIM
#define _LCD_CONTROLE_PINO_BACKLIGHT        _PORTD_1
#define _LCD_MODO_GREEN                     _SIM
#define _LCD_MODO_GREEN_TEMPO               10


/* 9. Funções da CGRAM
 * Define se as funções para criação de caracteres na CGRAM devem ser incluidas
 * 
 * _LCD_FUNCOES_CGRAM
 * _NAO: Funções não são incluidas
 * _SIM: Funções são incluidas
 */ 
#define _LCD_FUNCOES_CGRAM                  _SIM


/* 10. Funções de exibições
 * Define as funções de exibições que devem ser incluidas no sistema
 * 
 * _LCD_FUNCOES_RELOGIO
 * _NAO: Funções de exibição de horario e data não são incluidas
 * _SIM: Funções de exibição de horario e data são incluidas
 */ 
#define _LCD_FUNCOES_RELOGIO               _SIM







#endif	/* LCDCONFIG_H */

