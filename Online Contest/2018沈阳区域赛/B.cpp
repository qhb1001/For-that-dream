#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring> 
using namespace std;
typedef long long ll;
const int MAX = 110;
ll d[MAX][MAX][2];
stack<int>ss;
char s[MAX];
bool vis[MAX][MAX][2];
int A[MAX], len;
void init() {
    memset(vis, 0, sizeof(vis));
    memset(A, 0, sizeof(A));
    memset(d, 0, sizeof(d));
}
ll dfs(int l, int r, int flag) {
    if (s[l] == '(' && A[l] == r)   return dfs(l + 1, r - 1, flag);
    if (vis[l][r][flag])    return d[l][r][flag];
    vis[l][r][flag] = 1;
    int cnt = 0;
    for (int i = r; i >= l; --i) {
        if (s[i] == '(')    ++cnt;
        if (s[i] == ')')    --cnt;
        if (s[i] == '+' && !cnt) {
            if (flag)   return d[l][r][1] = dfs(l, i - 1, 1) + dfs(i + 1, r, 1);
            else return d[l][r][0] = dfs(l, i - 1, 0) + dfs(i + 1, r, 0);
        } 
        if (s[i] == '-' && !cnt) {
            if (flag)   return d[l][r][1] = dfs(l, i - 1, 1) - dfs(i + 1, r, 0);
            else return d[l][r][0] = dfs(l, i - 1, 0) - dfs(i + 1, r, 1);
        }
    }

    cnt = 0;
    for (int i = r; i >= l; --i) {
        if (s[i] == '(')    ++cnt;
        if (s[i] == ')')    --cnt;
        if (s[i] == '*' && !cnt) {
            if(flag==0)
            {
                d[l][r][0]=min(dfs(l,i-1,0)*dfs(i+1,r,0),dfs(l,i-1,1)*dfs(i+1,r,1));
                d[l][r][0]=min(d[l][r][0],dfs(l,i-1,0)*dfs(i+1,r,1));
                d[l][r][0]=min(d[l][r][0],dfs(l,i-1,1)*dfs(i+1,r,0));
            }
            else
            {
                d[l][r][1]=max(dfs(l,i-1,0)*dfs(i+1,r,0),dfs(l,i-1,1)*dfs(i+1,r,1));
                d[l][r][1]=max(d[l][r][1],dfs(l,i-1,0)*dfs(i+1,r,1));
                d[l][r][1]=max(d[l][r][1],dfs(l,i-1,1)*dfs(i+1,r,0));
            }
            return d[l][r][flag];
        }
    }

    cnt = 0;
    for (int i = l; i <= r; ++i) {
        if (s[i] == '(')    ++cnt;
        if (s[i] == ')')    --cnt;
        if (!cnt && s[i] == 'd') {
            if (flag)   return d[l][r][1] = dfs(l, i - 1, 1) * dfs(i + 1, r, 1);
            else return d[l][r][0] = dfs(l, i - 1, 0);
        }
    }

    ll sum = 0;
    for (int i = l; i <= r; ++i)    sum = sum * 10 + s[i] - '0';
    return d[l][r][flag] = sum;
}
int main() {
    while (scanf("%s", s + 1) != EOF) {
        init();
        len = strlen(s + 1);
        for (int i = 1; i <= len; ++i) if (s[i] == '(') ss.push(i);  else if (s[i] == ')') A[ss.top()] = i, ss.pop();

        printf("%lld %lld\n", dfs(1, len, 0), dfs(1, len, 1));
    }
}