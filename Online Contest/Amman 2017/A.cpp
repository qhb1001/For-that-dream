#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        memset(a,0,sizeof(a));
        string s ;int tmp;
        for(int i=0;i<n;i++){
            cin>>s>>tmp;
            a[tmp]++;
        }
        int ans=0,idx;
        for(int i=11111;i<=99999;i++){
            if(a[i]>ans){
                idx=i;
                ans=a[i];
            }
        }
        cout<<idx<<endl;
    }
    return 0;
}
