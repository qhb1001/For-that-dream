#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,i;cin>>T;
    bool flagdown,flag;
    ll be,now;
    while(T--){
        int n;cin>>n;
        flagdown=false;flag=true;
        cin>>now>>be;
        if(now>=be){
            flag=false;
        }
        for(i=2;i<n;i++){
            cin>>now;
            if(now<be){
                flagdown=true;
                be=now;
                break;
            }
            if (now==be) {
                flag=false;
            }
            be=now;
        }
        for(i++;i<n;i++){
            cin>>now;
            if (now>=be) {
                flag=false;
            }
            be=now;
        }
        if(!flag||!flagdown) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
