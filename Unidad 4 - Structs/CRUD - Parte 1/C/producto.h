#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <stdio.h>
#include <string.h>

#include "util.h"

#define CANTIDAD_PRODUCTOS 10
#define LONGITUD_NOMBRE 50
#define LONGITUD_DESCRIPCION 100
#define NOMBRE_ARCHIVO_SECUENCIAL "productos.txt"
#define NOMBRE_ARCHIVO_ALEATORIO "productos.dat"

typedef enum {
    SECUENCIAL,
    ALEATORIO
} Guardado;

typedef struct {
    int id;
    int cantidadStock;
    float precio;
    char nombre[LONGITUD_NOMBRE];
    char descripcion[LONGITUD_DESCRIPCION];
} Producto;

// Prototipos de funciones
Producto capturarProducto(int cantidad);
int capturarIdProducto(int cantidadProductos, char *titulo);
void inicializarProductos(Producto *productos);
void agregarProducto(Producto *productos, Producto p, int *cantidad);
void listarProductos(Producto *productos, int cantidadProductos);
void mostrarProducto(Producto *productos, int id, int cantidadProductos);
void leerArchivoSecuencial(Producto *productos, int *cantidad);
void leerArchivoAleatorio(Producto *productos, int *cantidad);
void escribirArchivoSecuencial(Producto *productos, int cantidad);
void escribirArchivoAleatorio(Producto *productos, int cantidad);

// Implementacion de funciones

/**
 * Inicializa todos los productos con valores por defecto.
 * 
 * @param productos Arreglo de productos
 * @return void
*/
void inicializarProductos(Producto *productos)
{
    // Inicializar todos los productos con valores por defecto
    for (int i = 0; i < CANTIDAD_PRODUCTOS; i++)
    {
        productos[i].id = 0;
        productos[i].cantidadStock = 0;
        productos[i].precio = 0;
        // strcpy copia una cadena a otra, "" es una cadena vacia
        strcpy(productos[i].nombre, "");
        strcpy(productos[i].descripcion, "");
    }
}

/**
 * Captura la informacion de un producto.
 * 
 * @param cantidad Cantidad de productos capturados
 * @return Producto
*/
Producto capturarProducto(int cantidad)
{
    Producto producto;
    // El ID del producto es la cantidad de productos + 1
    producto.id = ++cantidad;

    limpiarPantalla();
    printf("1 - CAPTURA DE PRODUCTO\n\n");
    printf("Nombre: ");
    scanf("%[^\n]", producto.nombre);
    limpiarBuffer();
    printf("Descripcion: ");
    scanf("%[^\n]", producto.descripcion);
    printf("Precio: $");
    scanf("%f", &producto.precio);
    printf("Cantidad en stock: ");
    scanf("%d", &producto.cantidadStock);
    limpiarBuffer();

    return producto;
}

/**
 * Captura el ID de un producto y valida que sea un valor valido.
 * Checa que el ID sea mayor a 0 y menor o igual a la cantidad de productos.
 * 
 * @param cantidadProductos Cantidad de productos en el arreglo
 * @param titulo Titulo de la pantalla
*/
int capturarIdProducto(int cantidadProductos, char *titulo)
{
    int id;

    do
    {
        limpiarPantalla();
        printf("%s\n\n", titulo);
        printf("Ingrese el ID del producto: ");
        scanf("%d", &id);
        limpiarBuffer();

        if (id <= 0 || id > cantidadProductos)
        {
            printf("ID no valido\n");
            pausar("Presione ENTER para continuar...");
        }
    } while (id <= 0 || id > cantidadProductos);

    return id;
}


/**
 * Agrega un producto al arreglo de productos.
 * 
 * @param productos Arreglo de productos
 * @param p Producto a agregar
 * @param cantidad Cantidad de productos
*/
void agregarProducto(Producto *productos, Producto p, int *cantidad)
{
    // Recibimos la cantidad de productos por referencia y la incrementamos
    productos[*cantidad] = p;
    (*cantidad)++;
}

