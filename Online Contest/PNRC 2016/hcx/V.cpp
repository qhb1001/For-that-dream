#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
struct ty{
    ll idx,x,m;
    bool operator<(const ty &b)const{
        if(x!=b.x) return x<b.x;
        if(m!=b.m) return m<b.m;
        return idx<b.idx;
    }
};
priority_queue<ty>q[2];
int n,k,a,b;
ll ans=0;
ty tmp,tmp2;
ll solve(int flag){
    ll res=0;
    while(!q[flag].empty()){
        tmp=q[flag].top();q[flag].pop();
        ll temp=(tmp.m+k-1)/k;//times
        ll d=0;
        if(tmp.m%k!=0) d=k-tmp.m%k;
        res+=2LL*temp*tmp.x;//come and back

        while(d){//leave with other x together
//            cout<<"d: "<<d<<endl;
            if(q[flag].empty()) break;
            tmp2=q[flag].top();q[flag].pop();

            ll now=min(d,tmp2.m);//leave together
            tmp2.m-=now;
            d-=now;
            if(tmp2.m!=0) q[flag].push({tmp2});//if not all,then leave next;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(a>0) q[0].push({i,a,b});
        else q[1].push({i,-a,b});
//        cout<<i<<" "<<a<<" "<<b<<endl;
    }

    ans+=solve(0);
//    cout<<ans<<endl;
    ans+=solve(1);
    cout<<ans<<endl;
    return 0;
}
