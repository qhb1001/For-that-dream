#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 3e5 + 5;
typedef long long ll;
int G[2][MAX], n;
ll sum111[2][MAX], sum123[2][MAX], sum321[2][MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> G[i][j];
        }
    }

    for (int i = 1; i <= 2; ++i) {
        for (int j = n; j >= 1; --j) {
            sum111[i][j] = sum111[i][j + 1] + G[i][j];
            sum123[i][j] = sum123[i][j + 1] + 1ll * j * G[i][j];
            sum321[i][j] = sum321[i][j + 1] + 1ll * (n - j + 1) * G[i][j];
        }
    }
}

struct Node {
    ll now;
    int x, y, t;

    //如果在第一行，表示第二行是否被使用
    //如果在第二行，表示第一行是否被使用
    bool ok;

    Node(ll a = 0, int c = 0, int d = 0, bool e = 0, int f = 1) {
        now = a;
        x = c; y = d;
        ok = e;
        t = f;
    }
}now, temp;

ll ans;
void deal() {
    queue<Node>q;
    q.push(Node(G[1][1], 1, 1, false));

    ll temp;
    while (q.empty() == 0) {
        now = q.front(); q.pop();
        if (now.y > n) {
            ans = max(ans, now.now);
            continue;
        }

        if (now.x == 1) {
            if (now.ok == false && now.y != n) {
                //首先向右走，拐弯，回到当前点下方
                temp = now.now + sum123[1][now.y + 1] + now.t * sum111[1][now.y + 1];
                temp += (now.t + 1 - now.y + 1) * sum111[2][now.y] + sum321[2][now.y];
                if (temp > ans) ans = temp;
            }

            if (now.ok == true && now.y != n) {
                temp = now.now + sum123[1][now.y + 1] + now.t * sum111[1][now.y + 1];
                temp += (now.t + 1 - now.y + 1) * sum111[2][now.y + 1] + sum321[2][now.y + 1];
                if (temp > ans) ans = temp;

                //向右走一步
                q.push(Node(now.now + 1ll * G[1][now.y + 1] * (now.t + 1), 1, now.y + 1, false, now.t + 1));
            }
        }

        if (now.x == 2) {
            if (now.ok == false && now.y != n) {
                //首先向右走，拐弯，回到当前点下方
                temp = now.now + sum123[2][now.y + 1] + now.t * sum111[2][now.y + 1];
                temp += (now.t + 1 - now.y + 1) * sum111[1][now.y] + sum321[1][now.y];
                if (temp > ans) ans = temp;
            }

            if (now.ok == true && now.y != n) {
                temp = now.now + sum123[2][now.y + 1] + now.t * sum111[2][now.y + 1];
                temp += (now.t + 1 - now.y + 1) * sum111[1][now.y + 1] + sum321[1][now.y + 1];
                if (temp > ans) ans = temp;

                //向右走一步
                q.push(Node(now.now + 1ll * G[2][now.y + 1] * (now.t + 1), 2, now.y + 1, false, now.t + 1));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    deal();
    cout << ans << endl;
}