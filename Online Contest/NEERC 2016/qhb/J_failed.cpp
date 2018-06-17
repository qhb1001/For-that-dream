#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int n, m, sum, First[222], Second[222];
string in[222];
void preTreatment() {
	for (int i = 1; i <= sum; ++i) {
		First[i] = (in[i][0] - '0') * 100 + (in[i][1] - '0') * 10 + in[i][2] - '0';
		Second[i] = (in[i][3] - '0') * 100 + (in[i][4] - '0') * 10 + in[i][5] - '0';
	}
}
vector<int>G[222];
void buildGraph() {
	for (int i = 1; i <= n; ++i)
		for (int j = n + 1; j <= sum; ++j) {
			if (First[i] == Second[j])	G[i].push_back(j);
			if (Second[i] == First[j])	G[j].push_back(i);
		}
}

 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	sum = n + m;
	for (int i = 1; i <= sum; ++i) {
		cin >> in[i];
	}
}
