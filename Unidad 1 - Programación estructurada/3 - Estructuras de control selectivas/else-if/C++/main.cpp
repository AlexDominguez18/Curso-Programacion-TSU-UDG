#include <iostream>

#define CALIFICACION_MINIMA 60
#define CALIFICACION_BUENA 80

int main()
{
    using namespace std;

    float calificacion = 0;

    cout << "Ingrese la calificacion: ";
    cin >> calificacion;

    // Si la calificacion es mayor o igual a 80, imprime "Excelente!"
    // Si la calificacion es mayor o igual a 60, imprime "Aprobado"
    // Si la calificacion no entra en ninguna condicion, entra al else y imprime "Reprobado"
    
    if (calificacion >= CALIFICACION_BUENA){
        cout << "Excelente!" << endl;
    } else if (calificacion >= CALIFICACION_MINIMA) {
        cout << "Aprobado" << endl;
    } else {
        cout << "Reprobado" << endl;
    }

    cout << "Presione ENTER para terminar...";
    cin.ignore();
    cin.get();

    return 0;
}
