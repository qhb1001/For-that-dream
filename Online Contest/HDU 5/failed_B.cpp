#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int n, k, len;
char s[15], a[15], b[15];
struct Node {
    int idx;
    char c;
    Node(int a = 0, char b = 0) : idx(a), c(b) {}
};
vector<Node>q[12];

int find_min(char x, int idx) {//在idx位置之后寻找比x小的
    for (char c = (idx == 0? '1' : '0'); c != x; ++c) {
        for (int i = len - 1; i > idx; --i) {
            if (a[i] == c)  {
                return i;
            }
        }
    }

    return -1;
}

int find_max(char x, int idx) {
    for (char c = '9'; c != x; --c) {
        for (int i = len - 1; i > idx; --i) {
            if (b[i] == c) return i;
        }
    }

    return -1;
}
int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s%d", s, &k);

        //deal with the first index
        len = strlen(s);
        memcpy(a, s, sizeof(s));
        memcpy(b, s, sizeof(b));
        int t = find_min(a[0], 0), cnt = 0;
        for (int i = 0; i <= 10; ++i)   q[i].clear();
        if (t != -1) {
            swap(a[t], a[0]);
            ++cnt;
        }

        
        for (int i = 1; i < len; ++i) {
            if (cnt == k)   break;
            t = find_min(a[i], i);
            if (t != -1) {
                q[a[t] - '0'].push_back(Node(i, a[i]));
                swap(a[t], a[i]);
                ++cnt;
            }
            if (cnt == k)   break;
        }
        
        for (int i = 0; i <= 9; ++i) {
            
        }
        cnt = 0;
        for (int i = 0; i < len; ++i) {
            t = find_max(b[i], i);
            if (t != -1) {
                swap(b[t], b[i]);
                ++cnt;
            }
            if (cnt == k)   break;
        }
        printf("%s %s\n", a, b);
    }
}