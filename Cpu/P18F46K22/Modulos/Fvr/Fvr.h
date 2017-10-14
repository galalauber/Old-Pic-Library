/* 
 * Arquivo: Fvr.h
 * Autor:   JABNeto
 * Versao:  2016.05.19
 */

#ifndef FVR_H
#define	FVR_H

#include <xc.h>

//Definições do módulo -------------------------------------------------------

//Tensão de saída
#define _FVR_0000           0
#define _FVR_1024           1
#define _FVR_2048           2
#define _FVR_4096           3


#include "Fvr Config.h"


//Publicação das funções do módulo --------------------------------------------
void Fvr_Inicializacao (void);


#endif	/* FVR_H */

