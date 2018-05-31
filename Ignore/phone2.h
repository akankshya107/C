typedef char* Name;
typedef long unsigned int Number;

typedef struct{
	Name nm;
	Number nr;
}Record;

typedef struct{
	int size;
	int no_of_rec;
	Record *arr[];
}Array;

typedef Array *orderbyname, *orderbynumber;
void init();
void addRecord(Name name, Number no);
Name findName(Number no);
Number findNumber(Name name);
void incomingCall(Number no);


//when is it necessary to store records in a separate array instead of storing them loose
