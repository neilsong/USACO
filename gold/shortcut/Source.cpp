#include <bits/stdc++.h>
using namespace std;

int V, E,T;
vector<vector<pair<int, int>>> adj;
vector <int> visited, dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> reference(10005);


//adj pair<vertex, weight>
//pq pair<dist, vertex>

vector<vector<long long>> spadj; //(shortest path tree, used for occurrences);
vector<int> parent;
vector<long long> nums; //(number of occurrences)

//use a dfs to fill nums (occurrences of vertex in the paths)
void dfs(int v, int p) {
	long long sum = reference[v]; //intial amount passing through (1 by default)
	for (auto nei : spadj[v]) {
		if (nei == p) continue;
		dfs(nei, v);
		sum += nums[nei];
	}

	nums[v] = sum;
}

void dijkstra(int source) {
	visited.resize(V);
	dist.resize(V);
	fill(dist.begin(), dist.end(), INT_MAX);
	pq.push({ 0,source });
	dist[source] = 0;
	fill(begin(parent), end(parent), -1);
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = 1;
		for (auto i : adj[cur]) {
			int a = i.first;
			int b = i.second;
			if (dist[a] > cost + b) {
				dist[a] = cost + b;
				pq.push({ dist[a], a });
				parent[a] = cur;
			}
			//lexicographically smallest
			else if (dist[a] == cost + b) {
				if (cur < parent[a]) {
					parent[a] = cur;
					pq.push({ dist[a],a });
				}
			}
		}
	}
}

int main(void) {
	ifstream fin("shortcut.in");
	ofstream fout("shortcut.out");
	fin >> V >> E >> T;
	adj.resize(V);
	spadj.resize(V);
	parent.resize(V);
	nums.resize(V);
	for (int i = 0; i < V; i++) {
		int cow;
		fin >> cow;
		reference[i] = cow;
	}
	for (int i = 0; i < E; i++) {
		int v1, v2, w;
		fin >> v1 >> v2 >> w;
		v1--; v2--;
		adj[v1].push_back({ v2,w });
		adj[v2].push_back({ v1,w });
	}
	dijkstra(0);

	//standard backtrack O(N^2)
	//for (int k = 1; k <= n; k++) {
	//	vector<int> path;
	//	int i = k;
	//	while (i != -1) {
	//		path.push_back(i);
	//		i = par[i];
	//	}
	//
	//}


	//occurrences of vertex in path
	for(int k = 1; k < V; k++){
	  //construct edge list using the parent array
		spadj[k].push_back(parent[k]);
		spadj[parent[k]].push_back(k);
	}
	dfs(0, -1);
	long long ans = 0;
	for (int i = 1; i < V; i++) {
		ans = max(ans, nums[i] * (dist[i] - T));
	}
	fout << ans << endl;
}