/**
 * Lista todos los productos en el arreglo de productos.
 * Imprime el ID, nombre y precio de cada producto con un formato
 * de tabla.
 * 
 * @param productos Arreglo de productos
 * @return void
*/
void listarProductos(Producto* productos, int cantidadProductos)
{
    char* encabezadoTabla = "| ID | Nombre             | Precio |";
    const short int tamanioLinea = strlen(encabezadoTabla);

    limpiarPantalla();
    printf("2 - LISTADO DE PRODUCTOS\n\n");
    imprimirLinea('-', tamanioLinea);
    printf("%s\n", encabezadoTabla);
    imprimirLinea('-', tamanioLinea);

    for (int i = 0; i < cantidadProductos; i++){
        if (productos[i].id == 0)
            break;
        printf("%c %-2d %c %-18.10s %c $%.2f %c\n",
               '|', productos[i].id,
               '|', productos[i].nombre,
               '|', productos[i].precio, '|');
        imprimirLinea('-', tamanioLinea);
    }
}

/**
 * Muestra la informacion de un producto en el arreglo de productos.
 * 
 * @param productos Arreglo de productos
 * @param id ID del producto a mostrar
 * @param cantidadProductos Cantidad de productos
 * 
 * @return void
*/
void mostrarProducto(Producto *productos, int id, int cantidadProductos)
{
    const short int tamanioLinea = 50;

    for (int i = 0; i < cantidadProductos; i++) {
        if (productos[i].id == id) {
            imprimirLinea('-', tamanioLinea);
            printf("| ID %10c %33d|\n", '|', productos[i].id);
            printf("| Nombre %6c %33s|\n", '|', productos[i].nombre);
            printf("| Precio %6c %28c%.2f|\n", '|', '$', productos[i].precio);
            printf("| Unidades %4c %33d|\n", '|', productos[i].cantidadStock);
            printf("| Descripcion %c %33.20s|\n", '|',
                   // strcmp devuelve 0 si las cadenas son iguales
                   strcmp(productos[i].descripcion, "") == 0 ? "N/A" : productos[i].descripcion);
            imprimirLinea('-', tamanioLinea);
            return;
        }
    }
}

/**
 * Lee los productos desde un archivo secuencial y los guarda en un arreglo.
 * El formato del archivo es el siguiente:
 *  campo1,campo2,campo3,campo4,campo5\n
 * En donde cada linea representa un producto.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void leerArchivoSecuencial(Producto *productos, int *cantidad)
{
    int cantidadBytes = 0;
    FILE *archivo = fopen(NOMBRE_ARCHIVO_SECUENCIAL, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    fseek(archivo, 0, SEEK_END);
    cantidadBytes = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);
    
    while (ftell(archivo) < cantidadBytes) {
        fscanf(archivo, "%d,%49[^,],%99[^,],%f,%d\n",
            &productos[*cantidad].id,
            productos[*cantidad].nombre,
            productos[*cantidad].descripcion,
            &productos[*cantidad].precio,
            &productos[*cantidad].cantidadStock
        );
        
        (*cantidad)++;
    }

    fclose(archivo);
}

/**
 * Lee los productos desde un archivo de acceso aleatorio y los guarda en un arreglo.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void leerArchivoAleatorio(Producto *productos, int *cantidad)
{
    FILE *archivo = fopen(NOMBRE_ARCHIVO_ALEATORIO, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    // Mientras se pueda leer un producto del archivo
    while (fread(&productos[*cantidad], sizeof(Producto), 1, archivo)) {
        (*cantidad)++;
    }

    fclose(archivo);
}

/**
 * Escribe los productos en un archivo de acceso aleatorio.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void escribirArchivoAleatorio(Producto *productos, int cantidad)
{
    FILE *archivo = fopen(NOMBRE_ARCHIVO_ALEATORIO, "wb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    fwrite(productos, sizeof(Producto), cantidad, archivo);
    fclose(archivo);
}

/**
 * Escribe los productos en un archivo secuencial.
 * El formato del archivo es el siguiente:
 *  campo1,campo2,campo3,campo4,campo5\n
 * En donde cada linea representa un producto.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void escribirArchivoSecuencial(Producto *productos, int cantidad)
{
    FILE *archivo = fopen(NOMBRE_ARCHIVO_SECUENCIAL, "wb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        fprintf(archivo, "%d,%s,%s,%.2f,%d\n",
            productos[i].id,
            productos[i].nombre,
            productos[i].descripcion,
            productos[i].precio,
            productos[i].cantidadStock
        );
    }

    fclose(archivo);
}

#endif // PRODUCTO_H