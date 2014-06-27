#include "PriorityQueue.h"
#include "assert.h"
#include "HuffmanTree.h"
#include <iostream>

using namespace std;





void testEmptyPriorityQueue(){
    PriorityQueue pq = emptyPriorityQueue();
    assert(size(pq) == 0);

    std::cout << "testEmptyPriorityQueue - OK" << std::endl;

    deletePriorityQueue(pq);

}


void testEnqueue() {
    PriorityQueue pq = emptyPriorityQueue();
    HuffmanTree leaf1 = leaf('a', 4);
    enqueue(pq, leaf1);
    assert(size(pq) == 1);

    HuffmanTree leaf2 = leaf('b', 5);
    enqueue(pq, leaf2);
    assert(size(pq) == 2);

    std::cout << "testEnqueue - OK" << std::endl;


    deletePriorityQueue(pq);

}


void testDequeue() {
    PriorityQueue pq = emptyPriorityQueue();
    HuffmanTree leaf1 = leaf('a', 1);
    HuffmanTree leaf2 = leaf('b', 2);
    HuffmanTree leaf3 = leaf('c', 3);
    HuffmanTree leaf4 = leaf('d', 5);
    HuffmanTree leaf5 = leaf('e', 6);
    HuffmanTree leaf6 = leaf('f', 4);

    enqueue(pq, leaf1);
    enqueue(pq, leaf2);
    enqueue(pq, leaf3);
    enqueue(pq, leaf4);
    enqueue(pq, leaf5);
    enqueue(pq, leaf6);

    assert(weight(dequeue(pq)) == 1);
    assert(weight(dequeue(pq)) == 2);
    assert(weight(dequeue(pq)) == 3);
    assert(weight(dequeue(pq)) == 4);
    assert(weight(dequeue(pq)) == 5);
    assert(weight(dequeue(pq)) == 6);

    std::cout << "testDequeue - OK" << std::endl;

    deletePriorityQueue(pq);
}
