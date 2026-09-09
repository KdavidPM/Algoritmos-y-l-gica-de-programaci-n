#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string numero;
    double saldo;

public:
    CuentaBancaria() {
        numero = "";
        saldo = 0.0;
    }

    CuentaBancaria(string num, double saldoInicial) {
        numero = num;
        saldo = saldoInicial;
    }

    string getNumero() { return numero; }
    double getSaldo() { return saldo; }

    void mostrarDatos() {
        cout << "Cuenta N: " << numero << " | Saldo: $" << saldo << endl;
    }

    void recibirDinero(double monto) {
        saldo += monto;
        cout << "Se recibieron $" << monto << " en la cuenta " << numero << endl;
    }

    bool enviarDinero(double monto) {
        if (monto > saldo) {
            cout << "Fondos insuficientes en la cuenta " << numero << endl;
            return false;
        }
        saldo -= monto;
        cout << "Se enviaron $" << monto << " desde la cuenta " << numero << endl;
        return true;
    }
};

class Cliente {
private:
    string dni;
    CuentaBancaria cuentas[3];
    int cantidadCuentas;

public:
    Cliente(string documento) {
        dni = documento;
        cantidadCuentas = 0;
    }

    string getDni() { return dni; }
    int getCantidadCuentas() { return cantidadCuentas; }

    void crearCuenta(string numero, double saldoInicial) {
        if (cantidadCuentas < 3) {
            cuentas[cantidadCuentas] = CuentaBancaria(numero, saldoInicial);
            cantidadCuentas++;
        } else {
            cout << "El cliente ya tiene el maximo de 3 cuentas." << endl;
        }
    }

    CuentaBancaria* getCuenta(int indice) {
        if (indice >= 0 && indice < cantidadCuentas) {
            return &cuentas[indice];
        }
        return nullptr;
    }

    void listarCuentas() {
        for (int i = 0; i < cantidadCuentas; i++) {
            cout << i + 1 << ". ";
            cuentas[i].mostrarDatos();
        }
    }
};

int main() {
    string dni;
    cout << "=== SISTEMA DE CUENTAS BANCARIAS ===" << endl;
    cout << "Ingrese el DNI del cliente: ";
    cin >> dni;

    Cliente cliente(dni);

    int cantidad;
    cout << "Cuantas cuentas desea registrar (maximo 3)? ";
    cin >> cantidad;
    if (cantidad > 3) cantidad = 3;

    for (int i = 0; i < cantidad; i++) {
        string numero;
        double saldoInicial;
        cout << "Numero de la cuenta " << i + 1 << ": ";
        cin >> numero;
        cout << "Saldo inicial: ";
        cin >> saldoInicial;
        cliente.crearCuenta(numero, saldoInicial);
    }

    int opcion = -1;
    while (opcion != 5) {
        cout << "\nCliente DNI: " << cliente.getDni() << endl;
        cliente.listarCuentas();

        cout << "\nSeleccione una cuenta (1-" << cliente.getCantidadCuentas() << "): ";
        int seleccion;
        cin >> seleccion;
        seleccion--;

        CuentaBancaria* cuenta = cliente.getCuenta(seleccion);
        if (cuenta == nullptr) {
            cout << "Cuenta invalida." << endl;
            continue;
        }

        cout << "\n--- MENU ---" << endl;
        cout << "1. Ver atributos de la cuenta" << endl;
        cout << "2. Enviar dinero" << endl;
        cout << "3. Recibir dinero" << endl;
        cout << "4. Transferencia entre cuentas" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        double monto;
        switch (opcion) {
            case 1:
                cuenta->mostrarDatos();
                break;
            case 2:
                cout << "Monto a enviar: ";
                cin >> monto;
                cuenta->enviarDinero(monto);
                break;
            case 3:
                cout << "Monto a recibir: ";
                cin >> monto;
                cuenta->recibirDinero(monto);
                break;
            case 4: {
                cout << "Seleccione cuenta destino (1-" << cliente.getCantidadCuentas() << "): ";
                int destino;
                cin >> destino;
                destino--;
                CuentaBancaria* cuentaDestino = cliente.getCuenta(destino);
                if (cuentaDestino == nullptr || cuentaDestino == cuenta) {
                    cout << "Cuenta destino invalida." << endl;
                    break;
                }
                cout << "Monto a transferir: ";
                cin >> monto;
                if (cuenta->enviarDinero(monto)) {
                    cuentaDestino->recibirDinero(monto);
                }
                break;
            }
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    }

    return 0;
}
