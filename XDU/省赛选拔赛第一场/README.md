# Problem A(POJ3259)

#### qhb

题目描述：给出多个对象之间的多对关系，每对关系按照'A > B' || 'A < B' 这样的形式给出。其中A和B均代表string。要求判断是否存在给出的某对关系与之前给出的关系矛盾。

噩梦的开始：因为最近在做并查集，同时又跟 `HDU3038`很相向，于是跟cx开始朝着并查集的方向思考。然而首先因为**食物链**那道题目就不怎么熟，导致在这个方向上走了很久。之后发现当两条本不相交的集合通过某对关系连在一起的时候，并查集是不足以解决这种情况的，才终于走出了这个坑。

💡💡💡: 这个时候开始向有向图靠拢。瞬间意识到是一个有向图判圈题目。。虽然得到了正确的思路，但是仍然有点怂。。因为以为这种都是模板的问题，自己不敢写。但是在通过推遍历过程中图上的性质时，仍然得到了一个算法。A掉啦。 

# Problem B(补题)

The German Colleigate Programming Contest 2016

#### qhb

题目描述：你拥有c块一摸一样的CPU要卖，现在要依次拜访m位商人，各个商人那里给出了一次性买一个、一次性买两个、一次性买三个….一次性买c个的价钱。试求最终你可以获得的最大收益。

**比赛的时候没有看懂题意。。。。可是事实上仍然是一道可以A掉的题目，注意注意!!**

然后本题应该是背包问题的一个变形，使用dp来解，状态设计为$dp[i][j]$    第一维表示目前在哪一个商人，第二维表示从前 $i$ 个商人那里卖 $j$ 块CPU可以得到的最优解

把目前在哪一个商人作为阶段，记录从之前各位商人那里卖k块的最优值

在输出答案的时候要注意，最终的答案不必要从卖出 $c$ 块CPU那里转移过来，因为商人给的套餐可能会使得一次性卖少的获得的价值更高

# Problem G

#### qhb

题目描述：给出一大小为n的数组，给出一个模数m，要求从其中删去尽可能多的连续元素，使得删除这些元素之后，剩余的元素加和取模，与原数组加和取模的结果一致。

mm读错题目了…. 看来读题不能依赖性太强，或者说自己的质疑精神应该更强一些

可以将这些模数视为一些状态，然后记录某个状态第一次出现的位置

找到该状态最后一次出现的位置，两者之间的数字加和必定为m

注意要对 0 这个状态特殊处理，寻找最后面的 0 状态即可

# Problem H

#### qhb

一道模拟题目。。

# Problem J

#### qhb

CF原题。。

对KMP中Next数组的使用



