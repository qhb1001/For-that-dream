#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1005;
bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) if (x % i == 0)    return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int m = 1; m <= 1000; ++m) if (!isPrime(n * m + 1))    return 0 * printf("%d\n", m); 
}