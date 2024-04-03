#include <iostream>

int sumar(int& a, int& b);

int main()
{
    int num1 = 5;
    int num2 = 3;
    int resultado = sumar(num1, num2);

    std::cout << "El resultado de la suma es: " << resultado << std::endl;
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;
    
    return 0;
}

int sumar(int& a, int& b)
{
    a = 10; // a y b son los valores originales
    b = 15;

    return a + b;
}