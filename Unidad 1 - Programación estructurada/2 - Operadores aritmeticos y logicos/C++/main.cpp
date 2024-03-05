#include <iostream>

using namespace std;

int main()
{
    int a = 9;
    int b = 3;

    cout << "Operadores aritmeticos" << endl;
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (a / b) << endl;
    cout << a << " % " << b << " = " << (a % b) << endl;

    cout << "Operadores relacionales" << endl;
    cout << a << " == " << b << " = " << (a == b) << endl;
    cout << a << " != " << b << " = " << (a != b) << endl;
    cout << a << " > " << b << " = " << (a > b) << endl;
    cout << a << " < " << b << " = " << (a < b) << endl;
    cout << a << " >= " << b << " = " << (a >= b) << endl;
    cout << a << " <= " << b << " = " << (a <= b) << endl;

    cout << "Operadores logicos" << endl;
    cout << "a && b = " << (a && b) << endl;
    cout << "a || b = " << (a || b) << endl;
    cout << "!(a) = " << !(a) << endl;

    cout << "Presiona ENTER para terminar..." << endl;
    cin.get();

    return 0;
}