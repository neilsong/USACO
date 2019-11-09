#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<pair<int, int>>> adj;
vector <int> visited, dist, parent;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//adj pair<vertex, weight>
//pq pair<dist, vertex>

void dijkstra(int source) {
	visited.resize(V);
	dist.resize(V);
	fill(dist.begin(), dist.end(), INT_MAX);
	pq.push({ 0,source });
	dist[source] = 0;
	parent.resize(V);
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (auto i : adj[cur]) {
			int a = i.first;
			int b = i.second;
			if (dist[a] > cost + b) {
				dist[a] = cost + b;
				pq.push({ dist[a], a });
				parent[a] = cur;
			}
		}
	}
}

int main(void) {
	cin >> V >> E;
	adj.resize(V);
	for (int i = 0; i < E; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		v1--; v2--;
		adj[v1].push_back({ v2,w });
		adj[v2].push_back({ v1,w });
	}
	dijkstra(0);
	cout << dist[V-1] << endl;
}