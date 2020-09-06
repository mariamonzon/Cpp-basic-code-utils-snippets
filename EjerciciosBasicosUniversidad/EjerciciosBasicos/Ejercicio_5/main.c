/* 
 * File:   main.c
 * Author: Maria
 *
 * Created on 22 de octubre de 2014, 11:32
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
//Declaraciones
    int dia, mes, ano, ano1;
    
    //Entrada de datos
    printf("Introduza el numero del dia: ");
    scanf("%d", &dia);
    
    printf("Introduzca el numero del mes: ");
    scanf("%d", &mes);
    
    printf("Introduzca el año: ");
    scanf("%d", &ano);
    
    //Operaciones
    ano1=ano%100;
    
    //Resultado
    printf("La fecha es %02d/%02d/%02d", dia, mes, ano1);
    
    return (0);
}

