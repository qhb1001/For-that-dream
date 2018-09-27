#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 5e5 + 5;
char s[MAX], Ma[MAX*2];
int bit[MAX], n, p[MAX*2], len, Mp[MAX*2];
int Manacher(char s[],int len)
{
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for(int i = 0; i<len; i++)
    {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for(int i = 0; i<l; i++)
    {
        Mp[i] = mx>i ? min(Mp[2*id-i],mx-i) : 1;
        while(i-Mp[i]>=0 && Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
    return l;
}
int lowbit(int x) {return x & -x;}
void add(int i, int x) {
    for (; i <= n; i += lowbit(i)) bit[i] += x;
}
int query(int i) {
    int ans = 0;
    for (; i; i -= lowbit(i)) ans += bit[i];
    return ans;
}
vector<int>q[MAX];
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", s);
        len = strlen(s);
        memset(bit, 0, sizeof(bit));
        for (int i = 0; i <= len; ++i) q[i].clear();
        int l = Manacher(s, len), cnt = 1;
        n = len;
        for (int i = 2; i < l; i += 2) {
            p[cnt] = Mp[i] / 2 - 1;
            q[cnt - p[cnt]].push_back(cnt);
            ++cnt;
        }

        
        long long ans = 0;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < q[i].size(); ++j) add(q[i][j], 1);
            ans += query(min(i + p[i], len)) - query(i);
        }

        printf("%lld\n", ans);
    }
}


