//
//  main.cpp
//  proyecto2
//
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Definición de la estructura Producto
struct Producto {
    string nombre;
    string codigo;
    double precio;
    string proveedor;
    int existencia;
    char estado;
    double descuento;
};

// Procedimiento para agregar un producto
void agregarProducto(vector<Producto> &productos) {
    Producto nuevoProducto;

    cout << "Nombre: ";
    cin >> nuevoProducto.nombre;
    cout << "Código: ";
    cin >> nuevoProducto.codigo;
    cout << "Precio: ";
    cin >> nuevoProducto.precio;
    cout << "Proveedor: ";
    cin >> nuevoProducto.proveedor;
    cout << "Existencia: ";
    cin >> nuevoProducto.existencia;
    cout << "Estado (A = Aprobado, R = Reprobado): ";
    cin >> nuevoProducto.estado;
    cout << "Descuento: ";
    cin >> nuevoProducto.descuento;

    productos.push_back(nuevoProducto);

    // Guardar en el archivo
    ofstream archivo("productos.txt", ios::app);
    archivo << nuevoProducto.nombre << " " << nuevoProducto.codigo << " " << nuevoProducto.precio << " "
            << nuevoProducto.proveedor << " " << nuevoProducto.existencia << " " << nuevoProducto.estado << " "
            << nuevoProducto.descuento << "\n";
    archivo.close();

    cout << "Producto agregado con éxito.\n";
}

// Procedimiento para buscar un producto
void buscarProducto(const vector<Producto> &productos) {
    string codigoBusqueda;
    cout << "Ingrese el código del producto a buscar: ";
    cin >> codigoBusqueda;

    for (const auto &producto : productos) {
        if (producto.codigo == codigoBusqueda) {
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Código: " << producto.codigo << endl;
            cout << "Precio: " << producto.precio << endl;
            cout << "Proveedor: " << producto.proveedor << endl;
            cout << "Existencia: " << producto.existencia << endl;
            cout << "Estado: " << producto.estado << endl;
            cout << "Descuento: " << producto.descuento << endl;

            return;
        }
    }

    cout << "Producto no encontrado.\n";
}

// Procedimiento para modificar un producto
void modificarProducto(vector<Producto> &productos) {
    string codigoModificacion;
    cout << "Ingrese el código del producto a modificar: ";
    cin >> codigoModificacion;

    for (auto &producto : productos) {
        if (producto.codigo == codigoModificacion) {
            cout << "Nuevo Precio: ";
            cin >> producto.precio;
            cout << "Nueva Existencia: ";
            cin >> producto.existencia;
            cout << "Nuevo Estado (A = Aprobado, R = Reprobado): ";
            cin >> producto.estado;
            cout << "Nuevo Descuento: ";
            cin >> producto.descuento;

            // Actualizar en el archivo
            ofstream archivo("productos.txt");
            for (const auto &p : productos) {
                archivo << p.nombre << " " << p.codigo << " " << p.precio << " "
                        << p.proveedor << " " << p.existencia << " " << p.estado << " "
                        << p.descuento << "\n";
            }
            archivo.close();

            cout << "Producto modificado con éxito.\n";
            return;
        }
    }

    cout << "Producto no encontrado.\n";
}

// Función principal
int main() {
    vector<Producto> productos;

    // Leer el archivo si existe
    ifstream archivo("productos.txt");
    if (archivo.is_open()) {
        while (!archivo.eof()) {
            Producto p;
            archivo >> p.nombre >> p.codigo >> p.precio >> p.proveedor >> p.existencia >> p.estado >> p.descuento;
            productos.push_back(p);
        }
        archivo.close();
    }

    int opcion;
    do {
        cout << "\n=== Menú de Productos ===\n";
        cout << "1. Agregar Producto\n";
        cout << "2. Buscar Producto\n";
        cout << "3. Modificar Producto\n";
        cout << "0. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto(productos);
                break;
            case 2:
                buscarProducto(productos);
                break;
            case 3:
                modificarProducto(productos);
                break;
            case 0:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}