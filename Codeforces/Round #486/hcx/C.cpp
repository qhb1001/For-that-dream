#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
vector<int>v[maxn];
map<int,int>vis;
int k,val;
int l,r,x;
int sum[maxn];
int n[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++){
            cin>>x;v[i].push_back(x);
            sum[i]+=x;
        }
    }

    bool flag=false;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n[i];j++){
            x=v[i][j];
            if(!vis[sum[i]-x]||vis[sum[i]-x]==i)
                vis[sum[i]-x]=i;
            else{
                l=i;r=vis[sum[i]-x];
                x=sum[i]-x;
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    if(!flag)
        cout<<"NO\n";
    else{
        int idx1,idx2;
        for(int i=0;i<n[l];i++){
            if(v[l][i]==sum[l]-x)
                idx1=i+1;
        }
        for(int i=0;i<n[r];i++){
            if(v[r][i]==sum[r]-x)
                idx2=i+1;
        }
        cout<<"YES\n";
        cout<<l<<" "<<idx1<<endl<<r<<" "<<idx2<<endl;
    }
    return 0;
}
