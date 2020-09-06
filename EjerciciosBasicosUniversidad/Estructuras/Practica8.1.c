/* 
 * File:   Practica8.1.c
 * Author: alumno
 *
 * Created on 24 de noviembre de 2014, 19:03
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXTAM1 5
#define MAXTAM2 20


struct DatosPabellones
{
    float tarifas;
    float metrosAlquilados;
};

struct DatosStands
{
    char NombreEmpresa[MAXTAM2];
    int NumeroDePabellon;
    int DiasAlquilados;
    float metros;
    float precio; /*precio=tarifa * metros*dias alquilados*/
    
    
};

void PideTarifasPabellones(struct DatosPabellones Pabellones[]);
void VisualizarStandsYPabellones(struct DatosPabellones Pabellones[],struct DatosStands Stands[],int numeroStands);
void ModificarTarifa(struct DatosPabellones Pabellones[]);
void AnadirStand(struct DatosPabellones Pabellones[],struct DatosStands Stands[],int numeroStands);
void InsertarElemento(struct DatosStands Stands[],int *numeroStands,struct DatosStands Apoyo);


int main(void)
{
    
    struct DatosPabellones Pabellones[MAXTAM1];
    struct DatosStands Stands[MAXTAM2];
    int operacion,num=0,numeroStands=0;
    
    
    PideTarifasPabellones(Pabellones);
    
    do
    {
    
    printf("\nOpciones a realizar:\n1.-Añadir Stand\n2.-Eliminar Stand\n3.-Modificar tarifa de pabellon\n4.-Visualizar todo\n5.-Salir\n");
    scanf("%d",&operacion);
    
    
    switch(operacion)
    {
        case 1:
            numeroStands++;
            AnadirStand(Pabellones,Stands,numeroStands);
            
            break;
        
        case 2:
            
            
            break;
            
        case 3:
            ModificarTarifa(Pabellones);
            break;
            
        case 4:
            VisualizarStandsYPabellones(Pabellones,Stands,numeroStands);        
            break;
            
        case 5: 
            num=1;            
            break;
    }
    
    
    }while(num==0);
    
    
    

    return (EXIT_SUCCESS);
}
void PideTarifasPabellones(struct DatosPabellones Pabellones[])
{
    int indice;
    for(indice=0;indice<MAXTAM1;indice++)
    {
        printf("Introduzca la tarifa del Pabellon %d: ",indice+1);
        scanf("%f",&Pabellones[indice].tarifas);
    }
}
void VisualizarStandsYPabellones(struct DatosPabellones Pabellones[],struct DatosStands Stands[],int numeroStands)
{
    int indice;
    
    printf("Datos de los pabellones: \n");
    
    for(indice=0;indice<MAXTAM1;indice++)
    {
        printf("\nTarifa del pabellon %d : %f ",indice+1,Pabellones[indice].tarifas);
        printf("\nmetrosAlquilados %d :\n %f ",indice+1,Pabellones[indice].metrosAlquilados);
    }
    
    if(numeroStands==0)
    {
        printf("\nActualmento no hay ningun Stand.");
    }
    else
    {
        for(indice=0;indice<numeroStands;indice++)
        {
            printf("\nNombre de la empresa : ");
            puts(Stands[indice].NombreEmpresa);
            printf("\nNumero de pabellon: %d",Stands[indice].NumeroDePabellon);
            printf("\nDias de alquiler: %d",Stands[indice].DiasAlquilados);
            printf("\nmetros alquilados: %f",Stands[indice].metros);
            printf("\nprecio total del alquiler %f",Stands[indice].precio);
        }
    }
    
    
}
void ModificarTarifa(struct DatosPabellones Pabellones[])
{
    int indice;
    
    printf("\nIntroduzca el numero del pabellon del que quiere realizar la modificacion: ");
    scanf("%d",&indice);
    
    indice--;
    
    printf("\nIntroduzca la nueva tarifa del Pabellon %d: ",indice+1);
    scanf("%f",&Pabellones[indice].tarifas);
    
}
void AnadirStand(struct DatosPabellones Pabellones[],struct DatosStands Stands[],int numeroStands)
{
    
    struct DatosStands Apoyo;
    
/*
    numeroStands++;
*/
    printf("\nNombre de la empresa : ");
     fflush(stdout);
    __fpurge(stdin);
    gets(Apoyo.NombreEmpresa);
    printf("\nNumero de pabellon : ");
    fflush(stdout);
    __fpurge(stdin);
    scanf("%d",&Apoyo.NumeroDePabellon);
    printf("\nDias de alquiler: ");
    scanf("%d",&Apoyo.DiasAlquilados);
    printf("\nmetros alquilados: ");
    scanf("%f",&Apoyo.metros);
    
    Apoyo.precio=(Apoyo.metros)*(Apoyo.DiasAlquilados)*(Pabellones[Apoyo.NumeroDePabellon].tarifas);
    
    InsertarElemento(Stands,&numeroStands,Apoyo);
    
}
void InsertarElemento(struct DatosStands Stands[],int *numeroStands,struct DatosStands Apoyo)
{
    
    int inicio=0,final=(*numeroStands),mitad=(inicio+final)/2;
    int indice;
    int numero=0;
    
    do
    {
        if(Apoyo.NombreEmpresa>Stands[mitad].NombreEmpresa)
        {
            final=mitad;
            mitad=(inicio+final)/2;
            
            if(inicio-final==-1)
            {
                
                if(Apoyo.NombreEmpresa>Stands[inicio].NombreEmpresa)
                {
                    
                    for(indice=(*numeroStands)-1;indice>inicio;indice--)
                    {
                        Stands[indice]=Stands[indice-1];
                    }
                    
                    Stands[inicio]=Apoyo;
                    
                }
                else
                {
                    for(indice=(*numeroStands)-1;indice>final;indice--)
                    {
                        Stands[indice]=Stands[indice-1];
                    }
                    Stands[final]=Apoyo;
                }
                
                numero=1;
            }
        }
        
            if(Apoyo.NombreEmpresa<Stands[mitad].NombreEmpresa)
            {
                inicio=mitad;
                mitad=(inicio+final)/2;
                
                 if(inicio-final==-1)
                    {
                        
                        if(Apoyo.NombreEmpresa>Stands[inicio].NombreEmpresa)
                        {
                    
                                for(indice=(*numeroStands)-1;indice>inicio;indice--)
                                {
                                     Stands[indice]=Stands[indice-1];
                                }
                    
                        Stands[inicio]=Apoyo;
                    
                        }
                         else
                        {
                            for(indice=(*numeroStands)-1;indice>final;indice--)
                             {
                                 Stands[indice]=Stands[indice-1];
                             }
                            
                             Stands[final].DiasAlquilados=Apoyo.DiasAlquilados;
                        }
                        
                        numero=1;
                    }
                    
                
               }
        
            
        
    }
    while(numero!=1);
    
}