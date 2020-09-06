/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 17 de octubre de 2014, 12:45
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265
/*
 * 
 */
int main() 
{
//Declaracion
    float rcirculo, areacirculo, btriangulo, htriangulo, areatriangulo;
    float lcuadrado, areacuadro;
       //Introducir valores
    
    // Entrada de radio del círculo
    printf( "Introduzca el radio del círculo: ");
    scanf( "%f", &rcirculo );
    
    // Cálculo del aŕea del círculo
    areacirculo=2*PI*rcirculo;
    
    printf( "Área del círculo: %f unidades al cuadrado\n", areacirculo );
    
    // Entrada de datos del triángulo
    printf( "Introduzca el valor de la base del triángulo: ");
    scanf( "%f", &btriangulo );
    printf( "Introduzca el valor de la altura del triángulo: ");
    scanf( "%f", &htriangulo );
    
    // Cálculo del aŕea del triángulo
    areatriangulo = btriangulo*htriangulo/2;
    
    printf( "Área del triángulo: %f unidades al cuadrado \n", areatriangulo );
    
    // Entrada de lado del cuadrado
    printf( "Introduzca el valor del lado del cuadrado: ");
    scanf( "%f", &lcuadrado );
    
    // Cálculo del aŕea del círculo
    areacuadro = lcuadrado*lcuadrado;
    
    printf( "Área del cuadrado: %f unidades al cuadrado\n", areacuadro );
    
    return 0;
  
    
}

