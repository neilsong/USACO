#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<pair<int, int>>> adj;
vector<vector<int>>twodist;
vector<int> visited, Visited;

void bfs(int source) {
	queue<pair<int,int>> q;
	q.push({ source,0 });
	visited.clear();
	visited.resize(V);
	while (!q.empty()) {
		int cv = q.front().first;
		int cdist = q.front().second;
		if(cv!=source)twodist[source][cv] = min(cdist, twodist[source][cv]);
		q.pop();
		if(cv!=source) { if (visited[cv]) continue; }
		visited[cv] = 1;
		for (auto i : adj[cv]) {
			if (visited[i.first])continue;
			if (twodist[source][i.first] > min(twodist[source][cv], i.second)) {
				twodist[source][i.first] = min(twodist[source][cv], i.second);
			}
			q.push(i);
		}
	}
}
ifstream fin("mootube.in");
ofstream fout("mootube.out");

int main(void) {
	int q;
	fin >> V >> q;
	adj.resize(V);
	Visited.resize(V);
	twodist.resize(V);
	for (int i = 0; i < V; i++) {
		twodist[i].resize(V);
		fill(twodist[i].begin(), twodist[i].end(), INT_MAX);
	}
	for (int i = 0; i < V-1; i++) {
		int v1, v2,w;
		fin >> v1 >> v2 >> w;
		v1--; v2--;
		adj[v1].push_back({ v2,w });
		adj[v2].push_back({ v1,w });
	}
	for (int i = 0; i < q; i++) {
		int node, k;
		fin >> k >> node;
		node--;
		int ans = 0;
		if (!Visited[node]) {
			Visited[node] = 1;
			bfs(node);
		}
	
		for (int i = 0; i < V; i++) {
			if (twodist[node][i] != INT_MAX && twodist[node][i] >= k) {
				ans++;
			}
		}
		fout << ans << endl;
	}
}