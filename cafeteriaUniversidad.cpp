#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string nombreComprador, carrera, cedula, producto;
    int cantidad;
    const double PRECIO_UNITARIO = 1.00;
    const int STOCK_DISPONIBLE = 10;
    double subtotal, descuento, total, pago;

    cout << "--- Datos del comprador ---" << endl;
    cout << "Nombre: ";
    getline(cin, nombreComprador);

    cout << "Carrera: ";
    getline(cin, carrera);

    cout << "Cedula: ";
    getline(cin, cedula);

    cout << "\n--- Datos de la compra ---" << endl;
    cout << "Nombre del producto: ";
    getline(cin, producto);

    cout << "Precio unitario: $" << fixed << setprecision(2) << PRECIO_UNITARIO << endl;

    cout << "Cantidad de unidades (stock disponible: " << STOCK_DISPONIBLE << "): ";
    cin >> cantidad;

    if (cantidad > STOCK_DISPONIBLE) {
        cout << "\nNo hay suficiente stock. Solo hay " << STOCK_DISPONIBLE << " unidades disponibles." << endl;
        return 0;
    }

    if (cantidad <= 0) {
        cout << "\nCantidad invalida." << endl;
        return 0;
    }

    subtotal = cantidad * PRECIO_UNITARIO;
    descuento = subtotal * 0.10;
    total = subtotal - descuento;

    cout << "Dinero entregado: $";
    cin >> pago;

    cout << fixed << setprecision(2);
    cout << "\n--- Resumen de compra ---" << endl;
    cout << "Comprador: " << nombreComprador << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Cedula: " << cedula << endl;
    cout << "Producto: " << producto << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Precio unitario: $" << PRECIO_UNITARIO << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Descuento (10%): $" << descuento << endl;
    cout << "Total a pagar: $" << total << endl;

    if (pago >= total) {
        double cambio = pago - total;
        cout << "Pago suficiente. Cambio: $" << cambio << endl;
    } else {
        double faltante = total - pago;
        cout << "Dinero insuficiente. Falta: $" << faltante << endl;
    }

    return 0;
}
