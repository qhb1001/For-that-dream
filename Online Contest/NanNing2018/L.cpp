#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
               int n, Max = 0, temp;
               cin >> n;
               while(n--) {
                          cin >> temp;
                          Max = max(Max, temp);  
               }
               cout << Max << endl;
    }    
    
}

