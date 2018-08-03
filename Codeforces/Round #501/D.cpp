#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
ll k, s, n;
void input() {
    cin >> n >> k >> s;
}
vector<int>ans;

//return the times to fully cover the number
ll get(ll x, ll a) {
    ll ans = x / a;
    if (x % a)  ++ans;
    return ans;
}

//find the boundary of devide the lower and higher
ll binary1() {// the range is [1, n - 1), because the plus operation
    ll l = 1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (get(s, mid) < k && get(s, mid + 1) < k)    r = mid - 1;
        else    l = mid + 1;
    }
    
    mid = (l + r) >> 1;
    for (ll i = 5; i >= -5; --i) {
        if (mid + i + 1 <= n - 1 && get(s, mid + i) >= k && get(s, mid + i + 1) <= k)   return mid + i;
    }
    return mid;
}

bool isInRange(ll x) {
    if (x >= 1 && x <= n)   return true;
    return false;
}
bool deal() {
    if (get(s, n - 1) > k)  return false;
    if (get(s, 1) < k)  return false;
    
    ll boundary = binary1();
    
    //find the exact times to use the bigger number
    ll l = 0, r = get(s, boundary + 1) + 1, mid, rr = r; //the range is [l, r)
//    cout << r << endl;
    while (l < r) {
        mid = (l + r) >> 1;
        if (mid + get(s - mid * (boundary + 1), boundary) > k)    l = mid + 1;
        else    r = mid - 1;
    }
    
    mid = (l + r) >> 1;
    for (ll i = 5; i >= -5; --i) {
//        if (mid + i == 9) cout <<mid + i + get(s - (mid + i) * (boundary + 1), boundary) << endl;
        if (mid + i < rr && mid + i + get(s - (mid + i) * (boundary + 1), boundary) == k) {
            cout << "YES\n";
            ll x = mid + i, pos = 1;
            
            while (x--) {
                if (isInRange(pos + boundary + 1)) {
                    cout << pos + boundary + 1<< ' ';
                    pos = pos + boundary + 1;
                }
                else {
                    cout << pos - boundary - 1<< ' ';
                    pos = pos - boundary - 1;
                }
            }
            
            s = s - (mid + i) * (boundary + 1);
            x = s / boundary;
            while (x--) {
                if (isInRange(pos + boundary))  {
                    cout << pos + boundary << ' ';
                    pos = pos + boundary;
                } else {
                    cout << pos - boundary << ' ';
                    pos = pos - boundary;
                }
            }
            
            if (s % boundary != 0) {
                x = s % boundary;
                if (isInRange(pos + x)) cout << pos + x << endl;
                else    cout << pos - x << endl;
            }
            break;
        }
    }
    
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    if (deal() == 0)    cout << "NO";
}
