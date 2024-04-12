#include <iostream>
#include <cstdlib>
#include <string>

#define CANTIDAD_ALUMNOS 3
#define TAMANIO_NOMBRE 50
#define TAMANIO_TSU 100

using namespace std;

struct Alumno {
    string nombre;
    string tsu;
    int codigo;
    float promedio;
};

void capturarInformacion(Alumno* alumnos);
void mostrarInformacion(Alumno* alumnos);

int main()
{
    Alumno alumnos[CANTIDAD_ALUMNOS];

    capturarInformacion(alumnos);
    mostrarInformacion(alumnos);

    return 0;
}

void capturarInformacion(Alumno* alumnos)
{
    cout << "Captura la informacion de los alumnos" << endl;
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        cout << "Nombre: ";
        getline(cin, alumnos[i].nombre);
        cout << "Codigo: ";
        cin >> alumnos[i].codigo;
        cin.ignore();
        cout << "TSU: ";
        getline(cin, alumnos[i].tsu);
        cout << "Promedio: ";
        cin >> alumnos[i].promedio;
        cin.ignore();
    }
    cout << "Presione una tecla para continuar...";
    cin.get();
}

void mostrarInformacion(Alumno* alumnos)
{
    system("cls || clear");
    cout << "Mostrando la informacion de los alumnos" << endl;
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Codigo: " << alumnos[i].codigo << endl;
        cout << "TSU: " << alumnos[i].tsu << endl;
        cout << "Promedio: " << alumnos[i].promedio << endl;
        cout << "--------------------" << endl;
    }
}