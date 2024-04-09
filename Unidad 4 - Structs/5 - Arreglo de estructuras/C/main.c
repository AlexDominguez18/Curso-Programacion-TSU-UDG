#include <stdio.h>

#define TAMANIO_NOMBRE 50
#define CANTIDAD_ALUMNOS 5

typedef struct {
    int codigo;
    char nombre[TAMANIO_NOMBRE];
    float calificacion;
} Alumno;

float calcularPromedio(Alumno alumnos[]);

int main()
{
    Alumno alumnos[CANTIDAD_ALUMNOS] = {
        {123, "Juan"},
        {456, "Pedro"},
        {789, "Maria"},
        {1011, "Ana"},
        {1213, "Luis"}
    };

    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        printf("Ingrese la calificacion del alumno %s: ", alumnos[i].nombre);
        scanf("%f", &alumnos[i].calificacion);
    }

    printf("Promedio de calificaciones: %.2f\n", calcularPromedio(alumnos));
    
    return 0;
}

float calcularPromedio(Alumno alumnos[])
{
    float suma = 0;
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        suma += alumnos[i].calificacion;
    }
    return suma / CANTIDAD_ALUMNOS;
}