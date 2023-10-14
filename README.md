# Proyecto 2 Algoritmos

## Presentado por:
### Bryan Josue Alvarez Lopez, Julio Alexander Alvarado Morales y Jonathan Joel Istupe Martinez
###### Bryan Alvarez: 7690-23-16816
###### Julio Alvarado: 7690-23-13706
###### Jonathan Istupe: 7690-23-15804

## Algoritmo
Es un proyecto de Algoritmos el cual vamos a usar la libreria fstream para leer o escribir archivos usando C++ y Python
Al iniciar la aplicación debe mostrar un menú que contenga las siguientes opciones

###### Agregar producto
###### Buscar a un producto
###### Modificar los datos de un producto
###### Cada opción del menú debe tener las siguientes limitantes

Agregar producto: el código de producto no debe repetirse
Buscar producto: se debe buscar por el código, o por el nombre. Para el segundo caso debe se
debe realizar la función contiene, por lo que si el usuario ingresa solo una palabra mostrará
todos los productos que contengan dicha palabra en su nombre
Modificar datos: el código no puede modificarse, los otros atributos si

# Video acerca de nuestro tema
## https://youtu.be/rJ_7n8Wamew

## C++ 
```cpp
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
    //parametros
};

// Función para agregar un producto
void agregarProducto(vector<Producto>& productos) {
    Producto nuevoProducto;

    cout << "Nombre: ";
    cin >> nuevoProducto.nombre;
    cout << "Codigo: ";
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
    /// no retornan nada a la consola porque son procedimientos

    productos.push_back(nuevoProducto);

    // Guardar en el archivo
    ofstream archivo("productos.txt", ios::app);
    archivo << nuevoProducto.nombre << " " << nuevoProducto.codigo << " " << nuevoProducto.precio << " "
        << nuevoProducto.proveedor << " " << nuevoProducto.existencia << " " << nuevoProducto.estado << " "
        << nuevoProducto.descuento << "\n"; /// parametros
    archivo.close();// cierra el archivo

    cout << "Producto agregado con exito.\n";
}

// Función para buscar un producto
void buscarProducto(const vector<Producto>& productos) {   /// un verctor procucto guarda todos los productos, lo busca y si esta  lo muestra, y si no esta da producto no encontrado
    string codigoBusqueda;
    cout << "Ingrese el codigo del producto a buscar: ";
    cin >> codigoBusqueda;  /// funcion buscar 

    for (const auto& producto : productos) {
        if (producto.codigo == codigoBusqueda) {
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Codigo: " << producto.codigo << endl;
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

// Función para modificar un producto
void modificarProducto(vector<Producto>& productos) {
    string codigoModificacion;
    cout << "Ingrese el codigo del producto a modificar: ";
    cin >> codigoModificacion;

    for (auto& producto : productos) {
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
            for (const auto& p : productos) {
                archivo << p.nombre << " " << p.codigo << " " << p.precio << " "
                    << p.proveedor << " " << p.existencia << " " << p.estado << " "
                    << p.descuento << "\n";
            }
            archivo.close();

            cout << "Producto modificado con exito.\n";
            return;
        }
    }

    cout << "Producto no encontrado.\n";
}

// Función principal
int main() {  /// retorna un un vector, llee el archivo , 
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

    int opcion; ///  esta hechon con un do while, porque entrar por lo menos iunas ves.
    do {
        cout << "\n=== Menu de Productos ===\n";
        cout << "1. Agregar Producto\n";
        cout << "2. Buscar Producto\n";
        cout << "3. Modificar Producto\n";
        cout << "0. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {  ///  en swhic da las funciones que puede buscar, agregar o modificar, 
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
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
```
## Python 
```python
import os
class Producto:
    def _init_(self, nombre, codigo, precio, proveedor, existencia, estado, descuento):
        self.nombre = nombre
        self.codigo = codigo
        self.precio = precio
        self.proveedor = proveedor
        self.existencia = existencia
        self.estado = estado
        self.descuento = descuento

productos = []
archivo = "productos.txt"

# Función para verificar si un producto con un código ya existe
def producto_existe(codigo):
    for producto in productos:
        if producto.codigo == codigo:
            return True1
    return False
# Función para agregar un producto
def agregar_producto():
    codigo = input("Ingrese el código del producto: ")
    if producto_existe(codigo):
        print("¡El producto ya existe!")
    else:
        nombre = input("Nombre del producto: ")
        precio = float(input("Precio del producto: "))
        proveedor = input("Proveedor: ")
        existencia = int(input("Existencia: "))
        estado = input("Estado (A = Aprobado, R = Reprobado): ").upper()
        descuento = float(input("Descuento: "))

        producto = Producto(nombre, codigo, precio, proveedor, existencia, estado, descuento)
        productos.append(producto)
        guardar_productos()
        print("Producto agregado con éxito.")

# Función para buscar un producto
def buscar_producto():
    termino = input("Ingrese el código o parte del nombre del producto que desea buscar: ")
    resultados = []
    for producto in productos:
        if termino in producto.codigo or termino in producto.nombre:
            resultados.append(producto)
    if resultados:
        print("Resultados de la búsqueda:")
        for producto in resultados:
            print(f"Código: {producto.codigo}, Nombre: {producto.nombre}")
    else:
        print("No se encontraron resultados.")

# Función para modificar los datos de un producto
def modificar_producto():
    codigo = input("Ingrese el código del producto que desea modificar: ")
    for producto in productos:
        if producto.codigo == codigo:
            print("Modificar producto:")
            producto.precio = float(input(f"Nuevo precio ({producto.precio}): ") or producto.precio)
            producto.proveedor = input(f"Nuevo proveedor ({producto.proveedor}): ") or producto.proveedor
            producto.existencia = int(input(f"Nueva existencia ({producto.existencia}): ") or producto.existencia)
            nuevo_estado = input(f"Nuevo estado (A = Aprobado, R = Reprobado) ({producto.estado}): ").upper()
            if nuevo_estado in ['A', 'R']:
                producto.estado = nuevo_estado
            producto.descuento = float(input(f"Nuevo descuento ({producto.descuento}): ") or producto.descuento)
            guardar_productos()
            print("Producto modificado con éxito.")
            return
    print("Producto no encontrado.")

# Función para guardar los productos en un archivo
def guardar_productos():
    with open(archivo, 'wb') as f:
        pickle.dump(productos, f)

# Función para cargar los productos desde un archivo
def cargar_productos():
    if os.path.exists(archivo):
        with open(archivo, 'rb') as f:
            productos.extend(pickle.load(f))

# Función para mostrar el menú
def menu():
    while True:
        print("\nMenú:")
        print("1. Agregar producto")
        print("2. Buscar producto")
        print("3. Modificar datos de un producto")
        print("4. Salir")
        opcion = input("Seleccione una opción: ")
        if opcion == "1":
            agregar_producto()
        elif opcion == "2":
            buscar_producto()
        elif opcion == "3":
            modificar_producto()
        elif opcion == "4":
            guardar_productos()
            break
        else:
            print("Opción no válida. Inténtelo de nuevo.")

if _name_ == "_main_":
    cargar_productos()
    menu()
```

## Gracias por su atencion
## Saludos

