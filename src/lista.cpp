#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <string.h>
#include "lista.h"
#include <math.h>


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

void lista::InsertarInicio(string v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     primero=new nodo (v,primero);
}

void lista::InsertarFinal(string v)
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


void lista::InsertarPos(string v,int pos)
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
                pnodo temp = primero;
                primero= NULL;
                delete temp;
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

int lista::operadorBinario(string caracter){

     std::string str1 (caracter);

    bool valor;

    if ((str1.compare("+") == 0) || (str1.compare("-") == 0) ||(str1.compare("/") == 0)||(str1.compare("*") == 0)||
        (str1.compare("^") == 0)|| (str1.compare("(") == 0) || (str1.compare(")") == 0))
            valor = true;
    //else if (strcmp(caracter, "0") == 0)
        //valor = true;
    else
        valor = false;
    return valor;
}


int lista::validacion(char *caracter){

    bool valor = false;
    char *finalPtr;

    if (operadorBinario(caracter))
        valor = true;
    else if (strtod(caracter, &finalPtr) != 0)
        valor = true;
    else
        valor = false;
    return valor;

}

int lista::valorDentroPila(string caracter){
    int valor = 0;
    std::string str1 (caracter);

    if (str1.compare("(") == 0)
        valor = 0;
    else if ((str1.compare("+") == 0) || (str1.compare("-")) == 0)
        valor = 1;
    else if (((str1.compare("*")) == 0) || (str1.compare("/") == 0))
        valor = 2;
    else if (str1.compare("^")== 0)
        valor = 3;
    return valor;
}




string lista::Ultimo(){

    string elemento;
    pnodo aux = primero;
    while (aux != NULL){
        elemento = aux -> valor;
        aux = aux -> siguiente;
    }
    return elemento;
}

int lista::valorFueraPila(string caracter){
    int valor = 0;
    std::string str1 (caracter);

    if (str1.compare("(") == 0)
        valor = 5;
    else if ((str1.compare("+") == 0) || (str1.compare("-") == 0))
        valor = 1;
    else if ((str1.compare("*") == 0) || (str1.compare("/") == 0))
        valor = 2;
    else if (str1.compare("^")== 0)
        valor = 4;
    return valor;
}


void lista::Leer() {

 	char nombreArchivo[50];
  	char caracter[100];

 	ifstream Archivo;
 	cin.getline(nombreArchivo, 50);
 	Archivo.open(nombreArchivo);

 	if (Archivo.is_open()) {
	 	while (!Archivo.eof()) {

	    Archivo >> caracter;
	    if (validacion(caracter)){

            //cout<<endl;
            //cout<<caracter;
            InsertarFinal(caracter);
            //cout << "->";
            //cout << valorFueraPila(caracter)<<endl;
	    }
	    else{
            cout << "Ingrese caracteres validos para el programa."<< endl;
            break;
	    }

	 	}
	}
Archivo.close();

}

string lista::multiplicar(char *numero1, char *numero2){

    char *num1;
    char *num2;
    double a;
    double b;
    string conversion;

    a = strtod(numero1, &num1);
    b = strtod(numero2, &num2);

    float result = a * b;

    std::ostringstream ostr;
    ostr << result;
    conversion = ostr.str();
    return conversion;

}

string lista::aplicarOperando(string numero1, string numero2,string caracter){

    std::string str1 (numero1);
    std::string str2 (numero2);
    std::string operador (caracter);
    double a = atoi(str1.c_str());
    double b = atoi(str2.c_str());
    float result;
    string conversion;


    if (operador.compare("+") == 0)
        result = a + b;
    else if (operador.compare("-") == 0)
        result = a - b;
    else if (operador.compare("*") == 0)
        result = a * b;
    else if (operador.compare("^") == 0)
        result = powf(a, b);
    else {
        if (b == 0)
            return "La operacion esta indefinida.";
        else
            result = a / b;
    }

    std::ostringstream ostr;
    ostr << result;
    conversion = ostr.str();

    return conversion;

}

void lista::procesar() {

    lista Pila, ExpPostFijo, listaNumeros;
    pnodo aux = primero;
    string temporal;
    int eliminado = 0;
    string numero1;
    string numero2;
    int posicion = 0;


// Transformacion de la expresion algebraica a expresion postfijo
    while (aux != NULL){
        if (Pila.ListaVacia())
            Pila.InsertarFinal(aux -> valor);
        else {
            std::string str1 (aux -> valor);
            if ((operadorBinario(aux -> valor))&&(str1.compare(")") != 0)){
                if (valorFueraPila(aux -> valor) > valorDentroPila(Pila.Ultimo()))
                    Pila.InsertarFinal(aux -> valor);
                else {
                    temporal = Pila.Ultimo();
                    Pila.BorrarFinal();
                    Pila.InsertarFinal(aux -> valor);
                    ExpPostFijo.InsertarFinal(temporal);
                }
            }
            else if ((operadorBinario(aux -> valor))&&(str1.compare(")") == 0)) {
                std::string ultimoPila (Pila.Ultimo());
                while (eliminado != 1){
                    ExpPostFijo.InsertarFinal(Pila.Ultimo());
                    Pila.BorrarFinal();
                    std::string parada(Pila.Ultimo());
                    if (parada.compare("(") == 0)
                        eliminado += 1;
                }
                Pila.BorrarFinal();
                eliminado = 0;
            }
            else
                ExpPostFijo.InsertarFinal(aux -> valor);
        }
        aux = aux -> siguiente;
        if (aux == NULL)
            ExpPostFijo.InsertarFinal(Pila.Ultimo());
    }
    Pila.BorrarFinal();        // Elimina el ultimo nodo sobrante en la pila.
    Pila.Imprimir();           // Para saber como quedo la pila despues de la expresion postfijo.
    ExpPostFijo.Imprimir();    //Verficar visualmente la expresion postfijo.


// Realizacion de la Expresion Postfijo

    pnodo aux2 = ExpPostFijo.primero;

    while (aux2 != NULL){
       if (posicion <=1){
            numero1 = aux2 -> valor;
            numero2 = aux2 -> siguiente -> valor;
            aux2 = aux2 -> siguiente -> siguiente;
            listaNumeros.InsertarFinal(aplicarOperando(numero1, numero2, aux2 -> valor));
            aux2 = aux2 -> siguiente;
            posicion += 3;
       }
       else if (posicion % 2 == 0){
            listaNumeros.BorrarFinal();
            listaNumeros.InsertarFinal(aplicarOperando(numero1, numero2, aux2 -> valor));
            aux2 = aux2 -> siguiente;
            posicion ++;
       }
       else{
            numero1 = listaNumeros.Ultimo();
            numero2 = aux2 -> valor;
            aux2 = aux2 -> siguiente;
            posicion ++;
       }
    }
    listaNumeros.Imprimir();
}












