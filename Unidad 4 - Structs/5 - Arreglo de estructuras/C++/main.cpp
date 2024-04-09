#include <iostream>
#include <string>

#define TAMANIO_NOMBRE 50
#define CANTIDAD_ALUMNOS 5

using namespace std;

struct Alumno {
    int codigo;
    string nombre;
    float calificacion;
};

float calcularPromedio(Alumno alumnos[]);

int main()
{
    Alumno alumnos[CANTIDAD_ALUMNOS] = {
        {123, "Juan"},
        {456, "Pedro"},
        {789, "Maria"},
        {1011, "Ana"},
        {1213, "Luis"}
    };

    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        cout << "Ingrese la calificacion del alumno " << alumnos[i].nombre << ": ";
        cin >> alumnos[i].calificacion;
    }

    cout << "Promedio de calificaciones: " << calcularPromedio(alumnos) << endl;
    
    return 0;
}

float calcularPromedio(Alumno alumnos[])
{
    float suma = 0;
    for (int i = 0; i < CANTIDAD_ALUMNOS; i++) {
        suma += alumnos[i].calificacion;
    }
    return suma / CANTIDAD_ALUMNOS;
}