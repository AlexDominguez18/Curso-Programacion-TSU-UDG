#include <iostream>

using namespace std;

int main()
{
    int opcion = 0;

    cout << "MENU" << endl;
    cout << "1. Opcion 1" << endl;
    cout << "2. Opcion 2" << endl;
    cout << "3. Opcion 3" << endl;
    cout << "Ingrese la opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1:
            cout << "Elegiste la opcion 1" << endl;
            break;
        case 2:
            cout << "Elegiste la opcion 2" << endl;
            break;
        case 3:
            cout << "Elegiste la opcion 3" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }

    cout << "Presione ENTER para terminar...";
    cin.ignore();

    return 0;
}
