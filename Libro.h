#ifndef LIBRO_H //inicializador
#define LIBRO_H
#include <string>

class Libro
{
private:
    //atributos
    int ID;
    std::string Titulo;
    int Cant;
public:
    //metodos
    Libro();//constructor
    Libro(int ID, std::string Titulo, int Cant); //constructor;

    int getID ();
    std::string getTitulo ();
    int getCant ();
};
    #endif //finalizador