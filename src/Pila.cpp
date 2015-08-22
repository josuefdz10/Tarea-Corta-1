#include <iostream>
#include "Pila.h"
using namespace std;

void Pila::push (int v){
    if(Tope < tamano){
       	Tope++;
    	pila[Tope]= v;
    }
    else
     	cout<<"La pila esta llena"<<endl;
}

void Pila:: pop ()
{
        if(!pilaVacia()){
            Tope--;
        }
        else
         	cout<<"La pila esta vacia"<<endl;
}

void Pila:: imprimir(){
    for(int i = Tope;i>=0;i--){
            cout<<pila[i]<<"->";
    }
    cout << endl;
}



