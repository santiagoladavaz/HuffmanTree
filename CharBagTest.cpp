#include "CharBag.h"
#include <iostream>
#include "assert.h"

using namespace std;


///////////////////
//  Test CharBag
//////////////////


void testEmptyCharBag(){

    CharBag charBag = emptyCharBag(256);

    for(int i=0; i<=256; i++){
        assert(get(charBag,i) == 0);
    }

    deleteCharBag(charBag);
    std::cout << "testEmptyCharBag - OK" << std::endl;

}


void testAdd(){
    CharBag charBag = emptyCharBag(256);

    add(charBag,'a');
    assert(get(charBag,'a') == 1);

    add(charBag,'a');
    assert(get(charBag,'a') == 2);


    deleteCharBag(charBag);

    std::cout << "testAdd - OK" << std::endl;

}


void testGet(){

    CharBag charBag = emptyCharBag(256);
    assert(get(charBag,'a') == 0);

    add(charBag,'a');
    add(charBag,'a');
    assert(get(charBag,'a') == 2);

    deleteCharBag(charBag);

    std::cout << "testGet - OK" << std::endl;

}


////////////////////////
//  Test CharBagIterator
///////////////////////

void testNext(){

    CharBag charBag = emptyCharBag(256);
    add(charBag,'a');
    add(charBag,'b');
    CharBagIterator it = iterate(charBag);
    next(it);
    assert(currentChar(it) == 'b');

    deleteCharBagIterator(it);
    std::cout << "testNext - OK" << std::endl;

}


void testCurrentChar(){

    CharBag charBag = emptyCharBag(256);
    add(charBag,'a');
    CharBagIterator it = iterate(charBag);
    assert(currentChar(it) == 'a');


    deleteCharBagIterator(it);
    std::cout << "testCurrentChar - OK" << std::endl;

}


void testCurrentCount(){

    CharBag charBag = emptyCharBag(256);
    add(charBag,'a');
    CharBagIterator it = iterate(charBag);

    assert(currentCount(it) == 1);

    add(charBag,'a');
    assert(currentCount(it) == 2);


    deleteCharBagIterator(it);
    std::cout << "testCurrentCount - OK" << std::endl;

}


void testValid(){
    CharBag charBag = emptyCharBag(256);
    add(charBag,'a');
    CharBagIterator it = iterate(charBag);

    assert(valid(it));

    deleteCharBagIterator(it);
    std::cout << "testValid - OK" << std::endl;


}

