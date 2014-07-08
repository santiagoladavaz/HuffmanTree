#include <iostream>
#include <sstream>

#include "ArrayList.h"

struct ArrayListStr {
	int* elems;
	int capacity;
	int last;
};


ArrayList emptyArrayList() {
	ArrayListStr* result = new ArrayListStr;
	result->capacity = 256;
	result->elems = new int[result->capacity];
    result->last = 0;

	return result;
}

void deleteArrayList(ArrayList& l) {
	delete[] l->elems;
	delete l;
}

int size(ArrayList l) {
	return l->last;
}

bool isEmpty(ArrayList l) {
	return size(l) == 0;
}

int get(ArrayList l, int i) {
	return l->elems[i];
}

void set(ArrayList& l, int i, int n) {
	l->elems[i] = n;
}

void resize(ArrayList& l) {
	if (l->capacity == l->last) {
		int* elems = new int[l->capacity <<= 1];
		for (int i = 0; i < l->last; ++i)
			elems[i] = l->elems[i];
		delete[] l->elems;
		l->elems = elems;
	}
}

void push(ArrayList& l, int n) {
	resize(l);
	l->elems[l->last] = n;
	l->last++;
}

int pop(ArrayList& l) {
	l->last--;
	return l->elems[l->last];
}

void removeL(ArrayList& l, int charB){
    int encontrado=0;
    int i=0;

    while (!encontrado && i < l->last){
       if (l->elems[i] == charB){
            encontrado = 1;
            int k = i + 1;

            while (k < l->last){
                l->elems[k-1] = l->elems[k];
                k++;
            }

            l->last--;
        }

        i++;
    }


}



struct ArrayListIteratorStr {
	ArrayList list;
	int index;
};


ArrayListIterator iterate(ArrayList l) {
	ArrayListIteratorStr* result = new ArrayListIteratorStr;
	result->list = l;
	result->index = 0;
	return result;
}

void deleteIterator(ArrayListIterator& it) {
	delete it;
}

bool valid(ArrayListIterator it) {
	return it->index < size(it->list);
}

int getCurrent(ArrayListIterator it) {
	return get(it->list, it->index);
}

void setCurrent(ArrayListIterator it, int n) {
	set(it->list, it->index, n);
}

void next(ArrayListIterator& it) {
	it->index++;
}

void insert(ArrayListIterator it, int n) {
	resize(it->list);
	it->list->last++;
	for (int i = it->list->last-1; i >= it->index; --i)
		set(it->list, i, get(it->list, i-1));
	set(it->list, it->index, n);
}

void remove(ArrayListIterator it) {
	for (int i = it->index; i < it->list->last; ++i)
		set(it->list, i, get(it->list, i+1));
	it->list->last--;
}

std::string toString(ArrayList l) {
	std::stringstream sout;
	sout << "[ ";
	ArrayListIterator it;
	for (it = iterate(l); valid(it); next(it))
		sout << getCurrent(it) << " ";
	sout << "]";
	deleteIterator(it);
	return sout.str();
}

void print(ArrayList l) {
	std::cout << toString(l) << std::endl;
}


