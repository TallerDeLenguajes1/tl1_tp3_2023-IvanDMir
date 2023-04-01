//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//array cte de tipo puntero char
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"}; 
float costos[5];
//
struct {
    int ProductoID; 
    int Cantidad; 
    char *TipoProducto; 
    float PrecioUnitario; 
    float constoTotal;
} typedef Producto;

struct {
    int ClienteID; 
    char *NombreCliente; 
    int CantidadProductosAPedir; 
    Producto *Productos; 
                     
} typedef Clientes;
// Declaracion de funciones
void cargarcompradores( Clientes * compradores, int cantClientes);
void cargarProductos(Producto * Producto, int cantProducto );
void mostrado(Clientes *array, int cant);
float costoProducto(Producto *producto,int cantPro);
void liberar (Clientes *compradores, int cantClientes);



int main (void)
{
    int cantClientes;
    Clientes *compradores;
    srand(time(NULL));
    puts("Ingresa la cantidad de clientes ");
    scanf("%d",&cantClientes);
    compradores= (Clientes *) malloc(sizeof(Clientes)*cantClientes);
    cargarcompradores(compradores,cantClientes);
    mostrado(compradores,cantClientes);
    liberar(compradores,cantClientes);
    return 0;
}

//----Funciones----



void cargarcompradores( Clientes * compradores, int cantClientes)
{
int i;
    for ( i = 0; i < cantClientes; i++)
    {
        char nombre[20];
        printf("CLIENTE  %d ",i+1);
        compradores[i].ClienteID=i;
        printf("nombre: ");
        fflush(stdin);
        gets(nombre);
        compradores[i].NombreCliente = (char *) malloc((strlen(nombre)+1) * sizeof(char));
        strcpy(compradores[i].NombreCliente,nombre); 
        compradores[i].CantidadProductosAPedir = rand () % (5-1)+1;
        compradores[i].Productos= (Producto *)malloc(sizeof(Producto)*compradores[i].CantidadProductosAPedir);
        cargarProductos((compradores[i].Productos),(compradores[i].CantidadProductosAPedir));
        costos[i] = costoProducto(compradores[i].Productos,compradores[i].CantidadProductosAPedir);


    }
    
}

void cargarProductos( Producto * Producto, int cantProducto )
{
int i;
    for ( i = 0; i < cantProducto; i++)
    {
        Producto[i].ProductoID=i;
        Producto[i].Cantidad= rand () % (10-1)+1;
        Producto[i].TipoProducto = TiposProductos[rand () % 4];                                               
        Producto[i].PrecioUnitario=rand () % (100-10)+10;
    }
}

void mostrado( Clientes *array, int cant)
{
    printf("\n\n");
    for (int k = 0; k < cant; k++)
    {
        printf("CLIENTE N: %d\n", k + 1);
        printf("NOMBRE: %s\n", array[k].NombreCliente);
        printf("CANTIDAD DE PRODUCTOS: %d\n",array[k].CantidadProductosAPedir);
        printf("\n");
        for (int i = 0; i < array[k].CantidadProductosAPedir; i++)
        {
            printf("Producto N %d\n", i + 1);
            printf("ID producto: %d\n", array[k].Productos[i].ProductoID);
            printf("Cantidad: %d\n", array[k].Productos[i].Cantidad);
            printf("Tipo de producto: %s\n", array[k].Productos[i].TipoProducto);
            printf("precio unitario: %.2f\n", array[k].Productos[i].PrecioUnitario);
            printf("\n");
        }
        printf("\nTOTAL: %.2f\n",costos[k]);
        printf("\n");
        puts("=============== FIN CLiente====================");
        printf("\n");
    }
    puts("---------------FIN COMPRA--------------------");
}
float costoProducto(Producto *producto, int cantPro)
{
    int TotalPro=0,i;
    for ( i = 0; i < cantPro; i++)
    {
        TotalPro += (producto->Cantidad) * (producto->PrecioUnitario);
        producto++;
    }
    
    return (TotalPro);
}

void liberar (Clientes *compradores, int cantClientes)
{
int i;
    for ( i = 0; i < cantClientes; i++)
    {
       free(compradores[i].Productos);
    }
    free(compradores);
}
