#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i;
    int numeroPersonas = 0;
    float sumaEstaturas = 0;
    float promedioEstaturas = 0;

    // Leemos el numero de personas
    cout << "Ingrese el numero de personas: ";
    cin >> numeroPersonas;

    // Creamos un arreglo de estaturas en base al numero de personas
    float estaturas[numeroPersonas];
    
    // Leemos las estaturas de las personas
    for (i = 0; i < numeroPersonas; i++) {
        cout << "Ingrese la estatura de la persona " << i + 1 << ": ";
        cin >> estaturas[i];
    }

    // Sumamos las estaturas de las personas
    for (i = 0; i < numeroPersonas; i++) {
        sumaEstaturas += estaturas[i];
    }

    // Calculamos el promedio de estaturas
    promedioEstaturas = sumaEstaturas / numeroPersonas;

    cout << "El promedio de estaturas es: " << fixed << setprecision(2) << promedioEstaturas << endl;

    cin.ignore(); // Limpiamos el buffer del teclado
    cout << "Presione enter para terminar...";
    cin.get();

    return 0;
}