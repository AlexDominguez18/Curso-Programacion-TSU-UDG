#include <iostream>
#include <iomanip>

using namespace std;

#define TOTAL_CALIFICACIONES 5

int main()
{
    // Declaracion del arreglo
    float calificaciones[TOTAL_CALIFICACIONES];
    float promedio = 0;
    float sumaCalificaciones = 0;

    /**
     * En este caso, no inicializamos el arreglo con un ciclo, sino que leemos
     * los valores desde consola.
     * Guardamos los valores en el arreglo con un ciclo para no tener que
     * escribir N veces la misma instruccion.
    */
    for (int i = 0; i < TOTAL_CALIFICACIONES; i++) {
        cout << "Ingrese la calificacion " << i + 1 << ": ";
        cin >> calificaciones[i];
    }

    // Sumamos todas las calificaciones
    for (int i = 0; i < TOTAL_CALIFICACIONES; i++) {
        sumaCalificaciones += calificaciones[i];
    }

    // Calculamos el promedio
    promedio = sumaCalificaciones / TOTAL_CALIFICACIONES;

    cout << "El promedio de las calificaciones es: ";
    // Mostramos el promedio con dos decimales
    cout << fixed << setprecision(2) << promedio << endl;

    cin.ignore();
    cout << "Presione ENTER para continuar...";
    cin.ignore();

    return 0;
}