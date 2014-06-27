#include "CharBag.h"
#include "ArrayList.h"
#include <iostream>

using namespace std;

// INV. DE REPRESENTACION
// -> El Charbag no tiene elementos repetidos
// -> EL INVARIANTE
// ->



struct CharBagStr{

	int* bag;
	ArrayList listIterator;

};


/*************************************/
/* Implementacion de las operaciones */
/*************************************/


// Retorna un CharBag vacío, con capacidad para almacenar n chars.
CharBag emptyCharBag(int n){

    //Probar siempre con n = 256
    CharBag newBag = new CharBagStr;

    newBag-> bag= new int[n];

    //Inicializo mi bag en 0.
    for(int i =0; i<n ; i++)
        newBag->bag[i] = 0;

    //Creo la lista donde se guardan los chars que hayan aperecido por primera vez
    newBag-> listIterator = emptyArrayList();

    return newBag;

}


// Libera la memoria utilizada por el CharBag c.
void deleteCharBag(CharBag& b){

    delete[] b->bag;
    deleteArrayList(b->listIterator);
    delete b;

}

// Agrega una ocurrencia del caracer c en el CharBag.
void add(CharBag& b, unsigned char c){

    b->bag[(int) c] = b->bag[(int) c] + 1;

    //Si es la primera vez que inserto char c, agrego su posicion a la lista
    if( b->bag[(int) c] == 1)
        push(b->listIterator, (int)c);
}


// Retorna la cantidad de ocurrencias del caracter c en el CharBag.
int get(CharBag& b,unsigned char c){

    return b->bag[(int)c];

}


////////////////////
// Char Bag Iterator
///////////////////

struct CharBagIteratorStr{

    CharBag charBag;

    //Iterador definido en ArrayList junto con sus operaciones
    ArrayListIterator arrayIterator;

};



// Construye un iterador a un CharBag apuntando al primer elemento definido.
CharBagIterator iterate(CharBag b){
    CharBagIterator newBagIterator = new CharBagIteratorStr;

    newBagIterator->charBag = b;
    newBagIterator->arrayIterator = iterate(b->listIterator);

    return newBagIterator;

}

// Libera la memoria correspondiente al iterador.
void deleteCharBagIterator(CharBagIterator& it){

    delete it;

}

// Indica si el iterador apunta a un element válido.
bool valid(CharBagIterator it){

    return valid(it->arrayIterator);

}

// Avanza al siguiente elemento definido en el CharBag
// (aquellos con ocurrencias mayor a cero)
void next(CharBagIterator it){
    next(it->arrayIterator);
}

// Retorna el caracter actualmente apuntado por el iterador.
char currentChar(CharBagIterator it){
    int c = getCurrent(it->arrayIterator);
    return (char) c;

}

// Retorna la cantidad de ocurrencias del caracter actualmente apuntado por el iterador.
int currentCount(CharBagIterator it){

    int indice = getCurrent(it->arrayIterator);
    return it->charBag->bag[indice];

}
