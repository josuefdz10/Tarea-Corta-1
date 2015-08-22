#include <Cola.h>
#ifndef ARCHIVOS_H
#define ARCHIVOS_H

class Archivos
{
    public:
        Archivos(){

        }

        void Leer();

    private:
        Cola cola;

    friend class nodo;

};

#endif // ARCHIVOS_H
