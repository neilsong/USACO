#include <bits/stdc++.h>
using namespace std;

void dijkstra() {
	vector<int> visited(n), dist(n, INT_MAX);
	priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	dist[0] = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int v = pq.top().second; int vw = pq.top().first; pq.pop();
		if (vw > dist[v]) continue;
		for (auto u : adj[v]) {
			if (dist[v] + u.c < dist[u.u]) {
				dist[u.u] = dist[v] + u.c;
				pq.push({ dist[u.u], u.u });
			}
		}
	}
}