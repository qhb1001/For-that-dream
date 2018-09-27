#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e4 + 5;
int Month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int cal(int year, int month, int day, int hour, int minu) {
    int allYear = 365 * 24 * 60, ans = 0;
    ans += (year - 2013) * allYear;
    if (year == 2016)   Month[2] = 29;
    for (int i = 1; i < month; ++i) 
        ans += Month[i] * 24 * 60;
    ans += (day - 1) * 24 * 60;
    ans += hour * 60 + minu;
    if (year == 2016) Month[2] = 28;
    return ans;
}
vector<pair<int, int> >room;
char s[100];
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
int main() {

    int T; scanf("%d", &T);
    while (T--) {
        int b, c; scanf("%d%d", &b, &c);
        room.clear();
        for (int i = 1, year, month, day, hour, minu; i <= b; ++i) {
            scanf("%s", s); scanf("%d-%d-%d %d:%d", &year, &month, &day, &hour, &minu);
            room.push_back(make_pair(cal(year, month, day, hour, minu), 1));
            scanf("%d-%d-%d %d:%d", &year, &month, &day, &hour, &minu);
            room.push_back(make_pair(cal(year, month, day, hour, minu + c), -1));
        }

        sort(room.begin(), room.end(), cmp);

        int ans = 0, now = 0, len = room.size();
        for (int i = 0; i < len; ++i) {
            now += room[i].second;
            ans = max(now, ans);
        }

        printf("%d\n", ans);
    }
}