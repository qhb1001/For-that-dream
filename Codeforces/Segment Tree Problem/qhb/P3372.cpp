#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
typedef long long ll;
struct Node {
	ll val, lazy;
	int l, r;
	struct Node*L, *R;
};
ll a[MAX];
void build(Node*& t, int l, int r) {
	t->l = l;t->r = r;t->lazt = 0;
	if (l == r) {
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

}
