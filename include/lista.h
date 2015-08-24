#include <stdio.h>
#include <string>
#ifndef LISTA_H
#define LISTA_H
#include <fstream>
#include <iostream>

using namespace std;



class nodo {
   public:
    nodo(string v)
    {
       valor = v;
       siguiente = NULL;
    }
    nodo(string v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    string valor;
    nodo *siguiente;
    int prioridad;


   friend class lista;
};

typedef nodo *pnodo;

class lista {
   public:
       //Constructor
    lista() { primero = actual = NULL; }
    ~lista();

    //Funciones
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Siguiente();
    void Primero();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void Leer();
    int validacion(char *caracter);
    int valorDentroPila(string caracter);
    int operadorBinario(string caracter);
    int valorFueraPila(string caracter);
    string Ultimo();
    void procesar();
    string multiplicar(char *numero1, char *numero2);
    string sumar(char *numero1, char *numero2);
    string restar(char *numero1, char *numero2);
    string dividir(char *numero1, char *numero2);
    string elevar(char *numero1, char *numero2);
    string aplicarOperando(string numero1, string numero2,string caracter);

    //Atributos
    private:
    pnodo primero;
    pnodo actual;
};

#endif // LISTA_H
