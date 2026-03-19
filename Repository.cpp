//archivo de implementacion - Como lo hace (implementacion)
#include "Repository.h"
#include "Libro.h"
#include <iostream>
using namespace std;

// Constructor
Repository::Repository(int cantidad) {
    this->capacidad = cantidad;
    this->size = 0;
    this->Libros = new Libro[cantidad];
}

Repository::~Repository() {
    delete[] this->Libros;
}
// void Repository::librosDisponibles() {
//     Libros[0] = class Libro
//     {
//     private:
//         /* data */
//     public:
//         Repository(/* args */);
//         ~Repository();
//     };
    
//     Repository::Repository(/* args */)
//     {
//     }
    
//     Repository::~Repository()
//     {
//     }
//     ::Libro(1, "El Alquimista", "Paulo Coelho", 3);
//     Libros[1] = Libro(2, "1984", "George Orwell", 5);
//     Libros[2] = Libro(3, "Cien años de soledad", "García Márquez", 2);
//     Libros[3] = Libro(4, "El Principito", "Saint-Exupéry", 1);
//     Libros[4] = Libro(5, "Orgullo y prejuicio", "Jane Austen", 2);

//     size = 5; // IMPORTANTÍSIMO
}

