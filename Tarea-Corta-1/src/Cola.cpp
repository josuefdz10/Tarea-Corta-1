#include "Cola.h"
#include <iostream>
using namespace std;

void Cola:: insertar (int v)
{
         if(fondo < tamano){
             fondo++;
             cola[fondo]= v;

         }
         else{
         cout<<"La cola esta llena";
         }
}

void Cola:: eliminar ()
{
         if(!ColaVacia()){
            frente++;
         }
         else{
         cout<<"La cola esta vacia";
         }
}

void Cola:: imprimir(){
     for(int i = frente;i<fondo+1;i++){
         cout<<cola[i]<<"->";
           }
    cout <<endl;
}
