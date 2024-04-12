#include <iostream>
#include <iomanip>
#include <string>

#define CANTIDAD_PRODUCTOS 3
#define TAMANIO_NOMBRE 50
#define TAMANIO_DESCRIPCION 100

using namespace std;

struct Producto {
    string nombre;
    string descripcion;
    float precio;
    int cantidad;
};

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

    cout << "Presione una tecla para continuar...";
    cin.get();

    return 0;
}

Producto capturarProducto()
{
    Producto producto;

    cout << "Nombre: ";
    getline(cin, producto.nombre);
    cout << "Descripcion: ";
    getline(cin, producto.descripcion);
    cout << "Precio: ";
    cin >> producto.precio;
    cout << "Cantidad en stock: ";
    cin >> producto.cantidad;
    cin.ignore();

    return producto;
}

void imprimirLinea(short int longitud)
{
    // Se imprime la linea de la tabla
    cout << "|";
    for (int i = 0; i < longitud; i++) {
        cout << "-";
    }
    cout << "|" << endl;
}

void mostrarProducto(Producto* producto)
{
    /*
     * Aqui hacemos uso de la funcion setw para establecer el ancho de la salida
     * de la informacion del producto, de esta manera se logra que la informacion
     * se alinee a la derecha.
     * 
     * setfill se utiliza para rellenar los espacios vacios con algun caracter.
    */
    imprimirLinea(40);
    setfill('.');
    cout << "| Nombre:" << setw(32) << right << producto->nombre << "|" << endl;
    cout << "| Descripcion:" << setw(27) << right << producto->descripcion << "|" << endl;
    cout << "| Precio:" << setw(32) << right << fixed << setprecision(2) << producto->precio << "|" << endl;
    cout << "| Cantidad en stock:" << setw(21) << right << producto->cantidad << "|" << endl;
    imprimirLinea(40);
}