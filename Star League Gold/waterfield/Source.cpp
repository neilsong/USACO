#include <bits/stdc++.h>
using namespace std;

map<pair<int,int> ,vector<pair<int, pair<int,int>>>> adj;
int n;


int MST() {
	vector <pair<int,int>> visited(n, adj.begin()->first);
	map<pair<int, int>, int> dist;
	dist[visited[0]] = 0;
	int count = 0, ans = 0;
	while (count != n) {
		pair<int, int> minv = { 0,INT_MAX };
		int ind = 0;
		for (auto i : dist) {
			if (!visited[ind]) {
				if (minv.second > i) {
					minv.first = ind;
					minv.second = i;
				}
			}
			ind++;
		}
		visited[minv.first] = 1;
		ans += minv.second;
		count++;
		for (auto j : adj[minv.first]) {
			if (j.second < dist[j.first]) {
				dist[j.first] = j.second;
			}
		}
	}
	return ans;
}

int main(void) {
	int n, c;
	cin >> n >> c;
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cost = ((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
			if (cost >= c) {
				adj[v[i]].push_back(make_pair(cost, v[j]));
			}
			
		}
	}
}