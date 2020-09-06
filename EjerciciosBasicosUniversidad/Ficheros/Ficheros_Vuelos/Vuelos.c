/* 
 * File:   main.c
 * Author: Maria
 *
 * Created on 5 de enero de 2015, 12:53
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define NF "vuelos.dat"
/*
 * 
 */
typedef struct vuelo{
    int numero_vuelo;
    char destino[30];
    char horario_salida[6];
    int numero_plazas_libres;
}VUELO;


void cb();
void introducirCadena(char *cad, int tam);
void menu(char *opc);
void mostrarFichero( char *nf);
void mostrarVuelo(VUELO v);
int obtenerTamanio(char *nf);
void volcarFicheroArray(char *nf, VUELO *vuelos);
void volcarArrayFichero(char *nf, VUELO *vuelos, int tam);
void  desplazarInsertar(VUELO *vuelos, VUELO nuevo, int pos, int *numVuelo);
int buscarPosicion(VUELO *vuelos, VUELO nuevo, int tam);
void  desplazarInsertar(VUELO *vuelos, VUELO nuevo, int pos, int *numVuelo);
void opcion2(char *nf);
void opcion3(char *nf);
void eliminar( VUELO * vuelos, int pos, int *tam);
VUELO anadir();
void opcion4( char *nf);
void opcion5( char *nf);
void pedirVuelo(int *num);
    
int main() {
    char opc;
    VUELO *vuelos;
    do{
        menu(&opc);
        switch(opc){
            case '1': mostrarFichero(NF); break;
            case '2': opcion2(NF);break;
            case '3': opcion3(NF);break;
            case '4': opcion4(NF);break;
            case '5': opcion5(NF);break;
            case '0': printf("\nFIN\n"); break;
            default: printf("\nOpcion Incrrecta");
        }
        
    }while(opc!='0');
    
    return (0);
}
void cb(){
    fflush(stdout);
    __fpurge(stdin);
}
void introducirCadena(char *cad, int tam){
    cb();
    fgets(cad, tam, stdin);
    if(cad[strlen(cad)-1]=='\n')
        cad[strlen(cad)-1]='\0'; 
}
void menu(char *opc){
    printf("\nMENU");
    printf("\n1.-Informacion de vuelos");
    printf("\n2.-Añadir un vuelo");
    printf("\n3.-Cancelar un vuelo");
    printf("\n4.-Modificar horario salida de un vuelo");
    printf("\n5.-Modificar  el numero de plazas de un vuelo");
    printf("\n0.-Salir");
    printf("\nEscoja una opcion:  ");
    cb();
    scanf("%c", opc);
}
void mostrarFichero( char *nf){
    FILE *pf;
    VUELO v;
    pf=fopen(nf, "rb");
    if(pf!=(FILE*)NULL){
        printf("\nNº VUELO   DESTINO                  HORA DE SALDA    Nº PLAZAS LIBRES ");
        while(fread(&v, sizeof(VUELO), 1, pf)!=0){
                mostrarVuelo(v);
        }
        fclose(pf);
               
    }
}
void mostrarVuelo(VUELO v){
    
    printf("\n%3.d        %-29s%-5s             %3.d", v.numero_vuelo, 
            v.destino, v.horario_salida, v.numero_plazas_libres);
}
int obtenerTamanio(char *nf){
    FILE *pf;
    int tam=0;
    pf=fopen(nf, "rb");
    if(pf!=(FILE*)NULL){
        fseek(pf, 0, SEEK_END);
        tam=ftell(pf)/sizeof(VUELO);
        fclose(pf);
    }
    
    return tam;
}
    
void volcarFicheroArray(char *nf, VUELO *vuelos){
    
    FILE *pf;
    int i=0;
    pf=fopen(nf, "rb");
    if(pf!=(FILE*)NULL){
        while(fread(&vuelos[i], sizeof(VUELO), 21, pf)!=0)
            i++;
        fclose(pf);
    }
 }       
