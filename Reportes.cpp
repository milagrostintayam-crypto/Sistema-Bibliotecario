//archivo de implementacion - Como lo hace (implementacion)
#include <iostream>
#include <string>
#include "Reportes.h"
#include "Repository.h"
#include "Prestamos.h"
#include "Devolucion.h"
#include "Usuarios.h"

using namespace std;
//Constructor
Reportes::Reportes(Repository* r, Prestamos* p, Devolucion* d) {
    repo = r;
    prestamos = p;
    devolucion = d;
}
void Reportes::mostrarResumenGeneral() {
    cout << "===== RESUMEN GENERAL =====\n";
    cout << "Total libros: " << repo->totalLibros() << endl;
    cout << "Disponibles: " << repo->contarDisponibles() << endl;
    cout << "Agotados: " << repo->contarAgotados() << endl;

    cout << "Total prestamos: " << prestamos->totalPrestamos() << endl;
    cout << "Total devoluciones: " << devolucion->totalDevoluciones() << endl;
}
