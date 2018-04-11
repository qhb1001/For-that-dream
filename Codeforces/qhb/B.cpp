#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 2e5 + 5;
char in[MAX], now[MAX];
int main() {
	int n, a, b;
	scanf("%d%d%d%s",&n, &a, &b, in + 1);

	in[0] = '*';
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(a == 0 && b == 0)	break;
		if(in[i - 1] == '*' && in[i] == '.') {
			 if(a > b)	{
				--a;
				++ans;
				now[i] = 'a';
			 } else {
				--b;
				++ans;
				now[i] = 'b';
			 }
		} else if(in[i - 1] == '.' && in[i] == '.') {
			if(now[i - 1] == 'a' && b) {
				now[i] = 'b';
				--b;
				++ans;
			} else if(now[i - 1] == 'b' && a){
				now[i] = 'a';
				--a;
				++ans;
			}
		}
	}

	cout << ans << endl;
}
