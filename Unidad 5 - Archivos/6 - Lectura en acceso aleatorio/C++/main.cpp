#include <iostream>
#include <fstream>

#define NOMBRE_ARCHIVO "../../5 - Escritura en acceso aleatorio/C++/personas.dat"
#define TAMANIO_NOMBRE 50

struct Persona {
    int edad;
    char nombre[TAMANIO_NOMBRE];
};

using namespace std;

int main()
{
    int cantidadPersonas;
    fstream archivo;

    // Se abre el archivo en modo lectura y binario
    archivo.open(NOMBRE_ARCHIVO, ios::in | ios::binary);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }

    // Se obtiene la cantidad de personas en el archivo
    archivo.seekg(0, ios::end);
    cantidadPersonas = archivo.tellg() / sizeof(Persona);
    archivo.seekg(0, ios::beg);

    Persona personas[cantidadPersonas];
    // Se lee cada persona del archivo
    for (int i = 0; i < cantidadPersonas; i++) {
        archivo.read(reinterpret_cast<char*>(&personas[i]), sizeof(Persona));

    }
    
    archivo.close();

    cout << "Se leyeron " << cantidadPersonas << " registros del archivo." << endl;
    for (int i = 0; i < cantidadPersonas; i++) {
        cout << "Nombre: " << personas[i].nombre << " Edad: " << personas[i].edad << endl;
    }

    return 0;
}