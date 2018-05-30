#include <stdbool.h>
#ifndef NEW_ELE
#define ELE
struct Element{
  int data;
  struct Element *next;
};

typedef struct Element Element;
Element* returnEle(int data); //returns element with data
#endif

struct Queue{
  int size;
  Element *head;
  Element *tail;
};

typedef struct Queue Queue;

Queue* newQ(); // returns an empty Queue
bool isEmptyQ(Queue *q); // tests whether q is empty
Queue* delQ(Queue *q); // deletes the element from the front of the Queue; returns the modified Queue
Element* front(Queue *q); // returns the element from the front of the Queue;
Queue* addQ(Queue *q , Element *e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue *q); // returns the length of the Queue

