#include <iostream>

using namespace std;

int factorial(int n);

int main()
{
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    cout << "El factorial de " << n << " es " << factorial(n) << endl;
    
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