int partition(int* a, int left, int right){
	int x = a[(left + right) >> 1];
	int i = left, j = right;
	while(true){
		while(a[i] < x) ++i;
		while(a[j] > x) --j;
		if(i >= j) return j;
		swap(a[i], a[j]);
		++i;
		--j;
	}
}

void quick_sort(int* a, int left, int right){
	if(left >= right) return;
	int p = partition(a, left, right);
	quick_sort(a, left, p);
	quick_sort(a, p + 1, right);
}