#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2005;
int one[MAX], two[MAX], dp[MAX];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i)	cin >> one[i];
		for(int i = 2; i <= n; ++i)	cin >> two[i];
		dp[1] = one[1];
		for(int i = 2; i <= n; ++i) 
			dp[i] = min(dp[i - 1] + one[i], dp[i - 2] + two[i]);
		
		int second = dp[n];
		int minute = second / 60;second %= 60;
		int hour = minute / 60;minute %= 60;
		printf("%02d:%02d:%02d %s\n", (hour + 8), minute, second, (hour + 8) > 12? "pm": "am");
	}
}
