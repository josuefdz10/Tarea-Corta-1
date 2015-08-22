#ifndef PILA_H
#define PILA_H

class Pila
{
   private:
       int Tope;
       int tamano;
       int pila[5];
    public:
        //Constructor
       Pila(){
	       	Tope = -1;
	       	tamano = sizeof(pila)/sizeof(int);
	       	/*for(int i =0;i<tamano;i++){
	         	pila[i]=0;
	    	}*/
       }

    //Funciones
       void push(int v);

       void pop ();

       void imprimir();

       bool pilaVacia(){return Tope < 0;}

};


#endif // PILA_H
