/* 
 * File:   App.c
 * Author: jose_010573
 *
 * Created on 23 de Março de 2016, 07:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>


int main(int argc, char** argv)
{
    ANSELB = 0;
    LATB = 0b10101010;
    TRISB = 0;
    
    while(1)
    {
        
    }

    return (EXIT_SUCCESS);
}

