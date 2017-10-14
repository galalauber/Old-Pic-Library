/* 
 *  Arquivo:    Fvr.h
 *  uC:         PIC18F46K22
 *  Autor:      JABNeto
 *  Versão:     161011 
 */


#ifndef FVR_H
#define	FVR_H

#include <xc.h>
#include "Definicoes Gerais.h"


//Definições do módulo --------------------------------------------------------
#define Fvr_1024            1
#define Fvr_2048            2
#define Fvr_4096            3


#include "Fvr Config.h"


//Funções públicas do módulo --------------------------------------------------
void Fvr_Inicializacao (void);



#endif	/* FVR_H */

