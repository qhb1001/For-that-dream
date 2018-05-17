#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll T,n,k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n==0){
        cout<<"0"<<endl;
        return 0;
    }
    n++;
    if(n%2) cout<<n<<endl;
    else cout<<n/2<<endl;

    return 0;
}
