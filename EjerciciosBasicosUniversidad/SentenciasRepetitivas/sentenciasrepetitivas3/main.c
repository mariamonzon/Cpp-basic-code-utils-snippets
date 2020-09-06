/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 24 de octubre de 2014, 13:47
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

int main() {
    float n, p, r0, r, e;
    //Introducir valores
    printf( "Introduzca el numero: ");
    scanf("%f", &n);
    
    printf( "Introduzca la precision: ");
    scanf("%f", &p);
    
    printf( "Introduzca la primera aproximacion: ");
    scanf("%f", &r0);
    
    //Operaciones
    r= ((n/r0)+r0)/2;
    e= fabs(r-r0);
        while (p<=e){
         r0=r;
         r= ((n/r0)+r0)/2;
        }
    printf( "La raiz del numero es %f", r);       
     
  
    return (0);
}

