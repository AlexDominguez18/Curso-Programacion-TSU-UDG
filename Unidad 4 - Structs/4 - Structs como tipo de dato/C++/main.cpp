#include <iostream>
#include <string>

#define TAMANIO_NOMBRE 50
#define TAMANIO_CURP 18
#define TAMANIO_RFC 13

using namespace std;

// C++ no necesita usar typedef para definir estructuras como tipo de dato
struct Persona {
    char nombre[TAMANIO_NOMBRE];
    char curp[TAMANIO_CURP + 1];
    char rfc[TAMANIO_RFC + 1];
};

int main() {
    Persona persona = {
        "Juan Perez",
        "PEMJ920313HDFLRN01",
        "PEMJ920313"
    };

    cout << "Nombre: " << persona.nombre << endl;
    cout << "CURP: " << persona.curp << endl;
    cout << "RFC: " << persona.rfc << endl;

    return 0;
}