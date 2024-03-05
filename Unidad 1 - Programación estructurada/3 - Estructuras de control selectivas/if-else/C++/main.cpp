#include <iostream>

using namespace std;

#define CALIFICACION_MINIMA 60

int main() {
    float calificacion = 0;

    cout << "Ingrese la calificacion: ";
    cin >> calificacion;

    // Si la calificacion es mayor o igual a 60, imprime "Aprobado"
    // Si la calificacion es menor a 60, entra al else y imprime "Reprobado"
    if (calificacion >= CALIFICACION_MINIMA){
        cout << "Aprobado" << endl;
    } else {
        cout << "Reprobado" << endl;
    }

    cout << "Presione ENTER para terminar...";
    cin.ignore();
    cin.get();

    return 0;
}
