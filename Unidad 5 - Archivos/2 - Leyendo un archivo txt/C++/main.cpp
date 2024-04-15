#include <iostream>
#include <fstream>
#include <string>

#define NOMBRE_ARCHIVO "../../1 - Escribiendo en archivo txt/C++/ejemplo.txt"
#define MAX 100

using namespace std;

int main()
{
    int tamanioArchivo;
    // Buffer para almacenar el contenido del archivo.
    char buffer[MAX];
    fstream archivo;

    archivo.open(NOMBRE_ARCHIVO, ios::in);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    
    // seekg se usa para mover el puntero de lectura/escritura al fin del archivo.
    archivo.seekg(0, ios::end);
    // tellg devuelve la posicion del puntero de lectura/escritura.
    tamanioArchivo = archivo.tellg();
    // seekg se usa para mover el puntero de lectura/escritura al inicio del archivo.
    archivo.seekg(0, ios::beg); 


    cout << "Tamanio del archivo: " << tamanioArchivo << " bytes" << endl;
    // read lee el contenido del archivo y lo almacena en el buffer.
    archivo.read(buffer, tamanioArchivo);
    cout << "Contenido del archivo: " << buffer << endl;

    archivo.close();

    return 0;
}