/* 
 * Arquivo: Principal.c
 * Autor:   JABNeto
 * Versao:  
 */

#include "App.h"



//Fun��o principal -----------------------------------------------------------
void main(void)
{
    App_Inicializacao();
    
    
    while(1)
    {
       App_ControleDeFuxo();
    }
}
