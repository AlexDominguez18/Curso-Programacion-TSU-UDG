#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream archivo;

    archivo.open("ejemplo.txt", ios::out);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    archivo << "Hola mundo desde archivo\n";

    archivo.close();

    return 0;
}