/* 
 * File:   main.c
 * Author: Alumno
 *
 * Created on  de diciembre 1 de 2014, 8:10
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define TAMMAX 50
#define PAB 5
/*
 * 
 */
typedef struct stand{
    char nombre [TAMMAX];
    int numero;
    int dias;
    float metros;
    float total_alquiler;
} tstand;

typedef struct pabellon{
    float tarifa;
    float metros;
} tpabellon;

void cb();
void menu();
void tarifa (struct pabellon arraypabellon[5]);
void menu (struct stand arraystand[], struct pabellon arraypabellon[]);
void AnadirStand (struct stand arraystand[], struct pabellon arraypabellon[], int empresas);
void ordenar(struct stand arraystand[], struct stand auxiliar, int empresas);
void EliminarStand (struct stand arraystand[], struct pabellon arraypabellon[], int empresas);
void ModificarStand ( struct stand arraystand[], struct pabellon arraypabellon[], int empresas);
void visualizar (struct stand arraystand[], struct pabellon arraypabellon[], int empresas);

int main(void) {
    struct stand arraystand[TAMMAX];
    struct pabellon arraypabellon[PAB];
    tarifa (arraypabellon);
    menu(arraystand, arraypabellon);
    return (0);
}

void cb(){
    fflush(stdout);
    __fpurge(stdin);
}
void tarifa(struct pabellon arraypabellon[5]){
    int i;
    for(i=0; i<PAB; i++){
        printf("Introduzca la tarifa de cada pabellon: ");
        scanf("%f", &arraypabellon[i].tarifa);
    }
}
void menu(struct stand arraystand[], struct pabellon arraypabellon[]){
    int option, empresas=0;       
    printf("1.-Añadir un stand \n");
    printf("2.-Eliminar un stand\n");
    printf("3.-Modificar la tarifa de un pabellon\n");
    printf("4.-Visualizar la informacion de los stands y pabellones\n");
    printf("5.-Salir del programa\n");
    
    do{ 
    printf("Escoja una opcion: ");
    cb(); 
    scanf("%d", &option);
        switch(option){    
            case 1: 
                empresas++;
                AnadirStand(arraystand, arraypabellon, empresas); 
                break;
            case 2:
                EliminarStand(arraystand, arraypabellon, empresas);
                empresas--;
                break;
            case 3: 
                ModificarStand(arraystand, arraypabellon, empresas);
                break;
            case 4:
                visualizar (arraystand, arraypabellon, empresas);
                break;
            case 5:
                printf("Salir");
                break;  
        }
    }while (option>1||option<4);
}
void AnadirStand (struct stand arraystand[], struct pabellon arraypabellon[], int empresas){
    int  i;
    struct stand auxiliar;
    for(i=0;i <empresas; i++){
    printf("Introduzca el nombre del stand: ");
    cb();
    gets(auxiliar.nombre);
    printf("Introduzca el numero del pabellon: ");
    cb();
    scanf("%d", &auxiliar.numero);
    printf("Introduzca el numero de dias: ");
    cb();
    scanf("%d", &auxiliar.dias);
    printf("Introduzca los metros cuadrados: ");
    cb();
    scanf("%f", &auxiliar.metros);
    auxiliar.total_alquiler = arraypabellon[auxiliar.numero].tarifa*auxiliar.dias*auxiliar.metros;
    arraypabellon[auxiliar.numero].metros += auxiliar.metros;
    ordenar( arraystand, auxiliar, empresas);
    }
    
}
void ordenar(struct stand arraystand[], struct stand auxiliar, int empresas){// Metodo quicksort
    int i, pos=0;
    if(empresas==0) {
        arraystand[0]=auxiliar;
    } else {
        while(pos<empresas) {
            if(strcmp(arraystand[pos].nombre, auxiliar.nombre)>0) {
                for(i=empresas; i>pos; i--) {
                    arraystand[i]=arraystand[i-1];
                }
                arraystand[pos]=auxiliar;
                break;
            } else {
                pos++;
            }
        }
    }
}    

void EliminarStand (struct stand arraystand[], struct pabellon arraypabellon[], int empresas){
    int i,j;
    char nombre[TAMMAX];
    printf("Introduzca el nombre de la empresa\n");
    cb();
    fgets(nombre, TAMMAX, stdin);
    
    for(i=0; i<empresas; i++) {
        if(strcmp(arraystand[i].nombre,nombre)==0) {
            for(j=i; j<empresas; j++) {
                arraystand[j]=arraystand[j+1];
            }
        }
    }
} 
void ModificarStand (struct stand arraystand[], struct pabellon arraypabellon[], int empresas){
    int n, i;
        printf("Introduzca el numero de pabellon: \n");
        cb();
        scanf("%d", &n);
        printf("Introduzca la nueva tarifa del pabellon: \n");
        cb();
        scanf("%f", &arraypabellon[n].tarifa);
        for(i=0; i<empresas; i++)
            if(arraystand[i].numero==n)
            arraystand[i].total_alquiler=arraypabellon[i].tarifa*arraystand[i].metros*arraystand[i].dias;
}
void visualizar (struct stand arraystand[], struct pabellon arraypabellon[], int empresas){
    int i, j;
    for(i=0; i<PAB; i++){
        printf(" Pabellon  %d\n", i+1);
        printf("Tarifa %f\n", arraypabellon[i].tarifa);
        printf("Metros %f\n", arraypabellon[i].metros);
        printf("\n");
    }
    if (empresas==0){
    printf(" No hay ningun stand");
    }else{
        printf("Stands \n");
        for(i=0;i<empresas; i++){
            printf(" Stand %d\n", i+1);
            printf("Nombre del stand %s \n", arraystand[i].nombre);
            printf("Numero del pabellon del stand %d \n", arraystand[i].numero);
            printf("Dias de alquiler %d \n", arraystand[i].dias);
            printf("Metros cuadrados del stand %f \n", arraystand[i].metros);
            printf("Precio total del alquiler %.2f \n", arraystand[i].total_alquiler);
        } 
    }
}