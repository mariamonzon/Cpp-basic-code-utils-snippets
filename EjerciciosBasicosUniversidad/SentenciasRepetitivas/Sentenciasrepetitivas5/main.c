/* 
 * File:   main.c
 * Author: Maria
 *
 * Created on 24 de octubre de 2014, 17:33
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 
 */
int main() {
    int i, sum, num;
   
    printf( "Introduzca un numero entero positivo: ");
    scanf("%d",&num);
    i=1;
  
    while(i<=num)
    {  
    sum = pow(i,i) + sum;
    i++;                
    }
   printf( "El resultado del sumatorio es %d\n", sum);
    
    return (0);
}

