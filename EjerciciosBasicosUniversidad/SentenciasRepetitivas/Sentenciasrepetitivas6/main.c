/* 
 * File:   main.c
 * Author: Maria
 *
 * Created on 28 de octubre de 2014, 23:43
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    char i, c, v;
        for(i=1; i<=28; i++){
            printf ("linea %d" , i);
            
            for (c=0; c<8; c++){
                v=( 25 +8*i + c);
                printf (" %d %c ", v, v);
                
            }
        printf ("\n");
    }
    
    return (0);
}