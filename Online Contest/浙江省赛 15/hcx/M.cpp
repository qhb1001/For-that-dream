#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        bool flag=false;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(!((x+d)%7)) flag=true;
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
