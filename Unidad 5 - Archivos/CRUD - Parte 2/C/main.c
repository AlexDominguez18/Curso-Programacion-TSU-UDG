#include <stdio.h>
#include <stdlib.h>

#include "producto.h"
#include "util.h"

// Prototipo de funcion
int elegirOpcionMenu();

int main()
{
    int cantidadProductos = 0;
    Producto productos[TOTAL_PRODUCTOS];
    booleano continuarPrograma = true;
    Guardado tipoGuardado = SECUENCIAL;

    inicializarProductos(productos);
    if (tipoGuardado == SECUENCIAL) leerArchivoSecuencial(productos, &cantidadProductos);
    else leerArchivoAleatorio(productos, &cantidadProductos);

    do {
        switch (elegirOpcionMenu()) {
            case AGREGAR_PRODUCTO:
                agregarProducto(productos, &cantidadProductos);
                break;
            case BAJA_PRODUCTO:
                eliminarProducto(productos, &cantidadProductos);
                break;
            case LISTAR_PRODUCTOS:
                listarProductos(productos, cantidadProductos);
                break;
            case MOSTRAR_PRODUCTO:
                mostrarProducto(productos, cantidadProductos);
                break;
            case EDITAR_PRODUCTO:
                editarProducto(productos, cantidadProductos);
                break;
            case SALIR:
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
    printf("1. Dar de alta producto\n");
    printf("2. Dar de baja producto\n");
    printf("3. Consultar producto\n");
    printf("4. Listar productos\n");
    printf("5. Editar producto\n");
    printf("6. Salir\n\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);
    limpiarBuffer();

    return opcion;
}