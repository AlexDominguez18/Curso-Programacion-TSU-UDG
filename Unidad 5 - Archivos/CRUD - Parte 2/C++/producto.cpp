#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "producto.h"
#include "util.h"

/**
 * Captura la informacion de un producto.
 *
 * @param cantidad Cantidad de productos
 */
Producto capturarProducto(int cantidad)
{
    Producto producto;

    producto.id = ++cantidad;
    std::cout << "Nombre: ";
    std::cin.getline(producto.nombre, LONGITUD_NOMBRE);
    std::cout << "Descripcion: ";
    std::cin.getline(producto.descripcion, LONGITUD_DESCRIPCION);
    std::cout << "Precio: $";
    std::cin >> producto.precio;
    limpiarBuffer();
    std::cout << "Cantidad en stock: ";
    std::cin >> producto.cantidadStock;
    limpiarBuffer();

    return producto;
}

/**
 * Captura el ID de un producto y valida que sea un valor valido.
 *
 * @param cantidad Cantidad de productos en el arreglo
 * @param titulo Titulo de la pantalla
 *
 * @return int
 */
int capturarIdProducto(Producto *productos, int cantidad, const char *titulo)
{
    int id;
    bool idValido = false;

     if (cantidad == 0) {
        std::cout << "No hay productos registrados" << std::endl;
        return 0;
    }

    do
    {
        limpiarPantalla();
        std::cout << titulo << std::endl << std::endl;
        std::cout << "Ingrese el ID del producto: ";
        std::cin >> id;
        std::cin.ignore();

        idValido = validarIdProducto(productos, id, cantidad);
        if (!idValido)
        {
            std::cout << "ID no valido" << std::endl;
            pausar("Presione ENTER para continuar...");
        }
    } while (id <= 0 || id > cantidad);

    return id;
}

/**
 * Inicializa el arreglo de productos.
 * 
 * @param productos Arreglo de productos
 * 
 * @return void
*/
void inicializarProductos(Producto *productos)
{
    for (int i = 0; i < TOTAL_PRODUCTOS; i++) {
        // Inicializa los productos con valores por defecto
        productos[i] = (Producto){0, 0, 0, "", ""};
    }
}

/**
 * Valida que el ID del producto sea valido.
 *
 * @param productos Arreglo de productos
 * @param id ID del producto
 * @param cantidad Cantidad de productos
 *
 * @return bool
 */
bool validarIdProducto(Producto *productos, int id, int cantidad)
{
    if (id <= 0 || id > cantidad) {
        return false;
    }

    for (int i = 0; i < cantidad; i++) {
        if (productos[i].id == id) {
            return true;
        }
    }

    return false;
}

/**
 * Pregunta al usuario si desea continuar con la operacion
 * indicada.
 *
 * @param mensaje Mensaje a mostrar
 *
 * @return bool
 */
bool confirmarOperacion(const char *mensaje)
{
    char respuesta;

    std::cout << mensaje << " (s/n): ";
    std::cin >> respuesta;
    std::cin.ignore();

    return respuesta == 's' || respuesta == 'S';
}

/**
 * Agrega un producto al arreglo de productos.
 *
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 *
 * @return void
 */
void agregarProducto(Producto *productos, int *cantidad)
{
    limpiarPantalla();
    std::cout << "1 - DAR DE ALTA PRODUCTO\n\n";

    productos[*cantidad] = capturarProducto(*cantidad);
    (*cantidad)++;

    std::cout << "Producto agregado corrrectamente" << std::endl;
}

/**
 * Elimina un producto del arreglo de productos.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void eliminarProducto(Producto *productos, int *cantidad)
{
    int id = capturarIdProducto(productos, *cantidad, "2 - DAR DE BAJA PRODUCTO");

    for (int i = 0; i < *cantidad; i++) {
        if (productos[i].id == id) {
            if (confirmarOperacion("¿Esta seguro de eliminar el producto?")) {
                for (int j = i; j < *cantidad - 1; j++) {
                    productos[j] = productos[j + 1];
                }
                productos[*cantidad - 1] = (Producto){0, 0, 0, "", ""};
                (*cantidad)--;
                std::cout << "Producto eliminado correctamente" << std::endl;
            }
            break;
        }
    }
}

/**
 * Imprime la informacion de un producto.
 *
 * @param producto Producto a mostrar
 *
 * @return void
 */
void imprimirProducto(Producto p)
{
    std::string cabeceras[] = {"ID", "Nombre", "Descripcion", "Precio", "Stock"};
    const int tamanioConsola = 50;
    const int tamanioMaximoCabecera = 12;

    imprimirLinea('-', tamanioConsola);
    std::cout << "| " << cabeceras[0] 
        << std::setw(tamanioMaximoCabecera - cabeceras[0].length()) << "|"
        << std::setw(tamanioConsola - 15) << p.id << "|" << std::endl;
    std::cout << "| " << cabeceras[1] 
        << std::setw(tamanioMaximoCabecera - cabeceras[1].length()) << "|"
        << std::setw(tamanioConsola - 15) << p.nombre << "|" << std::endl;
    std::cout << "| " << cabeceras[2] 
        << std::setw(tamanioMaximoCabecera - cabeceras[2].length()) << "|"
        << std::setw(tamanioConsola - 15) << p.descripcion << "|" << std::endl;
    std::cout << "| " << cabeceras[3]
        << std::setw(tamanioMaximoCabecera - cabeceras[3].length()) << "|"
        << std::setw(tamanioConsola - 15) << p.precio << "|" << std::endl;
    std::cout << "| " << cabeceras[4]
        << std::setw(tamanioMaximoCabecera - cabeceras[4].length()) << "|"
        << std::setw(tamanioConsola - 15) << p.cantidadStock << "|" << std::endl;
    imprimirLinea('-', tamanioConsola);
}   

