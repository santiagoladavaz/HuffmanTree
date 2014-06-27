#include <iostream>
#include "PriorityQueue.h"
#include "HuffmanTree.h"
#include <stdlib.h>


struct PriorityQueueStr{

    HuffmanTree* htrees; // array de HuffmanTree
    int size; //largo del array htrees
	int sizepq; // cantidad de elementos del pq

};


/*************************************/
/* Implementacion de las operaciones */
/*************************************/



// Construye una PriorityQueue vacía.
PriorityQueue emptyPriorityQueue(){

    PriorityQueue pq = new PriorityQueueStr;
    pq->sizepq = 256;
    pq->htrees = new HuffmanTree[ pq->sizepq + 1];
    pq->size = 0;
    pq->htrees[0]= leaf('a',0); // Centinela

    return pq;

}

// Libera la memoria utilizada por la PriorityQueue.
void deletePriorityQueue(PriorityQueue& q){

    delete[] q->htrees;
    delete q;

}

// Retorna la cantidad de elementos en la PriorityQueue.
int size(PriorityQueue q){

    return q->size;
}



bool isEmpty(PriorityQueue q){

    return q->size == 0;
}



// Agrega un elemento a la PriorityQueue.
//NOTA: Al iniciar el array de HuffmanTree en 256 no hace falta el resize
void enqueue(PriorityQueue& q, HuffmanTree t){

    int i;

    i= ++(q->size);

    while(weight(q->htrees[i/2]) > weight(t)){

        q->htrees[i] = q->htrees[i/2];
        i = i/2;
    }

    q->htrees[i]=t;

}

// Remueve y retorna el elemento de menor prioridad de la PriorityQueue.
// PRE: La PriorityQueue no puede estar vacia
HuffmanTree dequeue(PriorityQueue& q){

    int i;
    int child;

    HuffmanTree minHTree = q->htrees[1];
    HuffmanTree lastElem = q->htrees[q->size--];

    for(i=1; i*2 <= q->size; i=child){
        child = i*2;

        if(child != q->size && weight(q->htrees[child + 1]) < weight(q->htrees[child])){
            child++;
        }

        if(weight(lastElem) > weight(q->htrees[child])){
            q->htrees[i] = q->htrees[child];
        }
        else{break;}
    }

    q->htrees[i] = lastElem;

   return minHTree;
}



