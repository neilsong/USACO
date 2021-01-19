#include <bits/stdc++.h>
using namespace std;

vector<vector <int>> adj;
vector <int> trav;
int n;

long MST() {
	vector <int> visited(n, 0), dist(n, -1);
	dist[0] = 0;
	int count = 0;
	long ans = 0;
	while (count != n) {
		pair<int, int> minv = { 0,-1 };
		int ind = 0;
		for (auto i : dist) {
			if (!visited[ind]) {
				if (minv.second < i) {
					minv.first = ind;
					minv.second = i;
				}
			}
			ind++;
		}
		visited[minv.first] = 1;
		ans += minv.second;
		count++;
		int distind = 0;
		for (int j = 0; j < n-1; j++) {
			if (j == minv.first) distind++;
			if (adj[minv.first][j] > dist[distind]) {
				dist[distind] = adj[minv.first][j];
			}
			distind++;
		}
	}
	return ans;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		trav.push_back(w);
	}
	adj.resize(n);
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				adj[i].push_back(trav[i] ^ trav[j]);
			}
		}
	}
	cout << MST() << endl;
}