#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string ans[]={"","First","Second","Third"};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b&&a<c){
            cout<<ans[1]<<endl;
        }
        if(b<a&&b<c) cout<<ans[2]<<endl;
        if(c<a&&c<b) cout<<ans[3]<<endl;
    }
    return 0;
}
