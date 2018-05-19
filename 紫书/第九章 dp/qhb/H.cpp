#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 5e3 + 5;
int end[2][30];
string a, b;
int lena, lenb;
void in() {
	cin >> a >> b;
	lena = a.size();
	lenb = b.size();
	for (int i = 0; i < lena; ++i)
		end[0][a[i] - 'A'] = i;
	for (int i = 0; i < lenb; ++i)
		end[1][b[i] - 'A'] = i;
}

int dp[MAX][MAX], L[MAX][MAX];
void deal() {
:
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
