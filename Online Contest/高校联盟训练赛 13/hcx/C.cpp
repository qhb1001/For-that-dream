#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int k,sub1,sub2,sub3;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>k){
        for(int i=10000;i<=30000;i++){
            sub1=i/100;
            sub2=i/10%1000;
            sub3=i%1000;
            if(sub1%k)continue;
            if(sub2%k)continue;
            if(sub3%k)continue;
//            cout<<sub1<<" "<<sub2<<" "<<sub3<<endl;
            cout<<i<<endl;
        }
    }
    return 0;
}
