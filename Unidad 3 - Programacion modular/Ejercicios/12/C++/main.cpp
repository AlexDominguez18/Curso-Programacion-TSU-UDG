#include <iostream>

#define RECURSIVO 1
#define ITERATIVO 2
#define SALIR 3

using namespace std;

int elegirOpcion();
int leerNumero();
int fibonacciRecursivo(int n);
int fibonacciIterativo(int n);

int main()
{
    int n;
    int resultado;
    bool continuarPrograma = true;

    do {
        switch (elegirOpcion()) {
        case RECURSIVO:
            n = leerNumero();
            resultado = fibonacciRecursivo(n);
            cout << "El resultado de la serie de fibonacci recursiva hasta la posicion " << n << " es: " << resultado << endl;
            break;
        case ITERATIVO:
            n = leerNumero();
            resultado = fibonacciIterativo(n);
            cout << "El resultado de la serie de fibonacci iterativa hasta la posicion " << n << " es: " << resultado << endl;
            break;
        case SALIR:
            continuarPrograma = false;
            break;
        default:
            break;
        }
        cout << "Presione una tecla para continuar...";
        cin.get();
        cin.get();
    } while(continuarPrograma);

    return 0;
}

int leerNumero()
{
    int numero;
    cout << "Ingrese hasta que posicion de la serie de fibonacci desea obtener: ";
    cin >> numero;
    return numero;
}

int elegirOpcion()
{
    int opcion;
    system("cls || clear");
    cout << "Menu" << endl;
    cout << "1. Fibonacci recursivo" << endl;
    cout << "2. Fibonacci iterativo" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}

/**
 * Teniendo los casos base, podemos decir que la serie de fibonacci
 * para cualquier n es la suma de los dos numeros anteriores.
 * 
 * Por lo que la ultima llamada recursiva seria:
 * 0 + 1 = 1
 * Luego con esos valores se obtiene el siguiente:
 * 1 + 1 = 2
 * Y asi sucesivamente.
 * 2 + 1 = 3
 * 3 + 2 = 5
 * 5 + 3 = 8
 * ...
 * Etc.
 * 
 * El uso recursivo de esta funcion es muy ineficiente, ya que se
 * hacen muchas llamadas a la funcion con los mismos valores.
 * 
*/
int fibonacciRecursivo(int n)
{
    // Casos base
    if (n == 0) return 0;
    if (n == 1) return 1;

    // F(n) = F(n-1) + F(n-2)
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

/**
 * La version iterativa de la serie de fibonacci es mucho mas eficiente
 * que la version recursiva, ya que no se hacen llamadas a la funcion
 * con los mismos valores.
 * 
 * El uso de un ciclo y dos variables para almacenar los valores anteriores
 * es suficiente para obtener el resultado de la serie de fibonacci y no 
 * se llena la pila de llamadas de funciones.
*/
int fibonacciIterativo(int n)
{
    // Variables inicializadas con los primeros valores de la serie
    int fn1 = 0;
    int fn2 = 1;
    int fn = 1;

    // Empezamos desde 2 ya que los primeros dos valores son 0 y 1
    for (int i = 2; i <= n; i++) {
        // F(n) = F(n-1) + F(n-2)
        fn = fn1 + fn2;
        // Actualizamos los valores anteriores
        fn1 = fn2;
        fn2 = fn;
    }

    return fn;
}