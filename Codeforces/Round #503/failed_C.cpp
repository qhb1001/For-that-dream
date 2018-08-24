#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 3e3 + 5;

typedef long long ll;
struct Node {
    int id, belong;
    ll cost;
    Node(int a = 0, int b = 0, ll c = 0): id(a), belong(b), cost(c) {}
    bool operator < (const Node b) const {
        return cost > b.cost;
    }
}a, b, c;

struct Party {
    priority_queue<Node>q;
    int len, id;
    Party() {
        len = 0;
    }
}party[MAX];

int belong[MAX], n, m, now, lenOfParty; //用于保存党派id对应的下标
bool vis[MAX];
priority_queue<Node>people;
void input() {
    cin >> n >> m;
    int idOfParty;
    ll cost;
    for (int i = 1; i <= n; ++i) {
        cin >> idOfParty >> cost;
        if (idOfParty != 1) {
            ++party[idOfParty].len;
            party[idOfParty].q.push(Node(i, idOfParty, cost));
            people.push(Node(i, idOfParty, cost));
            belong[i] = idOfParty;
        } else {
            ++now;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();

    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }

    int Max = 0, id;
    for (int i = 1; i <= m; ++i) Max = max(Max, party[i].len);
    if (now > Max) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {//保证之后每次都至少可以从中取出两个元素
        cout << people.top().cost << endl;
        return 0;
    }
    ll ans = 0;
    while (true) {
        // for (int i = 1; i <= n; ++i)    cout << vis[i] << ' ';
        // cout << endl;

        Max = 0;
        for (int i = 2; i <= m; ++i) {
            // cout << party[i].len << ' ';
            if (Max < party[i].len) {
                Max = party[i].len;
                id = i;
            }
        }
        // cout << endl;
        if (now > Max)  break;

        if (now == Max) {
            while (vis[party[id].q.top().id])   party[id].q.pop();
            while (vis[people.top().id])    people.pop();
            a = party[id].q.top();
            b = people.top();
            if (b.belong == id) {
                ans += b.cost;
                vis[b.id] = 1;
                party[id].q.pop();
            } else {
                vis[b.id] = 1;
                ans += b.cost;
            }
            people.pop();
            ++now;
            party[id].len--;
        } else {
            while (vis[party[id].q.top().id])   party[id].q.pop();
            while (vis[people.top().id])    people.pop();

            a = party[id].q.top(); party[id].q.pop();
            b = people.top(); people.pop(); c = people.top();  people.pop();

            if (a.id == b.id || a.id == c.id) {
                ans += a.cost;
                ++now;
                party[id].len--;
                vis[a.id] = 1;
                if (a.id == b.id) {
                    people.push(c);
                } else {
                    people.push(b);
                }
            } else {

                // cout << now << ' ' << 1 << endl;
                // cout << a.cost << ' ' << b.cost << ' ' << c.cost << endl;
                if (a.cost > b.cost + c.cost) {
                    ans += b.cost;
                    vis[b.id] = 1;
                    party[id].q.push(a);
                    ++now;
                    party[b.id].len--;
                    people.push(c);
                } else {
                    people.push(c);
                    people.push(b);
                    vis[a.id] = 1;
                    ans += a.cost;
                    party[id].len--;
                    ++now;
                }
            }
        }
    }

    cout << ans << '\n';
}