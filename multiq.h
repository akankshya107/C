#include <stdio.h>
#define NEW_ELE
typedef long int TaskId;
typedef int Priority;
typedef struct{
	TaskId tid;
	Priority p;
}Task;
struct Element{
	Task *t;
	struct Element *next;
};
typedef struct Element Element;

#include "que.h"
typedef struct{
	Priority p;
	Queue *q;
}ModifiedQueue;

typedef struct{
	int num;
	ModifiedQueue *sche[0];
}MultiQ;

MultiQ* createMQ(int num); // creates a list of num Queues, each of which is empty.
MultiQ* addMQ(MultiQ *mq, Task *t); // adds t to the Queue corresponding to priority p in mq. Task includes a TaskID tid and a priority p.
Task* nextMQ(MultiQ *mq); // returns the front of the non-empty Queue in mq with the highest priority.
MultiQ* delNextMQ(MultiQ *mq); // deletes the front of the non-empty Queue in mq with the highest priority; returns the modified MultiQ
bool isEmptyMQ(MultiQ *mq); // tests whether all the Queues in mq are empty
int sizeMQ(MultiQ *mq); // returns the total number of items in the MultiQ
int sizeMQbyPriority(MultiQ *mq, Priority p); //returns the number of items in mq with the priority p.
Queue* getQueueFromMQ(MultiQ *mq, Priority p); //returns the Queue with priority p
Element* returnElement(Task *t);
Task* returnTask(TaskId tid, Priority p);
ModifiedQueue* returnModifiedQ();

MultiQ* loadData(FILE *f, MultiQ *mq); //reads from f a list of pairs (task_id, priority) and adds each item to a MultiQ appropriately
MultiQ* testDel(int num, MultiQ *mq); //performs num of delNextMQ operations
