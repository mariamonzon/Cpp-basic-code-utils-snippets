/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 24 de octubre de 2014, 12:43
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
//Declaraciones
    int n, cont, fac;
// Introducir valores
    printf( "Introduzca un numero entero positivo: ");
    scanf("%d",&n);
    
//Operaciones
    fac = 1;
    cont = 1;
    
    while (cont<=n) {
    fac=fac*cont;
    cont++;
    }
 
    printf( "El factorial de el numero es %d", fac);

    return (0) ;
    
}