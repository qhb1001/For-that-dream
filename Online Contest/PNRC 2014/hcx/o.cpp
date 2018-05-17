#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct ty{
    double w,c;
}Node[205];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            cin>>Node[i].w>>Node[i].c;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            int tmp=1;
            for(int j=i+1;j<n;j++){
                if(Node[j].w<=Node[i].w||Node[j].c>=Node[i].c) break;
                tmp++;
            }
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}

