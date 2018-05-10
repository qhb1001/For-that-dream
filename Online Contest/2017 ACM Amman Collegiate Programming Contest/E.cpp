#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,k;
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        cout<<(n-1+k)<<endl;
    }
    return 0;
}
