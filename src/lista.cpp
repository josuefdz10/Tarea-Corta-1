#include <iostream>
#include <stdio.h>
#include "lista.h"

using namespace std;

lista::~lista()
{
   pnodo aux;

   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   actual = NULL;
}

int lista::largoLista(){
    int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }

}

void lista::InsertarInicio(char v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     primero=new nodo (v,primero);
}

void lista::InsertarFinal(char v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }
}


void lista::InsertarPos(char *v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1){
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;
        }
        else{
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;

        }
        }
}

void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }

              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;


                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;

   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                primero=primero->siguiente;
                delete aux;
            }
        }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        primero=primero->siguiente;
        }else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            aux->siguiente=aux->siguiente->siguiente;
            }
        }
     }

}


void lista::Imprimir()
{
   nodo *aux;

   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
      //hola
   }
   cout << endl;
}

void lista::Siguiente()
{
   if(actual) actual = actual->siguiente;
}

void lista::Primero()
{
   actual = primero;
}

void lista::Ultimo()
{
   actual = primero;
   if(!ListaVacia())
      while(actual->siguiente) Siguiente();
}
