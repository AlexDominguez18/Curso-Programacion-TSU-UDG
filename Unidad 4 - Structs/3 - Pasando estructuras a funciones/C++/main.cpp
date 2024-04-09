#include <iostream>
#include <string>

#define TAMANIO_NOMBRE 50
#define TAMANIO_CURP 18
#define TAMANIO_RFC 13

using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[TAMANIO_NOMBRE];
    char curp[TAMANIO_CURP + 1];
    char rfc[TAMANIO_RFC + 1];
    Fecha fechaNacimiento;
};

void imprimirPersona(struct Persona persona);
void imprimirPunteroPersona(struct Persona* ptr);

int main()
{
    Persona persona = {
        "Juan Perez",
        "PEMJ920313HDFLRN01",
        "PEMJ920313",
        {13, 3, 1992}
    };

    imprimirPersona(persona);
    imprimirPunteroPersona(&persona);

    return 0;
}

void imprimirPersona(Persona persona)
{
    std::cout << "Nombre: " << persona.nombre << std::endl;
    std::cout << "CURP: " << persona.curp << std::endl;
    std::cout << "RFC: " << persona.rfc << std::endl;
    std::cout << "Fecha de nacimiento: " << persona.fechaNacimiento.dia << "/" << persona.fechaNacimiento.mes << "/" << persona.fechaNacimiento.anio << std::endl;
}

void imprimirPunteroPersona(Persona* ptr)
{
    std::cout << "Nombre: " << ptr->nombre << std::endl;
    std::cout << "CURP: " << ptr->curp << std::endl;
    std::cout << "RFC: " << ptr->rfc << std::endl;
    std::cout << "Fecha de nacimiento: " << ptr->fechaNacimiento.dia << "/" << ptr->fechaNacimiento.mes << "/" << ptr->fechaNacimiento.anio << std::endl;
}