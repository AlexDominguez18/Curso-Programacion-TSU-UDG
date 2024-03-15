#include <stdio.h>

#define TOTAL_CALIFICACIONES 5

int main()
{
    // Declaracion del arreglo
    float calificaciones[TOTAL_CALIFICACIONES];
    float promedio = 0;
    float sumaCalificaciones = 0;

    /**
     * En este caso, no inicializamos el arreglo con un ciclo, sino que leemos
     * los valores desde consola.
     * Guardamos los valores en el arreglo con un ciclo para no tener que
     * escribir N veces la misma instruccion.
    */
    for (int i = 0; i < TOTAL_CALIFICACIONES; i++) {
        printf("Ingrese la calificacion %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
    }

    // Sumamos todas las calificaciones
    for (int i = 0; i < TOTAL_CALIFICACIONES; i++) {
        sumaCalificaciones += calificaciones[i];
    }

    // Calculamos el promedio
    promedio = sumaCalificaciones / TOTAL_CALIFICACIONES;

    printf("El promedio de las calificaciones es: %.2f\n", promedio);

    getchar();
    printf("Presione ENTER para continuar...");
    getchar();

    return 0;
}