#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 1<<13;
char s[MAX];
struct Node {
    int l, r;
    char c;
}t[MAX];
void build(int i, int l, int r) {
    // cout << l << ' ' << r << endl;
    t[i].l = l; t[i].r = r; 
    if (l == r) {
        if (s[l] == '0')    t[i].c = 'B';
        else if (s[l] == '1')   t[i].c = 'I';
        return ;
    }
    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
    if (t[i<<1].c == t[i<<1|1].c)   t[i].c = t[i<<1].c;
    else    t[i].c = 'F';
}
void traverse(int i) {
    if (t[i].l == t[i].r) {
        cout << t[i].c;
        return ;
    }
    traverse(i<<1);
    traverse(i<<1|1);
    cout << t[i].c;
}
int main() {
    int n;
    scanf("%d%s", &n, s + 1);

    build(1, 1, 1<<n);
    traverse(1);

}