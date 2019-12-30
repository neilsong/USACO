#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

vector<int> sizes, parent;
int n;

int root(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = root(parent[v]);
}

//union by size
void join(int u, int v) {
	int U = root(u); int V = root(v);
	if (U == V) return;
	if (sizes[U] < sizes[V]) {
		parent[U] = V;
		sizes[V] += sizes[U];
	}
	else {
		parent[V] = U;
		sizes[U] += sizes[V];
	}
}

vector<vector<int>> adj;

int main(void) {
	cin >> n;
	sizes.assign(n, 1); parent.resize(n);
	iota(parent.begin(), parent.end(), 0);
	adj.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		int v1, v2;
		cin >> v1 >> v2; v1--; v2--;
		join(v1, v2);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	vector<vector<int>> adj2;
	adj2.assign(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == i || root(j) == root(i)) continue;
			adj2[root(i)][root(j)] = min(adj2[root(i)][root(j)], adj[i][j] * 2);
		}
	}
	int ans = INF;
	for (int i = 0; i < n; i++) {
		if (root(i) != i) continue;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (adj2[i][j] == INF) continue;
			sum += adj2[i][j];
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}