/* 
 * Arquivo: Teclado Config.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef TECLADO_CONFIG_H
#define	TECLADO_CONFIG_H


/* 1. Funções estendidas
 * Opções:
 * _NAO:    As funções estendidas não são incluidas. Essa opção somente inclui
 *          a função de inicialização do teclado. O testes de teclas pressiona
 *          das devem ser feitos localmente, no código do usuário.
 * _SIM:    As funções estendidas são incluidas. A variável Ctrl_Teclado é
 *          criada e a detecção das teclas presssionadas passa a ser feita
 *          através da função Teclado_Monitor().
  */
#define TECLADO_FUNCOES_ESTENDIDAS                          _SIM


/* 2. Tipo de amostragem do teclado
 * Opções:
 * _MANUAL:     A função Teclado Monitor() deve ser chamada no código do
 *              usuário.
 * _PERIODICO:  A amostragem do teclado é feita periodicamente. O temporizador
 *              Timer 0 deve ser utilizado para fazer a chamada da função
 *              Teclado_Monitor(). 
 */
#define TECLADO_TIPO_DE_AMOSTRAGEM                          _PERIODICO


/* 3. Modo de captura das teclas pressionadas
 * Opções:
 * _DIRETO:     Uma cópia dos estados das teclas é transferida diretamente para 
 *              o buffer do teclado.
 * _RECUO:      A detecção de uma tecla pressionada é feita somente se houver
 *              anteriormente o recuo de todas as teclas.
 */
#define TECLADO_MODO_DE_CAPTURA                             _RECUO


/* 4. Ativa funções de operação em conjunto com LCD
 * Opções:
 * _NAO:     Não ativa as funções de controle do lcd
 * _SIM:     Ativa as funções de controle do Lcd
 */
#define TECLADO_FUNCOES_LCD                                  _SIM



/* 4. definicoes das teclas
*/
#define UP                  1
#define DOWN                5
#define LEFT                2
#define RIGHT               4
#define ENTER               3



#endif	/* TECLADO_CONFIG_H */

