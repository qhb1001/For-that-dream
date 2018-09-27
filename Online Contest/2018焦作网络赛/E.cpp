#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    unsigned long long a = 10, b = 100;
    cout <<  a << endl;
    a = ~a * 10;
    cout << a << endl;
    a = ~a;
    
    cout << a << ' ' << ~b << endl;
}