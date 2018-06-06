#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,m;
ll x[maxn];
int ans=1;
ll xx,yy;
vector<ll>v;

bool Find(ll y){
    int l=0,r=n-1;
    if(y>x[r])return false;
    if(y<x[l])return false;
    while(l<=r){
        int mid=(l+r)>>1;
        if(x[mid]==y) return true;
        else if(x[mid]<y) l=mid+1;
        else r=mid-1;
    }
    return false;
}

void Init(){
    ll now=1;
    while(now<=2000000000){
        v.push_back(now);
        now<<=1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Init();
    cin>>n;
    for(int i=0;i<n;i++) cin>>x[i];
    sort(x,x+n);

    for(int i=0;i<n;i++){
        for(int j=0;j<31;j++){
//            cout<<x[i]<<" "<<v[j]<<endl;
            if(!Find(x[i]+v[j]))
                continue;
            if(!Find(x[i]+2*v[j])){
                ans=2;
                xx=x[i];yy=x[i]+v[j];
            }else{
                cout<<3<<endl;
                cout<<x[i]<<" "<<x[i]+v[j]<<" "<<x[i]+2*v[j]<<endl;
                return 0;
            }
        }
    }
    if(ans==2){
        cout<<2<<endl<<xx<<" "<<yy<<endl;
    }
    else{
        cout<<1<<endl<<x[0]<<endl;
    }
    return 0;
}
