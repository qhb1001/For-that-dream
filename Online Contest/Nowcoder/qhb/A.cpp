#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
string ans, in;
int len;
void deal(char c, int begin) {
	int final = begin - 1;

	for (int i = begin; i < len; ++i) {
		if (in[i] == c)	{
			final = i;
			ans += c;
		}
	}

	if (c == 'a')	return ;
	deal(c - 1, final + 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> in;
	len = in.size();
	deal('z', 0);
	cout << ans << endl;
}
