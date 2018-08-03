#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
string s, t;
int len;
void input() {
    cin >> len >> s >> t;
}
bool check() {
    int l[30] = {0}, r[30] = {0};
    for (int i = 0; i < len; ++i)   {
        ++l[s[i] - 'a'];
        ++r[t[i] - 'a'];
    }

    for (int i = 0; i < 30; ++i)    if (l[i] != r[i])   return false;
    return true;
}

void deal() {
    vector<int>ans;
    for (int i = 0; i < len; ++i) {
        if (t[i] == s[i])   continue;
        for (int j = i + 1; j < len; ++j) {
            if (t[i] == s[j]) {
                while (j != i) {
                    ans.push_back(j - 1);
                    swap(s[j], s[j - 1]);
                    --j;
                }
                break;
            }
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)    cout << ans[i] + 1<< ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //get the input
    input();

    //if it is possible to finish the task
    if (check() == 0)   {
        cout << -1 << endl;
        return 0;
    }

    //greedy change
    deal();
}