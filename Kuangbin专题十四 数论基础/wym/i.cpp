#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 1e8;
double ans[maxn/50+5];
void dabiao(){
    ans[0] = 0;
    double tmp = 0;
    for(int i=1; i<=maxn; i++){
        tmp += 1.0/i;
        if(i%50==0){
            ans[i/50] = tmp;
        }
    }
}
int main(){
    dabiao();
    int t;
    scanf("%d",&t);
    int kase = 0;
    while(t--){
        int n;
        scanf("%d",&n);
        int x = n / 50;
        double res = ans[x];
        for(int i=x*50+1; i<=n; i++){
            res += 1.0/i;
        }
        printf("Case %d: %.8lf\n",++kase,res);
    }
    return 0;
}
