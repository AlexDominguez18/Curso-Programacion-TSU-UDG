#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaramos una bandera para continuar con la repetición
    int mostrarMenu = 1;

    /**
     * La estructura de control repetitiva do-while se compone de dos partes:
     * 1. El bloque de código que se ejecutará
     * 2. La condición de continuación del ciclo
    */
    do {
        int opcion = 0;

        // Instruccion para limpiar la consola, se necesita la libreria stdlib.h
        system("clear || cls");
        printf("MENU DEL PROGRAMA\n");
        printf("1. Opcion 1\n");
        printf("2. Opcion 2\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Limpiamos el buffer del teclado porque lo siguiente a leer es un char

        // Dependiendo de la opcion seleccionada, se ejecutará un bloque de código
        switch (opcion) {
            case 1:
                printf("Selecciono la opcion 1\n");
                break;
            case 2:
                printf("Selecciono la opcion 2\n");
                break;
            case 3:
                printf("Selecciono la opcion 3, saliendo del programa...\n");
                mostrarMenu = 0;
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }

        printf("Presione enter para continuar...");
        getchar();
    } while (mostrarMenu); // La condición de continuación del ciclo es una bandera

    /**
     * El ciclo se ejecutará al menos una vez, ya que la condición se evalúa al final
     * del ciclo. En el caso anterior, mientras no seleccionemos la opcion 3, el ciclo
     * se ejecutará nuevamente.
    */
    printf("Fin del programa\n");

    return 0;
}