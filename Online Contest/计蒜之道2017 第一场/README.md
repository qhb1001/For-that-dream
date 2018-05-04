# Problem A

水题

# Problem B

KMP的简单应用

统计匹配串中含有多少个模式串

数据比较强，第一次我在匹配成功之后，设置`j = -1, i -= pLen;`但是结果超时了

之后重新设置为`j = Next[pLen]`，成功A掉了这道题目