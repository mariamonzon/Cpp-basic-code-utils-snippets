/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de octubre de 2014, 8:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926539

/*
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926539 

double pot (double numero, long potencia) {
    
    long r;
    double resultado;
    
    resultado = 1;
    
    for (r = 1; r <= potencia; r = r + 1) {
        
        resultado = resultado*numero;
    }
    
    return resultado;
}

long fact (long numero) {
    
    long r, fac;
    
    fac = 1;
    r = 1;
    
    while (r <= numero) {
        fac = fac*r;
        r = r + 1;
    }
    
    return fac;
}

double valorabs (double termino ) {
   
    if (termino<0) {
        termino = -termino;
    }
    return termino;
}
int main() {
    
    long k, q;
    double angulo, cos, abstermino1, abstermino2, termino1, termino2;
    
    printf("Introducir el valor del angulo en radianes: ");
    scanf("%lf", &angulo);
    
    while (angulo >= 2*PI) {
        
        angulo = angulo - 2*PI;
    }
    
    if (angulo > 3*PI/2) {
        
        angulo = angulo - 3*PI/2;
    } else if ((angulo > PI) && (angulo < 3*PI/2)) {
        
        angulo = angulo - PI/2;
    } else if (angulo == 3*PI/2){
        
        angulo = angulo - PI;
    }
    
    angulo = (double) angulo;
    
    k = 0;
    q = 1;
    cos = 1;
        
    do {
        
        termino1 = pot(angulo, 2*k+2)/fact(2*k+2);
        termino2 = pot(angulo, 2*q+2)/fact(2*q+2);
        abstermino1 = valorabs(termino1);
        abstermino2 = valorabs(termino2);
        
        cos = cos - termino1;
        k = k+2;
        
        if (abstermino1 >= 0.0005) {
            cos = cos + termino2;
            q = q+2;
        } else {
            termino2 = 0;
        }
        
    } while (abstermino2 >= 0.0005);
    
    printf("cos(x) = %.3lf \n", cos);
    
    return 0;
}

