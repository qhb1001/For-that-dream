#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<iterator>
using namespace std;
typedef unsigned long long ull;
#define top(a) ceil(64/(log(a)/log(2)))-1
int vis[80];
set<ull> s;
set<ull>::iterator si;
void solve(int n){
    memset(vis,0,sizeof(vis));
    int t = sqrt(n+0.5);
    for(int i=2;i<=t;i++) if(!vis[i])
        for(int j=i*i;j<=n;j+=i) vis[j]=1;
}
int main(){
    solve(80);
    s.clear();
    cout<<"1"<<endl;
    for(ull i=2;i<(1<<16);i++){
        int tp=top(i);
        ull num=i;
        for(int j=2;j<=tp;j++)
        {
            num*=i;
            if(!vis[j]) continue;
            if(s.count(num)==0) s.insert(num);
        }
    }
    si=s.begin();
    while(si!=s.end())
        cout<<*si++<<endl;
    return 0;

}
