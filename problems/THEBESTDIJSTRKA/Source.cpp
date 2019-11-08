#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> nbrs[100001];
map<pair<int, int>, int> edgewt;

map<int, int> dist;

void dijkstra(int source)
{
	set<pair<int, int>> visited;
	visited.insert(make_pair(0, source));
	while (!visited.empty()) {
		int i = visited.begin()->second;
		visited.erase(visited.begin());
		for (auto j : nbrs[i])
			if (dist.count(j) == 0 || dist[i] + edgewt[make_pair(i, j)] < dist[j]) {
				dist[j] = dist[i] + edgewt[make_pair(i, j)];
				visited.insert(make_pair(dist[j], j));
			}
	}
}

//insertion
for (int i = 0; i < M; i++) {
	int a, b, t;
	fin >> a >> b >> t;
	a--; b--;
	nbrs[a].push_back(b);
	nbrs[b].push_back(a);
	edgewt[make_pair(a, b)] = t;
	edgewt[make_pair(b, a)] = t;
}