#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;
vector<vector<int>> pairs;
int main(void) {
	int u, l, p;
	cin >> u >> l >> p;
	vector<vector<int>> model(l+1, vector<int>(52+1, 0));
	dp.assign(u+1, model);
	for (int i = 0; i < p; i++) {
		string pair;
		cin >> pair;
		pairs[pair[0] - '64'].push_back(pairs[pair[1] - '64']);
		pairs[pair[1] - '64'].push_back(pairs[pair[0] - '64']);
	}
	for (int i = 1; i <= u; i++){
		for (int j = 1; j <= l; j++) {
			for
		}
	}
}