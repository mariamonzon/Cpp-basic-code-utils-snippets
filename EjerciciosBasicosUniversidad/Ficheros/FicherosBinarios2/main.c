/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 15 de diciembre de 2014, 8:14
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50
/*
 * 
 */
struct personal{
    char nombre[TAM];
    char apellidos[TAM];
    char domicilio[TAM];
    char fecha_ingreso_empresa[TAM];   
};
struct cuentas {
    int numero_seg_social;
    int numero_cta_corriente;
};
struct trabajadores{
    struct personal p;
    struct cuentas c;
};

int main(void) {
    
    struct personal *p;
    struct trabajadores *trabajadores; 
    struct cuentas *c;
    FILE *fichcuentas, *fichpersonal, *fichtrabajadores;
    int tam1, tam2, tamtot;
    
    if ((fichcuentas = fopen("CUENTAS.dat", "rb")) == NULL)
    { 
    printf ( " Error en la apertura. Es posible que el fichero no exista \n ");
    }else{
        fseek(fichcuentas, 0, SEEK_END);
        tam1=ftell(fichcuentas)/sizeof( struct cuentas);
        c=(struct cuentas*)malloc(tam1*sizeof(struct cuentas));
        fread(c, sizeof(struct cuentas), tam1, fichcuentas);
    }
    if ((fichpersonal = fopen("PERSONAL.dat", "rb")) == NULL)
    { 
    printf ( " Error en la apertura. Es posible que el fichero no exista \n ");
    }else{
        fseek(fichpersonal, 0, SEEK_END);
        tam2=ftell(fichpersonal)/sizeof( struct personal);
        p=(struct personal*)malloc(tam2*sizeof(struct personal));
        fread(p, sizeof(struct personal), tam2, fichcuentas);
    }
    
    tamtot= tam1 + tam2; 
    trabajadores= (struct trabajadores*)malloc(tamtot*sizeof(struct personal));
    fichtrabajadores=fopen("TRABAJADORES.dat", "wb");
    fichtrabajadores=fwrite(trabajadores, sizeof( trabajadores), 1, fichtrabajadores);
    
    fclose(fichcuentas);
    fclose(fichpersonal);
    fclose(fichtrabajadores);
    
    return (0);
    
}


