#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int n;
ll p,q,b;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
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
        if(q==1) cout<<"Finite"<<endl;
        else {
            tmp=gcd(q,b);
            while(tmp>1){
                while((q%tmp)==0){//1 32 10
                    q/=tmp;
                }
                tmp=gcd(q,b);//7 8 4
            }

            if(q==1){
                cout<<"Finite"<<endl;
            }
            else cout<<"Infinite"<<endl;
        }
    }
    return 0;
}