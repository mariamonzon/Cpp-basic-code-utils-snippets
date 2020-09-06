/* 
 * File:   main.c
 * Author: lauragzama
 *
 * Created on 16 de diciembre de 2014, 21:20
 */

#include <stdio_ext.h>
#include <stdlib.h>

struct vuelos {
    int numero_vuelo;
    char destino[40];
    char horario_salida[6];
    int numero_plazas_libres;
};

void addvuelo(int n);
void cancelarvuelo(int n);
void abrirfichero(struct vuelos *, int n);
void escribirfichero(struct vuelos *, int n);
void visualizavuelos(int n);
int numerovuelos();
void modificarhorario(int n);
void modificarplazas(int n);
int main() {
    
    int opc,nvuelos=0,numero=0;
    

/*
    FILE *fich;
    fich=fopen("vuelos.dat","wb");    
    fwrite(&numero,sizeof(int),1,fich);    
    fclose(fich);
*/


    nvuelos=numerovuelos();

           
    do {
        printf("\nOpciones:\n1.Información de vuelos\n2.Añadir un nuevo vuelo\n3."
                "Cancelar un vuelo\n4.Modificar horario de salida de un vuelo\n5."
                "Actualizar el número de plazas libres de un vuelo\n0.Salir del programa\n");
        scanf("%d",&opc);
        
        switch(opc){
            case 0:
                numero=1;
                break;
            case 1:
                visualizavuelos(nvuelos);
                break;
            case 2:
                nvuelos++;
                addvuelo(nvuelos);
                break;          
            case 3:  
                cancelarvuelo(nvuelos);
                nvuelos--;
                break;
            case 4:
                modificarhorario(nvuelos);
                break;
            case 5:
                modificarplazas(nvuelos);
                break;
        }                               
    } while (numero==0);

    return 0;
}

void addvuelo(int n){
    
    struct vuelos *listavuelos;
    struct vuelos vuelo;
    int posicion=0,i;
    
    listavuelos=(struct vuelos*)malloc(n*sizeof(struct vuelos));
    
    abrirfichero(listavuelos,n-1);
    
    printf("Destino: ");
    __fpurge( stdin );
    gets(vuelo.destino);
    
    printf("Horario de salida (hh:mm): ");
    __fpurge( stdin );
    gets(vuelo.horario_salida);
    
    printf("Número de plazas libres: ");
    scanf("%d",&vuelo.numero_plazas_libres);
    
    while(posicion<n-1 && i!=1){
        if (strcmp(listavuelos[posicion].horario_salida,vuelo.horario_salida)>0)
            i=1;
        else{
            posicion++;          
        }
    }
    
    vuelo.numero_vuelo=posicion+1;
    
    i=n;
    while(i>=posicion){
        listavuelos[i+1]=listavuelos[i];
        listavuelos[i+1].numero_vuelo++;
        i--;
    }
    
    listavuelos[posicion]=vuelo;
    
    escribirfichero(listavuelos,n);
    
    free(listavuelos);
}

void abrirfichero(struct vuelos *listavuelos, int n){
    
    FILE *fich;
    
    fich=fopen("vuelos.dat","rb");
    
    fread(listavuelos,sizeof(struct vuelos),n,fich);
    
    fclose(fich);
}

void escribirfichero(struct vuelos *listavuelos, int n){
    
    FILE *fich;
    
    fich=fopen("vuelos.dat","wb");
    
    fwrite(listavuelos,sizeof(struct vuelos),n,fich);
    
    fclose(fich);
}

void visualizavuelos(int n){
    
    struct vuelos *listavuelos;
    int i;
    
    listavuelos=(struct vuelos*)malloc(n*sizeof(struct vuelos));
    
    abrirfichero(listavuelos,n);
    
    if (n==0)
        printf("No hay ningún vuelo registrado\n");
    else {
        printf("  Nº vuelo     Destino      Hora de salida     Nº plazas libres\n");
        printf("--------------------------------------------------------------------\n");
        for (i=0;i<n;i++){
            printf("    %d         %s           %s            %d        \n",listavuelos[i].numero_vuelo,listavuelos[i].destino,listavuelos[i].horario_salida,listavuelos[i].numero_plazas_libres);            
        }

    }     
    free(listavuelos);    
}

int numerovuelos(){
    
    int n;
    FILE *fich;
    
    fich=fopen("vuelos.dat","rb");
    fseek(fich,0,SEEK_END);
    n=ftell(fich)/sizeof(struct vuelos);
    fclose(fich);
    
    return n;
    
}

void cancelarvuelo(int n){
    
    struct vuelos *listavuelos;
    int numero,i,j;
    
    listavuelos=(struct vuelos*)malloc(n*sizeof(struct vuelos));
    
    abrirfichero(listavuelos,n);
    
    printf("Introduzca el número del vuelo a cancelar: ");
    scanf("%d",&numero);
    
    if (numero>listavuelos[n-1].numero_vuelo)
        printf("No existe ningún vuelo con el número de vuelo indicado\n");
    else{
        for(i=0;i<n;i++){
            if(listavuelos[i].numero_vuelo==numero){
                for(j=i;j<n;j++){
                    listavuelos[j]=listavuelos[j+1];
                    listavuelos[j].numero_vuelo--;
                }
            }
        }
    }
    escribirfichero(listavuelos,n-1);
    free(listavuelos);
}

void modificarhorario(int n){
    
    
}

void modificarplazas(int n){
    
    struct vuelos *listavuelos;
    int numero,i,plazas;
    
    listavuelos=(struct vuelos*)malloc(n*sizeof(struct vuelos));
    
    abrirfichero(listavuelos,n);
    
    printf("Introduzca el número del vuelo a modificar: ");
    scanf("%d",&numero);
      
    if (numero>listavuelos[n-1].numero_vuelo)
        printf("No existe ningún vuelo con el número de vuelo indicado\n");
    else{
         printf("Introduzca el nuevo número de plazas libres: ");
        scanf("%d",&plazas);   
        for(i=0;i<n;i++){
            if(listavuelos[i].numero_vuelo==numero){
                listavuelos[i].numero_plazas_libres=plazas;                
            }
        }
    }
    
    escribirfichero(listavuelos,n);
    
    free(listavuelos);    
}

