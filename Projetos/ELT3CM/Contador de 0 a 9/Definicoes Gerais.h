/* 
 * File:    Definicoes Gerais.h
 * Autor:   JABNeto
 * Data:    13/02/2016
 */

#ifndef DEFINICOES_GERAIS_H
#define	DEFINICOES_GERAIS_H

#define _NAO                0
#define _SIM                1

#define _FALSO              0
#define _VERDADEIRO         1

#define _DESATIVADO         0
#define _ATIVADO            1

#define _DESATIVADA         0
#define _ATIVADA            1


//Estruturas numericas -------------------------------
typedef unsigned char   Uchar;
typedef unsigned int    Uint;
typedef unsigned long   Ulong;

typedef signed char     Schar;
typedef signed int      Sint;
typedef signed long     Slong;


typedef union
{
    Uchar   valor;
    
    struct
    {
        Uint Nibble0:4;
        Uint Nibble1:4;
    }Nibbles;        
            
    struct
    {
        Uint   bit0:1;
        Uint   bit1:1;
        Uint   bit2:1;
        Uint   bit3:1;
        Uint   bit4:1;
        Uint   bit5:1;
        Uint   bit6:1;
        Uint   bit7:1;        
    }bits;
}Uint8;

typedef union
{
    Uint   valor;

    struct
    {
        Uchar   byte0;
        Uchar   byte1;      
    }bytes;

    struct
    {
        Uint   bit0:1;
        Uint   bit1:1;
        Uint   bit2:1;
        Uint   bit3:1;
        Uint   bit4:1;
        Uint   bit5:1;
        Uint   bit6:1;
        Uint   bit7:1;
        Uint   bit8:1;
        Uint   bit9:1;
        Uint   bit10:1;
        Uint   bit11:1;
        Uint   bit12:1;
        Uint   bit13:1;
        Uint   bit14:1;
        Uint   bit15:1; 
    }bits;    
}Uint16;

typedef union
{
    Ulong   valor;

    
    struct
    {
        Uchar   byte0;
        Uchar   byte1;
        Uchar   byte2;
        Uchar   byte3;         
    }bytes;
}Uint32;

typedef union
{
    float   valor;

    
    struct
    {
        Uchar   byte0;
        Uchar   byte1;
        Uchar   byte2;
    }bytes;
}Float24;

typedef union
{
    float   valor;
 
    struct
    {
        Uchar   byte0;
        Uchar   byte1;
        Uchar   byte2;
        Uchar   byte3;
    }bytes;
}Float32;


#endif	/* DEFINICOES_GERAIS_H */

