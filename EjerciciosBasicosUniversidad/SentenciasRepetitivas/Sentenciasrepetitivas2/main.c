/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 24 de octubre de 2014, 13:02
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    //Declaraciones 
    int n, i, b;
    
    n=rand()%100;
      fflush(stdin);
    __fpurge(stdin);
    
    printf( "Adivine el numero de dos cifras: ");
    scanf("%d", &b);
   
      fflush(stdin);
    __fpurge(stdin);
    i=10;
    while (i>0)
    {
    
    if(b==n){
    printf( "Felicidades, ha adivinado el numero ");
    printf( "Su nota es %d", i);     
    }   
    if (b!=n){ 
    printf( "Lo siento, no ha adivinado el numero ");
    printf( "Los intentos restantes son %d . ", i);
    i--;
    }
    if (i=0)
    {
        printf( "Usted ha perdido, intentelo de nuevo");
    }
    
}
    return (0);

}