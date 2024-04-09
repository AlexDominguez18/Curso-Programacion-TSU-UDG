#include <stdio.h>

#define TAMANIO_NOMBRE 50
#define TAMANIO_CURP 18
#define TAMANIO_RFC 13

typedef struct {
    char nombre[TAMANIO_NOMBRE];
    char curp[TAMANIO_CURP + 1];
    char rfc[TAMANIO_RFC + 1];
} Persona;

int main()
{
    // Ya no colocamos la palabra struct antes de Persona
    Persona persona = {
        "Juan Perez",
        "PEMJ920313HDFLRN01",
        "PEMJ920313"
    };

    printf("Nombre: %s\n", persona.nombre);
    printf("CURP: %s\n", persona.curp);
    printf("RFC: %s\n", persona.rfc);

    return 0;
}