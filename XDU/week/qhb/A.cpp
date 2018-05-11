#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool check(int *letter, char *s) {
	int len = strlen(s), now[30];
	memcpy(now, letter, sizeof(now));
	for (int i = 0; i < len; ++i)
		if (!now[s[i] - 'a'])	return false;
		else	now[s[i] - 'a']--;
	return true;
}
int main() {
	char s[100];
	while (scanf("%s", s) != EOF) {
		int len = strlen(s);
		int n;
		scanf("%d", &n);
		int Max = 0, letter[30] = {0};
		for (int i = 0; i < len; ++i)	letter[s[i] - 'a']++;
		while (n--) {
			char t[30];
			scanf("%s", t);
			if (check(letter, t))	Max = max(Max, (int)strlen(t));
		}
		printf("%d\n", Max);
	}
}
