#include <bits/stdc++.h>
using namespace std;

int d, p, c, f, s;
vector<vector<pair<int, int>>> adj;
vector <int> dist;
bool check = 0;

void bellmanford() {
	dist.resize(c);
	fill(dist.begin(), dist.end(), INT_MAX);
	dist[s-1] = 0;
	for (int i = 0; i < c; i++) {
		check = 0;
		for (int j = 0; j < c; j++) {
			int v = dist[j];
			if (v != INT_MAX) {
				for (auto l : adj[j]) {
					int cost = l.second, u = dist[l.first];
					if (v + cost < u) {
						dist[l.first] = cost + v;
						check = 1;
					}
				}
			}
		}
	}
	if (check) { cout << "-1" << endl; return; }
}

int Min = INT_MAX;
int main(void) {
	cin >> d >> p >> c >> f >> s;
	adj.resize(c);
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back({ b-1, 0 - d });
	}
	for (int i = 0; i < f; i++) {
		int a, b, C;
		cin >> a >> b >> C;
		adj[a-1].push_back({ b-1, C - d });
	}
	bellmanford();
	if (check) return 0;
	else {
		for (auto i : dist) {
			Min = min(Min, i);
		}
	}
	Min -= d;
	cout << 0 - Min << endl;
}