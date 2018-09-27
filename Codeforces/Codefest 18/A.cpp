#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
ll sum[100], two[100];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) cout << 1 << endl;
    else if (n == 2 || n == 3) cout << 2 << endl;
    else {
        two[1] = 1; two[2] = 2;
        sum[1] = 1; sum[2] = 3;
        for (int i = 3; i <= 50; ++i) {
            two[i] = sum[i - 1] + 1;
            sum[i] = sum[i - 1] + two[i];
            if (sum[i] >= n) {cout << i << endl; return 0;}
            
        }
    }
}
