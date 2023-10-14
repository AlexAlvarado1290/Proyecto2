import os
import pickle
class Producto:
    def __init__(self, nombre, codigo, precio, proveedor, existencia, estado, descuento):
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
            return True
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

if __name__ == "__main__":
    cargar_productos()
    menu()
