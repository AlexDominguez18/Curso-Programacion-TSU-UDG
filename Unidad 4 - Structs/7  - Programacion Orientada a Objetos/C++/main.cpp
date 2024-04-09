#include <iostream>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    Persona(); // Constructor
    Persona(string, int); // Constructor con parámetros
    void mostrarDatos(); // Método
};

// Definición de los métodos de la clase Persona
// Se usa el nombre de la clase seguido de :: para indicar que se trata de un método de la clase
// Usamos el this-> para hacer referencia a los atributos de la clase

Persona::Persona() {
    this->nombre = "Sin nombre";
    this->edad = 0;
}

Persona::Persona(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
}

void Persona::mostrarDatos() {
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
}

int main()
{
    // Instanciamos dos objetos de la clase Persona
    Persona persona1;
    Persona persona2("Juan", 25);

    persona1.mostrarDatos();
    persona2.mostrarDatos();

    return 0;
}