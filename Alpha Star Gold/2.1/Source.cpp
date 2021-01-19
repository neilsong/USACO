#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;

void bfs() {
	vector<int> dist(n, INT_MAX), visited(n);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (visited[v]) continue;
		visited[v] = 1;
		for (auto u : adj[v]) {
			dist[u] = min(dist[u], dist[v] + 1);
			if (visited[u]) continue;
			q.push(u);
		}
	}
	vector<int>::iterator iter = max_element(dist.begin(), dist.end());
	int ind = iter - dist.begin() + 1, maxd = *iter, ocur = 0;
	for (auto i : dist) {
		if (i == maxd) ocur++;
	}
	cout << ind << " " << maxd << " " << ocur;
}

int main(void) {
	cin >> n >> m;
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs();
}