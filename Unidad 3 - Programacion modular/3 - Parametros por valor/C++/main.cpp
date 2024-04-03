#include <iostream>

using namespace std;

int sumar(int a, int b);

int main()
{
    int num1 = 5;
    int num2 = 3;
    int resultado = sumar(num1, num2);

    cout << "El resultado de la suma es: " << resultado << endl;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    return 0;
}

int sumar(int a, int b)
{
    a = 10; // a y b son copias de los valores que se pasaron
    b = 15; // por lo que no se modifican las variables originales
    return a + b;
}