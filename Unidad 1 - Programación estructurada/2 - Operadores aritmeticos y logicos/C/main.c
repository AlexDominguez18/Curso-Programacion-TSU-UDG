#include <stdio.h>

int main()
{
    int a = 10;
    int b = 5;

    printf("Operadores aritmeticos\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b);

    printf("\nOperadores relacionales\n");
    printf("%d == %d = %d\n", a, b, a == b);
    printf("%d != %d = %d\n", a, b, a != b);
    printf("%d > %d = %d\n", a, b, a > b);
    printf("%d < %d = %d\n", a, b, a < b);
    printf("%d >= %d = %d\n", a, b, a >= b);
    printf("%d <= %d = %d\n", a, b, a <= b);

    printf("\nOperadores logicos\n");
    printf("%d && %d = %d\n", a, b, a && b);
    printf("%d || %d = %d\n", a, b, a || b);
    printf("!%d = %d\n", a, !a);

    printf("Presiona ENTER para terminar...");
    getchar();

    return 0;
}
