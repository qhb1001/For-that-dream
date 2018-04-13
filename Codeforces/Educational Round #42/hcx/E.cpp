//未考虑PP跳连
// #include <iostream>
// #include <algorithm>
// using namespace std;
// typedef long long ll;
// const int maxn=2e5+10;
// const ll INF=1e12;
// struct ty{
//     ll idx;
//     int flag;
// }x[maxn];
// int main(){
//     bool have_r=false,have_b=false,have_p=false;
//     ll lr=INF,lb=INF,rb=-INF,rr=-INF;
//     int n;cin>>n;
//     for(int i=0;i<n;i++){
//         char c;
//         cin>>x[i].idx>>c;
//         if(c=='R'){
//             x[i].flag=0;
//             lr=min(x[i].idx,lr);
//             rr=max(x[i].idx,rr);
//         }
//         else if(c=='P'){
//             x[i].flag=1;
//             have_p=true;
//         }
//         else{
//             x[i].flag=2;
//             lb=min(x[i].idx,lb);
//             rb=max(x[i].idx,rb);
//         }
//     }
//     ll ans=0;
//     if(!have_p){
//         if(lr<=rr) ans+=rr-lr;
//         if(lb<=rb) ans+=rb-lb;
//         cout<<ans<<endl;
//         return 0;
//     }
//     have_p=false;
//     for(int i=0;i<n;i++){
//         if(x[i].flag==0){   //R
//             if(have_r){
//                 ans+=x[i].idx-lr;
//                 lr=x[i].idx;
//             }
//             else{
//                 have_r=true;
//                 lr=x[i].idx;
//             }
//         }
//         else if(x[i].flag==1){  //P
//             if(have_b&&have_r){
//                 if(lr!=lb){
//                     ans+=2*x[i].idx-lr-lb;
//                 }
//                 else{
//                     ans+=x[i].idx-lr;
//                 }
//             }
//             else if(have_b){
//                 ans+=x[i].idx-lb;
//             }
//             else if(have_r){
//                 ans+=x[i].idx-lr;
//             }
//             else if(have_p){
//                 ans+=x[i].idx-lb;
//             }
//             have_p=have_b=have_r=true;
//             lr=lb=x[i].idx;
//         }
//         else{   //B
//             if(have_b){
//                 ans+=x[i].idx-lb;
//                 lb=x[i].idx;
//             }
//             else{
//                 have_b=true;
//                 lb=x[i].idx;
//             }
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll>r,b,p;
ll choose(const vector<ll>& v,ll l,ll r){
    ll x=lower_bound(v.begin(), v.end(), l)-v.begin();
    ll y=lower_bound(v.begin(), v.end(), r)-v.begin();
    ll tmp=0;
    for(ll i=x;i<y;i++){
        tmp=max(tmp,v[i+1]-v[i]);
    }
    return tmp;
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;char c;cin>>x>>c;
        if(c=='R'){
            r.push_back(x);
        }
        else if(c=='P'){
            r.push_back(x);
            b.push_back(x);
            p.push_back(x);
        }
        else{
            b.push_back(x);
        }
    }

    ll ans=0;
    ll nr=r.size(),nb=b.size(),np=p.size();
    if(nr>1) ans+=r[nr-1]-r[0];
    if(nb>1) ans+=b[nb-1]-b[0];
    if(!np||np==1){
        cout<<ans<<endl;
        return 0;
    }
//    cout<<ans<<endl;
    for(int i=0;i<np-1;i++){
        ll l=p[i],rr=p[i+1];
        ans-=max(0LL,choose(b, l, rr)+choose(r, l, rr)-(rr-l));
//        cout<<ans<<endl;
    }

    cout<<ans<<endl;
    return 0;
}
