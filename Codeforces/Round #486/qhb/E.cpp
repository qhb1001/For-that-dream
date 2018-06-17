#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string a, b;
int len;
int dealFirst(char now) {
	int nowIdx = -1;
	for (int i = 0; i < len; ++i)
		if (a[i] == now)
			nowIdx = i;

	if (nowIdx == -1)	return -1;
	int ans = 0, firstNoZero;
	for (int i = nowIdx; i < len - 1; ++i) {
		swap(b[i], b[i + 1]);
		++ans;
	}
	if (nowIdx != 0)	return ans;
	b = a;
	ans = 0;
	for (int i = len - 1; i > 0; --i)
		if (b[i] != '0')	firstNoZero = i;

	for (int i = firstNoZero; i > 0; --i) {
		swap(b[i], b[i - 1]);
		++ans;
	}

	for (int i = 1; i < len - 1; ++i) {
		swap(b[i], b[i + 1]);
		++ans;
	}
	return ans;
}

int dealSecond(char now) {
	int nowIdx = -1, ans = 0;
	for (int i = 0; i < len - 1; ++i)
		if (b[i] == now)	nowIdx = i;

	if (nowIdx == -1)	return -1;

	if (nowIdx != 0)	return len - 1 - nowIdx;

	int firstNoZero = -1;
	for (int i = len - 1; i > 0; --i)
		if (b[i] != '0')	firstNoZero = i;

	if (firstNoZero == -1)	return -1;

	return firstNoZero + len - 2 - 1;
}
int min(int a, int b) {
	if (a == -1)	return b;
	if (b == -1)	return a;
	if (a < b)	return a;
	return b;
}
int main() {
	cin >> a;
	len = a.size();
	if (len < 3) {
		if (a == "25" || a == "50" || a == "75")	cout << 0 << endl;
		else if (a == "52" || a == "57")	cout << 1 << endl;
		else	cout << -1 << endl;
		return 0;
	}

	int ans = -1;
	b = a;
	string temp[4] = {"25", "00", "50", "75"};

	for (int i = 0; i < 4; ++i) {
		b = a;
		if (dealFirst(temp[i][1]) != -1 && dealSecond(temp[i][0]) != -1)
			ans = min(ans, dealFirst(temp[i][1]) + dealSecond(temp[i][0]));
		cout << dealFirst(temp[i][1]) << " " << dealSecond(temp[i][0]) << endl;
	}

	cout << ans << endl;
}
