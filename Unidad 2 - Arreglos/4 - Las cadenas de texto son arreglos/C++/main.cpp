#include <iostream>

#define TAMANIO_TEXTO 20

using namespace std;

/**
 * El siguiente ejemplo es meramente ilustrativo, ya que en C++ se pueden
 * utilizar cadenas de texto de manera más sencilla con la clase string.
 * Sin embargo, es importante entender que las cadenas de texto son arreglos
 * de caracteres.
 * Ya que aunque no se utilicen arreglos de caracteres directamente, puede
 * darse el caso de que se necesite trabajar con ellos.
*/

int main()
{
    // Definimos un arreglo de caracteres para guardar el texto
    char texto[TAMANIO_TEXTO];
    char caracter;

    cout << "Ingrese un texto: ";

    // Leemos el texto caracter por caracter y lo guardamos en el arreglo
    for (int i = 0; i < TAMANIO_TEXTO; i++) {
        cin >> caracter;
        if (caracter == '\n') {
            // Agregamos el caracter nulo al final del texto
            texto[i] = '\0';
            break;
        }
        texto[i] = caracter;
    }

    // Imprimimos el texto
    cout << "El texto ingresado es: " << texto << endl;

    // Imprimimos el texto caracter por caracter
    for (int i = 0; i < TAMANIO_TEXTO; i++) {
        if (texto[i] == '\0') {
            break;
        }
        cout << "El caracter " << i << " es: " << texto[i] << endl;
    }

    cout << "Presione enter para continuar...";
    cin.ignore();

    return 0;
}
