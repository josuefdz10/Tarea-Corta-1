#include <stdio.h>
#ifndef LISTA_H
#define LISTA_H



class nodo {
   public:
    nodo(char v)
    {
       valor = v;
       siguiente = NULL;
    }
    nodo(char v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    char valor;
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
    void InsertarInicio(char v);
    void InsertarFinal(char v);
    void InsertarPos (char v, int pos);
    void EliminarInicio();
    void EliminarFinal();
    void EliminarPos(int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Borrar(int v);
    void Siguiente();
    void Primero();
    void Ultimo();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();

    //Atributos
    private:
    pnodo primero;
    pnodo actual;
};

#endif // LISTA_H
