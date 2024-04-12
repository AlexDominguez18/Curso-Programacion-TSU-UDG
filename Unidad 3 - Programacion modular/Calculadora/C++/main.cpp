#include <iostream>
#include <cstdlib>

#include "util.h"
#include "operaciones.h"

int elegirOpcion();

int main()
{
    int opcion;
    int a, b, resultado;
    bool continuarPrograma = true;

    do {
        opcion = elegirOpcion();

        if (opcion == FACTORIAL) {
            std::cout << "Ingrese un numero: ";
            std::cin >> a;
            limpiarBuffer();
        } else if (opcion != SALIR) {
            std::cout << "Ingrese el primer numero: ";
            std::cin >> a;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> b;
            limpiarBuffer();
        }

        switch (opcion) {
            case SUMA:
                resultado = suma(a, b);
                std::cout << a << " + " << b << " = " << resultado << std::endl;
                break;
            case RESTA:
                resultado = resta(a, b);
                std::cout << a << " - " << b << " = " << resultado << std::endl;
                break;
            case MULTIPLICACION:
                resultado = multiplicacion(a, b);
                std::cout << a << " * " << b << " = " << resultado << std::endl;
                break;
            case DIVISION:
                resultado = division(a, b);
                std::cout << a << " / " << b << " = " << resultado << std::endl;
                break;
            case RESIDUO:
                resultado = residuo(a, b);
                std::cout << a << " % " << b << " = " << resultado << std::endl;
                break;
            case FACTORIAL:
                resultado = factorial(a);
                std::cout << a << "! = " << resultado << std::endl;
                break;
            case SALIR:
                continuarPrograma = false;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                break;
        }

        if (continuarPrograma) {
            pausar("Presione una tecla para continuar...");
        }

    } while(continuarPrograma);
}

int elegirOpcion()
{
    int opcion;

    limpiarPantalla();
    std::cout << "Calculadora" << std::endl;
    std::cout << "1. Suma" << std::endl;
    std::cout << "2. Resta" << std::endl;
    std::cout << "3. Multiplicacion" << std::endl;
    std::cout << "4. Division" << std::endl;
    std::cout << "5. Residuo" << std::endl;
    std::cout << "6. Factorial" << std::endl;
    std::cout << "7. Salir" << std::endl;
    std::cout << "Elija una opcion: ";
    std::cin >> opcion;
    limpiarBuffer();

    return opcion;
}