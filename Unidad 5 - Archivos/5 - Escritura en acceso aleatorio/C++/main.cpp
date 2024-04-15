#include <iostream>
#include <fstream>

#define NOMBRE_ARCHIVO "personas.dat"
#define CANTIDAD_PERSONAS 5
#define TAMANIO_NOMBRE 50

using namespace std;

struct Persona {
    int edad;
    char nombre[TAMANIO_NOMBRE];
};

int main()
{
    Persona personas[CANTIDAD_PERSONAS] = {
        { 20, "Juan Perez" },
        { 25, "Maria Lopez" },
        { 30, "Pedro Alvarez" },
        { 35, "Ana Chavez" },
        { 40, "Luis Duran" }
    };
    fstream archivo;

    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::binary);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    for (int i = 0; i < CANTIDAD_PERSONAS; i++) {
        archivo.write((char*)&personas[i], sizeof(Persona));
    }

    archivo.close();
    
    return 0;
}