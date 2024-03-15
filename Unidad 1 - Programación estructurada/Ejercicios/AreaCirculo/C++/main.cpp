#include <iostream>
#include <iomanip>

#define PI 3.1416

using namespace std;

int main()
{

    float radio = 0;
    float area = 0;

    cout << "Ingrese el radio del circulo: ";
    cin >> radio;

    area = PI * (radio * radio);
    /**
     * Para imprimir el resultado con dos decimales se usa la función setprecision.
     * fixed: Indica que la notación de punto flotante se usará en forma fija.
     * setprecision(2): Indica que se mostrarán dos decimales.
    */
    cout << "El area es igual a: " << fixed << setprecision(2) << area << " mts cuadrados" << endl;
    
    return 0;
}