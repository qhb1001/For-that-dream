#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>q;
    q.push_back(1);
    q.push_back(2);
    cout << q.size() - 3 << endl;
}