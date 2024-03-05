#include <iostream>

#define CALIFICACION_MINIMA 60

using namespace std;

int main()
{
    float calificacion = 0;

    cout << "Ingrese la calificacion: ";
    cin >> calificacion;

    // Si la calificacion es mayor o igual a 60, imprime "Aprobado"
    // Si la calificacion es menor a 60, no entra al if y no imprime nada
    if (calificacion >= CALIFICACION_MINIMA){
        cout << "Aprobado" << endl;
    }

    cout << "Presione ENTER para terminar...";
    cin.ignore();
    cin.get();

    return 0;
}
