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
    bool prestarLibro(int libroId);
    Libro* buscarLibro(int ID);
};
#endif
//el uso de los asteriscos* para los punteros
//**puntero apunta a otro puntero 