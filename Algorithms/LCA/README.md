# HDU 2586

题目描述：给出一棵树，每条边都有一个边权，试求询问的两点之间的距离

题解：使用了dfs+并查集来做，也就是离线LCA。在这样的做法里面，我发现使用pair<T, T>可以简化代码

整个算法的关键部分是dfs过程，这里附上我的模版

```c++
void dfs(int u, int fa) {
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (!vis[v] && v != fa) {//注意无根树转有根树
            dfs(v, u);
            vis[v] = 1;//只有在从该点回溯到上一层之后，才可以将该点染为黑色
            unit(u, v);
        }
    }

    int len = query[u].size();
    pair<int, int> now;
    for (int i = 0; i < len; ++i) {
        now = query[u][i];
        if (vis[now.first])     {
            ans.push_back(make_pair(now.second, d[now.first] + d[u] - 2*d[find(now.first)]));
            // cout << u << ' ' << now.first << ' ' << find(now.first) << endl;
        }
    }
}
```

同时此处使用的lca思想，或者说树上的思想也很重要，那就是：如果快速地求两个点之间的距离

答案就是得到1. 任意结点到达根结点的距离数组  2. 任意询问两个结点的最近公共祖先

使用这种思想来解决该问题真是太完美了