/**
 * Muestra la informacion de un producto.
 *
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 *
 * @return void
 */
void mostrarProducto(Producto *productos, int cantidad)
{
    int id = capturarIdProducto(productos, cantidad, "3 - MOSTRAR PRODUCTO");

    for (int i = 0; i < cantidad; i++) {
        if (productos[i].id == id) {
            imprimirProducto(productos[i]);
            break;
        }
    }
}


/**
 * Lista los productos registrados.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void listarProductos(Producto* productos, int cantidad)
{
    std::string encabezadoTabla = "| ID | Nombre             | Precio |";
    const short int tamanioLinea = encabezadoTabla.length();

    limpiarPantalla();
    std::cout << "4 - LISTAR PRODUCTOS" << std::endl << std::endl;
    imprimirLinea('-', tamanioLinea);
    std::cout << encabezadoTabla << std::endl;
    imprimirLinea('-', tamanioLinea);

    for (int i = 0; i < cantidad; i++) {
        std::cout << "| " << std::setw(2) << productos[i].id << " | "
            << std::setw(18) << productos[i].nombre << " | $"
            << std::setw(6) << std::fixed << std::setprecision(2) << productos[i].precio << "|" << std::endl;
        imprimirLinea('-', tamanioLinea);
    }
}

/**
 * Edita la informacion de un producto.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void editarProducto(Producto *productos, int cantidad)
{
    int id = capturarIdProducto(productos, cantidad, "5 - EDITAR PRODUCTO");

    for (int i = 0; i < cantidad; i++) {
        if (productos[i].id != id) continue;
        if (!confirmarOperacion("¿Desea editar este producto?")) break;
        std::cout << "\nSi no desea modificar un campo presione ENTER sin ingresar nada o un 0 en el caso de los campos numericos\n\n";
        imprimirProducto(productos[i]);
        Producto producto = capturarProducto(cantidad);
        if (std::string(producto.nombre).length() > 0) strcpy(productos[i].nombre, producto.nombre);
        if (std::string(producto.descripcion).length() > 0) strcpy(productos[i].descripcion, producto.descripcion);
        if (producto.precio > 0) productos[i].precio = producto.precio;
        if (producto.cantidadStock > 0) productos[i].cantidadStock = producto.cantidadStock;
        std::cout << "Producto modificado correctamente" << std::endl;
    }
}

/**
 * Escribe los productos en un archivo secuencial.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void escribirArchivoSecuencial(Producto *productos, int cantidad)
{
    std::fstream archivo;

    archivo.open(NOMBRE_ARCHIVO_SECUENCIAL, std::ios::out);

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo" << std::endl;
        return;
    }

    archivo << cantidad << std::endl;
    for (int i = 0; i < cantidad; i++) {
        archivo << productos[i].id << SEPARADOR_CAMPOS;
        archivo << productos[i].nombre << SEPARADOR_CAMPOS;
        archivo << productos[i].descripcion << SEPARADOR_CAMPOS;
        archivo << productos[i].precio << SEPARADOR_CAMPOS;
        archivo << productos[i].cantidadStock << std::endl;
    }

    archivo.close();
}

/**
 * Lee los productos de un archivo secuencial.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void leerArchivoSecuencial(Producto *productos, int *cantidad)
{
    std::fstream archivo;

    archivo.open(NOMBRE_ARCHIVO_SECUENCIAL, std::ios::in);

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo" << std::endl;
        return;
    }

    archivo >> *cantidad;
    archivo.ignore(); // Ignora el salto de linea

    for (int i = 0; i < *cantidad; i++) {
        std::string campo;
        std::getline(archivo, campo, SEPARADOR_CAMPOS);
        productos[i].id = std::stoi(campo);
        std::getline(archivo, campo, SEPARADOR_CAMPOS);
        strcpy(productos[i].nombre, campo.c_str());
        std::getline(archivo, campo, SEPARADOR_CAMPOS);
        strcpy(productos[i].descripcion, campo.c_str());
        std::getline(archivo, campo, SEPARADOR_CAMPOS);
        productos[i].precio = std::stof(campo);
        std::getline(archivo, campo);
        productos[i].cantidadStock = std::stoi(campo);
    }
}

/**
 * Escribe los productos en un archivo aleatorio.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void escribirArchivoAleatorio(Producto *productos, int cantidad)
{
    std::fstream archivo;

    archivo.open(NOMBRE_ARCHIVO_ALEATORIO, std::ios::out | std::ios::binary);

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo" << std::endl;
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        archivo.write((char*)&productos[i], sizeof(Producto));
    }

    archivo.close();
}

/**
 * Lee los productos de un archivo aleatorio.
 * 
 * @param productos Arreglo de productos
 * @param cantidad Cantidad de productos
 * 
 * @return void
*/
void leerArchivoAleatorio(Producto *productos, int *cantidad)
{
    std::fstream archivo;

    archivo.open(NOMBRE_ARCHIVO_ALEATORIO, std::ios::in | std::ios::binary);

    if (!archivo.is_open()) {
        std::cout << "Error al abrir el archivo" << std::endl;
        return;
    }

    while (archivo.read((char*)&productos[*cantidad], sizeof(Producto))) {
        (*cantidad)++;
    }

    archivo.close();
}