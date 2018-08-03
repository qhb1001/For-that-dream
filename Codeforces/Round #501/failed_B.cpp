#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
map<string, bool> vis;
string temp, s, t;
const int MAX = 1e4;
int ans[MAX + 5], len, step;
//len for the lenth of the string
//ans for the operation of the changing
void output() {
    cout << step << endl;
    for (int i = 0; i < step; ++i)  cout << ans[i] + 1 << ' ';
}
bool dfs() {
    if (temp == t) {
        output();
        return true;
    }

    vis[temp] = 1;
    if (step == MAX)    return false;
    for (int i = 0; i < len - 1; ++i) {
        swap(temp[i], temp[i + 1]);

        //memorize search
        if (vis[temp]) {
            swap(temp[i], temp[i + 1]);
            //trace-back!!!
            continue;
        }


        ans[step++] = i;
        if (dfs())  return true;

        //trace-back
        step--;
        swap(temp[i], temp[i + 1]);
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> len >> s >> t;
    temp = s;
    if (dfs() == 0) cout << -1;
}