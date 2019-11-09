#include <bits/stdc++.h>
using namespace std;

vector <int> bounds;
map<int, int> numof;
vector<vector<int>> visited;

vector <vector <int>> grid;
int ccount = 0;

void floodfill(int x, int y, int id) {
	if (visited[x][y])
		return;
	visited[x][y] = 1;
	numof[grid[x][y] - id]++;
	if (x > 0) {
		 floodfill(x-1,y, grid[x][y]);
	}
	if (x < grid.size() - 1) {
		 floodfill(x + 1, y, grid[x][y]);
	}
	if (y > 0) {
		floodfill(x, y-1, grid[x][y]);
	}
	if (y < grid.size() - 1) {
		floodfill(x, y+1, grid[x][y]);
	}
	return;
}


int binsearch() {
	int lo = 0;
	int hi = bounds.size()-1;
	int mid = (lo + hi) / 2;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		long compare = 0;
		for (auto i : numof) {
			if (i.first == bounds[mid]) {
				compare += i.second;
				break;
			}
			compare += i.second;
		}
		if (compare > (pow(grid.size(),2) /2)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	return bounds[mid];
}

int main(void) {
	int n;
	cin >> n;
	grid.resize(n);
	visited.resize(n);
	set<int> bset;
	for (int i = 0; i < n; i++) {
		grid[i].resize(n);
		visited[i].resize(n);
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			grid[i][j] = a;
			bset.insert(a);
		}
	}
	for (auto i : bset) {
		bounds.push_back(i);
		numof.insert(make_pair(i, 0));
	} 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {	
				floodfill(i, j, grid[i][j]);
				numof[grid[i][j]] = ccount;
				ccount = 0;
			}
		}
	}
	cout << binsearch() << endl;
}