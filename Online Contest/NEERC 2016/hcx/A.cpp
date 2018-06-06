#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    int x=min(n,m);
    int ans=n*2/x;
    int res = n*2 % x;
    if (res){
        ans++;
    }
    cout<<ans<<endl;

    return 0;
}
