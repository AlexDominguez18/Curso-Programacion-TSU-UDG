#include <stdio.h>

struct Estructura
{
    int a;
    float b;
};

union Union
{
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

    printf("Tamanio de la estructura: %d bytes\n", sizeof(struct Estructura));
    printf("Tamanio de la union: %d bytes\n", sizeof(union Union));

    printf("%s\n%s\n",
           "La union tiene el mismo tamanio que el tipo de dato mas grande que contiene,",
           "mientras que la estructura tiene el tamanio de la suma de los tamanios de sus miembros.)");

    // Imprime ambos valores de la estructura de forma correcta
    printf("s.a: %d\n", s.a);
    printf("s.b: %f\n", s.b);
    // Solo imprime el valor de b correctamente, ya que es el último valor asignado a la unión
    printf("u.a: %d\n", u.a);
    printf("u.b: %f\n", u.b);

    return 0;
}