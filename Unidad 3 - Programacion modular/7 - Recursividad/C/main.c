#include <stdio.h>

int factorial(int n);

int main()
{
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("El factorial de %d es %d\n", n, factorial(n));
    
    return 0;
}

int factorial(int n)
{   
    // Caso base
    if (n == 1) {
        return 1;
    }
    // Llamada recursiva
    return n * factorial(n - 1);
}