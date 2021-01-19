#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<unordered_set<int>> G;

void dfs(int s, int v) {
	G[s].insert(v);
	for (auto w : G[v]) {
		if (G[s].find(w) == G[s].end())
		{
			dfs(s, w);
		}
	}
}

int main(void) {
	int n, m, q;
	cin >> n >> m >> q;
	G.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		G[a - 1].insert(b - 1);
		G[b - 1].insert(a - 1);
	}
	for (int v = 0; v < n; v++) {
		for (auto i : G[v]) {
			dfs(v, i);
		}
	}
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (G[a-1].find(b-1) != G[a-1].end() || G[b-1].find(a-1) != G[b-1].end()) cout << "Y" << endl;
		else cout << "N" << endl;
	}
}