#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string a, b, c;
long long ans[4], len[4], N;
void deal(long long &ans, string now) {
	int len = now.size();
	int letter[200] = {0};
	for (int i = 0; i < len; ++i)
		letter[now[i]]++;

	int Max = 0;
	for (int i = 0; i < 200; ++i)
		if (letter[i] > Max)	Max = letter[i];
	ans = Max;
}

bool pre() {
	int cnt = 0;
	while (true) {
		if (!N)	break;
		bool flag = 0;
		for (int i = 1; i <= 3; ++i) {
			if (ans[i] == len[i])	flag = 1;
		}
		if (!flag)	break;
		for (int i = 1; i <= 3; ++i) {
			if (ans[i] == len[i])	ans[i]--;
			else	ans[i]++;
		}
		--N;
		++cnt;
		if (cnt > 100000)	break;
	}
	if (cnt > 100000)	return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	cin >> a >> b >> c;
	len[1] = a.size(); len[2] = b.size(); len[3] = c.size();
	deal(ans[1], a); deal(ans[2], b);deal(ans[3], c);
	if (pre()) {
		cout << "Draw\n";
		return 0;
	}
	ans[1] += min(len[1] - ans[1], N);
	ans[2] += min(len[2] - ans[2], N);
	ans[3] += min(len[3] - ans[3], N);

	if (ans[1] > ans[2] && ans[1] > ans[3])	cout << "Kuro" << endl;
	else if (ans[2] > ans[1] && ans[2] > ans[3])	cout << "Shiro" << endl;
	else if (ans[3] > ans[1] && ans[3] > ans[2])	cout << "Katie" << endl;
	else	cout << "Draw" << endl;
}
