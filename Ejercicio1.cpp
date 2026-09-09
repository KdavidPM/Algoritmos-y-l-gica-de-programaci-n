#include <iostream>
using namespace std;

void mostrarHora(int h, int m, int s) {
    cout << "Hora registrada: ";
    if (h < 10) cout << "0";
    cout << h << ":";
    if (m < 10) cout << "0";
    cout << m << ":";
    if (s < 10) cout << "0";
    cout << s << endl;
}

int main() {
    int hora, minutos, segundos;
    char respuesta;

    cout << "=== CONTROL DE HORA ===" << endl;
    cout << "Ingrese la hora (0-23): ";
    cin >> hora;
    cout << "Ingrese los minutos (0-59): ";
    cin >> minutos;
    cout << "Ingrese los segundos (0-59): ";
    cin >> segundos;

    mostrarHora(hora, minutos, segundos);

    do {
        cout << "Desea cambiar la hora? (s/n): ";
        cin >> respuesta;

        if (respuesta == 's' || respuesta == 'S') {
            cout << "Ingrese la nueva hora (0-23): ";
            cin >> hora;
            cout << "Ingrese los nuevos minutos (0-59): ";
            cin >> minutos;
            cout << "Ingrese los nuevos segundos (0-59): ";
            cin >> segundos;

            mostrarHora(hora, minutos, segundos);
        }

    } while (respuesta == 's' || respuesta == 'S');

    cout << "Programa finalizado." << endl;
    return 0;
}
