typedef struct{
	int n;
	int *arr[];
}Array;

int determinant(Array *a){
	if(a->n==2) return (a->arr[0]
