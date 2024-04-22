#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <stdio.h>
#include <string.h>

#include "util.h"

#define TOTAL_PRODUCTOS 10
#define LONGITUD_NOMBRE 50
#define LONGITUD_DESCRIPCION 100

enum opcionesMenu { 
    AGREGAR_PRODUCTO = 1, 
    BAJA_PRODUCTO,
    MOSTRAR_PRODUCTO, 
    LISTAR_PRODUCTOS,
    EDITAR_PRODUCTO, 
    SALIR 
};

typedef struct {
    int id;
    int cantidadStock;
    float precio;
    char nombre[LONGITUD_NOMBRE];
    char descripcion[LONGITUD_DESCRIPCION];
} Producto;

// Prototipos de funciones
Producto capturarProducto(int cantidad);
int capturarIdProducto(Producto *productos, int cantidad, char *titulo);
booleano confirmarAccion(char *mensaje);
booleano validarIdProducto(Producto *productos, int cantidad, int id);
void imprimirProducto(Producto producto);
void inicializarProductos(Producto *productos);
void agregarProducto(Producto *productos, int *cantidad);
void eliminarProducto(Producto *productos, int *cantidad);
void listarProductos(Producto *productos, int cantidad);
void mostrarProducto(Producto *productos, int cantidad);
void editarProducto(Producto *productos, int cantidad);

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
    for (int i = 0; i < TOTAL_PRODUCTOS; i++)
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
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos en el arreglo
 * @param titulo Titulo de la pantalla
*/
int capturarIdProducto(Producto * productos, int cantidad, char *titulo)
{
    int id;
    booleano idValido = false;

    if (!cantidad) {
        printf("No hay productos registrados\n");
        return 0;
    }

    do {
        limpiarPantalla();
        printf("%s\n\n", titulo);
        printf("Ingrese el ID del producto: ");
        scanf("%d", &id);
        limpiarBuffer();

        idValido = validarIdProducto(productos, cantidad, id);
        if (!idValido) pausar("Presione ENTER para continuar...");

    } while (!idValido);

    return id;
}

/**
 * Pregunta al usuario si desea confirmar una accion.
 * 
 * @param mensaje Mensaje a mostrar
 * 
 * @return booleano
*/
booleano confirmarAccion(char *mensaje)
{
    char respuesta;

    printf("%s (s/n): ", mensaje);
    scanf("%c", &respuesta);
    limpiarBuffer();

    return respuesta == 's' || respuesta == 'S';
}

/**
 * Valida si el ID de un producto es valido.
 * 
 * @param id ID del producto
 * 
 * @return booleano
*/
booleano validarIdProducto(Producto *productos, int cantidad, int id)
{
    if (id <= 0 || id > TOTAL_PRODUCTOS) {
        printf("ID no valido\n");
        return false;
    }

    for (int i = 0; i < cantidad; i++ ) {
        if (productos[i].id == id) return true;
    }

    printf("ID no valido\n");
    return false;
}

/**
 * Imprime la informacion formateada de un producto.
 * 
 * @param producto Producto a imprimir
 * 
 * @return void
*/
void imprimirProducto(Producto producto)
{
    const short int tamanioLinea = 50;

    imprimirLinea('-', tamanioLinea);
    printf("| ID %10c %33d|\n", '|', producto.id);
    printf("| Nombre %6c %33s|\n", '|', producto.nombre);
    printf("| Precio %6c %28c%.2f|\n", '|', '$', producto.precio);
    printf("| Unidades %4c %33d|\n", '|', producto.cantidadStock);
    printf("| Descripcion %c %33.20s|\n", '|',
        // strcmp devuelve 0 si las cadenas son iguales
        strcmp(producto.descripcion, "") == 0 ? "N/A" : producto.descripcion);
    imprimirLinea('-', tamanioLinea);
}

/**
 * Agrega un producto al arreglo de productos.
 * 
 * @param productos Arreglo de productos
 * @param p Producto a agregar
 * @param cantidad Cantidad de productos
*/
void agregarProducto(Producto *productos, int *cantidad)
{
    limpiarPantalla();
    printf("1 - CAPTURA DE PRODUCTO\n\n");
    
    // Recibimos la cantidad de productos por referencia y la incrementamos
    productos[*cantidad] = capturarProducto(*cantidad);
    (*cantidad)++;

    printf("Producto agregado correctamente\n");
}

/**
 * Elimina un producto del arreglo de productos.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * @param id ID del producto a eliminar
 * 
 * @return void
*/
void eliminarProducto(Producto *productos, int *cantidad)
{
    int id = capturarIdProducto(productos, *cantidad, "2 - DAR DE BAJA PRODUCTO");
    /**
     * Buscamos el producto con el id especificado y lo eliminamos,
     * para ello movemos todos los productos una posicion a la izquierda
     * a partir de la posicion del producto a eliminar.
    */
    for (int i = 0; i < *cantidad; i++) {
        if (productos[i].id != id) continue;
        if (!confirmarAccion("¿Esta seguro que desea eliminar el producto")) return;
        
        int j;
        for (j = i; j < *cantidad - 1; j++) {
            productos[j] = productos[j + 1];
        }
        productos[j] = (Producto){0, 0, 0, "", ""};
        (*cantidad)--;
        printf("Producto eliminado correctamente\n");
        break;
    }
}

/**
 * Lista todos los productos en el arreglo de productos.
 * Imprime el ID, nombre y precio de cada producto con un formato
 * de tabla.
 * 
 * @param productos Arreglo de productos
 * @return void
*/
void listarProductos(Producto* productos, int cantidad)
{
    char* encabezadoTabla = "| ID | Nombre             | Precio |";
    const short int tamanioLinea = strlen(encabezadoTabla);

    if (!cantidad) {
        printf("No hay productos registrados\n");
        return;
    }

    limpiarPantalla();
    printf("4 - LISTADO DE PRODUCTOS\n\n");
    imprimirLinea('-', tamanioLinea);
    printf("%s\n", encabezadoTabla);
    imprimirLinea('-', tamanioLinea);

    for (int i = 0; i < cantidad; i++){
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
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void mostrarProducto(Producto *productos, int cantidad)
{
    int id = capturarIdProducto(productos, cantidad, "3 - MOSTRAR PRODUCTO");
    
    for (int i = 0; i < cantidad; i++) {
        if (productos[i].id == id) {
            imprimirProducto(productos[i]);
            return;
        }
    }
}

/**
 * Edita la informacion de un producto en el arreglo de productos.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void editarProducto(Producto *productos, int cantidad)
{
    int i;
    int id = capturarIdProducto(productos, cantidad, "5 - EDITAR PRODUCTO");

    for (i = 0; i < cantidad; i++) {
        if (productos[i].id != id) continue;

        if(!confirmarAccion("¿Esta seguro que desea editar el producto")) return;
        printf("\nSi no desea modificar un campo presione ENTER sin ingresar nada o un 0 en el caso de los campos numericos\n\n");
        imprimirProducto(productos[i]);
        
        Producto p = capturarProducto(cantidad);
        if (strcmp(p.nombre, "") != 0) strcpy(productos[i].nombre, p.nombre);
        if (strcmp(p.descripcion, "") != 0) strcpy(productos[i].descripcion, p.descripcion);
        if (p.precio != 0) productos[i].precio = p.precio;
        if (p.cantidadStock != 0) productos[i].cantidadStock = p.cantidadStock;
        
        printf("Producto editado correctamente\n");
        break;
    }
}
#endif // PRODUCTO_H