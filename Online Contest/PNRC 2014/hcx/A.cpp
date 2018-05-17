#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1e5+10;
int a[1005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        memset(a,0,sizeof(a));
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            a[x]++;
        }
        int maxx=0,idx;
        for(int i=1;i<=1000;i++)
        {
            if(a[i]>maxx){
                maxx=a[i];
                idx=i;
            }
        }
        cout<<idx<<endl;
    }

    return 0;
}
