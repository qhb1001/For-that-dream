#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int maxn=1005;
vector<int>G[1005];
int n, m, fa[1005], fa_[1005], cnt_[1005];
bool in[1005];
char ans[1005];
int Find(int x) {
    return fa_[x] == x? x : fa_[x] = Find(fa_[x]);
}
void getIn() {
    int len;
    for (int i = 1; i <= n; ++i) {
        len = G[i].size();
        for (int j = 0; j < len; ++j) {
            in[Find(G[i][j])] = 1;
        }
    }
}
void Unit(int u, int v) {
    u = Find(u);
    v = Find(v);
    if (u == v) return ;
    if (cnt_[u] < cnt_[v])    swap(u, v);
    cnt_[u] += cnt_[v];
    fa_[v] = u;
}

void init() {
    for (int i = 1; i <= n; ++i)
        fa_[i] = i, cnt_[i] = 1;
}

bool dfs(int now, int path) {
    if (path == 3) {
        for (int i = 1; i <= n; ++i)
            if (Find(i)== Find(now)) {
                ans[i] = 'B';
                //                cout<<i<<" B "<<endl;
            }
        return true;
    } else if (path == 2) {
        bool flag = 0;// 0 - 没有子代
        int cnt;
        for (int i = 1; i <= n; ++i) {
            if (Find(i) != Find(now))   continue;
            cnt = G[i].size();
            if (cnt) {
                flag = 1;
                for (int j = 0; j < cnt; ++j) {
                    if (ans[G[i][j]] == 'B')    continue;
                    dfs(G[i][j], 3);
                }
            }
        }
        if (!flag)  return false;

        for (int i = 1; i <= n; ++i) {
            if (Find(i) == Find(now))  {
                ans[i] = 'R';
                //                cout<<i<<" R "<<endl;
            }
        }
        return true;
    } else {
        int cnt;
        bool flag = 0;// 0 - 代表没有长度为3的路
        for (int i = 1; i <= n; ++i) {
            if (Find(now) != Find(i))   continue;
            cnt = G[i].size();
            for (int j = 0; j < cnt; ++j) {
                if (ans[G[i][j]] == 'R' || dfs(G[i][j], 2)) {
                    flag = 1;
                }
            }
        }

        if (flag) {
            for (int i = 1; i <= n; ++i) {
                if (Find(i) == Find(now))  {
                    ans[i] = 'W';
                    //                    cout<<i<<" W "<<endl;
                }
            }
            return true;
        }
        return false;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    init();
    int u, v;
    char c;

    for(int i=0;i<m;i++){
        scanf("%d%c%d", &u, &c, &v);
        if (c == '=') {
            Unit(u, v);
        } else {
            if (c == '<')   swap(u, v);
            G[u].push_back(v);
        }
    }

    getIn();
    for (int i = 1; i <= n; ++i)
        if(in[Find(i)] == 0 && ans[i] == '\0') dfs(i, 1);

    for (int i = 1; i <= n; ++i)
        if (ans[i] != '\0') printf("%c", ans[i]);
        else    printf("?");
    printf("\n");
    return 0;
}
