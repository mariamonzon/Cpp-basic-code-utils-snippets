/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on 19 de noviembre de 2014, 17:06
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void parametros(int *fil, int *col);
int **reserva( int fil, int col);
void datosmatriz(int **matriz, int fil, int col);
void visualizarmatriz(int **matriz, int fil, int col);
void liberar (int ** matriz, int col);



int main() {
    int **matriz, fil, col;
    parametros(&fil, &col);
    matriz=reserva(fil,col);
    datosmatriz(matriz, fil, col);
    visualizarmatriz(matriz, fil, col);
    liberar(matriz, col);
    return (0);
}

void parametros(int *fil, int *col){
    printf("Introduzca el numero de filas: ");
    scanf("%d", fil);
    printf("Introduzca el numero de columnas: ");
    scanf("%d", fil);
}
int **reserva( int fil, int col){
    int **matriz;
    int i;
    matriz=(int**)malloc(fil*sizeof(int*));
    for( i=0; i<fil; i++ ){
        matriz[i]=(int*)malloc(col*sizeof(int));
    }
    return (matriz);
}
void datosmatriz(int **matriz, int fil, int col){
    int i, j;
    printf("Introduzca los elementos de la matriz ( entre 0 y 20)\n");
    
    for (i=0; i<fil; i++)
        for(j=0; j<col; j++){
            do{
                printf("Elemento[%d][%d]= ",i+1,j+1);
                scanf("%f",&matriz[i][j]); 
            } while (matriz[i][j]<0 || matriz[i][j]>20);   
        }    
}
void visualizarmatriz(int **matriz, int fil, int col){
    
    int i, j, contador1, contador2;
    float suma=0;
    
    for(i=0; i<fil; i++){  
        printf("|");    
        for(j=0; j<col; j++){ 
            if (((j==0)||(j==col-1))||((i==0)||(i==fil-1))){ 
                printf(" . ");
            } else if (((j!=0)||(j!=col-1))&&((i!=0)||(i!=fil-1))){
                for(contador1=i-1; contador1<i+2; contador1++){
                    for(contador2=j-1; contador2<j+2; contador2++){         
                        suma = suma + matriz[contador1][contador2];
                    }
                }   
                if (suma/9 > 6){ 
                    printf(" * ");
                }else {
                    printf(" . ");
                }
            }
        }
        printf("|\n");
    }
}
void liberar (int ** matriz, int col){
    int j;
    for(j=0; j<col; j++)    
        free(matriz[j]);
    free(matriz);
}