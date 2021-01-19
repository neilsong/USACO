#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> dist, visited;


void bfs(int source) {
	queue<int> q;
	q.push(source);
	dist.resize(V);
	visited.resize(V);
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
	cin >> V >> E;
	adj.resize(V);
	for (int i = 0; i < E; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	bfs(0);
}