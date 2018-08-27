#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=50010;
struct Line{
    int l,r;
    bool operator<(const Line& o)const{
        if(l==o.l) return r<o.r;
        return l<o.l;
    }
}line[maxn];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&line[i].l,&line[i].r);
    }
    sort(line+1,line+1+n);
    int pos=2,l=line[1].l,r=line[1].r;
    while(pos<=n){
        if(line[pos].l==l){
            r=line[pos].r;
            pos++;
        }else if(line[pos].l<=r){
            r=max(line[pos].r,r);
            pos++;
            continue;
        }else{
            printf("%d %d\n",l,r);
            l=line[pos].l;r=line[pos].r;
            pos++;
        }
    }
    printf("%d %d\n",l,r);
    return 0;
}