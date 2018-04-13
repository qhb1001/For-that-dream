#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll a[maxn],sum[maxn];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    double avg=sum[n]/2.0;
    for(int i=1;i<=n;i++){
        if(sum[i]>=avg){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
