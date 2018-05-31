int binarySearch(Element k, Element *a, int lo, int hi){
	int x = rand()%(hi-lo+1);
	if(a[x]==k) return x+1;
	else if(a[x]<=k) return binarySearch(k,a,x+1,hi);
	else return binarySearch(k,a,lo,x);
}
