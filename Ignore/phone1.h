typedef char* Name;
typedef long unsigned int Number;

typedef struct{
	Name nm;
	OrderByNumberRec *obnr;
}OrderByNameRec;

typedef struct{
	int size;
	OrderByNameRec *arr[];
}OrderByName;

typedef struct{
	Number nr;
	OrderByNameRec *obnr;
}OrderByNumberRec;

typedef struct{
	int size;
	OrderByNumberRec *arr[];
}OrderByNumber;

typedef struct{
	OrderByName *nameo;
	OrderByNumber *numbero;
}List;

Number searchByName(Name nm);
Name searchByNumber(Number nr);
List* createNewList();
OrderByNameRec* nameRec(Name nm);
OrderByNumberRec* numberRec(Number nr);
void readFromFile(FILE *ptr);
