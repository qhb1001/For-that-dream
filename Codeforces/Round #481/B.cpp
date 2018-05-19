#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;string s;
    cin>>n>>s;
    int cnt=0,ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='x'){
            cnt++;
        }
        else cnt=0;
        if(cnt==3){
            ans++;
            cnt--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
