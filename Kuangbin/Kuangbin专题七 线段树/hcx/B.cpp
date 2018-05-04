#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll t[2*maxn];
int n,m;
void bulid(){
    for(int i=n-1;i>0;i--) t[i]=max(t[i<<1],t[i<<1|1]);
}

void update(int x,int val){
    for(t[x+=n]=val;x>1;x>>=1) t[x>>1]=max(t[x],t[x^1]);
}

ll query(int l,int r){
    ll maxx=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) maxx=max(maxx,t[l++]);
        if(r&1) maxx=max(maxx,t[--r]);
    }
    return maxx;
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&t[i+n]);
        }
        bulid();
        char c;int x,y;
        while(m--){
            getchar();
            scanf("%c%d%d",&c,&x,&y);
//            cout<<c<<" "<<x<<" "<<y<<endl;
            if(c=='Q'){
                printf("%lld\n",query(x-1, y));
            }
            else{
                update(x-1, y);
            }
        }
    }
    return 0;
}
