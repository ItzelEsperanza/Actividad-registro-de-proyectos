#ifndef LISTA_LLAVESPRIMARIAS_H_INCLUDED
#define LISTA_LLAVESPRIMARIAS_H_INCLUDED

#include<iostream>
#include<fstream>

using namespace std;

class NodoP
{
private:
    string dato; //folio o llave primaria
    NodoP* prev;
    NodoP* sig;

public:
    NodoP();
    friend class Lista_LlavesPrimarias;
};
NodoP::NodoP()
{
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
class Lista_LlavesPrimarias
{
private:
    NodoP inicioLista;
    NodoP finalLista;

public:
    Lista_LlavesPrimarias(); //constructor
    void insertarFinal(string folio);
    bool isEmpty();
    void imprimir(Lista_Proyecto listaProyecto);
    void escribirLista(ofstream& objetoEscribir);
};



Lista_LlavesPrimarias::Lista_LlavesPrimarias() //Se liga el primer nodo con el ultimo nodo
{                                               //La lista se inicializa con estos nodos ya ligados
    inicioLista.sig=&finalLista;
    finalLista.prev=&inicioLista;

}


void Lista_LlavesPrimarias::insertarFinal(string folio)
{
    NodoP *molde;
    molde= new NodoP;

    if(finalLista.prev==(&inicioLista))
    {
        molde->sig=&finalLista;
        molde->prev=&inicioLista;
        inicioLista.sig= molde;
        finalLista.prev= molde;
        molde->dato=folio;
    }
    else
    {
        molde->sig=&finalLista;
        molde->prev= finalLista.prev;
        molde->prev->sig=molde;
        finalLista.prev=molde;
        molde->dato=folio;
    }

}

bool Lista_LlavesPrimarias::isEmpty()
{
    return (inicioLista.sig==&finalLista);
}


void Lista_LlavesPrimarias::imprimir(Lista_Proyecto listaProyecto)
{

    NodoP* a; //Nodo auxiliar para recorrer la lista
    a= inicioLista.sig;

    while (a != &finalLista)
    {
        //cout <<setw(10)<< a->dato<<endl; //se imprime campo dato(llave primaria) de cada nodo
        listaProyecto.buscarFolio(a->dato);
        a= a->sig;
    }
    cout<<endl;
}

void Lista_LlavesPrimarias::escribirLista(ofstream& objetoEscribir)
{
    NodoP* a;
    a= inicioLista.sig;

    while (a != &finalLista)
    {
        objetoEscribir <<setw(10)<< a->dato;
        a= a->sig;
    }

    objetoEscribir <<endl<<endl;
}



#endif // LISTA_LLAVESPRIMARIAS_H_INCLUDED
