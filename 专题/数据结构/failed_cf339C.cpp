#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
#include <vector>
using namespace std;
set<int>s;
vector<int>ans;
pair<int, int> now;
int last;
bool flag;
set<int>::iterator it;
bool check(int k) {
    int dx;
    if (flag)   k--;
    while (true) {
        dx = abs(now.first - now.second);
        it = s.upper_bound(dx);
        if (it == s.end()) break;
        if (*it == last)    ++it;
        if (it == s.end())  break;
        last = *it;
        if (!flag) now.first += *it;
        else now.second += *it;
        ans.push_back(last);
        cout << last << ' ';
        flag = !flag;
        --k;
        if (!k) break;
    }
    if (!k) return true;
    return false;
}
int main() {
    string in; int k;
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> in >> k;
    for (int i = 0, len = in.size(); i < len; ++i) {
        if (in[i] == '1')   s.insert(i + 1);
    }

    for (int i = 0; i < s.size(); ++i) {
        ans.clear(); if (!i) flag = false; else flag = true;
        if (!i) last = 0, now.first = now.second = 0;
        else {
            int t = i; it = s.begin();
            while (t--) it++;
            cout << ".........." << endl;
            now.first = *it; now.second = 0; last = *it;
            ans.push_back(last);
        }

        if (check(k))  {break;}
    }

    if (ans.size() == k) {cout << "YES\n"; for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' '; cout << endl;}
    else cout << "NO\n";
}