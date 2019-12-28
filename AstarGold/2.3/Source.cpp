#include <bits/stdc++.h>
using namespace std;
int n, m, x;

struct vert {
	int u, c, f;
};

vector<vector<vert>> adj;
vector<int> flows;


int dijkstra(int f) {
	vector<int> visited(n), dist(n, INT_MAX);
	priority_queue<pair<int, int>, std::vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
	dist[0] = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		int v = pq.top().second; int vw = pq.top().first; pq.pop();
		if (vw > dist[v]) continue;
		for (auto u : adj[v]) {
			if (u.f < f) continue;
			if (dist[v] + u.c < dist[u.u]) {
				dist[u.u] = dist[v] + u.c;
				pq.push({ dist[u.u], u.u });
			}
			
		}
	}
	return dist[n - 1];
}

int main(void) {
	cin >> n >> m >> x;
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b, c, f;
		cin >> a >> b >> c >> f; a--; b--;
		adj[a].push_back({ b,c,f });
		adj[b].push_back({ a,c,f });
		flows.push_back(f);
	}
	int bc = 0, bf = 1;
	for (auto f : flows) {
		int cf = f;
		int cc = dijkstra(f);
		if (cc == INT_MAX) continue;
		if (bc == 0 || (float)(cc + (float)(x/cf)) < (float)(bc + (float)(x/bf))) {
			bc = cc; bf = cf;
		}
	}
	cout << (int)(bc + (float)(x / bf));
}