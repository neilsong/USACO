#include <bits/stdc++.h>
using namespace std;
int w, h;
vector<vector<int>> grid;
vector<int> shrubs;
vector<int> dx{ -1,1,0,0 }, dy{ 0,0,-1,1 };
vector<int> visited;
#define INF 0x3f3f3f3f
vector<vector<int>> dist(2);


void flood(pair<int, int> s, int id) {
	queue<pair<int, int>> q;
	q.push(s);
	while (!q.empty()) {
		pair<int, int> prev = q.front();
		q.pop();
		if (visited[prev.first * w + prev.second]) continue;;
		if (grid[prev.first][prev.second] == 1) continue;
		if (id == 0 && grid[prev.first][prev.second] == 3) continue;
		if (id == 1 && grid[prev.first][prev.second] == 2) continue;
		
		visited[prev.first * w + prev.second] = 1;
		for (int i = 0; i < 4; i++) {
			pair<int, int> start = { prev.first + dx[i], prev.second + dy[i] };
			if (start.first == h && i == 1) continue;
			if (start.first == -1 && i == 0) continue;
			if (start.second == w && i == 3) continue;
			if (start.second == -1 && i == 2) continue;
			if (start != prev)dist[id][start.first * w + start.second] = min(dist[id][start.first * w + start.second], dist[id][prev.first * w + prev.second] + 1);
			if (visited[(start.first) * w + start.second]) continue;
			q.push({ start.first, start.second });
		}
	}
}

int main(void) {
	cin >> w >> h;
	grid.assign(h, vector<int>(w, 0));
	pair<int,int> start, end;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 2) start = { i,j };
			if (grid[i][j] == 3) end = { i,j };
			if (grid[i][j] == 4) shrubs.push_back(i * w + j);
		}
	}
	dist[0].assign((w * h) + 1, INF); dist[1].assign((w * h) + 1, INF); dist[0][start.first * w + start.second] = 0; dist[1][end.first * w + end.second] = 0;
	visited.assign((w * h)+1, 0);
	flood(start, 0);
	visited.assign(w * h+1, 0);
	flood(end, 1);
	int ans = INF;
	for (auto i : shrubs) {
		ans = min(ans, dist[0][i] + dist[1][i]);
	}
	cout << ans << endl;
}