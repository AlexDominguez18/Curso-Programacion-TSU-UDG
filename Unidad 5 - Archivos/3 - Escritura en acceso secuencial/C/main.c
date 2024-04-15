#include <stdio.h>

#define NOMBRE_ARCHIVO "alumnos.txt"
#define TAMANIO_NOMBRE 30
#define CANTIDAD_ALUMNOS 5
#define SEPARADOR_CAMPOS ","

typedef struct {
    int codigo;
    char nombre[TAMANIO_NOMBRE];
} Alumno;

int main()
{
    Alumno alumnos[CANTIDAD_ALUMNOS] = {
        {1, "Juan"},
        {2, "Maria"},
        {3, "Pedro"},
        {4, "Ana"},
        {5, "Luis"},
    };
    FILE *archivo;

    archivo = fopen(NOMBRE_ARCHIVO, "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        fprintf(archivo, "%d%s%s\n", alumnos[i].codigo, SEPARADOR_CAMPOS, alumnos[i].nombre);
    }

    fclose(archivo);

    return 0;
}