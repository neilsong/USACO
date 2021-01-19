#include <bits/stdc++.h>
using namespace std;

int V, E, s1, s2, d, comp1 = 0, comp2 = 0;
vector<vector<pair<int, int>>> adj;
vector <int> visited, dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//adj pair<vertex, weight>
//pq pair<dist, vertex>

void dijkstra(int source) {
	visited.resize(V);
	dist.resize(V);
	fill(dist.begin(), dist.end(), INT_MAX);
	pq.push({ 0,source });
	dist[source] = 0;
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
			}
		}
	}
}

int main(void) {
	
	cin >> E >> V >> s1 >> s2 >> d;
	s1--; s2--; d--;
	adj.resize(V);
	for (int i = 0; i < E; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		v1--; v2--;
		adj[v1].push_back({ v2,w });
		adj[v2].push_back({ v1,w });
	}
	dijkstra(s1);
	comp1 += dist[s2];
	comp2 += dist[d];
	visited.clear();
	dist.clear();
	dijkstra(s2);
	comp1 += dist[d];
	comp2 += dist[d];
	cout << min(comp1, comp2) << endl;
}