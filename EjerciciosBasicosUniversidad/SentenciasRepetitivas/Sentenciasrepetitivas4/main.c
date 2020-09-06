/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on 24 de octubre de 2014, 16:28
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    //Declaraciones 
    char fra;
    int bln=0;
    int num=0;
    int let=0;
    //Introducir datos
    fflush(stdin);
    __fpurge(stdin);
    printf("Introduzca una frase con un punto al final: ");
    do {
        scanf("%c", &fra);
        if(fra== ' ')
            bln +=1;
        else if ((fra >= 'a' && fra<= 'z')||(fra >= 'A'&& fra <= 'Z'))
             let +=1;
        else if (fra >= '0' && fra <= '9')
            num +=1;
    }while( fra!='.');

        
    printf( "La cantidad de espacios es: %d\n", bln);
    printf( "La cantidad de numeros es: %d\n", num);
    printf( "La cantidad de letras es: %d\n", let);
    

    return (0);
}
