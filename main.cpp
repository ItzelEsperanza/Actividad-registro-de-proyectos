#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> //para el setw

#include "proyecto.h"
#include "indice_primario.h"
#include "lista_proyectos.h"
#include "lista_invertida.h"

using namespace std;

int main(void)
{

    int op;
    string folio;

    //Objetos a utilizar
    Proyecto x;
    Indice_Primario indiceP;
    Lista_Proyecto listaProyecto;
    Lista_Invertida listaInvertida;
    listaInvertida.insertarFinal(); //Creacion de nodos con su respectiva area


    ofstream objetoEscritura("Proyectos_Ministerio de Ciencias e Inovacion.txt",ios::out); //apertura archivo secuencial
    if(!objetoEscritura)
    {
        cout<<"Error, no se puede abrir el archivo" <<endl;
    }


    do
    {
        cout << setw(40)<< "|--------------MENU-------------|" << endl;
        cout << setw(40)<< "| 1. INSERTAR PROYECTO          |" << endl;
        cout << setw(40)<< "| 2. MOSTRAR PROYECTO POR FOLIO |" << endl;
        cout << setw(40)<< "| 3. MOSTRAR PROYECTO POR AREAS |" << endl;
        cout << setw(40)<< "| 4. SALIR                      |" << endl;
        cout << setw(40)<< "|-------------------------------|" << endl;
        cin >> op;

        switch (op)
        {

        case 1:
            x.capturar(); //captura proyecto
            x.escirbirEnArchivo(objetoEscritura); //archivo secuencial
            indiceP.extraerLlave(); //Se genera indice primario
            listaInvertida.insertar_ListaP(x.getArea(),x.getFolio()); //Mandar por referencia area y folio a lista invertida
            listaInvertida.escribirArchivo(); //Se genera el indice
            listaProyecto.insertarFinal(x); //Se agregan objetos a una lista de proyectos

            system("pause");
            system("cls");
            break;

        case 2:

            listaProyecto.imprimir(); //Se imprime un menu de folios existentes
            cout<< endl<< "--> Ingrese el folio del proyecto a mostrar: ";
            cin.ignore();
            getline(cin,folio);
            listaProyecto.buscarFolio(folio);
            system("pause");
            system("cls");
            break;

        case 3:
            listaInvertida.imprimir(listaProyecto); //Se muestra contenido de lista invertida
            system("pause");
            system("cls");
            break;
        }

    }
    while(op!=4);

    objetoEscritura.close();
    return 0;
}
