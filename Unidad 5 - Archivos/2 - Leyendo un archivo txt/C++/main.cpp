#include <iostream>
#include <fstream>
#include <string>

#define MAX 100

using namespace std;

int main()
{
    int tamanioArchivo;
    // Buffer para almacenar el contenido del archivo.
    char buffer[MAX];
    std::ifstream archivo("ejemplo.txt");

    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return 1;
    }
    
    // seekg se usa para mover el puntero de lectura/escritura al fin del archivo.
    archivo.seekg(0, std::ios::end);
    // tellg devuelve la posicion del puntero de lectura/escritura.
    tamanioArchivo = archivo.tellg();
    // seekg se usa para mover el puntero de lectura/escritura al inicio del archivo.
    archivo.seekg(0, std::ios::beg); 


    std::cout << "Tamanio del archivo: " << tamanioArchivo << " bytes" << std::endl;
    // read lee el contenido del archivo y lo almacena en el buffer.
    archivo.read(buffer, tamanioArchivo);
    std::cout << "Contenido del archivo: " << buffer << std::endl;

    archivo.close();

    return 0;
}