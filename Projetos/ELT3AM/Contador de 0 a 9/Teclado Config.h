/* 
 * Arquivo: Teclado Config.h
 * Autor:   JABNeto
 * Versao:  150710
 */

#ifndef TECLADO_CONFIG_H
#define	TECLADO_CONFIG_H


/* 1. Fun��es estendidas
 * Op��es:
 * _NAO:    As fun��es estendidas n�o s�o incluidas. Essa op��o somente inclui
 *          a fun��o de inicializa��o do teclado. O testes de teclas pressiona
 *          das devem ser feitos localmente, no c�digo do usu�rio.
 * _SIM:    As fun��es estendidas s�o incluidas. A vari�vel Ctrl_Teclado �
 *          criada e a detec��o das teclas presssionadas passa a ser feita
 *          atrav�s da fun��o Teclado_Monitor().
  */
#define TECLADO_FUNCOES_ESTENDIDAS                          _NAO


/* 2. Tipo de amostragem do teclado
 * Op��es:
 * _MANUAL:     A fun��o Teclado Monitor() deve ser chamada no c�digo do
 *              usu�rio.
 * _PERIODICO:  A amostragem do teclado � feita periodicamente. O temporizador
 *              Timer 0 deve ser utilizado para fazer a chamada da fun��o
 *              Teclado_Monitor(). 
 */
#define TECLADO_TIPO_DE_AMOSTRAGEM                          _MANUAL


/* 3. Modo de captura das teclas pressionadas
 * Op��es:
 * _DIRETO:     Uma c�pia dos estados das teclas � transferida diretamente para 
 *              o buffer do teclado.
 * _RECUO:      A detec��o de uma tecla pressionada � feita somente se houver
 *              anteriormente o recuo de todas as teclas.
 */
#define TECLADO_MODO_DE_CAPTURA                             _DIRETO


#endif	/* TECLADO_CONFIG_H */

