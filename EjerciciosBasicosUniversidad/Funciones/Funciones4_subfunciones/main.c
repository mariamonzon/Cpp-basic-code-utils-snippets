/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 3 de noviembre de 2014, 8:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long sum (int num) {
    
    int r; 
    long sum;
    
    sum = 0;
    r = 1;
    
    while (r < num) {
        sum = sum + r;
        r = r + 1;
    }
    return sum;
}

int centro (int numero) {
    
    int resultado, numero1;
    long sumadcha;
    
    numero1 = numero;
    sumadcha = 0;
    while (sumadcha < sum(numero)) {

        numero1 = numero1 +1;
        sumadcha = sumadcha + numero1;
    }
    if (sumadcha == sum(numero)) { 
        resultado = 1;
    } else { 
        resultado = 0;
    }
    return resultado;
}
 
int main() {
    
    int num, r;
    do {
        printf(" Introducir numero hasta 7000:  ");
        scanf (" %d", &num);
    } while ((num >= 7000) || (num <= 1));
    
     printf(" Los centro numericos entre 1 y %d son:", num);
    
    for (r = 2; r < num; r++) {
        if (centro(r) == 1) {
            printf("    %d", r);
        }
        
    }
     printf(".\n");
    
    return 0;
}

