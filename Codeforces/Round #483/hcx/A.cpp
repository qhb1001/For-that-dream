#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1005;
int a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<a[(n-1)/2]<<endl;
    return 0;
}
