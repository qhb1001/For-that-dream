#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=3e4+5;
struct ty{
    int v;
    int idx;
}a[maxn],b[maxn];
bool cmp(ty x,ty y){
    return x.v>y.v;
}
int main(){
    int n;
    while (scanf("%d",&n)!=EOF) {
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].v);
            a[i].idx=i;
        }
        sort(a+1,a+1+n,cmp);
        int num=1;
        b[num].v=a[1].v;
        b[num].idx=a[1].idx;
        for(int i=2;i<=n;i++){
            int j;
            for(j=1;j<=num;j++){
                if(b[j].v>a[i].v&&b[j].idx<a[i].idx){
                    b[j].v=a[i].v;b[j].idx=a[i].idx;
                    break;
                }
            }
            if(j>num){
                b[++num].v=a[i].v;
                b[num].idx=a[i].idx;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
