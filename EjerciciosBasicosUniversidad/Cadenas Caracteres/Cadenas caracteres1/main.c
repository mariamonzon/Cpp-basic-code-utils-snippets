/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 20 de noviembre de 2014, 8:07
 */

#include <stdio.h>
#include <stdlib.h>

void cb();
char *reserva(int tam);
void *iniciales (char *cadena, int longitud, char *ini);
void *finales (char *cadena, int longitud, char *fin);
void *intermedios (char *cadena, int longitud, char *inter);
void cuenta_palabras(char *cadena);
int longitudini( char* cadena);
int longitudfin( char* cadena);
int longitudinter( char* cadena);

int main(void){
    int longitud=100;
    char cadena [longitud];
    printf("Introducir cadena de caracteres: ");
    longitud = strlen(gets(cadena));
    char ini[longitud];
    iniciales(cadena, longitud, ini);
    longitud=strlen(ini);
    char fin[longitud];
    finales(ini, longitud, fin);
    char inter[longitud];
    intermedios(fin, longitud, inter);
    cuenta_palabras(inter);
    
return 0;
}
void cb(){
fflush(stdout);
__fpurge(stdin);
}

char *reserva(int tam){
    char *vector =(char*)malloc(tam*sizeof(char));
    return vector;
}

void *iniciales(char *cadena, int longitud, char *ini){
    int i,j;
    for (i=0; cadena[i]== ' '; i++);
    for (j=0; j<longitud-i; j++){
        ini[j]=cadena[j+i];
    }
    printf("%s\n", ini);
}
void *finales(char *cadena, int longitud, char *fin){
    int i,j;
    for(j=strlen(cadena); cadena[j]==' '; j--); 
    for(i=0; i<j; i++){
        fin[i]=cadena[i]; 
    }
    printf("%s\n", fin);
}
void *intermedios(char *cadena, int longitud, char *inter){
    int i=0, cont=0;
    for(i=0;i<longitud; i++){
       if(cadena[i-1]==' '&&cadena[i]==' ')    
           cont++;
       
    }
    for(i=0;i<longitud-cont; i++){
       inter[i]=cadena[i];
       if(cadena[i-1]==' '&&cadena[i]==' '){    
           inter[i]=cadena[i+1];
            i++;
       }   
    }       
    printf("%s\n", inter);
}
void cuenta_palabras(char *cadena){
    int i, cont, longitud;
    longitud=strlen(cadena);
    for (i=0; i<longitud; i++){
        if (cadena[i]==' ')
            cont++;
    }
    printf("El numero de palabras es: %d", cont+1);
}
