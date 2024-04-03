#include <iostream>

using namespace std;

// Function prototype
// If a function doesn't return anything, use void (which means empty)
void saludar();

int main()
{
    // Function call
    saludar();
    return 0;
}

// Function definition
void saludar()
{
    cout << "Hola!" << endl;
}