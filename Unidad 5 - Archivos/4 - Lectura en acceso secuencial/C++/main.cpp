#include <iostream>
#include <fstream>

#define NOMBRE_ARCHIVO "../../3 - Escritura en acceso secuencial/C++/alumnos.txt"
#define SEPARADOR_CAMPOS ','

using namespace std;

struct Alumno {
    int codigo;
    string nombre;
};

int main()
{
    int cantidadAlumnos;
    fstream archivo;

    archivo.open(NOMBRE_ARCHIVO, ios::in);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    archivo >> cantidadAlumnos;
    archivo.ignore(); // Ignora el salto de linea

    Alumno alumno[cantidadAlumnos];
    for (int i = 0; i < cantidadAlumnos; i++) {
        archivo >> alumno[i].codigo;
        archivo.ignore(); // Ignora el separador
        getline(archivo, alumno[i].nombre);
    }

    archivo.close();

    for (int i = 0; i < cantidadAlumnos; i++) {
        cout << "Codigo: " << alumno[i].codigo << ", Nombre: " << alumno[i].nombre << endl;
    }

    return 0;
}