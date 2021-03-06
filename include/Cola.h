#ifndef COLA_H
#define COLA_H
#include <lista.h>


class Cola
{
    private:
        int frente;
        int fondo;
        int cola[5];
        int tamano;

    public:
        //Constructor
       Cola(){
           frente = 0;
           fondo = -1;
           tamano = sizeof(Cola)/sizeof(int);

       }
       //Funciones
       bool ColaVacia(){return fondo < frente;}
	   void insertar(int v);
	   void eliminar ();
	   void imprimir();
};

#endif // COLA_H
