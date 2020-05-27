
int Next[10005];
int kmp(int *s, int n, int *p, int m){
	Next[0] = -1;
	int j = -1;
	for(int i = 1; i < m; i++){
		while(j >= 0 && p[j + 1] != p[i]) j = Next[j];
		if(p[j + 1] == p[i]) Next[i] = ++j;
	}
	
	j = -1;
	int res = -1;
	for(int i = 0; i < n; i++){
		while(j >= 0 && p[j + 1] != s[i]) j = Next[j];
		if(p[j + 1] == s[i]){
			j++;
		}
		if(j == m - 1){
			res = i - m + 2;
			break; 
		}
	}
	return res;
}