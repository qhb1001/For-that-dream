#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;
int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0){ 
        x=1;
        y=0;
        return a;
    }
    ll res = exgcd(b,a%b,x,y);
    ll tmp = x;
    x = y;
    y =tmp -(a/b)*y;
    return res;
}
int main()
{
    ll x,y,m,n,L;
    cin>>x>>y>>m>>n>>L;
    ll s = gcd(n-m,L);
    if ((x-y)%s!=0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    ll x1=0,y1=0;
    exgcd((n-m)/s,L/s,x1,y1);
    x1 = ((x1*(x-y)/s)%(L/s)+L/s)%(L/s);
    cout << x1 << endl;
    return 0;
}

