#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long ll;
int n;
ll p,q,b;
ll gcd(ll a,ll b){
    return a==0?b:gcd(b%a,a);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(n--){
        cin>>p>>q>>b;
        if(p==0){
            cout<<"Finite"<<endl;
            continue;
        }
        ll tmp=gcd(p,q);
        q/=tmp;
        if(q<=b){
            if(b%q==0){
                cout<<"Finite"<<endl;
            }
            else cout<<"Infinite"<<endl;
        }
        else{
            while((q%b)==0){
                q/=b;
            }
            if(q==1) cout<<"Finite"<<endl;
            else cout<<"Infinite"<<endl;
        }
    }
    return 0;
}
