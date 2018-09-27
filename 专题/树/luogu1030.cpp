#include <iostream>
#include <string>
using namespace std;
void deal(string a, string b) {
    if (a.size()) {
        char c = b[b.size() - 1];
        int k = a.find(c);
        cout << c;
        deal(a.substr(0, k), b.substr(0, k));
        deal(a.substr(k + 1), b.substr(k, b.size() - k - 1));
    }
}
int main() {
    string a, b;
    cin >> a >> b;
    deal(a, b);
    
}