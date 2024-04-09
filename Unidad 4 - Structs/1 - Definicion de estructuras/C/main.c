#include <stdio.h>

struct Coordenada {
    int x;
    int y;
};

int main()
{
    struct Coordenada punto = {10, 20};

    printf("Coordenada x: %d\n", punto.x);
    printf("Coordenada y: %d\n", punto.y);

    return 0;
}