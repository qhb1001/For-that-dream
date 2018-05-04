//POJ 1426
//my force
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
void bfs(ll n){
    queue<ll>q;
    q.push(1);
    while(!q.empty()){
        ll tmp=q.front();q.pop();
        if(!(tmp%n)){
            cout<<tmp<<endl;
            return ;
        }
        q.push(tmp*10);
        q.push(tmp*10+1);
    }
}
int main(){
    int n;
    while(cin>>n){
        if(!n) break;
        bfs(n);
    }
    return 0;
}

//From Internet
//Not understand yet

// //同余定理
// //Memory Time
// //2236K  32MS

// #include<iostream>
// using namespace std;

// int mod[524286];  //保存每次mod n的余数
// //由于198的余数序列是最长的
// //经过反复二分验证，436905是能存储198余数序列的最少空间
// //但POJ肯定又越界测试了...524286是AC的最低下限，不然铁定RE

// int main(int i)
// {
//     int n;
//     while(cin>>n)
//     {
//         if(!n)
//             break;

//         mod[1]=1%n;  //初始化，n倍数的最高位必是1

//         for(i=2;mod[i-1]!=0;i++)  //利用同余模定理，从前一步的余数mod[i/2]得到下一步的余数mod[i]
//             mod[i]=(mod[i/2]*10+i%2)%n;
//         //mod[i/2]*10+i%2模拟了BFS的双入口搜索
//         //当i为偶数时，+0，即取当前位数字为0  。为奇数时，则+1,即取当前位数字为1

//         i--;
//         int pm=0;
//         while(i)
//         {
//             mod[pm++]=i%2;   //把*10操作转化为%2操作，逆向求倍数的每一位数字
//             i/=2;
//         }
//         while(pm)
//             cout<<mod[--pm];  //倒序输出
//         cout<<endl;
//     }
//     return 0;
// }

//DP
//Not understand yet
// #include <iostream>
// #include <algorithm>
// using namespace std;

// __int64 dp[110][210];

// __int64 solve(int n) {
//     int rem = 1;
//     __int64 exp = 1;

//     memset(dp[0], 0, sizeof(dp[1]));
//     dp[0][1] = 1;

//     for (int i = 1; i <= 100; i++) {
//         exp *= 10;
//         rem = (rem * 10) % n;
//         for (int j = 0; j < n; j++) {
//             dp[i][j] = dp[i-1][j];
//         }
//         for (int j = 0; j < n; j++) {
//             if (dp[i-1][j] || j == 0) {
//                 int r0 = (j + rem) % n;
//                 if (dp[i][r0] == 0)
//                     dp[i][r0] = exp + dp[i-1][j];
//                 if (r0 == 0) 
//                     return dp[i][r0];
//             }
//         }
//     }
//     return 0;
// }

// int main() {
//     int n;
//     while (scanf("%d", &n) && n) {
//         if (n == 1) 
//             printf("1\n");
//         else
//             printf("%I64d\n", solve(n));
//     }
//     return 0;
// }
