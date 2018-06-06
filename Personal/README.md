# JAVA大数

#### HDU1063

本题需要使用两个内建的方法

一个是BigDecimal中的stripTrailingZeros()，用于去除小数后的零。如果小数点后全都是零，那么会返回一个不含小数点的大数。

另一个是BigDecimal中的toPlainString()，用于将改类型转换为String类型

由于本题需要把前缀0都取消掉，所以在转换成String之后，操作就灵活了起来

String访问某个索引下的数据时，需要使用charAt()方法



# 数据结构小学期

#### Barbell   Gym101291B  http://codeforces.com/gym/101291/attachments

一共有 1<<14 种可能组成的哑铃的重量

我们保存每一种重量，同时保存其对应的方案情况

当两种重量相同时，如何能判断有没有使用相同的哑铃呢？异或即可

将每一种重量都保存入一个vector中，或者离散化，将同一种重量的放入一个vector中

#### 单调队列入门题目 POJ 2823

#### CF Round #485 Problem C   图论  — 暴力题

#### 沈阳区域赛  2017  Problem L   图论 — 思维题

#### CF Round #486 Problem D   线段树  求逆序对

#### 天平挂砝码的题目 — bitset



# FFT

#### HDU 4609

给一组数，问可以组成多少个三角形



#### 2016香港网络赛

给一组数，问存在多少对$a_i+a_j=a_k$



据说去年网络赛考了FFT，好奇地看了一眼卷积，嗯嗯，理解了！背不下来模版！嗯嗯 就酱！