VUELO *reservar( int tam){
    VUELO *v;
    v=calloc( tam, sizeof(VUELO));
    return v;
}
void opcion2(char *nf){
    VUELO *vuelos;
    VUELO nuevo;
    int numVuelo, pos;
    numVuelo=obtenerTamanio(nf);
    vuelos=reservar(numVuelo+1);
    nuevo=anadir();
    volcarFicheroArray(nf, vuelos);
    pos=buscarPosicion(vuelos, nuevo, numVuelo);
    desplazarInsertar(vuelos, nuevo, pos, &numVuelo);
    volcarArrayFichero(nf, vuelos, numVuelo);
    free(vuelos);
}
VUELO anadir(){
    VUELO n;
    
    printf("\nDestino: ");
    introducirCadena(n.destino, 30);
    printf("\nHorario Salida (hh:mm): ");
    introducirCadena(n.horario_salida, 30);
    printf("\nNumero de plazas Libres: ");
    scanf("%d", &n.numero_plazas_libres);
    
    return n;
}
    
 int buscarPosicion(VUELO *vuelos, VUELO nuevo, int tam){
     int enc=0, pos=0;
    while(!enc &&pos<tam){
        if(strcmp(vuelos[pos].horario_salida, nuevo.horario_salida)>0)
            enc=1;
        else pos ++; 
    }
     return pos;
 }
void  desplazarInsertar(VUELO *vuelos, VUELO nuevo, int pos, int *numVuelo){
    int i;
    for(i=*numVuelo; i>pos; i--){
        vuelos[i]=vuelos[i-1];
        vuelos[i].numero_vuelo=i+1;
    }
    vuelos[pos]=nuevo;
    vuelos[pos].numero_vuelo=pos+1;
    (*numVuelo)++;
        
    }
void volcarArrayFichero(char *nf, VUELO *vuelos, int tam){
    FILE *pf;
    pf=fopen(nf, "wb");
    if(pf!=(FILE*)NULL)
       fwrite(vuelos, sizeof(VUELO), tam, pf);    
    fclose(pf);
}
void opcion3(char *nf){
    int numVuelo, pos;
    VUELO *vuelos;
    pedirVuelo(&pos);
    numVuelo=obtenerTamanio(nf);
    if(pos>0 && pos<=numVuelo){
        vuelos=reservar(numVuelo+1);
        volcarFicheroArray(nf, vuelos);
        eliminar( vuelos, pos-1, &numVuelo);
        volcarArrayFichero(nf, vuelos, numVuelo);
        free(vuelos);
    }else
        printf("\nNo hay ningun vuelo con ese numero");
}
void eliminar( VUELO * vuelos, int pos, int *tam){
    int i;
    (*tam)--;
    for(i=pos; i<*tam; i++){
        vuelos[i]=vuelos[i+1];
        vuelos[i].numero_vuelo=i+1;
    }
}
void pedirVuelo(int *num){
    printf("Introduzzca el numero de vuelo: ");
    cb();
    scanf("%d", num);
}
void opcion4( char *nf){
    int numVuelo, pos;
    VUELO *vuelos;
    VUELO mod;
    pedirVuelo(&pos);
    numVuelo=obtenerTamanio(nf);
    if(pos>0 && pos<=numVuelo){
        vuelos=reservar(numVuelo);
        volcarFicheroArray(nf, vuelos);
        mod=vuelos[pos-1];
        eliminar( vuelos, pos-1, &numVuelo);
        printf("Introduzca la nueva hora de salida (hh:mm):  ");
        introducirCadena(mod.horario_salida, 6);
        pos=buscarPosicion(vuelos, mod, numVuelo+1);
        desplazarInsertar(vuelos, mod, pos, &numVuelo);
        volcarArrayFichero(nf, vuelos, numVuelo);
        free(vuelos);
    }else
        printf("No hay ningun vuelo con ese numero");
}
void opcion5( char *nf){
    int numVuelo, pos;
    VUELO *vuelos;
    pedirVuelo(&pos);
    numVuelo=obtenerTamanio(nf);
    if(pos>0 && pos<=numVuelo){
        vuelos=reservar(numVuelo+1);
        volcarFicheroArray(nf, vuelos);
        printf("Introduzca las nuevas plazas libres: ");
        cb();
        scanf("%d", &vuelos[pos-1].numero_plazas_libres);
        volcarArrayFichero(nf, vuelos, numVuelo);
        free(vuelos);
    }else
        printf("No hay ningun vuelo con ese numero");
}