#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e5 + 5;
long long sum[5];
string a, b;
int aa[MAX], bb[MAX];
int main() {
    int len;
    cin >> len >> a >> b;
    for (int i = 0; i < len; ++i)   {
        aa[i + 1] = a[i] - '0';
        bb[i + 1] = b[i] - '0';
    }

    int now;
    for (int i = 2; i <= len; ++i) {
        now = aa[i] * 2 + bb[i];
        sum[now]++;
    }

    long long  ans = 0;
    for (int i = 1; i <= len; ++i) {
        now = aa[i] * 2 + bb[i];
        if (i != 1) sum[now]--;


        if (now == 0) {
            ans += sum[2] + sum[3];
        } else if (now == 2) {
            ans += sum[0] + sum[1];
        } else if (now == 1) {
            ans += sum[2];
        } else {
            ans += sum[0];
        }
    }

    cout << ans << endl;
}