#include <stdio.h>

#define CALIFICACION_MINIMA 60

int main()
{
    float calificacion = 0;

    printf("Ingrese la calificacion: ");
    scanf("%f", &calificacion);

    // Si la calificacion es mayor o igual a 60, imprime "Aprobado"
    // Si la calificacion es menor a 60, no entra al if y no imprime nada
    if (calificacion >= CALIFICACION_MINIMA){
        printf("Aprobado\n");
    }

    printf("Presione ENTER para terminar...");
    getchar();

    return 0;
}