#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int e[105];
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n/2;i++){
        cin>>e[i];
    }
    sort(e+1,e+1+n/2);
    int even=0,odd=0;
    int idx=n/2,now=n;;
    while(idx>0){
        even+=abs(now-e[idx]);
        idx--;
        now-=2;
    }

    idx=n/2;now=n-1;
    while(idx>0){
        odd+=abs(now-e[idx]);
//        cout<<now<<" "<<e[idx]<<" "<<odd<<endl;
        idx--;
        now-=2;
    }
    cout<<min(even,odd)<<endl;
    return 0;
}
