#ifndef DEVOLUCION_H
#define DEVOLUCION_H

#include <string>
#include <vector>
#include "Prestamos.h"
#include "Repository.h"
#include "Usuarios.h"

struct RegistroDevolucion {
    std::string libroId;
    std::string usuarioId;
    std::string fechaDevolucion;
};

class Devolucion
{
private:
    Prestamos* prestamos;
    Repository* repository;
    std::vector<RegistroDevolucion> historial;

public:
    Devolucion(Prestamos* prestamos, Repository* repository);
    ~Devolucion();

    bool devolverLibro(const std::string& libroId, const std::string& usuarioId, const std::string& fecha);
    void devolverLibroConReintentos(const std::string& libroId, Usuarios* usuarios, const std::string& fecha);
    void mostrarHistorial() const;
};

#endif