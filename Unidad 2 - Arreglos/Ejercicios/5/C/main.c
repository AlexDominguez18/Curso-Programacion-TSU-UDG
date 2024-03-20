#include <stdio.h>

int main()
{
    int i;
    int multiplicando;
    int ultimoMultiplicador;

    printf("Ingrese el multiplicando: ");
    scanf("%d", &multiplicando);

    printf("Ingrese el ultimo multiplicador: ");
    scanf("%d", &ultimoMultiplicador);

    printf("Tabla de multiplicar del %d usando *for*:\n", multiplicando);
    for (i = 1; i <= ultimoMultiplicador; i++) {
        printf("%d * %d = %d\n", multiplicando, i, multiplicando * i);
    }

    getchar(); // Limpiamos el buffer del teclado
    printf("Presione enter para continuar...");
    getchar();

    printf("Tabla de multiplicar del %d usando *while*:\n", multiplicando);
    i = 1;
    while (i <= ultimoMultiplicador) {
        printf("%d * %d = %d\n", multiplicando, i, multiplicando * i);
        i++;
    }

    printf("Presione enter para continuar...");
    getchar();

    printf("Tabla de multiplicar del %d usando *do-while*:\n", multiplicando);
    i = 1;
    do {
        printf("%d * %d = %d\n", multiplicando, i, multiplicando * i);
        i++;
    } while (i <= ultimoMultiplicador);

    printf("Presione enter para terminar...");
    getchar();

    return 0;
}