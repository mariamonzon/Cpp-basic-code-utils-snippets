/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on 23 de octubre de 2014, 18:46
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    //Declaracion
    float g, des, cp;
    
   //Introducir valores  
    
    printf( "Introduza el valor del gasto:  ");
    scanf("%f", &g );   
    //Operaciones
    if(g>20000){
       des=30;
       cp=0.7*g;
       printf("La cantiadad gastada %.2f euros",g);
       printf("El descuento es alto, %.f %", des);
       printf( "La cantidad a pagar es %.2f", cp);
    }else if(g>10000){
       des=20; 
       cp=0.8*g;
       printf("La cantiadad gastada %.2f euros",g);
       printf("El descuento es medio, %.f %", des);
       printf( "La cantidad a pagar es %.2f", cp);
              
    }else if(g>6000){
        des=0; 
        cp=g;
       printf("La cantiadad gastada %.2f euros",g);
       printf("El descuento es nulo, %.f por ciento ", des);
       printf( "La cantidad a pagar es %.2f", cp);
     
    }else{
       des=10;
       cp=0.9*g;
       printf("La cantiadad gastada %.2f euros",g);
       printf("El descuento es bajo, %.f por ciento", des);
       printf( "La cantidad a pagar es %.2f", cp);
    }
    return (0);
}

