#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 5;
int Next[MAX];
void getNext(char *a, int len) {
    int i = 0, j = -1;
    Next[0] = -1;
    while(i < len) {
        if(j == -1 || a[i] == a[j]) {
            Next[++i] = ++j;
        } else {
            j = Next[j];
        }
    }
}

int KmpSearch(char* s, char* p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	int ans = 0;
	while (i < sLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
			//next[j]即为j所对应的next值
			j = Next[j];
		}
		if (j == pLen)	{
			++ans;
			j = Next[pLen];
		}

		//cout << j << endl;
	}
	return ans;
}
int n, a, b, L, R;
char s[MAX], t[MAX];
int main() {
	scanf("%d%d%d%d%d", &n, &a, &b, &L, &R);
	int now = b;
	for (int i = 0; i < n; ++i) {
		if (now <= R && now >= L) {
			if (now % 2)	s[i] = 'T';
			else	s[i] = 'A';
		} else {
			if (now % 2)	s[i] = 'C';
			else	s[i] = 'G';
		}
		now = (now + a) % n;
	}
//	printf(" %s\n", s);

	scanf("%s", t);
	int len = strlen(t);
	getNext(t, len);
	printf("%d\n", KmpSearch(s, t));
	return 0;
}
