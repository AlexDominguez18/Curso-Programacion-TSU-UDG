#include <iostream>

using namespace std;

int main()
{
    int area = 0;
    int base = 0;
    int altura = 0;

    cout << "Ingrese la base del triangulo: ";
    cin >> base;
    cout << "Ingrese la altura del triangulo: ";
    cin >> altura;

    area = (base * altura) / 2;
    cout << "El area es igual a: " << area << " mts cuadrados" << endl;

    return 0;
}