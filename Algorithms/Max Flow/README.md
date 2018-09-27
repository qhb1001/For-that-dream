

# Edmonds-Karp

该算法相对于最基础的最大流算法，做出的改进是针对某种图来设计的

![figure1](/Users/qinhongbo/Desktop/Github/For-that-dream/Algorithms/Max Flow/figure1.png)

在这种图，如果使用dfs来进行增广，将会出现进入dfs 200次的情形

而如果使用bfs，则可以大大节省这个花费

由于是使用了邻接矩阵来存储整个图，也是为了便于进行修改，使得每次bfs的花费为$O(nm)$

同时注意到可能会出现至多进行n次增广，所以该算法的时间复杂度为$O(n^2 m)$

该算法是无法通过luogu3376的