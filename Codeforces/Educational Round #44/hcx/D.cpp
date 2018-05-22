#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n,h,tmp,ans,l,r,z,y;
const ll maxn=2e9;
bool check(ll x){
    if(x<=h) return tmp=(1+x)*x/2>=n;
    else if((x-h-1)%2){
        y=(x-h-1)/2+1;
        //z=y*(x-h)/2+h*(x-h)+h*(h+1)/2;
        z=y*(x-h)/2+h*(2*x-h+1)/2;
        return z>=n;
    }
    else{
        y=(x-h-1)/2;
        //z=y*(x-h+1)/2+h*(x-h)+h*(h+1)/2;
        z=y*(x-h+1)/2+h*(2*x-h+1)/2;
        return z>=n;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>h;
    ans=n;
    l=1;r=min(n,maxn);//枚举堆数
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}

