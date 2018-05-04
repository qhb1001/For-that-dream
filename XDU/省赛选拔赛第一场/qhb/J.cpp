#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e6 + 5;
int Next[MAX];
int getNext(string &a) {
    int i = 0, j = -1, len = a.size();
    Next[0] = -1;
    while(i < len) {
        if(j == -1 || a[i] == a[j]) {
            Next[++i] = ++j;
        } else {
            j = Next[j];
        }
    }

	int ans = Next[len];
	while(ans != 0) {
		for(int i = ans + 1; i < len; ++i) {
			if(Next[i] == ans && Next[i] != i)	{
				return ans;
			}
		}
		ans = Next[ans];
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	while(cin >> a) {
		int ans = getNext(a);
		if(ans == -1)	cout << "Just a legend\n";
		else	{
			for(int i = 0; i < ans; ++i)	cout << a[i];
			cout << endl;
		}
	}
}
