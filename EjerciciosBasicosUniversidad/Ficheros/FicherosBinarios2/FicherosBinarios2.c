/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 11 de diciembre de 2014, 8:26
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

/*ejercicio 2
 * 
 */

void lb();
void quitarSalto(char *cad);
void crearFicheroPersonal(char *nomfich);
void crearFicheroCuentas(char *nomfich);
void crearNuevoFichero(char*nf1, char*nf2, char*nf3);
typedef struct personal{
    char nom[20];
    char apes[30];//apellidos
    char dir[40];
    char fecha[11]; //es un char por si tengo que poner guiones o cualquier cosa que no sea un numero
}tPersonal;

typedef struct cuenta{
    char nss[30];
    char ncc[30];
}tCuenta;

typedef struct datos{//estructura anidada
    tPersonal p;
    tCuenta c;
}tDatos;

int main(int argc, char** argv) {
    char nomfich[30];
    crearFicheroPersonal("Personal.dat");
    crearFicheroCuentas("Cuentas.dat");
    printf("\nNombre del nuevo fichero: ");
    lb();
    fgets(nomfich, 30, stdin);
    crearNuevoFichero("Personal.dat", "Cuentas.dat", nomfich);
    return (EXIT_SUCCESS);
}

void lb() {
    fflush(stdout);
    __fpurge(stdin);
}
void quitarSalto(char *cad) {//suprime el retorno de carro, por si en el fichero no lo han quitado
    if (cad[strlen(cad) - 1] == '\n')
        cad[strlen(cad) - 1] = '\0';
}

void crearFicheroPersonal(char *nomfich){
    FILE *pf;
    int i;
    tPersonal p;
    pf=fopen(nomfich, "wb");
    if(pf!=(FILE*)NULL){
        for(i=0;i<3;i++){
            printf("\nNombre:");
            lb();
            fgets(p.nom, 20, stdin);
            quitarSalto(p.nom);
            printf("\nApellidos:");
            fgets(p.apes, 30, stdin);
            quitarSalto(p.nom);
            printf("\nDireccion:");
            lb();
            fgets(p.dir,40, stdin);
            quitarSalto(p.dir);
            printf("\nFecha:");
            lb();
            fgets(p.fecha,11, stdin);
            quitarSalto(p.fecha);
            fwrite(&p, sizeof(tPersonal), 1, pf);
        }
    }
}

void crearFicheroCuentas(char *nomfich) {
    FILE *pf;
    int i;
    tCuenta c;
    pf = fopen(nomfich, "wb");
    if (pf != (FILE*) NULL) {
        for (i = 0; i < 3; i++) {
            printf("\nNSS:"); //seguridad social
            lb();
            fgets(c.nss, 30, stdin);
            quitarSalto(c.nss); //funcion para el \n
            printf("\nNCC:"); //numero cuenta corriente
            lb();
            fgets(c.ncc, 30, stdin);
            quitarSalto(c.ncc);
        }
        fwrite(&c, sizeof (tCuenta), 1, pf);
    }fclose(pf);
}
void crearNuevoFichero(char*nf1, char*nf2, char*nf3){
    FILE *pfp, *pfc, *pfnuevo;
    tPersonal p;
    tCuenta c;
    tDatos d;
    pfp= fopen(nf1, "rb");
    pfc= fopen(nf2, "rb");
    pfnuevo= fopen(nf3, "wb");
    if(pfp!=(FILE*)NULL && pfc!=(FILE*)NULL && pfnuevo!=(FILE*)NULL){
        while(fread(&p, sizeof(tPersonal), 1, pfp)!=0 && fread(&c, sizeof(tCuenta), 1, pfc)!=0){
            d.p=p;
            d.c=c;
            fwrite(&d, sizeof(tDatos), 1, pfnuevo);
            }
        fclose(pfp);
        fclose(pfnuevo);
        fclose(pfc);
    }
}