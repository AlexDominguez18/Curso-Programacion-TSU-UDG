#include <iostream>

using namespace std;

// Function prototype
// The * indicates that it is a pointer to an array of characters
void saludar(char* nombre);

int main()
{
    // Function calls
    saludar("Juan");
    saludar("Maria");
    return 0;
}

// Function definition
void saludar(char* nombre)
{
   cout << "Hola " << nombre << "!" << endl;
}