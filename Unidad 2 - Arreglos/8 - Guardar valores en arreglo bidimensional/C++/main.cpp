#include <iostream>

#define FILAS 3
#define COLUMNAS 3

using namespace std;

int main()
{
    // Declaracion de un arreglo bidimensional inicializado en 0
    int arreglo[FILAS][COLUMNAS] = { {} };
    int i, j;

    /**
     * Para guardar valores en un arreglo bidimensional
     * es necesario indicar la posicion de la fila y la
     * posicion de la columna.
     * 
     * Se hace uso de dos ciclos anidados, el primer ciclo
     * recorre las filas y el segundo ciclo recorre las columnas.
     * 
     * Por costumbre se utiliza la variable i para recorrer las filas
     * y la variable j para recorrer las columnas.
    */
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            // Se solicita el valor para la fila i y columna j
            cout << "Ingrese el valor para la fila " << i << " y columna " << j << ": ";
            cin >> arreglo[i][j];
        }
    }

    cin.ignore(); // Limpiamos el buffer del teclado
    cout << "Presione una tecla para continuar...";
    cin.get();

    // Limpiamos la pantalla de la consola
    system("clear || cls");

    // Imprimimos el arreglo bidimensional con los valores leidos
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            cout << arreglo[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Presione una tecla para terminar...";
    cin.get();

    return 0;
}