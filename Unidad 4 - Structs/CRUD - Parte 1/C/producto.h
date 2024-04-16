#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <stdio.h>
#include <string.h>

#include "util.h"

#define CANTIDAD_PRODUCTOS 10
#define LONGITUD_NOMBRE 50
#define LONGITUD_DESCRIPCION 100

typedef struct {
    int id;
    int cantidadStock;
    float precio;
    char nombre[LONGITUD_NOMBRE];
    char descripcion[LONGITUD_DESCRIPCION];
} Producto;

void inicializarProductos(Producto* productos);
Producto capturarProducto(int cantidad);
void agregarProducto(Producto* productos, Producto p, int* cantidad);
void listarProductos(Producto* productos);
void mostrarProducto(Producto* productos, int id);

void inicializarProductos(Producto* productos)
{
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++) {
        productos[i].id = 0;
        productos[i].cantidadStock = 0;
        productos[i].precio = 0;
        strcpy(productos[i].nombre, "");
        strcpy(productos[i].descripcion, "");
    }
}

Producto capturarProducto(int cantidad)
{
    Producto producto;

    producto.id = ++cantidad;
    limpiarPantalla();

    printf("1 - CAPTURA DE PRODUCTO\n\n");
    printf("Nombre: ");
    scanf("%[^\n]", producto.nombre);
    limpiarBuffer();
    printf("Descripcion: ");
    scanf("%[^\n]", producto.descripcion);
    printf("Precio: ");
    scanf("%f", &producto.precio);
    printf("Stock: ");
    scanf("%d", &producto.cantidadStock);
    limpiarBuffer();

    return producto;
}

void agregarProducto(Producto* productos, Producto p, int* cantidad)
{
    productos[*cantidad] = p;
    (*cantidad)++;
}

void listarProductos(Producto* productos)
{
    limpiarPantalla();
    printf("2 - LISTADO DE PRODUCTOS\n");
    printf("ID\tNombre\tPrecio\tStock\n");
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++) {
        if (productos[i].id == 0) break;
        printf("%d\t%s\t%.2f\t%d\n",
            productos[i].id,
            productos[i].nombre,
            productos[i].precio,
            productos[i].cantidadStock
        );
    }
}

void mostrarProducto(Producto* productos, int id)
{
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++) {
        if (productos[i].id == id) {
            printf("ID: %d\n", productos[i].id);
            printf("Nombre: %s\n", productos[i].nombre);
            printf("Precio: %.2f\n", productos[i].precio);
            printf("Stock: %d\n", productos[i].cantidadStock);
            printf("Descripcion: %s\n", productos[i].descripcion);
            return;
        }
    }
    printf("Producto no encontrado\n");
}

#endif // PRODUCTO_H