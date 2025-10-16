// aprendiendo a utilizar git  
#include <iostream>
#include "Hotel.h"

using namespace std;

int main() {
    Hotel hotel;
    string comando;

    while (true) {
        cin >> comando;

        if (comando == "AGREGAR_HABITACION") {
            int numero;
            string tipo;
            cin >> numero >> tipo;
            hotel.agregarHabitacion(numero, tipo);
        }
        else if (comando == "REGISTRAR_CLIENTE") {
            int id;
            string nombre;
            cin >> id >> nombre;
            hotel.registrarCliente(id, nombre);
        }
        else if (comando == "ASIGNAR_HABITACION") {
            int idCliente, numHabitacion;
            cin >> idCliente >> numHabitacion;
            hotel.asignarHabitacion(idCliente, numHabitacion);
        }
        else if (comando == "LISTAR_HABITACIONES") {
            hotel.listarHabitaciones();
        }
        else if (comando == "LISTAR_CLIENTES") {
            hotel.listarClientes();
        }
        else if (comando == "BUSCAR_HABITACION") {
            int numero;
            cin >> numero;
            hotel.buscarHabitacion(numero);
        }
        else if (comando == "BUSCAR_CLIENTE") {
            int id;
            cin >> id;
            hotel.buscarCliente(id);
        }
        else if (comando == "ELIMINAR_HABITACION") {
            int numero;
            cin >> numero;
            hotel.eliminarHabitacion(numero);
        }
        else if (comando == "ELIMINAR_CLIENTE") {
            int id;
            cin >> id;
            hotel.eliminarCliente(id);
        }
        else if (comando == "SALIR") {
            break;
        }
        else {
            cout << "Comando no reconocido." << endl;
        }
    }
    return 0;
}
