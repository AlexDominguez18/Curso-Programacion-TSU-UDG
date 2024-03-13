#include <stdio.h>

// Constantes simbolicas para los meses del anio
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
    // Declaramos las variables para el dia, mes y anio
    int dia, mes, anio;
    // Declaramos una bandera para saber si la fecha es valida o no
    int esFechaValida = 0;
    // Leemos el dia, mes y anio
    printf("Dame el dia: ");
    scanf("%d", &dia);
    printf("Dame el mes: ");
    scanf("%d", &mes);
    printf("Dame el anio: ");
    scanf("%d", &anio);
    // Usamos el switch-case para agrupar los casos en los que los meses tienen 31, 30 y 28 o 29 dias
    switch (mes) {
        case ENERO:
        case MARZO:
        case MAYO:
        case JULIO:
        case AGOSTO:
        case OCTUBRE:
        case DICIEMBRE:
            // Si el dia es mayor a 0 y menor o igual a 31, la fecha es valida
            if (dia > 0  && dia <= 31) {
                esFechaValida = 1;
            }
            break;
        case FEBRERO:
            // Si el anio es bisiesto y el dia es mayor a 0 y menor o igual a 29, la fecha es valida
            if (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) {
                if (dia > 0  && dia <= 29) {
                    esFechaValida = 1;
                } 
            }
            // Si el anio no es bisiesto y el dia es mayor a 0 y menor o igual a 28, la fecha es valida
            else {
                if (dia > 0  && dia <= 28) {
                    esFechaValida = 1;
                }
            }
            break;
        case ABRIL:
        case JUNIO:
        case SEPTIEMBRE:
        case NOVIEMBRE:
            // Si el dia es mayor a 0 y menor o igual a 30, la fecha es valida
            if (dia > 0  && dia <= 30) {
                esFechaValida = 1;
            }
            break;
        default:
            // Si el mes no es valido, la fecha no es valida y nunca validamos el dia
            esFechaValida = 0;
            break;
    }

    // Imprimimos un mensaje de acuerdo a nuestra bandera
    if (esFechaValida) {
        printf("La fecha es valida\n");
    } else {
        printf("La fecha no es valida\n");
    }
    // Finalizamos el programa
    printf("Presionte ENTER para terminar...");
    getchar();

    return 0;
}