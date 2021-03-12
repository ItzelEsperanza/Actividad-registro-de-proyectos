#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<iomanip>
#include <sstream>

using namespace std;

class Proyecto{
    private:
    string folio;
    string nombre;
    string area;
    string especialidad;
    string monto_economico;
    string responsable;

    public:
    void setFloio(string); //geters y seters de variavles
    string getFolio();

    void setNombre(string);
    string getNombre();

    void setArea(string);
    string getArea();

    void setEspecialidad(string);
    string getEspecialidad();

    void setMonto_economico(string);
    string getMonto_economico();

    void setResponsable(string);
    string getResponsable();

    void capturar();
    string generarFolio(); //genera llavePrimaria
    void escirbirEnArchivo(ofstream& objetoEscritura); //Genera el archivo de entradas secuenciales

};


#endif // PROYECTO_H_INCLUDED
