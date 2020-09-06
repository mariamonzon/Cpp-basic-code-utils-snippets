/* 
 * File:   main.c
 * Author: Maria
 *
 * Created on 22 de octubre de 2014, 11:14
 */

#include <stdio.h>
#include <stdlib.h>


int main() {

    
    //Declaraciones
    int b500, b200, b100, b50, b20, b10, b5, m2, m1, mc50, mc20, mc10;
    int mc5, mc2, mc1, centimos, res;
    float euros;
    
    //Introducir datos
    printf("Introduzca la cantidad deseada en euros: ");
    scanf("%f", &euros);
    
    //Operaciones
        centimos=euros*100;
        //Billetes
        b500=centimos/50000;
        res=centimos%50000;

        b200=res/20000;
        res=res%20000;
        
        b100=res/10000;
        res=res%10000;
        
        b50=res/5000;
        res=res%5000;
        
        b20=res/2000;
        res=res%2000;
        
        b10=res/1000;
        res=res%1000;
        
        b5=res/500;
        res=res%500;
        
        //Monedas
        m2=res/200;
        res=res%200;
        m1=res/100;
        res=res%100;
        mc50=res/50;
        res=res%50;
        mc20=res/20;
        res=res%20;
        mc10=res/10;
        res=res%10;
        mc5=res/5;
        res=res%5;
        mc2=res/2;
        mc1=res%2;
    
    //Resultado
    printf("%d billete(s) 500 euros\n", b500);
    printf("%d billete(s) 200 euros\n", b200);
    printf("%d billete(s) 100 euros\n", b100);
    printf("%d billete(s) 50 euros\n", b50);
    printf("%d billete(s) 20 euros\n", b20);
    printf("%d billete(s) 10 euros\n", b10);
    printf("%d billete(s) 5 euros\n", b5);
    printf("%d moneda(s) de 2 euros\n", m2);
    printf("%d moneda(s) de 1 euro\n", m1);
    printf("%d moneda(s) de 50 centimos\n", mc50);
    printf("%d moneda(s) de 20 centimos\n", mc20);
    printf("%d moneda(s) de 10 centimos\n", mc10);
    printf("%d moneda(s) de 5 centimos\n", mc5);
    printf("%d moneda(s) de 2 centimos\n", mc2);
    printf("%d moneda(s) de 1 centimo\n", mc1);

    return 0;
}