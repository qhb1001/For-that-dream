#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
int Time[1005], n, A, B, C, T;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> A >> B >> C >> T;
	if(C <= B) {
		cout << n * A << endl;
		return 0;
	} 

	int temp;
	for(int i = 1; i <= n; ++i) {
		cin >> temp;
		Time[temp]++;
	}

	int cnt = 0, sum = 0;
	for(int i = 1; i <= T; ++i) {
		sum += cnt * (C - B);
		cnt += Time[i];
	}

	sum += A * n;
	cout << sum << endl;
}
