#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int n, d, h;
int main() {
    cin >> n >> d >> h;
    if (!((d + 1) / 2 <= h && h <= d))  {cout << -1 << endl; return 0;}

    if (d == 1 && n >= 3)   {cout << -1 << endl; return 0;}
    int last = 1, cnt = 2;
    while (cnt != n + 1) {
        if (cnt <= h + 1) {cout << last << ' ' << cnt << '\n'; last = cnt++;}
        else if (cnt > h + 1 && cnt <= d + 1) {cout << last << ' ' << cnt << '\n'; last = cnt++;}
        else {
            if (h != 1)
                cout << 2 << ' ' << cnt++ << '\n';
            else 
                cout << 1 << ' ' << cnt++ << '\n';        
        }
            
        if (cnt == h + 2)   last = 1;
    }

    
}