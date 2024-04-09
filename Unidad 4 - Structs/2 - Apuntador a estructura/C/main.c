#include <stdio.h>

struct Coordenada {
    int x;
    int y;
};

int main() {
    struct Coordenada punto = {10, 20};
    struct Coordenada* puntero = &punto;

    // Operador punto
    printf("Coordenada x: %d\n", punto.x);
    printf("Coordenada y: %d\n", punto.y);

    // Operador flecha
    printf("Coordenada x: %d\n", puntero->x);
    printf("Coordenada y: %d\n", puntero->y);

    return 0;
}