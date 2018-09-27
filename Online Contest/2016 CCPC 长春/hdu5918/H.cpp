#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 1e6 + 5;
int nex[MAX];
void get_next(int *b, int m)
{
	int i = 0, j = -1;
	nex[i] = j;
	while(i < m) {
		if(j == -1 || b[i] == b[j]) {
			++i; ++j;
			nex[i] = j;
		} else j = nex[j];
	}
}
int kmp(int *buf,int *str, int n, int m)
{
	int i = 0, j = 0, ans = 0;
	while(i < n) {
		if(j == -1 || buf[i] == str[j]) {
			++i; ++j;
			if(j == m) {
				++ans; j = nex[j];
			}
		} else j = nex[j];
	}
	return ans;
}
int a[MAX], b[MAX], vis[MAX], c[MAX];
int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.a", "w", stdout);

    int T, n, m, p, kase = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &p);
        int ans = 0;
        printf("Case #%d: ", kase++);
        for (int i = 0; i < n; ++i)    scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i)    scanf("%d", &b[i]);
        if (m > n) {printf("0\n"); continue;}

        get_next(b, m);
        for (int i = 0; i < n; ++i) if (vis[i] != kase) {
            if (i + (m - 1) * p >= n)    break;
            int idx = 0;
            for (int j = 0; i + j * p < n; ++j) {
                vis[i + j * p] = kase;
                c[idx++] = a[i + j * p];
            }
            ans += kmp(c, b, idx, m);
        }

        printf("%d\n", ans);
    }
}