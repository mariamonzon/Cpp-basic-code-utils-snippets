/* 
 * File:   main.c
 * Author: Admin
 *
 * Created on 19 de noviembre de 2014, 15:28
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

void parametros(int *fil, int *col);
int **reserva( int fil, int col);
void datosmatriz(int **matriz, int fil, int col);
void visualizar(int **matriz, int fil, int col);
void liberar (int ** matriz, int col);
void puntoSilla(int **matriz, int fil, int col);
int reservarvector(int n);

int main(){
    int **matriz;
    int fil,col;
    parametros(&fil, &col);
    matriz=reserva(fil,col);
    datosmatriz(matriz, fil, col);
    visualizar(matriz, fil, col);
    puntoSilla(matriz, fil, col);
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
    printf("Introduzca los elementos de la matriz (distintos entre si): \n");
    for (i=0; i<fil; i++){
            for(j=0; j<col; j++){
                printf("Elemento[%d][%d]= ",i+1,j+1);
                scanf("%d",&matriz[i][j]);
            } 
            }
}
void visualizar(int **matriz, int fil, int col){
    int i, j;
    for(i=0 ; i<fil; i++){
        for(j=0; j<col; j++){
        printf(" %d ",matriz[i][j]);
        }
        printf("\n");
    }
}
void liberar (int ** matriz, int col){
    int j;
    for(j=0; j<col; j++)    
        free(matriz[j]);
    free(matriz);
}

int reservarvector(int n){
        int *array;
        array=(int*)malloc(n*sizeof(int));
        return(array);
    
}  
void puntoSilla(int **matriz, int fil, int col){
     int i,j,k,l, mayor, menor, *fmayor, *fmenor, *cmayor, *cmenor, puntodesilla;
    
    fmayor=reservarvector(fil);
    fmenor=reservarvector(fil);
    cmayor=reservarvector(col);
    cmenor=reservarvector(col);
    
    for(i=0;i<fil;i++){
        for(j=0,mayor=0, menor=1000;j<col;j++){
            if (matriz[i][j]>mayor)
                mayor=matriz[i][j];
            if (matriz[i][j]<menor)
                menor=matriz[i][j];
        }
        fmayor[i]=mayor;
        fmenor[i]=menor;
    }
    
    for(j=0;j<col;j++){
        for(i=0,mayor=0, menor=1000;i<fil;i++){
            if (matriz[i][j]>mayor)
                mayor=matriz[i][j];
            if (matriz[i][j]<menor)
                menor=matriz[i][j];
        }
        cmayor[j]=mayor;
        cmenor[j]=menor;
    }
    
    for(i=0;i<fil;i++)
        for(j=0;j<col;j++){
            if (fmayor[i]==cmenor[j]){
                puntodesilla=fmayor[i];
                for(k=0;k<fil;k++)
                    for(l=0;l<col;l++)
                        if (matriz[k][l]==puntodesilla)
                        printf("Existe un punto de silla en el elemento [%d][%d]= %d\n", k+1, l+1, puntodesilla);
                
            }
            if (cmayor[j]==fmenor[i]){
                puntodesilla=cmayor[j];
                for(k=0;k<fil;k++)
                    for(l=0;l<col;l++)
                        if (matriz[k][l]==puntodesilla)
                            printf("Existe un punto de silla en el elemento [%d][%d]= %d\n", k+1, l+1, puntodesilla);
                
            }
        } 
    
    free(fmayor);
    free(fmenor);
    free(cmayor);
    free(cmenor);
    
}
