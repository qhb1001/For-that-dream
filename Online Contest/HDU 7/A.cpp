#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;

//链式前向星
int head[MAX], cnt;
struct Edge {
    int to, nex, id;
}e[MAX<<2];
void add(int u, int v, int id) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    e[cnt].id = id;
    head[u] = cnt;
}

//读入处理
int n, m;
void input() {
    int u, v, id;
    cnt = 0;
    memset(head, 0, sizeof(head));
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &id);
        // cout << u << ' ' << v << ' ' << id << endl;
        add(u, v, id);
        add(v, u, id);
    }
}

//Dijkstra
struct Node {
    int cost, pre, now;
    Node(int cost_ = 0, int pre_ = 0, int now_ = 0): cost(cost_), pre(pre_), now(now_) {}
    bool operator < (const Node b) const {
        return cost > b.cost;
    }
}now, temp;
int d[MAX], vis[MAX];
void dijkstra() {
    memset(d, 0x3f3f3f3f, sizeof(d));
    d[1] = 0;
    priority_queue<Node>q;
    q.push(Node(0, -1, 1));

    int v;
    while (q.empty() == 0) {
        now = q.top(); q.pop();
        if (now.cost > d[now.now])  continue;

        // cout << now.now << endl;

        //进行松弛
        for (int i = head[now.now]; i; i = e[i].nex) {
            v = e[i].to;

            temp.now = v;
            temp.pre = now.pre;
            temp.cost = now.cost;
            //走本条道路不需要付费
            if (now.pre == e[i].id && d[v] > now.cost) {
                d[v] = now.cost;
                q.push(temp);
            } else if (now.pre != e[i].id && d[v] > now.cost + 1) {
                d[v] = now.cost + 1;
                temp.cost += 1;
                temp.pre = e[i].id;
                q.push(temp);
            }
        }
    }
}

//check是否可达
bool check() {
    queue<int>q;
    bool vis[MAX] = {0};
    q.push(1);
    vis[1] = 1;
    int u, v;
    while (q.empty() == 0) {
        u = q.front(); q.pop();
        // cout << u << endl;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            // cout << v << endl;
            if (v == n) return true;
            if (vis[v]) continue;
            q.push(v);
        }
    }
    return false;
}
int main() {

    // freopen("input.txt", "r", stdin);
    while (scanf("%d%d", &n, &m) != EOF) {
        //处理输入
        input();

        //check是否可达
        if (!check())   {
            printf("-1\n");
            continue;
        }

        //dijkstra
        dijkstra();
        printf("%d\n", d[n]);
    }
}