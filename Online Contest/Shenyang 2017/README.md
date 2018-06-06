# Problem F 

打表找规律

需要使用java

使用String初始化BigInteger的方法

```java
import java.math.*;
BigInteger a = new BigInteger("10000");
```



# Problem I

java大数  求和

# Problem K

找规律

# Problem L

题目描述：给出k种颜色，本问题要求对结点进行染色。定义一种颜色对应的边集为连接所有该颜色的边组成的集合。当所有颜色对应的边集求公共边时，求最多可以有多少条公共边。

#### qhb

思考什么样的边会满足该性质？

当该边的两侧，拥有的结点数都 >= k时，该边必然可以满足条件

一趟dfs求出每个结点的子代个数

由于一棵树中每个结点的父结点只有一个，利用该性质即可得到答案

