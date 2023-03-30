#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 20

int main (){
    char** arreglo;
    char* nombres;
    int i,j;  
    arreglo = (char**) malloc(5* sizeof(char**)) ;
    nombres =(char*) malloc(20*sizeof(char*));
    for (i=0;i<5;i++){
        puts("Ingrese un nombre");
        gets(nombres);
        arreglo[i]=(char*)malloc(strlen(nombres)+1);
        strcpy(arreglo[i],nombres);
    }
    for (i=0;i<5;i++){
        printf("El nombre es %s \n",arreglo[i]);
    }
    free(arreglo);
    free(nombres);
    return 0;
}