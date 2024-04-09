#include <iostream>

using namespace std;

struct Coordenada {
    int x;
    int y;
};

int main()
{
    // Aqui no hace falta poner struct Coordenada punto; como en C
    Coordenada punto = { 10, 20};

    cout << "Coordenada x: " << punto.x << endl;
    cout << "Coordenada y: " << punto.y << endl;

    return 0;
}