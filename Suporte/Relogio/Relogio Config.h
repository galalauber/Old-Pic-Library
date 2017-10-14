/* 
 * Arquivo: Relogio.h
 * Autor:   JABNeto
 * Versao:  150710
 */


#ifndef RELOGIO_CONFIG_H
#define	RELOGIO_CONFIG_H


/*
 * 1. Alarmes
 * Define se o modulo utiliza a detecção de alarmes
 * 
 * 1.1. RELOGIO_EVENTOS_DE_ALARMES
 * Define o numero de eventos de alarmes utilizados pelo sistema
 * 
 */
#define RELOGIO_EVENTOS_DE_ALARMES                      1


/*
 * 2. Dispositivo
 * Define o dispositivo RTCC utilizado
 * 
 * Opções:
 * _SOFTWARE:   Relogio implementado via software
 * _RTCC:       RTCC Interno. Para os uC que possuem RTCC interno.
 * _DS1307:     Utiliza o RTCC externo DS1307 (I2C)
 * _MCP7940:    Utiliza o RTCC externo MCP7940 (I2C)
 */
#define RELOGIO_DISPOSITIVO                             _DS1307








#endif	/* RELOGIO_CONFIG_H */

