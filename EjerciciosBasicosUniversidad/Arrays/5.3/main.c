/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 6 de noviembre de 2014, 9:04
 */

#include <stdio.h>
#include <stdlib.h>
#define N 9

int suma (int array[]);
long multiplicacion (int array[]);
int resta (int array[]);
int main() {
    
    int cuenta[N],n,resultado;
    
    for (n=0; n<N; n++){
        printf("Introduzca el numero %d de la cuenta: ", n+1);
        scanf("%d", &cuenta[n]);
    }
    
    if (cuenta[0]==1)
        resultado = suma (cuenta);
    else if (cuenta[0]==2)
        resultado = resta (cuenta);
    else if (cuenta[0]==3)
        resultado = multiplicacion (cuenta);
    else 
        printf("La cuenta no es válida");
    
    printf("El resultado de la operación es %d\n",resultado);
    resultado= abs(resultado);
    
    if (resultado%10 == cuenta[8])
       printf("La cuenta es válida\n");
    else 
        printf("La cuenta no es válida\n");

    return 0;
}

int suma (int array[]){
    
    int n,nmax=8,suma=0;
    
    for(n=0; n<nmax;n++){
        suma=suma+array[n];
    }
    return suma;
}

long multiplicacion (int array[]){
    
    int n, nmax=8;
    long mult=1;
    
    for(n=0;n<nmax;n++){
        mult=mult*array[n];
    }
    return mult;
}

int resta (int array[]){
        int n,nmax=8,resta=0;
    
    for(n=0; n<nmax;n++){
        resta=resta-array[n];
    }
    return resta;
}

int absoluto(int a){
    if(a<0)
        a=-a;
             
    return a;          
}
    


