#include <stdio.h>

int main()
{
    int i;
    int numeroPersonas = 0;
    float sumaEstaturas = 0;
    float promedioEstaturas = 0;

    // Leemos el numero de personas
    printf("Ingrese el numero de personas: ");
    scanf("%d", &numeroPersonas);

    // Creamos un arreglo de estaturas en base al numero de personas
    float estaturas[numeroPersonas];
    
    // Leemos las estaturas de las personas
    for (i = 0; i < numeroPersonas; i++) {
        printf("Ingrese la estatura de la persona %d: ", i + 1);
        scanf("%f", &estaturas[i]);
    }

    // Sumamos las estaturas de las personas
    for (i = 0; i < numeroPersonas; i++) {
        sumaEstaturas += estaturas[i];
    }

    // Calculamos el promedio de estaturas
    promedioEstaturas = sumaEstaturas / numeroPersonas;

    printf("El promedio de estaturas es: %.2f\n", promedioEstaturas);

    getchar(); // Limpiamos el buffer del teclado
    printf("Presione enter para terminar...");
    getchar();

    return 0;
}