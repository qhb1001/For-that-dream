#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF=1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a,w;
    cin>>n>>w;
    int maxx=w,minn=0;
    int now=0;
    for(int i=0;i<n;i++){
        cin>>a;
        now+=a;
        if(now>=0)maxx=min(maxx,w-now);
        if(now<0) minn=max(minn,-now);
    }
//    cout<<maxx<<" "<<minn<<endl;
    int ans;
    ans=maxx-minn+1<0?0:maxx-minn+1;
    cout<<ans<<endl;
    return 0;
}
