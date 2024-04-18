#include <stdio.h>
#include <stdlib.h>

#include "producto.h"
#include "util.h"

// Prototipo de funcion
int elegirOpcionMenu();

int main()
{
    int cantidadProductos = 0;
    Producto productos[CANTIDAD_PRODUCTOS];
    booleano continuarPrograma = true;
    Guardado tipoGuardado = ALEATORIO;

    inicializarProductos(productos);
    if (tipoGuardado == SECUENCIAL) leerArchivoSecuencial(productos, &cantidadProductos);
    else leerArchivoAleatorio(productos, &cantidadProductos);

    do {
        switch (elegirOpcionMenu()) {
            case 1:
                agregarProducto(productos,
                    capturarProducto(cantidadProductos), 
                    &cantidadProductos
                );
                break;
            case 2:
                listarProductos(productos, cantidadProductos);
                break;
            case 3:
                mostrarProducto(productos, 
                    capturarIdProducto(cantidadProductos, "3 - MOSTRAR PRODUCTO"),
                    cantidadProductos
                );
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

    if (tipoGuardado == SECUENCIAL) escribirArchivoSecuencial(productos, cantidadProductos);
    else escribirArchivoAleatorio(productos, cantidadProductos);

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