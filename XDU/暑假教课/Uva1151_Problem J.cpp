#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e3 + 5;
struct Point {
    int x, y;
}point[MAX];
struct Edge {
    int from, to;
    int dis;
    Edge(int a = 0, int b = 0, double c = 0): from(a), to(b), dis(c) {}
    bool operator < (const Edge b) const {
        return dis < b.dis;
    } 
};
vector<Edge>e;
int dis(Point a, Point b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
struct Plan {
    vector<int>point;
    int cost;
    int len;
}plan[10];
int n, q;


//union-find set
int fa[MAX], cnt[MAX];
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return ;
    if (cnt[v] > cnt[u])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}


vector<Edge>mst;
void init() {
    mst.clear();
    e.clear();
    for (int i = 1; i <= 8; ++i)    plan[i].point.clear();
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        cnt[i] = 1;
    }
}
void input() {
    cin >> n >> q;
    init();
    int p;
    for (int i = 1; i <= q; ++i) {
        cin >> plan[i].len >> plan[i].cost;
        for (int j = 1; j <= plan[i].len; ++j) {
            cin >> p;
            plan[i].point.push_back(p);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> point[i].x >> point[i].y;
    }
}
void getMST() {
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            e.push_back(Edge(i, j, dis(point[i], point[j])));
        }
    }

    sort(e.begin(), e.end());
    int k = n, len = e.size();
    for (int i = 0; i < len; ++i) {
        if (find(e[i].from) == find(e[i].to))   continue;
        --k;
        mst.push_back(e[i]);
        unit(e[i].from, e[i].to);
        if (k == 1) break;
    }
}

int deal() {
    int cost, ans = 1<<30;
    int now, idx;
    
    for (int i = 0; i < (1<<q); ++i) {
        cost = 0;
        now = i;
        //initialization for the union-find set
        for (int j = 1; j <= n; ++j) {
            fa[j] = j;
            cnt[j] = 1;
        }

        //choose the plan
        idx = 1;
        while (now != 0) {
            if (now % 2 == 1) {
                cost += plan[idx].cost;
                for (int j = 1; j < plan[idx].len; ++j) {
                    unit(plan[idx].point[0], plan[idx].point[j]);
                }
            }
            now >>= 1;
            ++idx;
        }        

        //calculate the total cost 
        for (int i = 0; i < n - 1; ++i) {
            if (find(mst[i].from) != find(mst[i].to)) {
                unit(mst[i].from, mst[i].to);
                cost += mst[i].dis;
            }
        }

        //update the answer
        ans = min(ans, cost);
    }

    return ans;
}
vector<int>ans;
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        input();
        getMST();

        // cout << mst.size() << endl;
        // for (int i = 0; i < n - 1; ++i) {
        //     cout << mst[i].from << ' ' << mst[i].to << '\n';
        // }
        ans.push_back(deal());
    }

    int len = ans.size();
    cout << ans[0] << '\n';
    for (int i = 1; i < len; ++i) {
        cout << '\n' << ans[i] << '\n';
    }
}