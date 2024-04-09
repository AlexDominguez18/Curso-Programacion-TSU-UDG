#include <iostream>

using namespace std;

struct Estructura {
    int a;
    float b;
};

union Union {
    int a;
    float b;
};

int main()
{
    struct Estructura s;
    union Union u;

    u.a = 10;
    u.b = 3.14;
    s.a = 20;
    s.b = 6.28;

    cout << "Tamaño de la estructura: " << sizeof(struct Estructura) << endl;
    cout << "Tamaño de la unión: " << sizeof(union Union) << endl;

    cout << "La unión tiene el mismo tamaño que el tipo de dato más grande que contiene," << endl;
    cout << "mientras que la estructura tiene el tamaño de la suma de los tamaños de sus miembros." << endl;
    
    // Imprime ambos valores de la estructura de forma correcta
    cout << "s.a: " << s.a << endl;
    cout << "s.b: " << s.b << endl;
    // Solo imprime el valor de b correctamente, ya que es el último valor asignado a la unión
    cout << "u.a: " << u.a << endl;
    cout << "u.b: " << u.b << endl;

    return 0;
}