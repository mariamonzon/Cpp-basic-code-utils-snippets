/* 
 * File:   main.c
 * Author: alumno
 *
 * Created on 28 de octubre de 2014, 8:09
 */

#include <stdio.h>
#include <stdlib.h>

/*/
 * 
 * 
 */

float altura( float ho,float r, float k)
  { 
    float hr = ho;
    int cont;
    for (cont=1; cont<=k; cont++)
    {         
        hr=ho*r;
        r=r*r;
    
    }
    return hr;
}
int main() {
    float r, ho, hf, alt;
    int k;
    
    printf("Introduzca la altura inicial; ");
    scanf("%f", &ho);
    
    printf("Introduzca el factor de rebote; ");
    scanf("%f", &r);
    
     printf("Introduzca la altura final; ");
    scanf("%f", & hf);
    if(r<0||r>=1){
    printf("Vuelva a introducir el factor de rebote; ");
    scanf("%f", &r);
    }
    k=0;
    alt= (hf + 1);
    while (alt >= hf) {
        k++; 
        alt= altura(ho,r,k);              
    }  
    
printf(" El orden de rebote es %d y la altura alcanzada %f" , k, alt);
             
    return (0);
}
