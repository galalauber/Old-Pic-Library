/* 
 * Arquivo: Timer 0 Config.h
 * Autor:   JABNeto
 * Versao:  150710
 */

 
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H


/* 1. Eventos de 10ms
 * 
 * 1.1 Define se o sistema utiliza eventos de 10ms. Caso afirmativo, os eventos
 *     devem ser nomeados.
 * _NAO: Não habilita eventos de 10ms
 * _SIM: Habilita eventos de 10ms
 * 
 * 1.2 Define os nomes dos evento
 */
#define _TIMER0_HABILITAR_EVENTOS_10MS                  _SIM
#define _EVENTOS_10MS_1                                 Evento1
#define _EVENTOS_10MS_2                                 Evento2
#define _EVENTOS_10MS_3                                 Evento3
#define _EVENTOS_10MS_4                                 Evento4
#define _EVENTOS_10MS_5                                 Evento5
#define _EVENTOS_10MS_6                                 Evento6
#define _EVENTOS_10MS_7                                 Evento7
#define _EVENTOS_10MS_8                                 Evento8


/* 2. Eventos de 100ms
 * 
 * 2.1 Define se o sistema utiliza eventos de 100ms. Caso afirmativo, os eventos
 *     devem ser nomeados.
 * _NAO: Não habilita eventos de 100ms
 * _SIM: Habilita eventos de 100ms
 * 
 * 2.2 Define os nomes dos evento
 */
#define _TIMER0_HABILITAR_EVENTOS_100MS                 _SIM
#define _EVENTOS_100MS_1                                Evento1
#define _EVENTOS_100MS_2                                Evento2
#define _EVENTOS_100MS_3                                Evento3
#define _EVENTOS_100MS_4                                Evento4
#define _EVENTOS_100MS_5                                Evento5
#define _EVENTOS_100MS_6                                Evento6
#define _EVENTOS_100MS_7                                Evento7
#define _EVENTOS_100MS_8                                Evento8


/* 3. Eventos de 1s
 * 
 * 3.1 Define se o sistema utiliza eventos de 250ms. Caso afirmativo, os eventos
 *     devem ser nomeados.
 * _NAO: Não habilita eventos de 1s
 * _SIM: Habilita eventos de 1s
 * 
 * 3.2 Define os nomes dos evento
 */
#define _TIMER0_HABILITAR_EVENTOS_1S                    _SIM
#define _EVENTOS_1S_1                                   Evento1
#define _EVENTOS_1S_2                                   Evento2
#define _EVENTOS_1S_3                                   Evento3
#define _EVENTOS_1S_4                                   Evento4
#define _EVENTOS_1S_5                                   Evento5
#define _EVENTOS_1S_6                                   Evento6
#define _EVENTOS_1S_7                                   Evento7
#define _EVENTOS_1S_8                                   Evento8


/* 4. Interrupção
 * 
 * 4.1 Define se o módulo Timer 0 deve ou não gerar eventos de interrupção
 *     Caso afirmativo (Padrão), o módulo de interrução deve ser acrescentado
 *     no sistema.
 * _NAO: O módulo pode gerar eventos de interrupção
 * _SIM: O módulo não pode gerar eventos de interrupção
 * 
 * 4.2 Define a prioridade da interrupção
 * _BAIXA:  Define o modo de alta prioridade para as interrupções do módulo
 * _ALTA:   Define o modo de alta prioridade para as interrupções do módulo 
 * 
 */
#define _TIMER0_USA_INTERRUPCAO                         _SIM
#define _TIMER0_PRIORIDADE                              _ALTA


/* 5. Habilitação de funções
 * 
 * 4.1 Define se o módulo Timer 0 deve ou não gerar eventos de interrupção
 *     Caso afirmativo (Padrão), o módulo de interrução deve ser acrescentado
 *     no sistema.
 */
#define _TIMER0_HABILITAR_FUNCOES_TECLADO               _NAO
#define _TIMER0_HABILITAR_FUNCOES_LCD                   _NAO
#define _TIMER0_HABILITAR_FUNCOES_ROTINAS               _NAO

#endif	/* XC_HEADER_TEMPLATE_H */

