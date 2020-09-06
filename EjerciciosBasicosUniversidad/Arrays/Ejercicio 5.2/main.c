/* 
 * File:   main.c
 * Author: Maria Monzon
 *
 * Created on 5 de noviembre de 2014, 8:10
 */

#include <stdio_ext.h>
#include <math.h>
#define TAM 10


}

void lb() {

    fflush(stdout);
    //__fpurge(stdin);

}

int main() {

    //Declaraciones

    int X[TAM], Y[TAM], Z[TAM], i, k = 1, j = 1;

    //Datos de X

    printf("Introduzca los elementos del array X.\n");

    for (i = 0; i < TAM; i++) {
        printf("X[%d]=", i);
        lb();
        scanf("%d", &X[i]);

    }
    for (i = 0; i < TAM; i++)
        printf("%d ", X[i]);
    lb();
    //Y

    printf("\n Introduzca los elementos del array Y.\n");

    for (i = 0; i < TAM; i++) {
        printf("Y[%d]=", i);
        lb();
        scanf("%d", &Y[i]);

    }
    for (i = 0; i < TAM; i++)
        printf("%d ", Y[i]);
    lb();


    //Comparar

    for (i = 0; i < TAM; i++) {

        if (X[i] > Y[i]) {
            Z[i] = 1;
            j++;
        }

        if (X[i] < Y[i]) {

            Z[i] = -1;
            k++;
        }

        if (X[i] == Y[i]) {
            Z[i] = 0;
        }
    }

    //Tabla
    printf("\n X mayores que Y %d \n", j);
    printf("X menores que Y %d \n", k);

    printf("\n Tabla \n");
    for (i = 0; i < TAM; i++) {
        printf("\n %d  %d  %d \n", X[i], Y[i], Z[i]);
    }

    return (0);
}
