/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 11 de diciembre de 2014, 8:12
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 50
/*
 * 
 */

struct registro{
    char nombre [TAM];
    char apellido1 [TAM];
    char apellido2 [TAM];
    unsigned int nacimiento;
    char direccion [TAM];
};
int main(void) {
    struct registro *censo;
    struct registro *jubilados; 
    int i,tam, personas=0;
    FILE *fich;
    if ((fich = fopen("registro.dat", "rb")) == NULL)
    { 
    printf ( " Error en la apertura. Es posible que el fichero no exista \n ");
    }else{
        fseek(fich, 0, SEEK_END);
        tam=ftell(fich)/sizeof( struct registro);
        censo=(struct registro*)malloc(tam*sizeof(struct registro));
        fread(censo, sizeof(struct registro), tam, fich);
        jubilados=(struct registro*)malloc(tam*sizeof(struct registro));
        fclose(fich);
   
        for (i=0; i<tam; i++){
            if (censo[i].nacimiento<= 1954){
                jubilados[personas]=censo[i]; 
                personas++;
            }
        }
        if(jubilados>0){
            for(i=0; i<personas; i++)
                printf ("persona %d %s  %s  %s  %d  %s \n", i, jubilados[i].nombre,jubilados[i].apellido1,jubilados[i].apellido2, jubilados[i].nacimiento, jubilados[i].direccion);
        }
            
    }
    return (0);
}

