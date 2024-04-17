#include <stdio.h>

#define NOMBRE_ARCHIVO "../../3 - Escritura en acceso secuencial/C/alumnos.txt"
#define TAMANIO_NOMBRE 30
#define CANTIDAD_ALUMNOS 5

typedef struct {
    int codigo;
    char nombre[TAMANIO_NOMBRE];
} Alumno;

int main()
{
    Alumno alumno[CANTIDAD_ALUMNOS];
    FILE *archivo;

    archivo = fopen(NOMBRE_ARCHIVO, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    
    // fscanf lee los datos del archivo y los almacena en las variables correspondientes
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        fscanf(archivo, "%d,%s\n", &alumno[i].codigo, alumno[i].nombre);    
    }

    fclose(archivo);

    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        printf("Codigo: %d, Nombre: %s\n", alumno[i].codigo, alumno[i].nombre);
    }

    return 0;
}