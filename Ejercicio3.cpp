#include <iostream>
#include <string>
using namespace std;

class Jean {
private:
    string codigo;
    string color;
    string talla;
    bool tenido;
    int cantidadTenidos;
    double precio;
    int cantidadBotones;
    double humedad; 
    string estadoTela;

public:
    Jean(string cod, string col, string tal, bool ten, int cantTen, double prec,
         int botones, double hum, string estado) {
        codigo = cod;
        color = col;
        talla = tal;
        tenido = ten;
        cantidadTenidos = cantTen;
        precio = prec;
        cantidadBotones = botones;
        humedad = hum;
        estadoTela = estado;
    }

    void mostrarDatos() {
        cout << "\n--- DATOS DEL JEAN ---" << endl;
        cout << "Codigo: " << codigo << endl;
        cout << "Color: " << color << endl;
        cout << "Talla: " << talla << endl;
        cout << "Tenido: " << (tenido ? "Si" : "No") << endl;
        cout << "Cantidad de tenidos: " << cantidadTenidos << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Cantidad de botones: " << cantidadBotones << endl;
        cout << "Humedad: " << humedad << "%" << endl;
        cout << "Estado de la tela: " << estadoTela << endl;
    }

    void lavar() {
        if (cantidadTenidos > 0) {
            cantidadTenidos--;
            humedad += 20;
            if (humedad > 100) humedad = 100;
            cout << "El jean fue lavado. Tenidos restantes: " << cantidadTenidos << endl;
        } else {
            cout << "El jean ya no tiene tenidos que perder." << endl;
        }
    }

    void secar() {
        if (humedad > 0) {
            humedad -= 25;
            if (humedad < 0) humedad = 0;
            cout << "El jean fue secado. Humedad actual: " << humedad << "%" << endl;
        } else {
            cout << "El jean ya esta seco." << endl;
        }
    }
};

int main() {
    string codigo, color, talla, estadoTela, respuestaTenido;
    int cantidadTenidos, cantidadBotones;
    double precio, humedad;
    bool tenido;

    cout << "=== REGISTRO DE JEAN ===" << endl;
    cout << "Codigo: ";
    cin >> codigo;
    cout << "Color: ";
    cin >> color;
    cout << "Talla: ";
    cin >> talla;
    cout << "Fue tenido? (s/n): ";
    cin >> respuestaTenido;
    tenido = (respuestaTenido == "s" || respuestaTenido == "S");
    cout << "Cantidad de tenidos: ";
    cin >> cantidadTenidos;
    cout << "Precio: ";
    cin >> precio;
    cout << "Cantidad de botones: ";
    cin >> cantidadBotones;
    cout << "Humedad actual (%): ";
    cin >> humedad;
    cout << "Estado de la tela: ";
    cin >> estadoTela;

    Jean jean(codigo, color, talla, tenido, cantidadTenidos, precio, cantidadBotones, humedad, estadoTela);

    int opcion;
    do {
        cout << "\n--- MENU JEAN ---" << endl;
        cout << "1. Mostrar datos" << endl;
        cout << "2. Lavar" << endl;
        cout << "3. Secar" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jean.mostrarDatos();
                break;
            case 2:
                jean.lavar();
                break;
            case 3:
                jean.secar();
                break;
            case 4:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 4);

    return 0;
}
