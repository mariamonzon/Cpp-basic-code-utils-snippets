/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de octubre de 2014, 9:25
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int mcd (int num1, int num2)
{
    while (num1!=num2){
        if(num1<num2){
        num2=num2-num1;
        }
        if(num2<num1){
          num1= num1-num2;
        }
    }
    
    return num1;
       
}
int main() {
    int denominador, numerador;
    int den, num, k;
    printf ("Introduzca el numerador:  ");
    scanf("%d", &numerador);
    
    printf ("Introduzca el denominador:  ");
    scanf("%d", &denominador);
     
    k = mcd (denominador, numerador);
    num= numerador/k;
    den=denominador/k;  
    
    printf ("%d  %d\n", numerador, num);
    printf ("--- = ---\n");            
    printf ("%d   %d\n", denominador, den);   
    
    return (0);
}
