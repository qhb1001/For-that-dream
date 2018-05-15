#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
long long ans[5], N;
string a[5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= 3; ++i)	{
		cin >> a[i];
		long long len = a[i].size();
		int letter[200] = {0};
		for (int j = 0; j < len; ++j) {
			letter[a[i][j]]++;
		}

		long long Max = 0;
		for (int j = 0; j < 200; ++j)
			if (Max < letter[j])	Max = letter[j];

		ans[i] = Max;

		if (ans[i] == len && N == 1)	ans[i]--;
		else	ans[i] += min(len - ans[i], N);
	}


	if (ans[1] > ans[2] && ans[1] > ans[3])	cout << "Kuro\n";
	else if (ans[2] > ans[1] && ans[2] > ans[3])	cout << "Shiro\n";
	else if (ans[3] > ans[1] && ans[3] > ans[2])	cout << "Katie\n";
	else cout << "Draw\n";
}
