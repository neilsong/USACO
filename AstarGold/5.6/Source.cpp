#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dist(2);
vector<vector<int>> adj;
vector<int> parent;
int n, k;
int ans = 0;
void dfs() {
	stack<int> stk;
	stk.push(k);
	vector<int> visited(n);
	while (!stk.empty()) {
		int v = stk.top();
		stk.pop();
		if (visited[v]) continue;
		visited[v] = 1;
		if (dist[0][v] == dist[1][v] + 1 || dist[0][v] == dist[1][v]) { ans++; continue; }
		for (auto u : adj[v]) {
			if (visited[u]) continue;
			stk.push(u);
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(k);
	dist[0][k] = 0;
	vector<int> visited(n);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (visited[v])continue;
		visited[v] = 1;
		for (auto u : adj[v]) {
			if (dist[0][v] + 1 < dist[0][u]) {
				dist[0][u] = min(dist[0][u], dist[0][v] + 1);
				parent[u] = v;
			}
			if (visited[u]) continue;
			q.push(u);
		}
	}
}
void msbfs(vector<int> sources) {
	queue<int> q;
	for (auto i : sources) {
		q.push(i);
		dist[1][i] = 0;
	}
	vector<int> visited(n);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (visited[v])continue;
		visited[v] = 1;
		auto u = parent[v];
		if (dist[1][v] + 1 < dist[1][u]) {
			dist[1][u] = min(dist[1][u], dist[1][v] + 1);
		}
		if (visited[u]) continue;
		q.push(u);
	}
}

int main(void) {
	cin >> n >> k; k--;
	adj.resize(n);
	parent.resize(n);
	dist[0].assign(n, INT_MAX); dist[1].resize(n, INT_MAX);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> sources;
	sources.push_back(k);
	bfs();
	sources.pop_back();
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 1) sources.push_back(i);
	}
	msbfs(sources);
	dfs();
	cout << ans << endl;
}