#ifndef LISTA_PROYECTOS_H_INCLUDED
#define LISTA_PROYECTOS_H_INCLUDED

#include<iostream>
#include<iomanip>
using namespace std;


class Nodo{
private:
    Proyecto dato; //El nodo tiene un campo de tipo Proyecto. Guarga objetos tipo Proyecto
    Nodo* prev;
    Nodo* sig;

public:
    Nodo();
    friend class Lista_Proyecto;
};
Nodo::Nodo()
{
}

class Lista_Proyecto{
private:
    Nodo inicioLista;
    Nodo finalLista;

public:
    Lista_Proyecto();
    void insertarFinal(Proyecto objeto);
    bool isEmpty();
    void imprimir();
    void buscarFolio(string folio);


};



Lista_Proyecto::Lista_Proyecto()//Se liga el primer nodo con el ultimo nodo
{                               //La lista se inicializa con estos nodos ya ligados
    inicioLista.sig=&finalLista;
    finalLista.prev=&inicioLista;

}

void Lista_Proyecto::insertarFinal(Proyecto objeto)
{

    Nodo *molde; //se crea nodo auxiliar para recorrer la lista
    molde= new Nodo;

    if(finalLista.prev==(&inicioLista)){ //verifica si no hay elementos en la lista
        molde->sig=&finalLista;
        molde->prev=&inicioLista;
        inicioLista.sig= molde;
        finalLista.prev= molde;
        molde->dato=objeto;
    }
        else{
            molde->sig=&finalLista;
            molde->prev= finalLista.prev;
            molde->prev->sig=molde;
            finalLista.prev=molde;
            molde->dato=objeto;
        }

}

bool Lista_Proyecto::isEmpty()
{
    return (inicioLista.sig==&finalLista);
}




void Lista_Proyecto::imprimir()
{
    Nodo* a;
    a= inicioLista.sig;

            cout<<setw(10)<< " FOLIOS: " <<endl <<endl;
        while (a != &finalLista){
            cout << a->dato.getFolio()<<endl; //Imprime el solo folios de proyectos
                                              // se manda a llamar en el main opc 2
            a= a->sig;

        }
}



void Lista_Proyecto::buscarFolio(string folio)
{
    Nodo* a;
    a= inicioLista.sig;
    bool bandera=false;

        cout<< endl <<endl << setw(20)<<"--PROYECTO--";

        while (a != &finalLista){

            if(a->dato.getFolio()==folio){
            cout<<endl<<endl;
            cout << "Folio: " << a->dato.getFolio()<<endl;
            cout << "Nombre: "<< a->dato.getNombre()<<endl;
            cout << "Area: "<< a->dato.getArea()<<endl;
            cout << "Especialidad: "<< a->dato.getEspecialidad()<<endl;
            cout << "Monto economico: "<< a->dato.getMonto_economico()<<endl;
            cout << "Responsable: "<< a->dato.getResponsable()<<endl;
            cout<<endl<<endl;

            bandera=true; //Si flag=true entonces si existe el folio
            break;
            }

            a= a->sig;

        }//fin while

        if(bandera==false){ //Validacion de folios existentes, si bandera=false no existe folio
        cout<<endl<<endl<< "Folio y proyecto inexistentes........." <<endl <<endl;
        }

}


#endif // LISTA_PROYECTOS_H_INCLUDED
