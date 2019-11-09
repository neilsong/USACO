#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> nbrs[100001];
map<pair<int, int>, int> edgewt;

map<int, int> dist;
vector <int> parent;

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
				parent[j] = i;
				visited.insert(make_pair(dist[j], j));
			}
	}
}

//insertion
int main(void) {
	
	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		a--; b--;
		nbrs[a].push_back(b);
		nbrs[b].push_back(a);
		edgewt[make_pair(a, b)] = t;
		edgewt[make_pair(b, a)] = t;
	}
	dijkstra(S);
	int diff = dist[D];
	vector <int> path;
	int i = N-1, j = parent[N-1];
	while (i != j) {
		path.push_back(i);
		i = parent[i];
		j = parent[i];
	}
	path.push_back(S);
	int Max = 0;
	for (int i = path.size() - 1; i > 0; i--) {
		edgewt[{path[i], path[i - 1]}] *= 2;
		edgewt[{path[i-1], path[i]}] *= 2;
		dist.clear();
		dijkstra(S);
		Max = max(Max, dist[D]);
		edgewt[{path[i], path[i - 1]}] /= 2;
		edgewt[{path[i - 1], path[i]}] /= 2;
	}
	cout << Max - diff<< endl;
}
