#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	set<string>s;
	string a, now;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		bool letter[100] = {0};
		for (int j = 0; j < a.size(); ++j) 
			letter[a[j] - 'a'] = 1;
		now = "";
		for (int j = 0; j < 26; ++j)
			if (letter[j])	now +=(char)(j + 'a');
		s.insert(now);
	}

	cout << s.size() << endl;
}
