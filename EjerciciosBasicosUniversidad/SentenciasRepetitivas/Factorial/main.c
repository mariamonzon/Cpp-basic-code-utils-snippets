/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 24 de octubre de 2014, 13:18
 */

#include <stdio.h>
#include <stdlib.h>


int main() {
    //Declaraciones
    int num, i, fac;
    i=1;
    fac=1;
    printf( "Introduzca un numero entero positivo: ");
    scanf("%d",&num);
    
    while (num>0)
    {
    fac = (num* fac);
    num--;                
    }
    printf( "El factorial de el numero es %d\n", fac);
   
    return 0;
}