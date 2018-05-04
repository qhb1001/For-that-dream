#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int n, from ,to, temp;
const int MAX = 3e4 + 5;
vector<int>G[MAX];
bool dfs(int now) {
	if(now == to)	return true;
	for(int i = 0; i < G[now].size(); ++i) {
		if(!dfs(G[now][i]))	continue;
		else	return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> to;
	for(int i = 1; i < n; ++i){
		cin >> temp;
		G[i].push_back(temp + i);
	}

	cout << ((dfs(1) == true)? "YES": "NO") << endl;
}
