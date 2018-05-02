#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int L,n;
        cin>>L>>n;
        L++;
        int maxx=1,minn=1;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            maxx=max(maxx,max(abs(x),abs(L-x)));
            minn=max(minn,min(abs(x),abs(L-x)));
        }
        cout<<minn<<" "<<maxx<<endl;
    }
    return 0;
}
