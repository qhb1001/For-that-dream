#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 5e4 + 5;
int n, xx[MAX], yy[MAX];
long long ans;
struct Node {
    int x, y, id;
    struct Node* nex;
};
void add(Node* now, Node* t) {
    t->nex = now->nex;
    now->nex = t;
}
void update1(Node* head, pair<int, int> now, int idx) {
    Node* cnt = head->nex;
    Node* last = head;
    while (cnt != NULL) {
        if (cnt->x < now.first) {
            if (yy[cnt->id] < now.second) {
                ans -= now.second - yy[cnt->id];
                yy[cnt->id] = now.second;
            }
        } else break;

        last = cnt;
        cnt = cnt->nex;
    }
    
    Node* tt = new Node();
    tt->id = idx;
    tt->x = now.first; tt->y = now.second; xx[idx] = yy[idx] = 0;
    add(last, tt);
}
void update2(Node* head, pair<int, int> now, int idx) {
    Node* cnt = head->nex;
    Node* last = head;
    while (cnt != NULL) {
        if (cnt->y < now.second) {
            if (xx[cnt->id] < now.first) {
                ans -= now.first - xx[cnt->id];
                xx[cnt->id] = now.first;
            }
        } else break;

        last = cnt;
        cnt = cnt->nex;
    }
    
    Node* tt = new Node();
    tt->id = idx;
    tt->x = now.first; tt->y = now.second; xx[idx] = yy[idx] = 0;
    add(last, tt);
}
int main( ) {
    scanf("%d", &n);
    Node* headX = new Node();
    Node* headY = new Node();
    headX->nex = headY->nex = NULL;
    pair<int, int>now;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &now.first, &now.second);
        ans += now.first + now.second;
        update1(headX, now, i);
        update2(headY, now, i);
    }

    printf("%lld\n", ans);
}