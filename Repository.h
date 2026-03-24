#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <string>

#include "Libro.h"
 
 //archivo de cabecera -Que puede hacer la clase (contrato)
class Repository
{
private:
    Libro** Libros;//puntero a un arreglo de objetos Libro- creacion de un 
    int size; //contador de libros actuales-cuántos libros ya están ocupando espacios
    int capacidad = 100; //cuántos espacios tiene la estantería (máximo)
public:
    //contructor
    Repository(int capacidad);
    ~Repository();//liberar memoria


    //metodos
    void cargarDatos(); // 👈 aquí simulas el vector
    void librosDisponibles();
    // NUEVO: Métodos para gestión automática de inventario
    bool decrementarCantidadLibro(int libroId); // Reduce stock al prestar libro
    bool incrementarCantidadLibro(int libroId); // Aumenta stock al devolver libro
    int obtenerCantidadLibro(int libroId) const; // Consulta cantidad disponible
    //METODO: Para el uso de un analisis general en reportes
    int totalLibros() const;
    int contarDisponibles() const;
    int contarAgotados() const;
};
#endif
//el uso de los asteriscos* para los punteros
//**puntero apunta a otro puntero 