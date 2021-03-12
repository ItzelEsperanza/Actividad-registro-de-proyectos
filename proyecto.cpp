#include"proyecto.h"
void Proyecto::setFloio(string _folio) //geters y seters
{
    folio=_folio;
}

string Proyecto::getFolio()
{
    return folio;
}

void Proyecto::setNombre(string _nombre)
{
    nombre= _nombre;
}

string Proyecto::getNombre()
{
    return nombre;
}

void Proyecto::setArea(string _area)
{
    area=_area;
}

string Proyecto::getArea()
{
    return area;
}

void Proyecto::setEspecialidad(string _especialidad)
{
    especialidad= _especialidad;
}

string Proyecto::getEspecialidad()
{
    return especialidad;
}

void Proyecto::setMonto_economico(string _monto_economico)
{
    monto_economico= _monto_economico;
}

string Proyecto::getMonto_economico()
{
    return monto_economico;
}

void Proyecto::setResponsable(string _responsable)
{
    responsable= _responsable;
}

string Proyecto::getResponsable()
{
    return responsable;
}


void Proyecto::capturar()
{
    int opc;

    cout << endl << "--> Nombre del Proyecto " << endl;
    cin.ignore();
    getline(cin,nombre);

    cout << endl<<setw(30)<< "** Selecciona una area **" << endl<< endl;

    cout<< "AREA 1: FISICO MATEMATICAS Y CIENCIAS DE LA TIERRA."<< endl;
    cout<< "AREA 2: BIOLOGIA Y QUIMICA." << endl;
    cout<< "AREA 3: CIENCIAS MEDICAS Y DE LA SALUD." << endl;
    cout<< "AREA 4: HUMANIDADES Y CIENCIAS DE LA CONDUCTA."<< endl;
    cout<< "AREA 5: CIENCIAS SOCIALES."<< endl;
    cout<< "AREA 6: BIOTECNOLOGIA Y CIENCIAS AGROPECUARIAS."<< endl;
    cout<< "AREA 7: INGENIERIAS."<< endl;
    cin>>opc;
        switch(opc){
            case 1: area= "Fisico matematicas y ciencias de la tierra"; break;
            case 2: area= "Biologia y quimica"; break;
            case 3: area= "Ciencias medicas y de la salud"; break;
            case 4: area= "Humanidades y ciencias de la conducta"; break;
            case 5: area= "Ciencias sociales"; break;
            case 6: area= "Biotecnologia y ciencias agropecuarias"; break;
            case 7: area= "Ingenierias"; break;
        }
    cin.ignore();
    cout << endl << "--> Especialidad " << endl;
    getline(cin,especialidad);

    cout << endl << "--> Monto Economico " << endl;
    getline(cin,monto_economico);

    cout << endl << "--> Responsable " << endl;
    getline(cin,responsable);

    cout << endl << "--> Folio " << endl;
    folio=generarFolio();
    cout<<folio<<endl<<endl;

}

string Proyecto::generarFolio()
{
    //3 letras nombre + guion medio + numero aleatorio;

 int cont=0;
 int numAleatorio;
 string molde;

    while(cont<3){ //3 letras
       molde+= nombre[cont]; //Se concatena primeras 3 letras de nombre a sring nombre
       cont++;
    }

    srand(time(NULL));
    numAleatorio= rand()%(100-1); //numero aleatorio
    molde+='-'+ to_string(numAleatorio); //molde= molde + '-'+ to_string(numAleatorio);
                                         // se le concatenan los caracteres a molde
                                         //el to_string convierte enteros a string

    return molde; //Se retorna el folio

}

void Proyecto::escirbirEnArchivo(ofstream& objetoEscritura) //Se escribe proyecto en archivo secuencial
{
    objetoEscritura<<folio<<" ♣ ";

    objetoEscritura<<nombre<<" ♣ ";

    objetoEscritura<<area<<" ♣ ";

    objetoEscritura<<especialidad<<" ♣ ";

    objetoEscritura<<monto_economico<<" ♣ ";

    objetoEscritura<<responsable<<" ♣ "<<endl;


}
