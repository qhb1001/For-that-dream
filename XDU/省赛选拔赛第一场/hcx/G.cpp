#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int maxx=1e4;
int First[maxx+5];
int Last[maxx+5];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(First,0,sizeof(First));
        memset(Last,0,sizeof(Last));
        int x;ll sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            sum=((sum+x)%m+m)%m;
            if(!First[sum]){
                First[sum]=i;
            }
            Last[sum]=i;
        }

        int ans=0;
        First[0]=0;
        for(int i=0;i<m;i++){
            if(Last[i]-First[i]>0){
                ans=max(Last[i]-First[i],ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
