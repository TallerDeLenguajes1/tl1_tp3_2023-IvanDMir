#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define fila 5
#define columna 12
int main(){
     int matriz[fila][columna],i,j,promedio[fila],max,posicion;
     for (i=0;i<5;i++){
        printf("\n");
        promedio[0]=0;
        max=0;
        for (j=0;j<12;j++){
            matriz[i][j]= rand() % 50001 + 10000;
           printf("%d  ",matriz[i][j]);
            promedio[i]=promedio[i] + matriz[i][j]; 
            if (matriz[i][j] > max){
                max= matriz[i][j];
                posicion =j;
            }
            
        }
       printf("\nEl promedio del año fue %d \n",promedio[i] / 12);
        printf("El maximo fue %d y ocurrio en el mes numero %d \n",max,posicion);

     }
     return 0;

}