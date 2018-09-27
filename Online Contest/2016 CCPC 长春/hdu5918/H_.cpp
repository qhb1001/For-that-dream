#include <stdio.h>
#include <string.h>
 
#define maxn 10010
 
int next[maxn];
char str[maxn], buf[maxn * 100];
 
void getNext() {
	int i = 0, j = -1;
	next[i] = j;
	while(str[i]) {
		if(j == -1 || str[i] == str[j]) {
			++i; ++j;
			if(str[i] == str[j]) 
				next[i] = next[j];
			else next[i] = j;
		} else j = next[j];
	}
}


void KMP() {
	getNext();
	int i = 0, j = 0, ans = 0;
	while(buf[i]) {
		if(j == -1 || buf[i] == str[j]) {
			++i; ++j;
			if(!str[j]) {
				++ans; j = next[j];
			}
		} else j = next[j];
	}
	printf("%d\n", ans);
}
 
int main() {
	// freopen("stdin.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	while(N--) {
		scanf("%s%s", str, buf);
		KMP();
	}
	return 0;
}

