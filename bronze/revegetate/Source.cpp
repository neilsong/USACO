#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(void) {
	ifstream cin("revegetate.in");
	ofstream cout("revegetate.out");
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> past(n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 4; j++) {
			int valid = 1;
			for (auto k : adj[i]) {
				if (past[k] == j) {
					valid = 0;
					break;
				}
			}
			if (valid) {
				past[i] = j;
				cout << j;
				break;
			}
		}
	}
	return 0;
}