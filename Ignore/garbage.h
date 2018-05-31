typedef void *PTR;
typedef struct{
	int no_of_sections;
	int block_size;
	PTR *list;
}FreeList;
typedef struct{
	PTR ptr;
	int size;
}Allocated;
typedef struct{
	Allocated *list;
	int no_of_sections;
}AllocatedList;
void mark();
void sweep(void **st);
