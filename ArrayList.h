// Estructura de los ArrayList.
struct ArrayListStr;
typedef ArrayListStr* ArrayList;

// Retorna una lista vacia.
ArrayList emptyArrayList();


// Borra la lista.
void deleteArrayList(ArrayList& l);

// Indica si la lista esta vacia.
bool isEmpty(ArrayList l);

// Retorna el tamaño de la lista.
int sizeL(ArrayList l);

// Retorna el elemento en la i-esima posicion.
// PRE: i < size(l)
int get(ArrayList l, int i);

// Altera el valor del elemento en la i-esima posicion.
// PRE: i < size(l)
void setL(ArrayList& l, int i, int n);

// Agrega el elemento n al final de la lista.
void push(ArrayList& l, int n);

// Retorna el elemento al final de la lista y lo remueve.
// PRE: !isEmpty(l)
int pop(ArrayList& l);


// Estructura de los iteradores de ArrayList.
struct ArrayListIteratorStr;
typedef ArrayListIteratorStr* ArrayListIterator;

// Retorna un iterador al inicio de la lista l.
ArrayListIterator iterate(ArrayList l);

// Destruye el iterador.
void deleteIterator(ArrayListIterator& it);

// Indica si el iterador apunta a un elemento valido.
bool valid(ArrayListIterator it);

// Retorna el elemento actualmente apuntado por el iterador.
// PRE: valid(it)
int getCurrent(ArrayListIterator it);

// Altera el valor del elemento apuntado.
// PRE: valid(it)
void setCurrent(ArrayListIterator it, int n);

// Avaza a la siguiente posicion.
// PRE: valid(it)
void next(ArrayListIterator& it);

// Inserta un elemento n delante de la posicion apuntada por it.
void insert(ArrayListIterator it, int n);

// Remueve el elemento apuntado por it, el iterador queda apuntando al siguiente.
void remove(ArrayListIterator it);

// Recorre la lista imprimiendo todos los valores.
void print(ArrayList l);

