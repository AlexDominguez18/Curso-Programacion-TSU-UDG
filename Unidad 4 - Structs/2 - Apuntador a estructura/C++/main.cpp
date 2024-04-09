#include <iostream>

using namespace std;

struct Coordenada {
    int x;
    int y;
};

int main()
{
    Coordenada punto = { 10, 20};
    Coordenada* puntero = &punto;

    // Operador punto
    cout << "Coordenada x: " << punto.x << endl;
    cout << "Coordenada y: " << punto.y << endl;
    
    // Operador flecha
    cout << "Coordenada x: " << puntero->x << endl;
    cout << "Coordenada y: " << puntero->y << endl;

    return 0;
}