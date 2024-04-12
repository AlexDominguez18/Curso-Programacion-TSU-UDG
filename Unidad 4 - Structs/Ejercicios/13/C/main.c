#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD_ALUMNOS 3
#define TAMANIO_NOMBRE 50
#define TAMANIO_TSU 100

typedef struct {
    char nombre[TAMANIO_NOMBRE];
    char tsu[TAMANIO_TSU];
    int codigo;
    float promedio;
} Alumno;

void capturarInformacion(Alumno* alumnos);
void mostrarInformacion(Alumno* alumnos);

int main()
{
    Alumno alumnos[CANTIDAD_ALUMNOS];

    capturarInformacion(alumnos);
    mostrarInformacion(alumnos);

    return 0;
}

void capturarInformacion(Alumno* alumnos)
{
    printf("Captura la informacion de los alumnos\n");
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        printf("Nombre: ");
        scanf("%[^\n]", alumnos[i].nombre);
        printf("Codigo: ");
        scanf("%d", &alumnos[i].codigo);
        getchar();
        printf("TSU: ");
        scanf("%[^\n]", alumnos[i].tsu);
        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
        getchar();
    }
    printf("Presione una tecla para continuar...");
    getchar();
}

void mostrarInformacion(Alumno* alumnos)
{
    system("cls || clear");
    printf("Mostrando la informacion de los alumnos\n");
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Codigo: %d\n", alumnos[i].codigo);
        printf("TSU: %s\n", alumnos[i].tsu);
        printf("Promedio: %.2f\n", alumnos[i].promedio);
        printf("--------------------\n");
    }
}