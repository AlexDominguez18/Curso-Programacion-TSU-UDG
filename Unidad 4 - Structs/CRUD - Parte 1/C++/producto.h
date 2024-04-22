#ifndef PRODUCTO_H
#define PRODUCTO_H

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
int capturarIdProducto(Producto* productos, int cantidad, char *titulo);
void inicializarProductos(Producto *productos);
bool confirmarAccion(const char *mensaje);
bool validarIdProducto(Producto *productos, int id, int cantidad);
void imprimirProducto(Producto producto);
void agregarProducto(Producto *productos, int *cantidad);
void eliminarProducto(Producto *productos, int *cantidad);
void listarProductos(Producto *productos, int cantidad);
void mostrarProducto(Producto *productos, int cantidad);
void editarProducto(Producto *productos, int cantidad);

#endif // PRODUCTO_H