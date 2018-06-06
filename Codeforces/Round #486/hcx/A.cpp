#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int n,m,x,mm;
bool vis[105];
int idx[105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    mm=m;
    for(int i=1;i<=n;i++){
        cin>>x;
        vis[x]=1;
        idx[x]=i;
    }

    for(int i=1;i<=100;i++){
        if(vis[i]) m--;
    }
    if(m>0) cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(int i=1;i<=100;i++){
            if(vis[i]) cout<<idx[i]<<" ",mm--;
            if(!mm) break;
        }
        cout<<endl;
    }
    return 0;
}

