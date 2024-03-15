#include <stdio.h>

int main()
{
    int numero1, numero2;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numero2);

    printf("%d + %d = %d\n", numero1, numero2, numero1 + numero2);
    printf("%d - %d = %d\n", numero1, numero2, numero1 - numero2);
    printf("%d - %d = %d\n", numero2, numero1, numero2 - numero1);
    printf("%d * %d = %d\n", numero1, numero2, numero1 * numero2);
    printf("%d / %d = %d\n", numero1, numero2, numero1 / numero2);
    printf("%d / %d = %d\n", numero1, numero2, numero2 / numero1);
    printf("%d %% %d = %d\n", numero1, numero2, numero1 % numero2);
    printf("%d %% %d = %d\n", numero2, numero1, numero2 % numero1);

    getchar();
    printf("Presione una tecla para continuar...");
    getchar();
    
    return 0;
}