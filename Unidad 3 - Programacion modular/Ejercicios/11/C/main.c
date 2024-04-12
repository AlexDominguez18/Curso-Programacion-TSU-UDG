#include <stdio.h>
#include <stdlib.h>

#define RECURSIVO 1
#define ITERATIVO 2
#define SALIR 3

typedef enum { false, true } booleano;

int elegirOpcion();
int leerNumero();
int factorialRecursivo(int n);
int factorialIterativo(int n);

int main()
{
    int n;
    booleano continuarPrograma = true;

    do {
        switch (elegirOpcion()) {
        case RECURSIVO:
            n = leerNumero();
            printf("El factorial de %d es %d\n", n, factorialRecursivo(n));
            break;
        case ITERATIVO:
            n = leerNumero();
            printf("El factorial de %d es %d\n", n, factorialIterativo(n));
            break;
        case SALIR:
            continuarPrograma = false;
            break;
        default:
            break;
        }
        getchar();
        printf("Presione una tecla para continuar...");
        getchar();
    } while (continuarPrograma);
    
    return 0;
}

int leerNumer()
{
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    return n;
}

int leerNumero()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    return numero;
}

int elegirOpcion()
{
    int opcion;
    system("cls || clear");
    printf("Menu\n");
    printf("1. Factorial recursivo\n");
    printf("2. Factorial iterativo\n");
    printf("3. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int factorialRecursivo(int n)
{
    if (n == 0) return 1;

    return n * factorialRecursivo(n - 1);
}

int factorialIterativo(int n)
{
    int resultado = n;
    
    while (n > 1) {
        resultado *= --n;
    }

    return resultado;
}