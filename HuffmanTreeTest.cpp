#include <iostream>
#include "assert.h"
#include "HuffmanTree.h"

using namespace std;


void testLeaf(){

    HuffmanTree leaf1 = leaf('a',1);

    assert(weight(leaf1) == 1);
    deleteHuffmanTree(leaf1);

    std::cout << "testLeaf - OK" << std::endl;
}


void testBinary(){
    HuffmanTree leaf1 = leaf('a',1);
    HuffmanTree leaf2 = leaf('b',2);
    HuffmanTree t = binary(leaf1,leaf2);

    assert(weight(t) == 3);
    deleteHuffmanTree(t);

    std::cout << "testBinary - OK" << std::endl;
}


void testWeight(){

    HuffmanTree leaf1 = leaf('a',1);
    HuffmanTree leaf2 = leaf('b',2);
    HuffmanTree leaf3 = leaf('c',3);
    HuffmanTree leaf4 = leaf('d',4);
    HuffmanTree t1 = binary(leaf1,leaf2);
    HuffmanTree t2 = binary(leaf3,leaf4);

    HuffmanTree t3 = binary(t1,t2);

    assert(weight(t3) == 10);
    deleteHuffmanTree(t3);

    std::cout << "testWeight - OK" << std::endl;
}



