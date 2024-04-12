#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_PRODUCTOS 3
#define TAMANIO_NOMBRE 50
#define TAMANIO_DESCRIPCION 100

typedef struct {
    char nombre[TAMANIO_NOMBRE];
    char descripcion[TAMANIO_DESCRIPCION];
    float precio;
    int cantidad;
} Producto;

Producto capturarProducto();
void mostrarProducto(Producto* producto);
void imprimirLinea(short int longitud);

int main()
{
    int i;
    Producto productos[CANTIDAD_PRODUCTOS];

    for (i = 0; i < CANTIDAD_PRODUCTOS; i++) {
        productos[i] = capturarProducto();
    }

    system("cls || clear");
    for (i = 0; i < CANTIDAD_PRODUCTOS; i++) {
        mostrarProducto(&productos[i]);
    }

    printf("Presione una tecla para continuar...");
    getchar();

    return 0;
}

Producto capturarProducto()
{
    Producto producto;

    printf("Nombre: ");
    scanf("%[^\n]", producto.nombre);
    getchar();
    printf("Descripcion: ");
    scanf("%[^\n]", producto.descripcion);
    printf("Precio: ");
    scanf("%f", &producto.precio);
    printf("Cantidad en stock: ");
    scanf("%d", &producto.cantidad);
    getchar();

    return producto;
}

void imprimirLinea(short int longitud)
{
    // Se imprime la linea de la tabla
    printf("|");
    for (int i = 0; i < longitud; i++) {
        printf("-");
    }
    printf("|\n");
}

void mostrarProducto(Producto* producto)
{
    /*
     * Se utiliza el formato %-20s para que el texto se alinee a la izquierda
     * y se reserve un espacio de 20 caracteres para el texto.
     * Se utiliza el formato %59s para que el texto se alinee a la derecha
     * y se reserve un espacio de 59 caracteres para el texto.
     * 
     * La suma de los espacios reservados y el caracter de barra vertical
     * es igual a la longitud de la linea impresa.
    */
    imprimirLinea(40);
    printf("%-20s %19s |\n", "| Nombre", producto->nombre);
    printf("%-20s %19s |\n", "| Descripcion", producto->descripcion);
    printf("%-20s %19.2f |\n", "| Precio", producto->precio);
    printf("%-20s %19d |\n", "| Cantidad en stock", producto->cantidad);
    imprimirLinea(40);
}