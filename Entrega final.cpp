#include <iostream>
using namespace std;

struct Productos {
    // Atributos
    string nombres[12] = {"1-Lapiz", "2-Cuaderno", "3-Carpeta", "4-Esfero", "1-Arroz", "2-Pan tajado", "3-Pasta", "4-Frijol", "1-Acetaminofen", "2-Ibuprofeno", "3-Noxpirin", "4-Losartan"};
    int unidades[12] = {25, 15, 20, 50, 25, 15, 10, 8, 6, 14, 13, 9};
    int precios[12] = {1800, 3700, 4000, 1200, 2200, 5600, 5300, 5800, 1300, 4800, 2500, 2400};
    int ventas[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // M�todos
    string mostrarInfProdPape();
    string mostrarInfProdSup();
    string mostrarInfProdDro();
    string venderProducto(int indiceProducto, int cantidad);
    string abastecerProducto(int indiceProducto, int indiceNuevoProducto, int cantidad);
    string cambiarProducto(int indiceProducto);
    string calcularEstadisticas();
};

// Mostrar productos de papeler�a
string Productos::mostrarInfProdPape() {
    string result = "-----------------Informacion de Productos: Papeleria------------------------\n";
    for (int i = 0; i < 4; i++) {
        result += nombres[i] + ", Precio: $" + to_string(precios[i]) + ", Unidades: " + to_string(unidades[i]) + "\n";
    }
    result += "\n";
    return result;
}

// Mostrar productos de supermercado
string Productos::mostrarInfProdSup() {
    string result = "-----------------Informacion de Productos: Supermercado---------------------\n";
    for (int i = 4; i < 8; i++) {
        result += nombres[i] + ", Precio: $" + to_string(precios[i]) + ", Unidades: " + to_string(unidades[i]) + "\n";
    }
    result += "\n";
    return result;
}

// Mostrar productos de droguer�a
string Productos::mostrarInfProdDro() {
    string result = "-----------------Informacion de Productos: Drogueria------------------------\n";
    for (int i = 8; i < 12; i++) {
        result += nombres[i] + ", Precio: $" + to_string(precios[i]) + ", Unidades: " + to_string(unidades[i]) + "\n";
    }
    result += "\n";
    return result;
}

// Funci�n para vender un producto
string Productos::venderProducto(int indiceProducto, int cantidad) {
    if (indiceProducto < 0 || indiceProducto >= 12) {
        return "Producto no encontrado.\n";
    }

    if (unidades[indiceProducto] >= cantidad) {
        unidades[indiceProducto] -= cantidad;
        ventas[indiceProducto] += cantidad;
        float totalVenta = precios[indiceProducto] * cantidad;
        return "Venta realizada exitosamente.\nProducto: " + nombres[indiceProducto] + "\nCantidad vendida: " + to_string(cantidad) + "\nTotal: $" + to_string(totalVenta) + "\n";
    } else {
        return "No hay suficiente inventario para realizar la venta.\n";
    }
}

// Funci�n para abastecer un producto (reemplazando un producto por otro)
string Productos::abastecerProducto(int indiceProducto, int indiceNuevoProducto, int cantidad) {
    if (indiceProducto < 0 || indiceProducto >= 12 || indiceNuevoProducto < 0 || indiceNuevoProducto >= 12) {
        return "Producto no encontrado.\n";
    }

    // Reemplazamos el producto original por el nuevo
    nombres[indiceProducto] = nombres[indiceNuevoProducto];
    precios[indiceProducto] = precios[indiceNuevoProducto];
    unidades[indiceProducto] = cantidad;  // Actualizamos la cantidad

    return "Producto reemplazado exitosamente. El producto " + nombres[indiceProducto] + " ahora tiene " + to_string(cantidad) + " unidades.\n";
}

// Funci�n para cambiar los detalles de un producto
string Productos::cambiarProducto(int indiceProducto) {
    if (indiceProducto < 0 || indiceProducto >= 12) {
        return "Producto no encontrado.\n";
    }

    cout << "Modificando el producto: " << nombres[indiceProducto] << "\n";
    cout << "Ingrese el nuevo nombre: ";
    cin >> nombres[indiceProducto];
    cout << "Ingrese el nuevo precio: ";
    cin >> precios[indiceProducto];
    cout << "Ingrese la nueva cantidad de unidades: ";
    cin >> unidades[indiceProducto];
    return "Producto actualizado correctamente.\n";
}

// Funci�n para calcular estad�sticas de ventas
string Productos::calcularEstadisticas() {
    float totalRevenue = 0;
    string result = "-----------------Estadisticas de Ventas------------------------\n";
    for (int i = 0; i < 12; i++) {
        float productRevenue = ventas[i] * precios[i];
        totalRevenue += productRevenue;
        result += "- " + nombres[i] + ": Unidades vendidas: " + to_string(ventas[i]) + ", Ingreso: $" + to_string(productRevenue) + "\n";
    }
    result += "Ingreso total de todas las ventas: $" + to_string(totalRevenue) + "\n";
    return result;
}

int leerNumero(const string& mensaje) {
    string entrada;
    int numero;

    while (true) {
        cout << mensaje;
        cin >> entrada;

        // Validar si la entrada contiene solo d�gitos
        bool esNumero = true;
        for (char c : entrada) {
            if (c < '0' || c > '9') { // Si no es un d�gito
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            // Convertir la cadena a n�mero
            numero = 0;
            for (char c : entrada) {
                numero = numero * 10 + (c - '0'); // Conversi�n de car�cter a d�gito
            }
            return numero; // Retorna el n�mero v�lido
        } else {
            cout << "Entrada inv�lida. Por favor, ingrese un n�mero.\n";
        }
    }
}


int main() {
    int opcMenu;
    int opcProducto, cantidad, indiceNuevoProducto;
    Productos productos;  // Declara un solo objeto para manejar el inventario

    do {
        cout << "Seleccione una opcion:\n";
        cout << "1. Visualizar la informacion de los productos\n";
        cout << "2. Vender un producto\n";
        cout << "3. Abastecer la tienda con un producto\n";
        cout << "4. Cambiar un producto\n";
        cout << "5. Calcular estadisticas de ventas\n";
        cout << "6. Salir\n\n";
        opcMenu = leerNumero("Opcion: ");
        
        switch (opcMenu) {
            case 1:  // Visualizar la informaci�n de productos
                cout << "\nSeleccione la categoria de productos:\n";
                cout << "1. Papeleria\n";
                cout << "2. Supermercado\n";
                cout << "3. Droguer�a\n";
                opcProducto = leerNumero("Opcion: ");
                
                switch (opcProducto) {
                    case 1:
                        cout << productos.mostrarInfProdPape();
                        break;
                    case 2:
                        cout << productos.mostrarInfProdSup();
                        break;
                    case 3:
                        cout << productos.mostrarInfProdDro();
                        break;
                    default:
                        cout << "Opcion no valida.\n";
                        break;
                }
                break;

            case 2:  // Vender un producto
                opcProducto = leerNumero("\nIngrese el numero del producto que desea vender (1-4): ");
                cantidad = leerNumero("\nIngrese la cantidad a vender: ");
                cout << productos.venderProducto(opcProducto, cantidad);
                break;

            case 3:  // Abastecer la tienda con un producto
                cout << "Que producto desea abastecer\n";
                cout << "1. Papeleria\n";
                cout << "2. Supermercado\n";
                cout << "3. Droguer�a\n";
                opcProducto = leerNumero("Opcion: ");

                switch (opcProducto) {
                    case 1:
                        cout << productos.mostrarInfProdPape();
                        opcProducto = leerNumero("\nIngrese el numero del producto que desea reemplazar (1-4): ");
                        indiceNuevoProducto = leerNumero("\nIngrese el numero del nuevo producto que reemplazara el anterior (1-4): ");
                        cantidad = leerNumero("\nIngrese la cantidad de unidades para el nuevo producto: ");
                        cout << productos.abastecerProducto(opcProducto, indiceNuevoProducto, cantidad);
                        break;
                    case 2:
                        cout << productos.mostrarInfProdSup();
                        opcProducto = leerNumero("\nIngrese el numero del producto que desea reemplazar (1-4): ");
                        indiceNuevoProducto = leerNumero("\nIngrese el numero del nuevo producto que reemplazara el anterior (1-4): ");
                        cantidad = leerNumero("\nIngrese la cantidad de unidades para el nuevo producto: ");
                        cout << productos.abastecerProducto(opcProducto, indiceNuevoProducto, cantidad);
                        break;
                    case 3:
                        cout << productos.mostrarInfProdDro();
                        opcProducto = leerNumero("\nIngrese el numero del producto que desea reemplazar (1-4): ");
                        indiceNuevoProducto = leerNumero("\nIngrese el numero del nuevo producto que reemplazara el anterior (1-4): ");
                        cantidad = leerNumero("\nIngrese la cantidad de unidades para el nuevo producto: ");
                        cout << productos.abastecerProducto(opcProducto, indiceNuevoProducto, cantidad);
                        break;
                    default:
                        cout << "Opcion no valida.\n";
                        break;
                }
                break;

            case 4:  // Cambiar un producto
                opcProducto = leerNumero("\nIngrese el numero del producto que desea cambiar (1-4): ");
                cout << productos.cambiarProducto(opcProducto);
                break;

            case 5:  // Calcular estad�sticas de ventas
                cout << productos.calcularEstadisticas();
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

