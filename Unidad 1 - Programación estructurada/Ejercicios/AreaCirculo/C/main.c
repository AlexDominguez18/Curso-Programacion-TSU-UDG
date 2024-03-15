#include <stdio.h>

#define PI 3.1416

int main()
{
    float radio = 0;
    float area = 0;

    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    area = PI * (radio * radio);
    printf("El area es igual a: %.2f mts cuadrados\n", area);
    
    return 0;
}