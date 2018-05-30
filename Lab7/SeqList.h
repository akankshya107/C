typedef int Key;
struct Element{
  Key key;
  struct Element *next;
};

typedef struct Element Element;

struct SeqList{
  int size;
  Element *head;
  Element *tail;
};

typedef struct SeqList SeqList;

SeqList* newList(); // creates an empty list
SeqList* insertInOrder(SeqList *sl, Element *e); // add e to sl in order of key assuming sl is ordered; return the modified list
SeqList* insertAtFront(SeqList *sl, Element *e); // add e at the front of the list; return the modified list
SeqList* insertAtEnd(SeqList *sl, Element *e); // add e at the end of the list; return the modified list
SeqList* delete(SeqList *sl, Element *e); // delete e from sl; return the modified list
SeqList* deleteAtFront(SeqList *sl); // delete the first element from sl; return the modified list
Element* find(SeqList *sl, Key k); // find the element e with key k in sl; return e
Element* createElem(Key k); //creates element with key k
SeqList* merge(SeqList *s1, SeqList *s2); //merges two sequential lists
SeqList* insertionsort(SeqList *sl); //sorts unordered list according to key
