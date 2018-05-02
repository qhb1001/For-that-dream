#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct ty{
    int val;
    int type;
}a[maxn];
int idx;
bool check(ty a,ty b){
    if(a.type==b.type) return a.val<b.val;
    else return a.type<b.type;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n,m;string s;
        cin>>n>>m;
        idx=0;
        for(int i=1;i<=n;i++){
            cin>>s;
            if(s[0]=='W'){
                idx=i;
                continue;
            }
            cin>>a[i].val;
            if(s[0]=='C') a[i].type=1;
            else if(s[0]=='B') a[i].type=2;
            else if(s[0]=='D') a[i].type=3;
        }
        a[n+1].type=3;a[n+1].val=m;
        if(n==1) {
            cout<<3*m<<endl;
            continue;
        }
        if(idx==1){
            cout<<(a[2].type-1)*m+a[2].val-1<<endl;
            continue;
        }
        if(idx==2){
            if(n==2) cout<<(a[3].type-a[1].type)*m+a[3].val-a[1].val+1<<endl;
            else
                cout<<(a[3].type-a[1].type)*m+a[3].val-a[1].val<<endl;
            continue;
        }
        if(!check(a[1], a[2])){
            cout<<1<<endl;
            continue;
        }
        if(idx==0){
            cout<<3*m-n+1<<endl;
            continue;
        }
        if(idx==n){
            cout<<(3-a[n-1].type)*m+m-a[n-1].val<<endl;
            continue;
        }
        cout<<(a[idx+1].type-a[idx-1].type)*m+a[idx+1].val-a[idx-1].val-1<<endl;
    }
    return 0;
}
