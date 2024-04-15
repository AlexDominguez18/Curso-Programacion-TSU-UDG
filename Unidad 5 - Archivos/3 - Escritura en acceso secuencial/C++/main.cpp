#include <iostream>
#include <fstream>

#define NOMBRE_ARCHIVO "alumnos.txt"
#define CANTIDAD_ALUMNOS 5
#define SEPARADOR_CAMPOS ","

using namespace std;

struct Alumno {
    int codigo;
    string nombre;
};

int main()
{   
    Alumno alumnos[] = {
        {1, "Juan"},
        {2, "Maria"},
        {3, "Pedro"},
        {4, "Ana"},
        {5, "Luis"},
    };
    fstream archivo;

    archivo.open(NOMBRE_ARCHIVO, ios::out);
    
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    archivo << CANTIDAD_ALUMNOS << endl;
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        archivo << alumnos[i].codigo << SEPARADOR_CAMPOS << alumnos[i].nombre << endl;
    }

    archivo.close();
   
    return 0;
}