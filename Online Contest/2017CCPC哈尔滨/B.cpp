#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
int a[MAX], b[MAX];
ll n, m, k;
// bool check(int x) {
//     vector<int>temp;
//     temp.push_back(0);
//     for (int i = 1; i <= n; ++i) if (a[i] >= x) temp.push_back(i);
//     ll ans = 0;
//     int len = temp.size();
//     for (int i = k; i < len; ++i) {
//         ans += (temp[i - k + 1] - temp[i - k]) * (n - temp[i] + 1);
//     }
//     return ans >= m;
// }

bool check(int x){
    int l=1,r=1;
    int tmp=0;
    ll ans=0;
    while(l+k-1<=n){
        while(r<=n&&tmp<k){
            if(a[r++]>=x) tmp++;
        }
        // cout<<l<<" "<<r<<endl;
        if(tmp<k) break;
        ans+=n-r+2;

        if(a[l]>=x) tmp--;
        l++;
    }
    // cout<<ans<<endl;
    return ans>=m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> k >> m;
        for (int i = 1; i <= n; ++i) {cin >> a[i]; b[i] = a[i];}
        sort(b + 1, b + 1 + n);
        int l = 1, r = n + 1, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (check(b[mid])) l = mid + 1;
            else r = mid - 1;
        }

        // cout<<"**"<<check(b[3])<<endl;
        mid = l + r >> 1;
        for (int i = 5; i >= -5; --i) if (mid + i <= n && mid + i >= 1 && check(b[mid + i])) {mid += i; break;}
        cout << b[mid] << endl;
    }


}