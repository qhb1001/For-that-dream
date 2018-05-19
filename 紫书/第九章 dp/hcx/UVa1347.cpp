#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1005;
int n;
struct ty{
    int x,y;
}Node[maxn];
double dp[maxn][maxn];
double dist(int i,int j){
    double x=Node[i].x-Node[j].x;
    double y=Node[i].y-Node[j].y;
    return sqrt(x*x+y*y);
}

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d%d",&Node[i].x,&Node[i].y);
        }
        double tmp=dist(n-1,n);
        for(int i=1;i<n-1;i++){
            dp[n-1][i]=tmp+dist(i, n);
        }
        
        for(int i=n-2;i>=1;i--){
            for(int j=i-1;j>=1;j--){
                dp[i][j]=min(dp[i+1][j]+dist(i,i+1),dp[i+1][i]+dist(j,i+1));
            }
        }
        
        printf("%.2lf\n",dp[2][1]+dist(1, 2));
    }
    return 0;
}
