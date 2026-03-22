#include <iostream>
#include "Devolucion.h"

using namespace std;

Devolucion::Devolucion(Prestamos* prestamos, Repository* repository) {
    this->prestamos = prestamos;
    this->repository = repository;
}

Devolucion::~Devolucion() {
    // No se gestionan recursos dinámicos propios
}

bool Devolucion::devolverLibro(const std::string& libroId, const std::string& usuarioId, const std::string& fecha) {
    Prestamo* prestamo = prestamos->buscarPrestamo(libroId, usuarioId);
    if (!prestamo) {
        cout << "No se encontro prestamo para Libro ID " << libroId << " y Usuario " << usuarioId << ".\n";
        return false;
    }

    int idNumerico;
    try {
        idNumerico = stoi(libroId);
    } catch (...) {
        cout << "ID de libro invalido.\n";
        return false;
    }

    if (!repository->incrementarCantidadLibro(idNumerico)) {
        cout << "No se pudo actualizar inventario de libro con ID " << idNumerico << ".\n";
        return false;
    }

    if (!prestamos->eliminarPrestamo(libroId, usuarioId)) {
        cout << "Error al eliminar prestamo luego de devolver.\n";
        return false;
    }

    historial.push_back({libroId, usuarioId, fecha});

    cout << "Libro " << libroId << " devuelto con exito por el usuario " << usuarioId << " en " << fecha << ".\n";
    return true;
}

void Devolucion::mostrarHistorial() const {
    if (historial.empty()) {
        cout << "No hay devoluciones registradas.\n";
        return;
    }

    cout << "===== Historial de Devoluciones =====\n";
    for (size_t i = 0; i < historial.size(); i++) {
        cout << "Devolucion " << i+1 << ":" << endl;
        cout << "  Libro ID: " << historial[i].libroId << endl;
        cout << "  Usuario: " << historial[i].usuarioId << endl;
        cout << "  Fecha de devolucion: " << historial[i].fechaDevolucion << endl;
    }
}

void Devolucion::devolverLibroConReintentos(const std::string& libroId, Usuarios* usuarios, const std::string& fecha) {
    string usuarioDni;
    bool usuarioEncontrado = false;

    while (!usuarioEncontrado) {
        cout << "\nIngrese DNI del usuario (o escriba 0 para cancelar): ";
        cin >> usuarioDni;

        if (usuarioDni == "0") {
            cout << "Operacion cancelada. Volviendo al menu...\n";
            return;
        }

        if (usuarios->buscarUsuario(usuarioDni)) {
            usuarioEncontrado = true;
            if (devolverLibro(libroId, usuarioDni, fecha)) {
                // Éxito en la devolución
            }
        } else {
            cout << "Usuario con DNI " << usuarioDni << " no encontrado. Intente nuevamente.\n";
        }
    }
}

