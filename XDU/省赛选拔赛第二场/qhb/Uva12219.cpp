#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int MAX = 5e4 + 5;
int l[MAX], r[MAX], cnt;
string a[MAX], in;
struct Tuple {
	string aa;
	int b, c;
	Tuple(){}
	Tuple(string aa, int bb, int cc) {
		this->aa = aa;
		b = bb;
		c = cc;
	}
	bool operator < (const Tuple& b) const {
		if (aa != b.aa)	return aa < b.aa;
		if (this->b != b.b)	return this->b < b.b;
		return c < b.c;
	}
}tempTuple;
map<Tuple, int>subTree;
int build(int x, int y) {
    string now = "";
//    cout << x << " " << y << endl;
    int u = ++cnt, p = 0;
    if (y - x <= 4) {
        bool flag = 0;
        for (int i = x; i < y; ++i) {
            now += in[i];
            if (in[i] == '(' || in[i] == ')' || in[i] == ',')    {
                flag = 1;
                break;
            }
        }
        if (!flag)    {
            l[u] = r[u] = 0;
            a[u] = now;
            return u;
        }
    }

    now = "";
    while (in[x] != '(')    now += in[x++];
    ++x;
    a[u] = now;

    int idx;
    for (int i = x; i < y; ++i) {
        if (in[i] == '(')    ++p;
        else if (in[i] == ')')    --p;
        else if (in[i] == ',' && !p)    {
            idx = i;
            break;
        }
    }

    if (in[idx] == ')')    l[u] = build(x, idx - 1);
    else    l[u] = build(x, idx);
    if (in[y - 1] == ')')   r[u] = build(idx + 1, y - 1);
    else    r[u] = build(idx + 1, y);


	if (subTree.count(Tuple(a[u], l[u], r[u])) != 0) {
		--cnt;
		return subTree[Tuple(a[u], l[u], r[u])];
	}
    return subTree[Tuple(a[u], l[u], r[u])] = u;;
}

int vis[MAX], kase = 1;
void print(int now) {
	//cout << now << endl;
	if (vis[now] == kase) {
		cout << a[now];
	} else {
		vis[now] = kase;
		if (l[now] != 0) {
			cout << a[now] << '(';print(l[now]);cout<<',';print(r[now]);cout<<')';
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> in;
		subTree.clear();
		build(0, in.size() - 1);
		++kase;
		print(1);
		cout << endl;
	}
}
