#include <iostream>

using namespace std;

int encontrarMenor(int* numeros, int cantidadNumeros);

int main()
{
    // Create a pointer to an array of integers
    int* numeros;
    int cantidadNumeros;
    int menor;

    cout << "Ingrese la cantidad de numeros: ";
    cin >> cantidadNumeros;

    numeros = new int[cantidadNumeros];

    // Ask the user for the numbers
    for (int i = 0; i < cantidadNumeros; i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    for (int i = 0; i < cantidadNumeros; i++) {
        cout << "Numero " << i + 1 << ": " << numeros[i] << endl;
    }

    // Call the function to find the smallest number
    menor = encontrarMenor(numeros, cantidadNumeros);

    cout << "El menor numero es: " << menor << endl;

    free(numeros);

    return 0;
}

int encontrarMenor(int* numeros, int cantidadNumeros)
{
    // Assume the smallest number is the first element of the array
    int menor = numeros[0];
   
    // Iterate through the array to find the smallest number
    for (int i = 1; i < cantidadNumeros; i++) {
        // If the current number is smaller than the current smallest, update the smallest
        if (numeros[i] < menor){
            menor = numeros[i];
        }
    }

    return menor;
}