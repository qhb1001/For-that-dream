#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 10;
int L[maxn], R[maxn];
bool vis[maxn];

int main()
{
	freopen("input", "r", stdin);
	freopen("output.b", "w", stdout);
    int N, M, a, r, i;
    while(scanf("%d%d", &N, &M) == 2){
        memset(vis, 0, sizeof(vis));
        long long sum = 0;
        for(i = 1; i <= N; i++){
            scanf("%d", &a);
            sum += a;
            r = (sum % M + M) % M;
            if(!vis[r]){
                vis[r] = 1;
                L[r] = i;
            }
            R[r] = i;
        }
        L[0] = 0;       //这个超级重要，没有就一直WA！
        int Max = 0;
        if(r == 0) Max = N;
        else for(i = 0; i < M; i++) if(vis[i]) Max = max(Max, R[i] - L[i]);
        printf("%d\n", Max);
    }
    return 0;
}

