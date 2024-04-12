#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "operaciones.h"

typedef enum { false, true } booleano;

int elegirOpcion();

int main()
{
    int opcion;
    int a, b, resultado;
    booleano continuarPrograma = true;

    do {
        opcion = elegirOpcion();

        if (opcion == FACTORIAL) {
            printf("Ingrese un numero: ");
            scanf("%d", &a);
            limpiarBuffer();
        } else if (opcion != SALIR) {
            printf("Ingrese el primer numero: ");
            scanf("%d", &a);
            printf("Ingrese el segundo numero: ");
            scanf("%d", &b);
            limpiarBuffer();
        }


        switch (opcion) {
            case SUMA:
                resultado = suma(a, b);
                printf("%d + %d = %d\n", a, b, resultado);
                break;
            case RESTA:
                resultado = resta(a, b);
                printf("%d - %d = %d\n", a, b, resultado);
                break;
            case MULTIPLICACION:
                resultado = multiplicacion(a, b);
                printf("%d * %d = %d\n", a, b, resultado);
                break;
            case DIVISION:
                resultado = division(a, b);
                printf("%d / %d = %d\n", a, b, resultado);
                break;
            case RESIDUO:
                resultado = residuo(a, b);
                printf("%d %% %d = %d\n", a, b, resultado);
                break;
            case FACTORIAL:
                resultado = factorial(a);
                printf("%d! = %d\n", a, resultado);
                break;
            case SALIR:
                continuarPrograma = false;
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }

        if (continuarPrograma) {
            pausar("Presione una tecla para continuar...");
        }

    } while(continuarPrograma);
}

int elegirOpcion()
{
    int opcion;

    limpiarPantalla();
    printf("Calculadora\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Residuo\n");
    printf("6. Factorial\n");
    printf("7. Salir\n");
    printf("Elija una opcion: ");
    scanf("%d", &opcion);
    limpiarBuffer();

    return opcion;
}