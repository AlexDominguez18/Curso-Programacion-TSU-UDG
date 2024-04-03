#include <stdio.h>

int sumar(int* a, int* b);

int main()
{
    int num1 = 5;
    int num2 = 3;
    int resultado = sumar(&num1, &num2);

    printf("El resultado de la suma es: %d\n", resultado);
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    
    return 0;
}

int sumar(int* a, int* b)
{
    *a = 10; // a y b son los valores originales
    *b = 15;
    return *a + *b;
}