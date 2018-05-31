//k=3
//Time taken is ϴ(n(log(base k)n))
void mergeSort(Array *a, int lo, int high){
	mid1=(lo+hi)/3;
	mid2=((lo+hi)*2)/3;
	mergeSort(a,lo,mid1);
	mergeSort(a,mid1+1,mid2);
	mergeSort(a,mid2+1,hi);
	merge(a,lo,mid1,a,mid1+1,mid2,a,lo,mid2);
	merge(a,lo,mid2,a,mid2+1,hi,a,lo,hi);
}
