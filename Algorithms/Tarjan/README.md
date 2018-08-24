[TOC]

# Depth-first Search

1. In general, the arcs of G' which are not part of the spanning tree interconnect the paths in the tree. However, if the search is depth-first, each edge (v, w) not in the spanning tree connects vertex v with one of its ancestors w.

2. The depth-first search ensures that every vertices is examined exantly once, each edge in the graph is examined exactly twice. 

3. If  $v \xrightarrow{*}w$ , v is an ancestor of w.

4. Trajan构建了一些弧，这些弧是在dfs过程中，当遍历某一个结点时，该结点出发的边连向了其已经遍历过的祖先(非父亲)，则将其标记为弧

5. 定义了dfs搜索过程中产生的搜索树 palm tree

   这个树中存在两种边

   * 在搜索过程中使用的边
   * 在搜索过程中某个节点的返祖边(弧)

   在生成这棵树的时候，依次对发现的结点进行了标记，并且发现地越早，该标记越小

   

# Biconnectivity

1. Let G = (V, E) be an undirected graph. Suppose that for each triple of distinct vertices v, w, a in v, there is a path p: $v \xrightarrow{*}w$ such that a is not on the path P. Then G is ***biconnected***. If, on the other hand, there is a triple of distinct vertices v, w, a in v such that a is on any path p: $v\xrightarrow{*}w$, and there exists at least one such path, then a is called an articulation point of P. 

   上述是对割点的定义

   当在原图中删掉割点以及与割点相关的边后，原图的联通分量分量个数增加，那么该点就是割点

   举例：在一个仅包含一个大环的图中，不存在割点

   举例：将两个环使用另外一个结点连接在一起，那么该结点就是一个割点

2. 接着定义了一个等价类(五向图)

   该类中定义两条边时等价的，当它们处于同一个环中的时候

   对于每一个这样的等价类，可以很容易发现

   * 这个类内部是biconnected的
   * 每个类的交集至多为一个顶点，并且可以保证这个交点是一个割点

   上述定义的东西称为联通分量(biconnect component)

3. 定义了$LOWPT(v)$

   Let LOWPT(v) be the smallest vertex in the set $\{v\}\bigcap \{ w| v \xrightarrow{*} -\rightarrow w\}$

   其中$-\rightarrow$表示返祖边

   两个符号连在一起使用，应该是表示两个边集都可以使用的意思

   这个符号表示的是某个点可以到达的最远祖先

   ---

   计算方式

   $LOWPT(v) = min (\{ NUMBER(v) \}  \bigcup \{ LOWPT(w) | v\rightarrow w \}  \bigcup  \{ NUMBER(w)| v -\rightarrow w \})$

4. 定理5

   Let G be a connected undirected graph. Let P be a palm tree formed by directing the edges of G, and let T be the spanning tree of P. Suppose a, v, w are distinct vertices of G such that (a, v) $\in$ T, and suppose w is not a descendant of v in T. If LOWPT(v) >= a then a is an articulation point of P and removal of a disconnects v and w.

   结合LOWPT的定义，容易发现结点v的联通分量最高最高为LOWPT(v)，当这个值大于a时，表示其最远的祖先在是a的后代，所以a必定是割点

