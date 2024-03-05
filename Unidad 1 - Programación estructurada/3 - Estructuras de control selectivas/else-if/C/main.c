#include <stdio.h>

#define CALIFICACION_MINIMA 60
#define CALIFICACION_BUENA 80

int main()
{
    float calificacion = 0;

    printf("Ingrese la calificacion: ");
    scanf("%f", &calificacion);

    // Si la calificacion es mayor o igual a 80, imprime "Excelente!"
    // Si la calificacion es mayor o igual a 60, imprime "Aprobado"
    // Si la calificacion no entra e ninguna condicion, entra al else y imprime "Reprobado"
    
    if (calificacion >= CALIFICACION_BUENA){
        printf("Excelente!\n");
    } else if (calificacion >= CALIFICACION_MINIMA) {
        printf("Aprobado\n");
    } else {
        printf("Reprobado\n");
    }

    printf("Presione ENTER para terminar...");
    getchar();

    return 0;
}