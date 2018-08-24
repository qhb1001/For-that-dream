#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 705;
bool dp[MAX][MAX], G[MAX][MAX], L[MAX][MAX], R[MAX][MAX];
int a[MAX];
int gcd(int a, int b) {
    return b == 0? a : gcd(b, a%b);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)    scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= i; ++j)   {
            if (gcd(a[i], a[j]) != 1) {
                G[i][j] = G[j][i] = 1;
            }    
        }
    

    for (int i = 1; i <= n; ++i) {
        dp[i][i] = L[i][i] = R[i][i] = 1;
    }

    int r, l;
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            r = i + len - 1;
            l = i;
            for (int mid = i; mid <= r; ++mid) {
                if (L[i][mid] && R[mid][r]) {
                    dp[l][r] = 1;
                    L[l][r + 1] |= G[mid][r + 1];
                    R[l - 1][r] |= G[mid][l - 1];
                }
            }
        }
    }


    printf("%s\n", dp[1][n]? "Yes":"No");

}