#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
int n, k;

int o1bfs(int A) {
	deque<int> dq;
	vector<int> visited(n), dist(n, INT_MAX);
	dist[0] = 0;
	dq.push_back(0);
	while (!dq.empty()) {
		int v = dq.front();
		dq.pop_front();
		visited[v] = 1;
		for (auto i : adj[v]){
			if (i.second >= A) dist[i.first] = min(dist[i.first], dist[v] + 1);
			else dist[i.first] = min(dist[i.first], dist[v]);
			if (visited[i.first]) continue;
			if (i.second >= A) dq.push_back(i.first);
			else dq.push_front(i.first);
		}
	}
	if (dist[n - 1] == INT_MAX) return -1;
	else if (dist[n - 1] > k)return 0;
	return 1;
}


int binsearch() {
	int lo=  0, hi = 1000000;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int result = o1bfs(mid);
		if (result == -1) {
			return -1;
		}
		else if (result > 0) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return (lo+hi)/2;
}

int main() {
	int p;
	cin >> n >> p >> k;
	adj.resize(n);
	for (int i = 0; i < p; i++) {
		int a, b, w;
		cin >> a >> b >> w; a--; b--;  w--;
		adj[a].push_back({ b,w });
		adj[b].push_back({ a,w });
	}
	int ans = binsearch();
	cout << ans << endl;
	return 0;
}