#include <bits/stdc++.h>
using namespace std;
vector <vector <int>> grid(1000002);

int counter = 0;
bool perimcheck(int x, int y) {
	int corn = 0;
	if (x > 0) {
		corn++;
		if (grid[x - 1][y] == 1) {
			corn--;
		}
	}
	if (x < 1000000 - 1) {
		corn++;
		if (grid[x + 1][y] == 1) {
			corn--;
		}
	}
	if (y < 1000000 - 1) {
		corn++;
		if (grid[x][y + 1] == 1) {
			corn--;
		}
	}
	if (x > 0) {
		corn++;
		if (grid[x][y - 1] == 1) {
			corn--;
		}
	}
	if (!corn)return 0;
	return 1;
}
void fcorn(int x, int y) {
	if (grid[x][y] == 1) {
		if (x > 0) {
			fcorn(x-1,y);
		}
		if (x < 1000000 - 1) {
			fcorn(x + 1, y);
		}
		if (y > 0) {
			fcorn(x, y - 1);
		}
		if (y < 1000000 - 1) {
			fcorn(x, y + 1);
		}
	}
	else {
		if (perimcheck(x, y))counter++;
	}
}



int main(void) {
	for (int i = 0; i < grid.size(); i++) {
		grid[i].resize(1000000);
	}
	int n;
	cin >> n;
	int x1=0, y1=0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (i == 0) {
			x1 = x;
			y1 = y;
		}
		grid[x][y] = 1;
	}
	fcorn(x1, y1);
	cout << counter << endl;
}