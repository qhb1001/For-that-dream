# 一路优化下去 - Dinic

#### 不带任何优化的Dinic

使用bfs对带有反向边的图进行分层

之后使用bfs寻找一条从s到达t的路径，同时记录每个节点的前驱

当找到t结点之后退出，对这一条路径进行增广

#### 优化一 层次图的及时退出

由于在寻找增广路的过程中只会从较低的level到达较高的level，并且到达t节点之后不会继续dfs

所以在分层时找到t节点之后就应该 `return true`

#### 优化二 使用dfs寻找增广路

```c++
int dfs(int u, int Min) {
    if (!Min || u == t) return Min;

    int v, ans = 0, plus;
    for (int i = head[u]; i != -1; i = e[i].nex) {
        v = e[i].to;
        if (level[v] == level[u] + 1 && e[i].flow) {
            plus = dfs(v, min(Min, e[i].flow));
            if (plus) {
                ans += plus;
                e[i].flow -= plus;
                e[i^1].flow += plus;
                return plus;
            }
        }
    }
    return 0;
}
```

#### 优化三 分层一次寻找多条增广路

```c++
int dfs(int u, int Min) {
    if (!Min || u == t) return Min;

    int v, ans = 0, plus;
    for (int i = head[u]; i != -1; i = e[i].nex) {
        v = e[i].to;
        if (level[v] == level[u] + 1 && e[i].flow) {
            plus = dfs(v, min(Min, e[i].flow));

            ans += plus;
            e[i].flow -= plus;
            e[i^1].flow += plus;
            Min -= plus;
        }
    }
    if (!ans)   level[u] = 0;
    return ans;
}
```

注意对Min的更新不可缺少

因为必须通过它来限制后面最多可以增广的流量