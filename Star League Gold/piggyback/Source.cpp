#include <bits/stdc++.h>
using namespace std;

int V, M, B, E, P;
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
	cin >> B >> E >> P >> V >> M;
	adj.resize(V);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	vector <int> dist1, dist2, dist3;
	bfs(0);
	dist1 = dist;
	dist.clear();
	visited.clear();
	bfs(1);
	dist2 = dist;
	dist.clear();
	visited.clear();
	bfs(V - 1);
	dist3 = dist;
	dist.clear();
	visited.clear();
	int ans = INT_MAX;
	for (int i = 0; i < V; i++) {
		int cost = dist1[i] * B + dist2[i] * E + dist3[i] * P;
		ans = min(ans, cost);
	}
	cout << ans << endl;
}