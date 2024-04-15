#include <stdio.h>

#define NOMBRE_ARCHIVO "personas.dat"
#define TAMANIO_NOMBRE 50
#define CANTIDAD_PERSONAS 5

typedef struct {
    int edad;
    char nombre[TAMANIO_NOMBRE];
} Persona;

int main()
{
    Persona personas[] = {
        {20, "Juan Perez"},
        {25, "Maria Lopez"},
        {30, "Pedro Martinez"},
        {35, "Ana Garcia"},
        {40, "Luis Rodriguez"},
    };
    FILE* archivo = fopen(NOMBRE_ARCHIVO, "wb");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    for (int i = 0; i < CANTIDAD_PERSONAS; i++) {
        fwrite(&personas[i], sizeof(Persona), 1, archivo);
    }

    fclose(archivo);

    printf("Se escribieron %d bytes en disco.\n", CANTIDAD_PERSONAS * sizeof(Persona));

    return 0;
}