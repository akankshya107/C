#include <stdbool.h>
struct Ele{
  int data;
  struct Ele *next;
};

typedef struct Ele Ele;
Ele* returnEle(int data); //returns Ele with data

struct Queue{
  int size;
  Ele *head;
  Ele *tail;
};

typedef struct Queue Queue;

Queue* newQ(); // returns an empty Queue
bool isEmptyQ(Queue *q); // tests whether q is empty
Queue* delQ(Queue *q); // deletes the Ele from the front of the Queue; returns the modified Queue
Ele* front(Queue *q); // returns the Ele from the front of the Queue;
Queue* addQ(Queue *q , Ele *e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue *q); // returns the length of the Queue

