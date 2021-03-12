#include "indice_primario.h"

void Indice_Primario::extraerLlave()
{
    ifstream objetoLectura("Proyectos_Ministerio de Ciencias e Inovacion.txt",ios::in); //Leer archivo secuencial

    ofstream objetoEscribir("Indice_Primario.txt",ios::ate); //Se crea archivo para indice secundario
    objetoEscribir<< "INDICE PRIMARIO" <<endl;

    if(!objetoEscribir)
    {
        cout<<" No se puede abrir " <<endl;
    }


    string indiceP[tamanioArregalo()]; //Arreglo para llave primaria y distancia en bytes
    string molde;
    string campos;
    string llave;
    int distancia_bytes=0; // Se le iran sumando la distacnia en bytes de cada campo
    int posicion=0; //Contador para el arreglo

    while(!objetoLectura.eof())  //mientras no se llegue al final del archivo
    {

        objetoLectura>>molde; //Se lee cada cadena de caracteres que se encuentra en el archivo (de uno en uno)

        if(objetoLectura.eof())
            break; //Si se llega al final del archivo se rome el ciclo

        if(molde!="♣")
        {
            campos+= molde + " "; //Campos concatena todas las cadenas que vaya almacenando molde, en una sola cadena
            distancia_bytes+=sizeof(molde); //Sizeof regresa el tamanio en bytes de molde y se va sumando a distancia_bytes

            if(campos.find("-")==3) //Si Find encuentra el caracter "-" en una cadena, esta candena sera una llave primaria
            {
                llave=campos; //Llave es la varibale en la cual se guada SOLO las llaves primarias
                llave+=" ♣ " + to_string(distancia_bytes+1);//El to sting convierte el tamanio en bytes (entero) a caracter
                //Se le suma uno a la distancia en bytes porque el registo comienza en el byte siguiente

                indiceP[posicion]=llave;

                posicion++;
                llave.clear();
            }

        }
        else
        {
            campos.clear(); //Borra el contenido del string si se encuentra con el delimitador
        }


    }

    //bubble sort para organizar el arreglo
    string aux;
    for (int i=0; i<tamanioArregalo()-1; i++){
    for (int j=i+1; j<tamanioArregalo(); j++)
    {
        if(indiceP[i]>indiceP[j])
        {
        aux = indiceP[i];
        indiceP[i] =indiceP[j];
        indiceP[j] = aux;
    }
  }
}

    //Se recorre el arreglo y se escribe el comtenido de cada posicion en el archivo
    for(int l=0; l<tamanioArregalo(); l++){
    objetoEscribir<< indiceP[l] <<endl;
    }

    objetoEscribir.close();

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int Indice_Primario::tamanioArregalo() //Retorna el numero de registoros que hay
{
    string molde; //Recibe cada palabra que se lee desde el archivo
    string campos; //Molde concatena las palabras y espacios que corresponden a un campo delimitado por ♣
    int contador=1; //Cuenta numero de registros

    ifstream objetoLectura("Proyectos_Ministerio de Ciencias e Inovacion.txt",ios::in);

    if(!objetoLectura)
    {
        cout<<endl<<" No se puede abrir el archivo "<< endl;
    }

    while(!objetoLectura.eof())  //mientras no se llegue al final del archivo
    {

        objetoLectura>>molde;

        if(molde!="♣")
        {

            if(objetoLectura.eof())
                break; //Si se llega al final del archivo se rome el ciclo
            campos+= molde + " ";
            if(campos.find("-")==3)
            {
                contador++;
                // cout<<"contador: "<<contador<<endl;
            }
        }
        else
        {
            campos.clear(); //Borra el contenido del string
        }

        if(molde=="♣")
        {
            campos.clear();
        }

    }
    objetoLectura.close();
    return contador;
}


