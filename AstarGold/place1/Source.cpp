#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> visited;
vector<int> ans;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	ans[start] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		visited[v] = 1;
		for (auto u : adj[v]) {
			if (visited[u]) continue;
			q.push(u);
			ans[u] = ans[v] + 1;
		}
	}
}

int main(void) {
	cin >> n >> m;
	adj.resize(n);
	visited.resize(n);
	ans.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c; a--; b--; c--;
		adj[a].push_back(b);
		adj[a].push_back(c);
	}
	bfs(0);
	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}