#include "Archivos.h"
#include <fstream>
#include <iostream>
#define ruta "p.txt"
using namespace std;

void Archivos::Leer()
{
    char cadena;
	ifstream file;
	file.open(ruta);
	if(file.is_open()){
        while(!file.eof())
        {
            file >> cadena;
            cout << cadena << endl;
            cola.insertar(cadena);

        }
	}
    else{
        cout<<"El archivo no se pudo abrir correctamente, verifique la ruta"<<endl;
    }
    file.close();

}


