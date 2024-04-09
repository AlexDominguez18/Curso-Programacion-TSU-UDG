#include <stdio.h>

#define TAMANIO_NOMBRE 50
#define TAMANIO_CURP 18
#define TAMANIO_RFC 13

struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Persona {
    char nombre[TAMANIO_NOMBRE];
    char curp[TAMANIO_CURP +1];
    char rfc[TAMANIO_RFC + 1];
    struct Fecha fechaNacimiento;
};

void imprimirPersona(struct Persona persona);
void imprimirPunteroPersona(struct Persona* ptr);

int main()
{
    struct Persona persona ={
        "Juan Perez",
        "PEMJ920313HDFLRN01",
        "PEMJ920313",
        {13, 3, 1992}
    };

    imprimirPersona(persona);
    imprimirPunteroPersona(&persona);
    
    return 0;
}

void imprimirPersona(struct Persona persona)
{
    printf("Nombre: %s\n", persona.nombre);
    printf("CURP: %s\n", persona.curp);
    printf("RFC: %s\n", persona.rfc);
    printf("Fecha de nacimiento: %d/%d/%d\n", persona.fechaNacimiento.dia, persona.fechaNacimiento.mes, persona.fechaNacimiento.anio);
}

void imprimirPunteroPersona(struct Persona* ptr)
{
    printf("Nombre: %s\n", ptr->nombre);
    printf("CURP: %s\n", ptr->curp);
    printf("RFC: %s\n", ptr->rfc);
    printf("Fecha de nacimiento: %d/%d/%d\n", ptr->fechaNacimiento.dia, ptr->fechaNacimiento.mes, ptr->fechaNacimiento.anio);
}