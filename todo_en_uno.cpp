

// === Comienzo de Cliente.cpp ===

//
// Created by Portatil on 8/10/2025.
//

#include "Cliente.h"

// === Fin de Cliente.cpp ===


// === Comienzo de Habitacion.cpp ===

//
// Created by Portatil on 8/10/2025.
//

#include "Habitacion.h"

// === Fin de Habitacion.cpp ===


// === Comienzo de Hotel.cpp ===

//
// Created by Portatil on 8/10/2025.
//

#include "Hotel.h"

// === Fin de Hotel.cpp ===


// === Comienzo de main.cpp ===

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

// === Fin de main.cpp ===


// === Comienzo de todo_en_uno.cpp ===


// === Fin de todo_en_uno.cpp ===


// === Comienzo de Cliente.h ===

//
// Created by Portatil on 8/10/2025.
//

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

using namespace std;

class Cliente {
private:
    int id;
    string nombre;
    int habitacionAsignada; // -1 si no tiene
public:
    Cliente() = default;

    Cliente(int id, const string& nombre)
        : id(id),
          nombre(nombre),
          habitacionAsignada(-1) {
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getNombre() const {
        return nombre;
    }

    void setNombre(const string& nombre) {
        this->nombre = nombre;
    }

    int getHabitacionAsignada() const {
        return habitacionAsignada;
    }

    void asignarHabitacion(int numero) { habitacionAsignada = numero; }
    void liberarHabitacion() { habitacionAsignada = -1; }

    void mostrar() const {
        cout << "ID: " << id << " | Nombre: " << nombre;
        if (habitacionAsignada != -1)
            cout << " | Habitacion asignada: " << habitacionAsignada;
        cout << endl;
    }
};


#endif //CLIENTE_H

// === Fin de Cliente.h ===


// === Comienzo de Habitacion.h ===

//
// Created by Portatil on 8/10/2025.
//

#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>

using namespace std;

class Habitacion {
private:
    int numero;
    string tipo;
    bool ocupada;

public:
    Habitacion() = default;

    Habitacion(int numero, const string& tipo)
        : numero(numero), tipo(tipo), ocupada(false) {
    }

    int getNumero() const {
        return numero;
    }

    void setNumero(int numero) {
        this->numero = numero;
    }

    string getTipo() const {
        return tipo;
    }

    void setTipo(const string& tipo) {
        this->tipo = tipo;
    }

    bool estaOcupada() const {
        return ocupada;
    }

    void ocupar() { ocupada = true; }
    void liberar() { ocupada = false; }

    void mostrar() const {
        cout << "Hab. " << numero
            << " | Tipo: " << tipo
            << " | Ocupada: " << (ocupada ? "Si" : "No") << endl;
    }
};


#endif //HABITACION_H

// === Fin de Habitacion.h ===


// === Comienzo de Hotel.h ===

//
// Created by Portatil on 8/10/2025.
//

#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <vector>
#include "Habitacion.h"
#include "Cliente.h"

using namespace std;

class Hotel {
private:
    vector<Habitacion> habitaciones;
    vector<Cliente> clientes;

public:
    Hotel() = default;

    void agregarHabitacion(int numero, const string& tipo) {
        for (auto& h : habitaciones) {
            if (h.getNumero() == numero) {
                cout << "Error: La habitacion ya existe." << endl;
                return;
            }
        }
        habitaciones.emplace_back(numero, tipo);
        cout << "Hab. " << numero << " (" << tipo << ") agregada correctamente." << endl;
    }

    void registrarCliente(int id, const string& nombre) {
        for (auto& c : clientes) {
            if (c.getId() == id) {
                cout << "Error: El cliente ya existe." << endl;
                return;
            }
        }
        clientes.emplace_back(id, nombre);
        cout << "Cliente " << id << " (" << nombre << ") registrado correctamente." << endl;
    }

    void asignarHabitacion(int idCliente, int numHabitacion) {
        Cliente* cliente = nullptr;
        Habitacion* habitacion = nullptr;

        for (auto& c : clientes)
            if (c.getId() == idCliente)
                cliente = &c;

        for (auto& h : habitaciones)
            if (h.getNumero() == numHabitacion)
                habitacion = &h;

        if (!cliente) {
            cout << "Error: Cliente no encontrado." << endl;
            return;
        }
        if (!habitacion) {
            cout << "Error: Habitacion no encontrada." << endl;
            return;
        }
        if (habitacion->estaOcupada()) {
            cout << "Error: La habitacion ya esta ocupada." << endl;
            return;
        }
        if (cliente->getHabitacionAsignada() != -1) {
            cout << "Error: El cliente ya tiene una habitacion asignada." << endl;
            return;
        }

        habitacion->ocupar();
        cliente->asignarHabitacion(numHabitacion);
        cout << "Hab. " << numHabitacion << " asignada al cliente "
            << idCliente << " (" << cliente->getNombre() << ")." << endl;
    }

    void listarHabitaciones() const {
        cout << "--- Lista de Habitaciones ---" << endl;
        if (habitaciones.empty()) {
            cout << "No hay habitaciones registradas." << endl;
            return;
        }
        for (const auto& h : habitaciones)
            h.mostrar();
    }

    void listarClientes() const {
        cout << "--- Lista de Clientes ---" << endl;
        if (clientes.empty()) {
            cout << "No hay clientes registrados." << endl;
            return;
        }
        for (const auto& c : clientes)
            c.mostrar();
    }

    void buscarHabitacion(int numero) const {
        for (const auto& h : habitaciones) {
            if (h.getNumero() == numero) {
                cout << "Hab. encontrada: ";
                h.mostrar();
                return;
            }
        }
        cout << "Error: Hab. no encontrada." << endl;
    }

    void buscarCliente(int id) const {
        for (const auto& c : clientes) {
            if (c.getId() == id) {
                cout << "Cliente encontrado: ";
                c.mostrar();
                return;
            }
        }
        cout << "Error: Cliente no encontrado." << endl;
    }

    void eliminarHabitacion(int numero) {
        for (auto it = habitaciones.begin(); it != habitaciones.end(); ++it) {
            if (it->getNumero() == numero) {
                habitaciones.erase(it);
                cout << "Hab. " << numero << " eliminada correctamente." << endl;
                return;
            }
        }
        cout << "Error: Habitacion no encontrada." << endl;
    }

    void eliminarCliente(int id) {
        for (auto it = clientes.begin(); it != clientes.end(); ++it) {
            if (it->getId() == id) {
                clientes.erase(it);
                cout << "Cliente " << id << " eliminado correctamente." << endl;
                return;
            }
        }
        cout << "Error: Cliente no encontrado." << endl;
    }
};


#endif //HOTEL_H

// === Fin de Hotel.h ===

