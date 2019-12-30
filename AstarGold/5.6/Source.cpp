#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist(2);
int n, k;
void bfs(vector<int> sources, int d) {
	queue<int> q;
	for (auto i : sources) {
		q.push(i);
		dist[d][i] = 0;
	}
	vector<int> visited(n);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (visited[v])continue;
		visited[v] = 1;
		for (auto u : adj[v]) {
			dist[d][u] = min(dist[d][u], dist[d][v] + 1);
			if (visited[u]) continue;
			q.push(u);
		}
	}
}

vector<vector<int>> adj;

int main(void) {

	cin >> n >> k; k--;
	adj.resize(n);
	dist[0].resize(n); dist[1].resize(n);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> sources;
	sources.push_back(k);
	bfs(sources, 0);
}