#include <bits/stdc++.h>
using namespace std;


int V;
vector<vector <int>> adj;
vector <int> dist;

void BFS(int s) {
	vector <bool> visited(V);
	queue<int> tovisit;
	tovisit.push(s);
	cout << s+1 << endl;
	while (tovisit.size() != 0) {
		int v = tovisit.front();
		tovisit.pop();
		visited[v] = 1;
		for (int i = 0; i < V; i++) {
			if (!visited[i] && adj[v][i]) {
				tovisit.push(i);
				dist[i] = dist[v] + 1;
			}
		}		
	}
	for (int i = 0; i < V; i++) {
		bool hasNxt = 0;
		for (int j = 0; j < V; j++) {
			if (dist[j] == i) {
				cout << j+1 << " ";
				hasNxt = 1;
			}
		}
		cout << endl;
	}
}

int main(void) {
	int n, m; cin >> n >> m;
	V = n;
	adj.resize(V);
	dist.resize(V);
	fill(dist.begin(), dist.end(), -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			adj[i].push_back(a);
		}
	}
	BFS(m-1);
	return 0;
}