#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <set>
using namespace std;
const int MAX = 5e4 + 5;
stack<int>Idx[MAX];
int a[MAX];
set<int>s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    while (cin >> n >> m >> q) {
        s.clear();
        for (int i = 1; i < MAX; ++i)    while(Idx[i].size())    Idx[i].pop();
        stack<int>toDelete;
        for (int i = 1; i <= q; ++i)    {
            cin >> a[i];
        }
        for (int i = q; i >= 1; --i)
            Idx[a[i]].push(i);
        int cnt = 1, ans = 0;
        if (n >= m) {
            for (int i = 1; i <= q; ++i)
                s.insert(a[i]);
            cout << s.size() << endl;
            continue;
        }
        while(s.size() != n) {
            if(s.find(a[cnt]) == s.end()) {
                s.insert(a[cnt]);
                Idx[a[cnt]].pop();
                ++ans;
            } else {
                Idx[a[cnt]].pop();
            }
            if(Idx[a[cnt]].size() == 0)    toDelete.push(a[cnt]);
            ++cnt;
        }

        for(int i = cnt; i <= q; ++i) {
            Idx[a[i]].pop();
            if(s.find(a[i]) == s.end()) {
                ++ans;
                if(toDelete.size() == 0) {
                    s.erase(s.begin());
                } else {
                    s.erase(s.find(toDelete.top()));
                    toDelete.pop();
                }
                s.insert(a[i]);
            }
            if(Idx[a[i]].size() == 0)    toDelete.push(a[i]);
        }
        cout << ans << '\n';
    }
}
