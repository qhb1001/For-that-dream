#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
ll fib[100];
int main() {
    int a = 1, b = 1, t;
    fib[1] = 1;
    while (true) {
        if (a + b > 20) break;
        fib[a + b] = 1;
        t = b;
        b = a;
        a = a + t;
    }
    int T, cnt = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << "Case #" << cnt++ << ": ";

        int ans = 0;
        for (int i = 1; i <= n; ++i)    ans += fib[i];
        cout << n - ans << endl;
    
    }
}