void bfs() {
	vector<int> dist(n, INT_MAX), visited(n);
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (visited[v]) continue;
		visited[v] = 1;
		for (auto u : adj[v]) {
			dist[u] = min(dist[u], dist[v] + 1);
			if (visited[u]) continue;
			q.push(u);
		}
	}
}