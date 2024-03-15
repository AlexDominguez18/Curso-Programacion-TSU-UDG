#include <iostream>

using namespace std;

int main()
{

    int numero1, numero2;

    cout << "Ingrese el primer numero: ";
    cin >> numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> numero2;

    cout << numero1 << " + " << numero2 << " = " << numero1 + numero2 << endl;
    cout << numero1 << " - " << numero2 << " = " << numero1 - numero2 << endl;
    cout << numero2 << " - " << numero1 << " = " << numero2 - numero1 << endl;
    cout << numero1 << " * " << numero2 << " = " << numero1 * numero2 << endl;
    cout << numero1 << " / " << numero2 << " = " << numero1 / numero2 << endl;
    cout << numero2 << " / " << numero1 << " = " << numero2 / numero1 << endl;
    cout << numero1 << " % " << numero2 << " = " << numero1 % numero2 << endl;
    cout << numero2 << " % " << numero1 << " = " << numero2 % numero1 << endl;

    cin.get(); // Limpiar el buffer de teclado
    cout << "Presione una tecla para continuar...";
    cin.get();
    
    return 0;
}