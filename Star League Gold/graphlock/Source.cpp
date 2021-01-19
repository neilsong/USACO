#include <bits/stdc++.h>
using namespace std;

int V, E, T;
vector<vector<pair<int, int>>> adj;
vector < vector<char>> mat;
vector <int> visited, dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//adj pair<vertex, weight>
//pq pair<dist, vertex>

void dijkstra(int source) {
	visited.resize(V*T);
	dist.resize(V*T);
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
	cin >> V >> E >> T;
	mat.resize(V);
	adj.resize(V*T);
	for (int i = 0; i < V; i++) {
		mat[i].resize(T);
		for (int j = 0; j < T; j++) {
			cin >> mat[i][j];
			if (j != T - 1) {
				adj[i*T + j].push_back({ i*T + j + 1,1 });
			}
			else {
				adj[i*T + j].push_back({ i*T, 1 });
			}
		}
	}
	for (int i = 0; i < E; i++) {
		int s, e;
		cin >> s >> e;
		int temps = s;
		s = min(s, e);
		e = max(temps, e);
		for (int j = 0; j < T; j++) {
			if (mat[s - 1][j] == mat[e - 1][j]) {
				adj[((s - 1)*T) + j].push_back({ ((e - 1)*T) + j , 0 });
				adj[((e - 1) * T) + j].push_back({ ((s - 1) * T) + j , 0 });
			}
		}
	}
	dijkstra(0);
	int ans = INT_MAX;
	for (int i = (V - 1) * T; i < V * T; i++) {
		ans = min(ans, dist[i]);
	}
	cout << ans << endl;
}