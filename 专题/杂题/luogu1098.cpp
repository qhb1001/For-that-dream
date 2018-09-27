#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string a, b;
int p1, p2, p3;
char get1(char c) {
    if (p1 == 3)    return '*';
    if ('0' <= c && c <= '9')   return c;

    if (p1 == 1)  return c;
    else if (p1 == 2) return c - 32;
    
}
string get(char c) {
    string now = "";
    for (int i = 0; i < p2; ++i) now += c;
    return now;
}
bool isChar(char c) {
    if ('a' <= c && c <= 'z')   return true;
    return false;
}
bool isDigit(char c) {
    if ('0' <= c && c <= '9')   return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> p1 >> p2 >> p3 >> a;
    if (a.size() < 3)    {
        cout << a << endl;
        return 0;
    }
    int len = a.size();
    b += a[0];
    for (int i = 1; i < len - 1; ++i) {
        if (a[i] == '-' && a[i + 1] > a[i - 1] && ((isDigit(a[i + 1]) && isDigit(a[i - 1])) || (isChar(a[i+1]) && isChar(a[i-1])))) {
            
            if (a[i - 1] + 1 == a[i + 1]) continue;


            if (p3 == 1) { //正序输出
                for (char c = a[i - 1] + 1; c < a[i + 1]; ++c) b += get(get1(c));
            } else {
                for (char c = a[i + 1] - 1; c > a[i - 1]; --c)  b += get(get1(c));
            }
        } else b += a[i];
    }
    b += a[len - 1];
    cout << b << endl;
}