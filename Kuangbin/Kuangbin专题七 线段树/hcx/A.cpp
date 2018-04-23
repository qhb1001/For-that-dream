#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int t[maxn];
int n,m;
void bulid(){
    for(int i=n-1;i>0;i--){
        t[i]=t[i<<1]+t[i<<1|1];
    }
}

void update(int x,int add){
    for(t[x+=n]+=add;x>1;x>>=1){
        t[x>>1]=t[x]+t[x^1];
    }
}

ll query(int l,int r){
    ll ans=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1){
            ans+=t[l++];
        }
        if(r&1){
            ans+=t[--r];
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    int Case=1;
    while(T--){
        cout<<"Case "<<Case++<<":"<<endl;
        cin>>n;
        for(int i=0;i<n;i++) cin>>t[i+n];
        bulid();
        string s;
        while(cin>>s&&s[0]!='E'){
            int x,y;cin>>x>>y;
            if(s[0]=='Q'){
                cout<<query(x-1, y)<<endl;
            }
            else if(s[0]=='A'){
                update(x-1, y);
            }
            else if(s[0]=='S'){
                update(x-1, -y);
            }
        }
    }
    
    return 0;
}
