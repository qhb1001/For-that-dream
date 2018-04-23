#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
struct Node{
    int score;
    string path;
}dp[32768+5], tempNode;

struct Class{
    char s[105];
    int dl;
    int cost;
}CC[17];

int n;

void bfs(){
    int sum_day,now_day, from, to;
    queue<int>q;
    q.push(0);
    dp[0].path="";
    dp[0].score=0;

    while(!q.empty()){
        from=q.front();
        q.pop();
        sum_day=0;
        for(int i=0;i<n;i++){
            if(from&(1<<i)){
                sum_day+=CC[i].cost;
            }
        }
        for(int i=0;i<n;i++){
            if(!(from&(1<<i))){
                now_day=sum_day+CC[i].cost;
                to = from | (1<<i);
                if(now_day<=CC[i].dl){
                    tempNode.score = dp[from].score;
                } else {
                    tempNode.score = dp[from].score + now_day - CC[i].dl;
                }
                tempNode.path = dp[from].path +(char) ('0' + i);

                if(dp[to].score == -1 || dp[to].score > tempNode.score || (dp[to].score == tempNode.score && dp[to].path > tempNode.path)) {
                    if(dp[to].score == -1)  q.push(to);
                    dp[to] = tempNode;
                }
            }
        }
    }
    printf("%d\n",dp[(1<<n)-1].score);
    for(int i=0;i<n;i++){
        printf("%s\n",CC[dp[(1<<n)-1].path[i]-'0'].s);
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s %d %d",CC[i].s,&CC[i].dl,&CC[i].cost);
        }
        for(int i = 0; i < (1<<15); ++i) dp[i].score = -1;

        bfs();
    }
    return 0;
}


//internet
// 且对于完成作业1,2,3和1,3,2和2,1,3和3,2,1和3,1,2来说,完成它们消耗的天数一定是一样的，只是完成的顺序不同从而扣的分不同
// 假如对于作业k, i中含有作业k已完成，那么i可以由和i状态相同的状态仅仅是k未完成的状态j=i-(1<<k)来完成k到达
// 并且j一定比i小，如果状态从0枚举到2^n-1那么j一定是在i之前已经计算过的
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <string>
// #include <queue>
// #include <algorithm>
// #include <map>
// #include <cmath>
// #include <iomanip>
// #define INF 99999999
// typedef long long LL;
// using namespace std;

// const int MAX=(1<<15)+10;
// int n;
// int dp[MAX],t[MAX],pre[MAX],dea[20],fin[20];//dp[i]记录到达状态i扣的最少分,t时相应的花去多少天了
// char s[20][110];

// void output(int x){
//     if(!x)return;
//     output(x-(1<<pre[x]));
//     printf("%s\n",s[pre[x]]);
// }

// int main(){
//     int T;
//     scanf("%d",&T);
//     while(T--){
//         scanf("%d",&n);
//         for(int i=0;i<n;++i)scanf("%s%d%d",&s[i],&dea[i],&fin[i]);
//         int bit=1<<n;
//         for(int i=1;i<bit;++i){//枚举到达状态i
//             dp[i]=INF;//初始化到达状态i的扣分
//             for(int j=n-1;j>=0;--j){//由于输入时按字符大小输入，而每次完成j相当于把j放在后面完成且下面判断是dp[i]>dp[i-temp]+score
//                 int temp=1<<j;      //所以是n-1开始，如果下面判断是dp[i]>=dp[i-temp]+score则从0开始
//                 if(!(i&temp))continue;//状态i不存在作业j完成则不能通过完成作业j到达状态i
//                 int score=t[i-temp]+fin[j]-dea[j];//i-temp表示没有完成j的那个状态
//                 if(score<0)score=0;//完成j被扣分数最小是0
//                 if(dp[i]>dp[i-temp]+score){
//                     dp[i]=dp[i-temp]+score;
//                     t[i]=t[i-temp]+fin[j];//到达状态i花费的时间
//                     pre[i]=j;//到达状态i的前驱,为了最后输出完成作业的顺序
//                 }
//             }
//         }
//         printf("%d\n",dp[bit-1]);
//         output(bit-1);//输出完成作业的顺序
//     }
//     return 0;
// }
