#include <bits/stdc++.h>
using namespace std;
int m, n;
int ccount = 0;
vector < vector <int> >castle;
vector < vector <int> > walls;
void floodfill(int i, int j, int room) {
	if (castle[i][j] != 0) {
		return;
	}
	castle[i][j] = room;
	ccount++;
	int test = walls[i][j];
	if (j > 0 && 1 != (test&1)) {
		floodfill(i, j-1, room);
		test = walls[i][j];
	}
	if (j < m - 1 && 4 != (test & 4)) {
		floodfill(i, j+1, room);
		test = walls[i][j];
	}
	if (i > 0 && 2 != (test & 2)) {
		floodfill(i-1, j, room);
		test = walls[i][j];
	}
	if (i < n - 1 && 8 != (test & 8)) {
		floodfill(i+1, j, room);
		test = walls[i][j];
	}
	return;
}

int main(void) {
	
	cin >> m >> n;
	castle.resize(n);
	walls.resize(n);
	vector <int> rsize;
	for (int i = 0; i < n; i++) {
		castle[i].resize(m);
		walls[i].resize(m);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> walls[i][j];
		}
	}
	int mcount = 0;
	int croom = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (castle[i][j] == 0) {
				ccount = 0;
				floodfill(i, j, croom);
				croom++;
				rsize.push_back(ccount);
				mcount = max(ccount, mcount);
			}
		}
	}
	int mtot = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int test = walls[i][j];
			if (j > 0 && 1 == (test & 1)) {
				if (castle[i][j-1] != castle[i][j]) {
					mtot = max(mtot, rsize[castle[i][j-1] - 1] + rsize[castle[i][j] - 1]);
					test = walls[i][j];
				}
			}
			if (j < m - 1 && 4 == (test & 4)) {
				if (castle[i][j+1] != castle[i][j]) {
					mtot = max(mtot, rsize[castle[i][j+1] - 1] + rsize[castle[i][j] - 1]);
					test = walls[i][j];
				}
			}
			if (i > 0 && 2 == (test & 2)) {
				if (castle[i - 1][j] != castle[i][j]) {
					mtot = max(mtot, rsize[castle[i - 1][j] - 1] + rsize[castle[i][j] - 1]);
					test = walls[i][j];
				}
				
			}
			if (i < n - 1 && 8 == (test & 8)) {
				if (castle[i + 1][j] != castle[i][j]) {
					mtot = max(mtot, rsize[castle[i + 1][j] - 1] + rsize[castle[i][j] - 1]);
					test = walls[i][j];
				}
				
			}
		}
	}
	cout << rsize.size() << endl << mcount << endl << mtot << endl;
}