5. 关于自己脑补出来的带有疑惑的图

   ![Figure1](https://github.com/qhb1001/For-that-dream/blob/master/论文/Tarjan/Figure1.png)

   由于在存边的栈中在执行完进行回溯的过程中，在遍历到比较小的联通分量时，是根本到达不了加入其返祖边的情形中的，因为该结点的返祖边指向的是其爷爷结点，而爷爷结点是被特判了的。虽然我不清楚为什么要对爷爷结点进行特判。。但是就算没有对爷爷结点进行特判也会因为当前栈顶元素的lowbit值太小而没有进行弹栈操作

   综上所述，最终只会对最大的联通分量进行操作

# Strong Connectivity

1. 新定义了一种边集，在有向图的dfs遍历过程中可能生成的边vine

   对于这样的结点对(v, w)，很明显，一定有w首先被遍历，处于左子树中，v之后被遍历，位于右子树中，即number[v] > number[w]


# trajan详解



1. 会使用到的变量

   * scc，用来记录**强连通分量**的编号
   * s[], top手动维护的栈， top表示栈顶
   * belong[] 表示某点对应的强连通分量编号
   * number[] 第一次发现该点的时间戳
   * low[] 从该点以及该点的子代出发，可以到达的最早祖先

2. 在dfs过程中可能遍历到哪几种边？对它们的处理分别是什么？

   可能遍历到两种边

   * 到达点是第一次遍历到的点，该点的特征是`number`数组中还没有对应的值

     对应的处理方案是dfs该点，之后使用该点的`low`来更新当前点的low

     这样的话可以保证每次圈出来的强连通分量都是尽量大的

   * 到达点是当前边出发点的祖先，并且尚未归类到强连通分量中，特征是`number有值`，并且`belong`为空

     对应的处理方案是使用祖先的`number`来更新当前点的`low`

   关于在什么地方使用low，什么地方使用number数组进行更新，应当参照low数组的定义

# 题目练习

### Problem A(求割点个数，以及删去该割点之后整个图的联通情况)

题目描述：给出一个包含N(<=1000)个结点的联通图，试求其中割点的个数，以及删去每个割点之后整个图的联通情况

记录一个`scc`数组，表示该点之下连接着多少个联通分量。但是这里有一个坑点，对于非根结点，得到的是它下面有多少个联通分量，删去这个点之后，由于上方还存在着一个，所以应该对结果加一

而如果是根结点，由于不存在上方结点，所以最后直接输入该点的值即可

而在dfs阶段，具体过程如下

```c++
void dfs(int u, int fa) {
	number[u] = low[u] = ++cnt;
    int v, child = 0;
    for (int i = head[u]; i; i = e[i].nex) {
    	v = e[i].idx;
        if (!number[v]) {
        	dfs(v, u);
            low[u] = min(low[u], low[v]);
            ++child;
            if (low[v] >= number[u])	++scc[u];
        } else if (number[v] < number[u] && v != fa) {
        	low[u] = min(low[u], number[v]);
        }
    }
    
    if (fa == -1 && child == 1)	scc[u] = 0;
}
```

---

本题我使用了链式前向星来存储整个图

### Problem B 洛谷P3388

求割点的裸题

但是要注意使用链式前向星时对于无向图，其边集要乘以2。。否则会RE

### 次小生成树

这是在逛Candy?博客时候发现的，之后在知乎上面发现了一篇[很好的文章](https://zhuanlan.zhihu.com/p/24950356)

是以前遇到过的题型，记得毛老师讲过，可是自己忘掉具体怎么做了- -

并且觉得这种思维的训练也是蛮棒的～

次小生成树，必定是采用了一条最小生成树中没有采用的边，然后替换掉之前的最小生成树中的某条边得到的

如果称最小生成树中包含的边为关键边，那么现在问题就变成了如何高效地在固定一条非关键边之后得到一棵生成树

第一个优化是现在即将要使用的边必定仍然是从关键边中获得的，所以省去了排序的复杂度

第二个优化是在我们加入这个非关键边之后，从之前的最小生成树，变成了一个包含一个圈的图，所以必须去掉一条边。而这条边只需要从这个环中去掉即可。实现这个功能的数据结构(听说)有很多，树链剖分/倍增/Link cut tree等(好兴奋啊)

### Problem C + D  

题目描述：给出一个有向图，试求添加多少条边之后可以使得该图成为强连通图

似乎可以直接扔出来一个结论：在一个DAG图中，若出度为0的点有`cnt1`，入度为0的点有`cnt2`，那么只需要添加`max(cnt1, cnt2)`条边即可达成目标

这样做的道理似乎是只要将原图的搞成一个大环即可，这样做的方法是使得这个图中不再存在入度为0以及出度为0的点

具体的加边方法是贪心，很容易构造

---

但是注意，当scc = 1时，不再需要加任何边了，直接输出0

### Problem E

题目描述：经典的 "缩点+DAG图上的dp"

在缩点之后要再调用一个`buildGraph`函数，用于建立一个新的图