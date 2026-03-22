#ifndef PRESTAMO_H
#define PRESTAMO_H
#include <string>

class Prestamo {
private:
//atributos
    std::string fechaPrestamo;
    std::string fechaDevolucion;
    std::string libroId;
    std::string usuarioId;
public:
    Prestamo(std::string fechaPrestamo, std::string fechaDevolucion, std::string libroId, std::string usuarioId);
    ~Prestamo();

    void mostrarPrestamo() const;

    std::string getFechaPrestamo() const;

    std::string getFechaDevolucion() const;

    std::string getLibro() const;

    std::string getUsuario() const;


};

#endif // PRESTAMO_H