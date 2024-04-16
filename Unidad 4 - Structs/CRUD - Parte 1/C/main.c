#include <stdio.h>
#include <stdlib.h>

#include "producto.h"
#include "util.h"

int elegirOpcionMenu();
int capturarIdProducto(int cantidadProductos);

int main()
{
    int cantidadProductos = 0;
    Producto productos[CANTIDAD_PRODUCTOS];
    booleano continuarPrograma = true;

    do {
        switch (elegirOpcionMenu()) {
            case 1:
                agregarProducto(productos, capturarProducto(cantidadProductos), &cantidadProductos);
                break;
            case 2:
                listarProductos(productos);
                break;
            case 3:
                mostrarProducto(productos, capturarIdProducto(cantidadProductos));
                break;
            case 4:
                continuarPrograma = false;
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }

        if (continuarPrograma) pausar("Presione ENTER para continuar...");
        else printf("Gracias por usar Alex Shop\n");

    } while(continuarPrograma);

    return 0;
}

int elegirOpcionMenu()
{
    int opcion;
    limpiarPantalla();
    printf("Bienvenido - Alex Shop\n\n");
    printf("1. Agregar producto\n");
    printf("2. Listar productos\n");
    printf("3. Mostrar producto\n");
    printf("4. Salir\n\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);
    limpiarBuffer();

    return opcion;
}

int capturarIdProducto(int cantidadProductos)
{
    int id;

    do {
        limpiarPantalla();
        printf("3 - MOSTRAR PRODUCTO\n\n");
        printf("Ingrese el ID del producto: ");
        scanf("%d", &id);
        limpiarBuffer();

        if (id <= 0 || id > cantidadProductos) {
            printf("ID no valido\n");
            pausar("Presione ENTER para continuar...");
        }
    } while (id <= 0 || id > cantidadProductos);

    return id;
}