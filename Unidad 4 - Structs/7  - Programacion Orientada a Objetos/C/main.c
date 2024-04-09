#include <stdio.h>

// En C no existe el concepto de clases, pero podemos simularlo con estructuras
// y funciones que actúen sobre ellas.

// Definimos una estructura Persona
typedef struct {
    char* nombre;
    int edad;
} Persona;

// Funciones que actúan sobre la estructura Persona
Persona inicializarPersona(char* nombre, int edad);
void imprimirPersona(Persona* persona);

int main()
{
    Persona persona = inicializarPersona("Juan", 30);
    imprimirPersona(&persona);

    return 0;
}

Persona inicializarPersona(char* nombre, int edad) {
    Persona persona;
    persona.nombre = nombre;
    persona.edad = edad;
    return persona;
}

void imprimirPersona(Persona* persona) {
    printf("Nombre: %s\n", persona->nombre);
    printf("Edad: %d\n", persona->edad);
}