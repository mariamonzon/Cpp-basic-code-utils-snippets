/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 5 de noviembre de 2014, 8:10
 */

#include <stdio.h>
#include <stdlib.h>
#define N 255

void cb(){
    fflush(stdout);
    __fpurge(stdin);
}

int main() {
    int c[N]={0}, i;
    char car;  

    
    printf("Introduzca el texto con un punto (.) al final:" );
    cb(); 
    scanf("%c" , &car);
    
    while (car != '.'){
        /* El caracter entre la a y la z*/
        if(car >= 'a' && car <= 'z')
            c[car-'a']++; 
    }
    for(car ='a', car< 'z'; 
           )
       
        return (0);
}
