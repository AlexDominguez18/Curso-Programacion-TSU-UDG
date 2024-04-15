#include <stdio.h>

#define NOMBRE_ARCHIVO "../../5 - Escritura en acceso aleatorio/C/personas.dat"
#define TAMANIO_NOMBRE 50

typedef struct {
    int edad;
    char nombre[TAMANIO_NOMBRE];
} Persona;

int main()
{  
    int cantidadPersonas;
    FILE* archivo = fopen(NOMBRE_ARCHIVO, "rb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Se calcula la cantidad de registros en el archivo
    // dividiendo el tamaño del archivo por el tamaño de la estructura
    fseek(archivo, 0, SEEK_END);
    cantidadPersonas = ftell(archivo) / sizeof(Persona);
    fseek(archivo, 0, SEEK_SET);

    Persona personas[cantidadPersonas];

    for (int i = 0; i < cantidadPersonas; i++) {
        fread(&personas[i], sizeof(Persona), 1, archivo);
    }

    fclose(archivo);

    printf("Se leyeron %d registros del archivo.\n", cantidadPersonas);
    for (int i = 0; i < cantidadPersonas; i++) {
        printf("Nombre: %s Edad: %d\n", personas[i].nombre, personas[i].edad);
    }

    return 0;
}