#include <stdio.h>

int main()
{
    int opcion = 0;

    printf("MENU\n");
    printf("1. Opcion 1\n");
    printf("2. Opcion 2\n");
    printf("3. Opcion 3\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &opcion);
    getchar();

    switch (opcion) {
        case 1:
            printf("Elegiste la opcion 1\n");
            break;
        case 2:
            printf("Elegiste la opcion 2\n");
            break;
        case 3:
            printf("Elegiste la opcion 3\n");
            break;
        default:
            printf("Opcion invalida\n");
            break;
    }

    printf("Presione ENTER para terminar...");
    getchar();

    return 0;
}