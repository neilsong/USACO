#include <bits/stdc++.h>
using namespace std;

//literally impossible
//literally impossible
//literally impossible
//literally impossible
//literally impossible
//literally impossible
//literally impossible


typedef long long ll;
#define INF 0x3f3f3f3f
vector<int> dx{ 1,-1,0,0, 1, -1,1,-1 }, dy{ 0,0,-1,1, 1, -1,-1,1 };
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<pair<int, int>> vpair;
int n, m;
vvint grid;
vector<vector<vector<int>>> cs;
vint mx, my;

vpair rmat{ {0,-1},{1,0} };

vvint r(vvint mat) {
	vvint tr;
	tr.assign(2*n + 1, vector<int>(m + 1, -1));
	int minx = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] < 0) continue;
			tr[i * rmat[0].first + j * rmat[0].second + m][i * rmat[1].first + j * rmat[1].second] = mat[i][j];
			minx = min(minx, i * rmat[0].first + j * rmat[0].second + m);
		}
	}
	for (int i = minx; i < 2*n; i++) {
		for (int j = 0; j < m; j++) {
			if (tr[i][j] >= 0) {
				tr[i - minx][j] = tr[i][j]; tr[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < n; i++) tr.pop_back();
	return tr;
}

void ff(int x, int y, int id) {
	if (grid[x][y] >= 0 || grid[x][y] == -1) return;
	grid[x][y] = id;
	for (int i = 0; i < 8; i++) {
		int cx = dx[i] + x, cy = dy[i] + y;
		if (cx < 0 || cx > n - 1 || cy < 0 || cy > m - 1) continue;
		ff(cx, cy, id);
	}
}

void altff(int x, int y, int id) {
	if (grid[x][y] != id) return;
	cs[id][x - mx[id]][y - my[id]] = 1;
	for (int i = 0; i < 4; i++) {
		if (x == n - 1 && i == 0)continue;
		if (x == 0 && i == 1)continue;
		if (y == m - 1 && i == 2) continue;
		if (y == 0 && i == 3)continue;
		ff(x + dx[i], y + dy[i], id);
	}
}


int main() {
	cin >> n >> m;
	grid.assign(n + 1, vector<int>(m + 1, 0));
	vvint model;
	model.assign(n + 1, vector<int>(m + 1, -1));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '*') grid[i][j] = -2;
			else grid[i][j] = -1;
		}
	}
	ll id = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == -2) {
				ff(i, j, id); id++;
			}
			if (grid[i][j] >= 0){
				ll cid = grid[i][j];
				if (cs.size() == cid) {
					cs.push_back(model);
					mx.push_back(INF);
					my.push_back(INF);
				}
				mx[cid] = min(mx[cid], i);
				my[cid] = min(my[cid], j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cid = grid[i][j];
			if (cid < 0)continue;
			cs[cid][i - mx[cid]][j - my[cid]] = cid;
		}
	}


	vector<int> dup(cs.size());
	for (ll i = 0; i < cs.size(); i++) {
		auto r1 = r(cs[i]), r2 = r(r1), r3 = r(r2);
		for (ll j = i+1; j < cs.size(); j++) {
			if (dup[j]) continue;
			vint rcheck(4,1);
			for (int li = 0; li < n; li++) {	
				for (int lj = 0; lj < m; lj++) {
					ll val = cs[j][li][lj];
					if (val == -1) continue;
					val = i;
					if (cs[i][li][lj] != val) rcheck[0] = 0;
					if (r1[li][lj] != val) rcheck[1] = 0;
					if (r2[li][lj] != val)rcheck[2] = 0;
					if (r3[li][lj] != val) rcheck[3] = 0;
				}
			}
			if (*max_element(rcheck.begin(), rcheck.end())) dup[j] = 1;
		}
	}
	cout << cs.size() - dup << endl;
	return 0;
}