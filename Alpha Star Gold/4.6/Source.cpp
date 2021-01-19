#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int,int>>> adj;
vector<int> parent;
vector<int> dx{ 1,-1,0,0 }, dy{ 0,0,1,-1 };
vector<vector<char>> grid;
vector<vector<int>>intgrid;

void flood(int i, int j, int id){
	if (grid[i][j] != 'X' || intgrid[i][j]) return;
	intgrid[i][j] = id;
	for (int k = 0; k < 4; k++) {
		int cx = i + dx[k], cy = j + dy[k];
		if (cx < 0 || cx > n - 1 || cy < 0 || cy > m - 1) {
			continue;
		}
		flood(cx, cy, id);
	}
}
vector<vector<int>> dist(3);
void o1bfs(int source, int id) {
	deque<int> dq;
	vector<int> visited(n * m);
	dist[id].assign(n * m, INT_MAX);
	dist[id][source] = 0;
	dq.push_back(source);
	while (!dq.empty()) {
		int v = dq.front();
		dq.pop_front();
		if (visited[v])continue;
		visited[v] = 1;
		for (auto i : adj[v]) {
			int x = i.first/m, y = i.first % m;
			int weight;
			grid[x][y] == '.' ? weight = 1 : weight = 0;
			dist[id][i.first] = min(dist[id][i.first], dist[id][v] + weight);
			if (visited[i.first]) continue;
			if (weight == 1)dq.push_back(i.first);
			else dq.push_front(i.first);
		}
	}
}

int main(void) {
	cin >> n >> m;
	adj.resize(n*m);
	grid.assign(n + 1, vector<char>(m + 1, '0'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	intgrid.assign(n + 1, vector<int>(m + 1, 0));
	vector<int> sources;
	int id = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 'X' && !intgrid[i][j]) {
				flood(i, j, id);
				sources.push_back(i * m + j);
				id++;
			}
			for (int k = 0; k < 4; k++) {
				int cx = i + dx[k], cy = j + dy[k];
				if (cx < 0 || cx > n - 1 || cy < 0 || cy > m - 1) {
					continue;
				}
				int weight = 1;
				if (grid[cx][cy] == 'X' && grid[i][j] == 'X') weight = 0;
				adj[i * m + j].push_back({ cx * m + cy, weight });
				adj[cx * m + cy].push_back({ i * m + j, weight });
			}
		}
	}
	int ind = 0;
	for (auto i : sources) {
		o1bfs(i, ind);
		ind++;
	}
	int ans = INT_MAX;
	for (int j = 0; j < n * m; j++) {
		int compare = 1;
		int same = dist[0][j];
		int sum = same;
		for (int i = 1; i < 3; i++) {
			sum += dist[i][j];
			if (dist[i][j] != same) compare = 0;
		}
		if (compare) sum -= 2;
		ans = min(ans, sum);
	}
	cout << ans<< endl;
}