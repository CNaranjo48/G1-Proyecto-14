#include <iostream>
using namespace std;

struct Productos {
    // Atributos
    string nombres[12] = {"Lapiz", "Cuaderno", "Carpeta", "Esfero", "Arroz", "Pan tajado", "Pasta", "Frijol", "Acetaminofen", "Ibuprofeno", "Noxpirin", "Losartan"};
    int unidades[12] = {25, 15, 20, 50, 25, 15, 10, 8, 6, 14, 13, 9};
    float precios[12] = {1800, 3700, 4000, 1200, 2200, 5600, 5300, 5800, 1300, 4800, 2500, 2400};
    int ventas[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // M�todos
    void mostrarInfProdPape();
    void mostrarInfProdSup();
    void mostrarInfProdDro();
    void venderProducto(int indiceProducto, int cantidad);
    void abastecerProducto(int indiceProducto, int cantidad);
    void cambiarProducto(int indiceProducto);
    void calcularEstadisticas();
};

// Mostrar productos de papeler�a
void Productos::mostrarInfProdPape() {
    cout << "-----------------Informacion de Productos: Papeleria------------------------" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "- Nombre: " << nombres[i] << ", Precio: $" << precios[i] << ", Unidades: " << unidades[i] << endl;
    }
    cout << endl;
}

// Mostrar productos de supermercado
void Productos::mostrarInfProdSup() {
    cout << "-----------------Informacion de Productos: Supermercado---------------------" << endl;
    for (int i = 4; i < 8; i++) {
        cout << "- Nombre: " << nombres[i] << ", Precio: $" << precios[i] << ", Unidades: " << unidades[i] << endl;
    }
    cout << endl;
}

// Mostrar productos de droguer�a
void Productos::mostrarInfProdDro() {
    cout << "-----------------Informacion de Productos: Drogueria------------------------" << endl;
    for (int i = 8; i < 12; i++) {
        cout << "- Nombre: " << nombres[i] << ", Precio: $" << precios[i] << ", Unidades: " << unidades[i] << endl;
    }
    cout << endl;
}

// Funci�n para vender un producto
void Productos::venderProducto(int indiceProducto, int cantidad) {
    if (indiceProducto < 0 || indiceProducto >= 12) {
        cout << "Producto no encontrado.\n";
        return;
    }

    if (unidades[indiceProducto] >= cantidad) {
        unidades[indiceProducto] -= cantidad;
        ventas[indiceProducto] += cantidad;
        float totalVenta = precios[indiceProducto] * cantidad;
        cout << "Venta realizada exitosamente.\n";
        cout << "Producto: " << nombres[indiceProducto] << "\nCantidad vendida: " << cantidad << "\nTotal: $" << totalVenta << "\n";
    } else {
        cout << "No hay suficiente inventario para realizar la venta.\n";
    }
}

// Funci�n para abastecer un producto
void Productos::abastecerProducto(int indiceProducto, int cantidad) {
    if (indiceProducto < 0 || indiceProducto >= 12) {
        cout << "Producto no encontrado.\n";
        return;
    }

    unidades[indiceProducto] += cantidad;
    cout << "Producto: " << nombres[indiceProducto] << " abastecido exitosamente.\n";
    cout << "Cantidad a�adida: " << cantidad << ", Nuevas unidades: " << unidades[indiceProducto] << "\n";
}

// Funci�n para cambiar los detalles de un producto
void Productos::cambiarProducto(int indiceProducto) {
    if (indiceProducto < 0 || indiceProducto >= 12) {
        cout << "Producto no encontrado.\n";
        return;
    }

    cout << "Modificando el producto: " << nombres[indiceProducto] << "\n";
    cout << "Ingrese el nuevo nombre: ";
    cin >> nombres[indiceProducto];
    cout << "Ingrese el nuevo precio: ";
    cin >> precios[indiceProducto];
    cout << "Ingrese la nueva cantidad de unidades: ";
    cin >> unidades[indiceProducto];
    cout << "Producto actualizado correctamente.\n";
}

// Funci�n para calcular estad�sticas de ventas
void Productos::calcularEstadisticas() {
    float totalRevenue = 0;
    cout << "-----------------Estadisticas de Ventas------------------------" << endl;
    for (int i = 0; i < 12; i++) {
        float productRevenue = ventas[i] * precios[i];
        totalRevenue += productRevenue;
        cout << "- " << nombres[i] << ": Unidades vendidas: " << ventas[i] << ", Ingreso: $" << productRevenue << "\n";
    }
    cout << "Ingreso total de todas las ventas: $" << totalRevenue << "\n";
}

int main() {
    int opcMenu;
    int opcProducto, cantidad;
    Productos productos;  // Declara un solo objeto para manejar el inventario

    do {
        cout << "Seleccione una opcion:\n";
        cout << "1. Visualizar la informacion de los productos\n";
        cout << "2. Vender un producto\n";
        cout << "3. Abastecer la tienda con un producto\n";
        cout << "4. Cambiar un producto\n";
        cout << "5. Calcular estadisticas de ventas\n";
        cout << "6. Salir\n\n";
        cout << "Opcion: ";
        cin >> opcMenu;

        switch (opcMenu) {
            case 1:  // Visualizar la informaci�n de productos
                cout << "\nSeleccione la categoria de productos:\n";
                cout << "1. Papeleria\n";
                cout << "2. Supermercado\n";
                cout << "3. Droguer�a\n";
                cout << "Opcion: ";
                cin >> opcProducto;

                switch (opcProducto) {
                    case 1:
                        productos.mostrarInfProdPape();
                        break;
                    case 2:
                        productos.mostrarInfProdSup();
                        break;
                    case 3:
                        productos.mostrarInfProdDro();
                        break;
                    default:
                        cout << "Opcion no valida.\n";
                        break;
                }
                break;

            case 2:  // Vender un producto
                cout << "\nIngrese el numero del producto que desea vender (0-11): ";
                cin >> opcProducto;
                cout << "Ingrese la cantidad a vender: ";
                cin >> cantidad;
                productos.venderProducto(opcProducto, cantidad);
                break;

            case 3:  // Abastecer la tienda con un producto
                cout << "\nIngrese el numero del producto que desea abastecer (0-11): ";
                cin >> opcProducto;
                cout << "Ingrese la cantidad a a�adir: ";
                cin >> cantidad;
                productos.abastecerProducto(opcProducto, cantidad);
                break;

            case 4:  // Cambiar un producto
                cout << "\nIngrese el numero del producto que desea cambiar (0-11): ";
                cin >> opcProducto;
                productos.cambiarProducto(opcProducto);
                break;

            case 5:  // Calcular estad�sticas de ventas
                productos.calcularEstadisticas();
                break;

            case 6:  // Salir
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida. Por favor, intente nuevamente.\n";
                break;
        }
    } while (opcMenu != 6);

    return 0;
}
