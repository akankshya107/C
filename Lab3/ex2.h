#ifndef ELE
#define NEW_ELE
struct Space{
	int size;
	void* ptr;
	struct Space *next;
};
typedef struct Space Space;
typedef struct {
	Space *head;
	unsigned int tsize;
}Allocated;
static Allocated *spaceAllocated;

#endif
#ifndef NEW_ELE
unsigned int spaceAllocated;
#endif
void init();
void* myalloc(unsigned int size); //returns starting address of space allocated
void myfree(void *ptr); //frees space pointed to by given argument
