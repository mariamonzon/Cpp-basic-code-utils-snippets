/* 
 * File:   main.c
 * Author: Maria
 *
 * Created on 28 de octubre de 2014, 17:45
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    //Declaraciones 
    char car;
    int dis, dd ;
    //Introducir datos
    fflush(stdin);
    __fpurge(stdin);
    
    printf("Introduzca una distancia (comprendido entre 0 y 26): ");
    scanf("%d", &dis);
    
    // Clausula para que el valor introducido sea correcto.
    while( dis < 0 || dis > 26){
    printf("El valor es incorrecto (d comprendido entre 0 y 26): ");
    printf("Vuelva a introducirlo");
    }
    printf("Introduzca una frase con un punto al final: ");
    
    do   {     
        scanf("%c", &car);
        if(car== ' '){
            printf(" ");
        }
        if (car >= 'a' && car<= 'z'){ 
            if (car + dis > 'z') {
                 dd = car + dis - 26;
            }
             printf ("%c", dd);
            }
            if(car + dis < 'z') 
            {dd= dis+car;
            printf ("%c", dd);
            } 
        if ( car >= 'A' && car<= 'Z'){ 
            if (car + dis > 'z') 
            {
            dd = (dis+car-26);
             printf ("%c", dd);
            }
            else {
            dd= dis+car;
            printf ("%c", dd);
            }
    }
    }while ( dis > 0 || dis < 26);
    
    return (0);
}