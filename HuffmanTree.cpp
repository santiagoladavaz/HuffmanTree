#include <iostream>
#include "HuffmanTree.h"
#include "ZipTable.h"
#include "ArrayList.h"
#include "PriorityQueue.h"

// INV. DE REPRESENTACION
// -> El peso del arbol sera igual a la suma de los pesos de sus hijos.
// -> Si es una hoja sus hijos deben ser NULL y char asociado.
// -> Si es un arbol no tiene un char asociado.


struct HuffmanTreeStr{

    char c;
    int weight;
    HuffmanTreeStr* t1;
    HuffmanTreeStr* t2;

};


// Construye una hoja de un árbold de Huffman a partir de un caracter y un peso.
HuffmanTree leaf(char c, int w){

    HuffmanTree newLeaf = new HuffmanTreeStr;
    newLeaf->c = c;
    newLeaf->weight = w;
    newLeaf->t1 = NULL;
    newLeaf->t2 = NULL;

    return newLeaf;
}

// Construye una nodo binario de un árbol de Huffman a partir de dos hijos.
HuffmanTree binary(HuffmanTree a, HuffmanTree b){


    HuffmanTree newBinary = new HuffmanTreeStr;

    //El peso de newBinary sera la suma de los pesos de sus hijos
    newBinary->weight = a->weight + b->weight;

    newBinary->t1 = a;
    newBinary->t2 = b;

    return newBinary;

}



bool isEmpty(HuffmanTree t){
    return t==NULL;
}


// Libera toda la memoria utilizada por un árbol de Huffman.
//Hecho de forma iterativa, ayudado por PriorityQueue.
void deleteHuffmanTree(HuffmanTree& t){

        PriorityQueue pendientes = emptyPriorityQueue();
        enqueue(pendientes,t);

        //Mientras haya elementos por borrar
        while(not isEmpty(pendientes)){

            //Agarro el primer elemento de la cola
            HuffmanTree current = dequeue(pendientes);

            //Agrego los hijos de current a la cola,si es que no son NULL
            if(not isEmpty(current->t1))
                enqueue(pendientes,current->t1);
            if(not isEmpty(current->t2))
                enqueue(pendientes,current->t2);

            //Borro current
            delete current;
        }

}


// Retorna el peso de un árbol de Huffman.
int weight(HuffmanTree t){

    return t->weight;
}



ZipTable buildTableAux(ZipTable zipTable, HuffmanTree tree, BitChain bitChain) {

    //Si es una hoja agrego el char a la tabla con su bitChain
    if(tree->t1 == NULL && tree->t2 == NULL) {
        add(zipTable, tree->c, bitChain);

    } else {
        // Voy recorriendo el arbol izquierdo
        append(bitChain, false);
        buildTableAux(zipTable, tree->t1, bitChain);
        remove(bitChain);

        //Voy recorriendo el arbol derecho
        append(bitChain, true);
        buildTableAux(zipTable, tree->t2, bitChain);
        remove(bitChain);
    }

    return zipTable;
}



ZipTable buildTable(HuffmanTree t) {

    ZipTable zipTable = emptyZipTable();
    BitChain bitChain = emptyBitChain();

    ZipTable res = buildTableAux(zipTable, t, bitChain);

    return res;
}
