#include <stdio.h>

int main()
{
    int area = 0;
    int base = 0;
    int altura = 0;

    printf("Ingrese la base del triangulo: ");
    scanf("%d", &base);
    printf("Ingrese la altura del triangulo: ");
    scanf("%d", &altura);

    area = (base * altura) / 2;
    printf("El area es igual a: %d mts cuadrados\n", area);

    return 0;
}