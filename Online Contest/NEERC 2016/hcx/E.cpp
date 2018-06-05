#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
ll a[MAX], k, preMin, preMax, Max, idx;
int n;
void in() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (Max < a[i]) Max = a[i], idx = i;
        ++preMin;
        preMax += a[i];
    }
    preMin += Max - 1;
}
ll turnMin, idxMin, turnMax, idxMax;
void deal() {
    //得到最小值
    turnMin = k / preMin;
    ll res = k % preMin;

    for (int i = 1; i <= n; ++i) {
        if (res == 0) {
            idxMin = 1;
            break;
        }
        if (i != idx)   --res;
        else    res -= Max;
        if (res <= 0) {
            idxMin = i + 1;
            break;
        }
    }
    turnMax = k / preMax;
    res = k % preMax;
    for (int i = 1; i <= n; ++i) {
        if (res == 0) {
            idxMax = 1;
            break;
        }
        res -= a[i];
        if (res <= 0) {
            idxMax = i + 1;
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    in();
    if (k == 0) {
        if (idx == 1)   cout << "YES\n";
        else    cout << "KEK\n";
        return 0;
    }

    deal();
    if (turnMin - turnMax > 1)  cout << "YES\n";
    else {
        if(turnMin - turnMax == 1){
            if (idx >= idxMax || idx <= idxMin) cout << "YES\n";
            else    cout << "KEK\n";
        }else{
            if (idx >= idxMax && idx <= idxMin) cout << "YES\n";
            else    cout << "KEK\n";
        }
    }
    return 0;
}
