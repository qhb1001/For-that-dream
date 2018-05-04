#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cctype>
#include <vector>
using namespace std;
const int MAX = 1005;
struct Node {
	string word, symbol;
}tempNode;
vector<Node>a[MAX];
void read(int n, string in) {
	tempNode.word = "";
	tempNode.symbol = "";
	int len = in.size();
	bool flag = 1;//1 - 正在读入word   0 - 正在读入分隔符
	for (int i = 0; i < len; ++i) {
		if (flag) {
			if (isdigit(in[i]) || isalpha(in[i]))	tempNode.word += in[i];
			else {
				flag = 0;
				tempNode.symbol += in[i];
			}
		} else {
			if (!isalpha(in[i]))	tempNode.symbol += in[i];
			else {
				flag = 1;
				a[n].push_back(tempNode);
				tempNode.word = in[i];
				tempNode.symbol = "";
			}
		}
	}
	a[n].push_back(tempNode);
}
void debug() {
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 0; j < a[i].size(); ++j)
			cout << a[i][j].word << a[i][j].symbol << endl;
	}
}

map<string, string>toOrigin;
set<string>s;
string toString(int x) {
	string ans = "";
	while (x) {
		ans = (char)(x % 10 + '0') + ans;
		x /= 10;
	}
	return	ans;
}
string deal(string t) {
	if (t.size() == 1)	return t;
	string small = t;
	transform(small.begin(), small.end(), small.begin(), ::tolower);
	string num = toString(t.size() - 2);
	if (isdigit(t[1]) == 0) {
		string aa = small[0] + num + small[small.size() - 1];
		string bb = (char)toupper(small[0]) + num + small[small.size() - 1];
		string cc = (char)toupper(small[0]) + num + (char)toupper(small[small.size() - 1]);
		if (toOrigin.count(aa) == 0) {
			toOrigin[aa] = small;
			toOrigin[bb] = small;
			toOrigin[cc] = small;
			//这样将会更加规范化
			return t;
		} else {
			if (toOrigin[aa] == small) {//如果这个缩写对应的串与其相同
				return t;
			}
			else {
				s.insert(aa);s.insert(bb);s.insert(cc);
				return t;//输出原串
			}
		}
	} else {
		if (s.find(t) != s.end())	return t;
		else {
			if (toOrigin.count(t) == 0)	return t;
			else {
				string ans = toOrigin[t];
				int len1 = ans.size(), len2 = t.size();
				if (ans[0] == t[0] && ans[len1 - 1] == t[len2 - 1])	return ans;
				else if (ans[0] != t[0] && ans[len1 - 1] == t[len2 - 1]) {
					ans = (char)toupper(ans[0]) + ans.substr(1);
					return ans;
				} else {
					transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
					return ans;
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	string in;
	
	freopen("input", "r", stdin);

	while (getline(cin, in)) {
		read(++n, in);
	}

	for (int i = 1; i <= n; ++i) {
		int len = a[i].size();
		for (int j = 0; j < len; ++j) {
			cout << deal(a[i][j].word) << a[i][j].symbol;
		}
		cout << '\n';
	}
//	debug();

}
