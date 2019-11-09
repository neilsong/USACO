#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
int n;

int MST() {
	vector <int> visited(n, 0), dist(n,INT_MAX);
	dist[0] = 0;
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
	
	cin >> n;
	adj.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int v;
			cin >> v;
			if(v != 0) adj[i].push_back(make_pair(j, v));
		}
	}
	cout << MST();
}