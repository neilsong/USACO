#include <bits/stdc++.h>
using namespace std;
int k, n, m;
vector<vector<int>> adj;
vector<int> past2cow;

vector<int> dist, visited;

void bfs(int source) {
	queue<int> q;
	q.push(source);
	dist.resize(n);
	visited.resize(n);
	fill(dist.begin(), dist.end(), INT_MAX);
	dist[source] = 0;
	while (!q.empty()) {
		int cv = q.front();
		q.pop();
		if (visited[cv]) continue;
		visited[cv] = 1;
		for (auto i : adj[cv]) {
			if (dist[i] > dist[cv] + 1) {
				dist[i] = dist[cv] + 1;
			}
			q.push(i);
		}
	}
}
int main(void) {
	cin >> k >> n >> m;
	adj.resize(n);
	past2cow.resize(n);
	for (int i = 0; i < k; i++) {
		int past;
		cin >> past;
		past--;
		past2cow[past]++;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int ccow = 0;
		bfs(i);
		for (int j = 0; j < dist.size(); j++) {
			if (dist[j] != INT_MAX) {
				if (past2cow[j]) {
					ccow+=past2cow[j];
				}
			}
		}
		if (ccow >= k) {
			ans++;
		}
		visited.clear();
		dist.clear();
	}
	cout << ans << endl;
}