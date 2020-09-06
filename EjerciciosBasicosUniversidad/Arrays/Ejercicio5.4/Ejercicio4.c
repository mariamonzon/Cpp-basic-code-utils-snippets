/* 
 * File:   Ejer4.c
 * Author: alumno
 *
 * Created on 10 de noviembre de 2014, 13:51
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include<math.h>
#define MAXTAM 50

/*
 * 
 */
int pide_datos(int *array);

float media(int *array,int num_elem);

int moda(int *array,int num_elem,int arrayz[]);

float desviacion(int *array,int num_elem,float m);
void datos(int *array,int tam);
void visualizar_moda(int array[],int *arrayz,int tam,int mo);


int main() {
    
    int array[MAXTAM],tam,arrayz[MAXTAM],mo;
    float m;
    
    
    tam=pide_datos(array);
    printf("\n%d",tam);
    m=media(array,tam);
    printf("\n%f",m);
    mo=moda(array,tam,arrayz);
    printf("\n%d",mo);
    visualizar_moda(array,arrayz,tam,mo);

    return (0);
}
int pide_datos(int *array)
{
   
    int indice=0;
    int num;
   
    
     printf("introduce numeros y si no quieres más introduce un punto .\n");
    do
    {
        printf("Array(%d): ",indice);
        
        scanf("%d",&num);
        
        
        if(num!='.')
        {
            array[indice]=num;
        }
        
        indice++;
        
    }while(num!='.' && indice<MAXTAM);
    
    indice--;
    
    return indice;

}


float media(int *array,int num_elem)
{
    int i;
    float suma=0;
    float m;
    for(i=0;i<num_elem;i++)
    {
        suma=suma+array[i];
        
        
    }
    m=suma/num_elem;
    
    return(m);
}

void visualizar_moda(int array[],int *arrayz,int tam,int mo)
{
    int i;
    
    for(i=0;i<tam;i++)
    {
        if(array[i]==mo)
            printf("La moda es el numero %d y se repite %d",array[i],mo);
    }
}
int moda(int *array, int num_elem, int arrayz[]) 
{
    int i, cont,moda=0;
    
    poner_a_uno(arrayz,num_elem);

    for (i = 0; i < num_elem; i++)
 {


        for (cont = i + 1; cont < num_elem; cont++) 
        {
            if (array[i] == array[cont]) {

                arrayz[i]++;

            }

        }
        if(arrayz[i]>moda)
            moda=arrayz[i];
        

    }
    return moda;

}

void datos(int *array,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        array[i]=1;
    }
    
}

float desviacion(int *array,int num_elem,int m)
{
    int i,suma=0,indice;
    float x,y;
    printf("\n%d",tam);
    for(i=0;i<num_elem;i++)
    {
        suma=suma+((m-array[indice])*(m-array[indice]));
    }
    x=sqrt(suma);
    
    y=x/num_elem;
    
    return(y);
    
}


