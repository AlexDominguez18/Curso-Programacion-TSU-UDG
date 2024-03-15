#include <iostream>

using namespace std;

#define ENERO 1
#define FEBRERO 2
#define MARZO 3
#define ABRIL 4
#define MAYO 5
#define JUNIO 6
#define JULIO 7
#define AGOSTO 8
#define SEPTIEMBRE 9
#define OCTUBRE 10
#define NOVIEMBRE 11
#define DICIEMBRE 12

int main()
{
    // Declaracion de variables
    int dia, mes, anio;
    /**
     * Bandera para almacenar si la fecha es valida o no
     * En C++ contamos con un tipo de dato booleano que nos
     * permite almacenar valores de verdadero o falso.
    */
    bool esFechaValida;
    // Bandera para almacenar si el anio es bisiesto o no
    bool esAnioBisiesto;

    // Lectura de datos del usuario
    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
    cin.get(); // Limpiamos el buffer del teclado porque lo siguiente a leer es un char

    /**
     * Primero validamos el mes ya que es el dato que
     * define la cantidad de dias que puede tener un mes.
     * Para ello utilizamos un switch - case ya que es la
     * estructura de control que nos permite evaluar una
     * variable en base a una serie de casos.
    */
    switch (mes) {
        // Los siguientes meses tienen 31 dias
        case ENERO:
        case MARZO:
        case MAYO:
        case JULIO:
        case AGOSTO:
        case OCTUBRE:
        case DICIEMBRE:
            // Validamos el rango de dias con un if
            if (dia > 0 && dia <= 31) {
                esFechaValida = true;
            }
            // El break nos permite salir del switch - case
            break;
        // Febrero tiene 28 o 29 dias dependiendo del anio
        case FEBRERO:
            /**
             * Utilizamos otra bandera en la que guardaremos
             * verdadeo o falso dependiendo si el anio es bisiesto
             * o no. Un anio es bisiesto si es divisible entre 4
             * y no es divisible entre 100 pero si es divisible entre
             * 400.
            */
            esAnioBisiesto = anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0);
            if (esAnioBisiesto && (dia > 0 && dia <= 29)) {
                esFechaValida = true;
            } else if (dia > 0 && dia <= 28) {
                esFechaValida = true;
            }
            break;
        // Los siguientes meses tienen 30 dias
        case ABRIL:
        case JUNIO:
        case SEPTIEMBRE:
        case NOVIEMBRE:
            if (dia > 0 && dia <= 30) {
                esFechaValida = true;
            }
            break;
        default:
            // Si el mes no esta en el rango de 1 a 12, la fecha no es valida
            esFechaValida = false;
    }

    // Finalmente mostramos el resultado
    if (esFechaValida) {
        cout << "La fecha es valida" << endl;
    } else {
        cout << "La fecha no es valida" << endl;
    }

    cout << "Presione enter para salir...";
    cin.get();

    return 0;
}