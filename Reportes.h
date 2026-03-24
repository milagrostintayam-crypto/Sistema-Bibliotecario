//archivo de cabecera -Que puede hacer la clase (contrato)
#ifndef REPORTES_H
#define REPORTES_H

#include "Repository.h"
#include "Prestamos.h"
#include "Devolucion.h"
#include "Usuarios.h"

class Reportes
{
private:
    Repository* repo;
    Prestamos* prestamos;
    Devolucion* devolucion;
    Usuarios* usuarios;
public:
    Reportes(Repository* r, Prestamos* p, Devolucion* d);
    ~Reportes();

    void mostrarResumenGeneral();
    void librosMasSolicitados();
    void usuariosMasActivos();
    void librosAgotados();
};
#endif