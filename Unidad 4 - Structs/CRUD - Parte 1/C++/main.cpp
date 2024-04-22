#include <iostream>

#include "producto.cpp"
#include "util.h"

using namespace std;

//Prototipo de funcion
int elegirOpcionMenu();

int main()
{
    Producto productos[TOTAL_PRODUCTOS];
    int cantidadProductos = 0;
    bool continuarPrograma = true;

    do {
        switch (elegirOpcionMenu()) {
            case AGREGAR_PRODUCTO:
                agregarProducto(productos, &cantidadProductos);
                break;
            case BAJA_PRODUCTO:
                eliminarProducto(productos, &cantidadProductos);
                break;
            case MOSTRAR_PRODUCTO:
                mostrarProducto(productos, cantidadProductos);
                break;
            case LISTAR_PRODUCTOS:
                listarProductos(productos, cantidadProductos);
                break;
            case EDITAR_PRODUCTO:
                editarProducto(productos, cantidadProductos);
                break;
            case SALIR:
                continuarPrograma = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }

        if (continuarPrograma) pausar("Presione ENTER para continuar...");
        else cout << "Gracias por usar Alex Shop" << endl;

    } while(continuarPrograma);

    return 0;
}

/**
 * Muestra el menu de opciones y captura la opcion seleccionada por el usuario.
 * 
 * @return int
*/
int elegirOpcionMenu()
{
    int opcion;

    limpiarPantalla();
    cout << "BIENVENIDO - ALEX SHOP" << endl << endl;
    cout << "1. Dar de alta producto" << endl;
    cout << "2. Dar de baja producto" << endl;
    cout << "3. Consultar producto" << endl;
    cout << "4. Listar productos" << endl;
    cout << "5. Editar producto" << endl;
    cout << "6. Salir" << endl << endl;
    
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    limpiarBuffer();

    return opcion;
}