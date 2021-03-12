#ifndef LISTA_INVERTIDA_H_INCLUDED
#define LISTA_INVERTIDA_H_INCLUDED

#include <iostream>
#include<fstream>
#include<iomanip>

#include "lista_llavesPrimarias.h"

using namespace std;

class NodoI
{
private:
    string area;  //llave secundaria
    Lista_LlavesPrimarias dato; //Lista de llaves Primarias
    NodoI* prev;
    NodoI* sig;

public:
    NodoI();
    friend class Lista_Invertida;
};
NodoI::NodoI()
{
}
/////////////////////////////////////////////////////////////////////////////////////////////
class Lista_Invertida
{
private:
    NodoI inicioLista;
    NodoI finalLista;

public:
    Lista_Invertida();
    void insertar_ListaP(string llaveSec,string folio); //area y folio como parametros
    void insertarFinal();
    bool isEmpty();
    void imprimir(Lista_Proyecto listaProyecto);
    void escribirArchivo();
};

Lista_Invertida::Lista_Invertida()//Se liga el primer nodo con el ultimo nodo
{                                   //La lista se inicializa con estos nodos ya ligados
    inicioLista.sig=&finalLista;
    finalLista.prev=&inicioLista;
}

void Lista_Invertida::insertar_ListaP(string llaveSec,string folio)
{
    NodoI* a; //se crea nuevo nodo auxiliar para recorrer la lista
    a= inicioLista.sig;

    while (a != &finalLista)  //Mientras no llegue al final de la lista
    {
        if(llaveSec==a->area)
/* si la llaveSecundaria que va entrando corresponde a el area (nodo) se inserta en la lista de el nodo al que corresponde */
        {
            a->dato.insertarFinal(folio); //Se inserta el folio en la lista de llaves primarias de el nodo
        }
        a= a->sig;
    }

}

void Lista_Invertida::insertarFinal() //Se crean 7 nodos uno para cada area (llave secundaria)
{
    NodoI *molde;
    molde= new NodoI; //nuevo nodo

    if(finalLista.prev==(&inicioLista))
    {
        molde->sig=&finalLista;
        molde->prev=&inicioLista;
        inicioLista.sig= molde;
        finalLista.prev= molde;
        molde->area= "Biologia y quimica"; //Se le asigna una llave secundaria a Nodo en su campo area
    }

    NodoI *molde2;
    molde2= new NodoI;

    molde2->sig=&finalLista;
    molde2->prev= finalLista.prev;
    molde2->prev->sig=molde2;
    finalLista.prev=molde2;
    molde2->area= "Biotecnologia y ciencias agropecuarias";

    NodoI *molde3;
    molde3= new NodoI;
    molde3->sig=&finalLista;
    molde3->prev= finalLista.prev;
    molde3->prev->sig=molde3;
    finalLista.prev=molde3;
    molde3->area= "Ciencias medicas y de la salud";

    NodoI *molde4;
    molde4= new NodoI;
    molde4->sig=&finalLista;
    molde4->prev= finalLista.prev;
    molde4->prev->sig=molde4;
    finalLista.prev=molde4;
    molde4->area= "Ciencias sociales";

    NodoI *molde5;
    molde5= new NodoI;
    molde5->sig=&finalLista;
    molde5->prev= finalLista.prev;
    molde5->prev->sig=molde5;
    finalLista.prev=molde5;
    molde5->area= "Fisico matematicas y ciencias de la tierra";

    NodoI *molde6;
    molde6= new NodoI;
    molde6->sig=&finalLista;
    molde6->prev= finalLista.prev;
    molde6->prev->sig=molde6;
    finalLista.prev=molde6;
    molde6->area= "Humanidades y ciencias de la conducta";

    NodoI *molde7;
    molde7= new NodoI;
    molde7->sig=&finalLista;
    molde7->prev= finalLista.prev;
    molde7->prev->sig=molde7;
    finalLista.prev=molde7;
    molde7->area= "Ingenierias";
}

bool Lista_Invertida::isEmpty()
{
    return (inicioLista.sig==&finalLista);
}

void Lista_Invertida::imprimir(Lista_Proyecto listaProyecto) //Imprime lista invertida
{
    if(isEmpty()){
        cout<< "No hay proyectos para mostrar" <<endl;//Se valida si hay elementos en la lista invertida
    }

    NodoI* a;
    a= inicioLista.sig;

    while (a != &finalLista)
    {

        cout <<"--> "<< a->area;
        a->dato.imprimir(listaProyecto);
        cout<<endl<<"-------------------------------------------------------------------------"<<endl;
        a= a->sig;
    }
    cout<<endl<<endl;


}

void Lista_Invertida::escribirArchivo()
{
    NodoI* a;
    a= inicioLista.sig;

    ofstream objetoEscribir("Indice_Secundario.txt",ios::ate);
        if(!objetoEscribir){
            cout<< "No se puede abrir el archivo "<<endl;
        }

    objetoEscribir << setw(15)<<"--INDICE SECUNDARIO--" <<endl <<endl;

    while (a != &finalLista)
    {
        objetoEscribir<< a->area;
        a->dato.escribirLista(objetoEscribir);
        a= a->sig;
    }
    cout<<endl<<endl;

    objetoEscribir.close();
}



#endif // LISTA_INVERTIDA_H_INCLUDED
