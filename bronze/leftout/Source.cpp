#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat;
vector<int> r, c, rr, rc;
int n;

int main(void) {
	ifstream fin("leftout.in");
	ofstream fout("leftout.out");
	fin >> n;
	r.resize(n+1);
	c.resize(n+1);
	r[n] = INT_MAX;
	c[n] = INT_MAX;
	mat.resize(n);
	int tot = 0;
	int minc = n - 1, minr = n - 1;;
	for (int i = 0; i < n; i++) {
		mat[i].resize(n);
		string dir;
		fin >> dir;
		int col = 0;
		for (auto j : dir) {
			if (j == 'R') {
				mat[i][col] = 0;
				r[i]--;
				c[col]--;
				tot++;
			}
			else {
				mat[i][col] = 1;
				r[i]++;
				c[col]++;
			}
			if (i == n - 1) {
				if (c[minc] > c[col]) minc = col;
				else if (c[minc] == c[col]) minc = max(minc, col);
			}
			col++;
		}
		if (r[minr] > r[i]) minr = i;
		else if (r[minr] == r[i]) minr = max(minr, i);
	}
	bool change = 1;
	while (tot > 2 && change) {
		bool rorc = 0;
		if (c[minc] < r[minr]) rorc = 1;
		else if (c[minc] == r[minr]) rorc = max(minr, minc) == minc;
		if (!rorc) {
			tot += r[minr];
			r[minr] = 0 - r[minr];
			int prevminr = minr;
			minc = n;
			for (int i = 0; i < n; i++) {
				if (r[minr] > r[i]) minr = i;
				else if (r[minr] == r[i]) minr = max(minr, i);
				if (!mat[prevminr][i]) {
					mat[prevminr][i] = 1;
					c[i] += 2;
				}
				else {
					mat[prevminr][i] = 0;
					c[i] -= 2;
				}
				if (c[minc] > c[i]) minc = i;
				else if (c[minc] == c[i]) minc = max(minc, i);
			}
		}
		else {
			tot += c[minc];
			c[minc] = 0 - c[minc];
			minr = n;
			int prevminc = minc;
			for (int i = 0; i < n; i++) {
				if (c[minc] > c[i]) minc = i;
				else if (c[minc] == c[i]) minc = max(minc, i);
				if (!mat[i][prevminc]) {
					mat[i][prevminc] = 1;
					r[i] += 2;
				}
				else {
					mat[i][prevminc] = 0;
					r[i] -= 2;
				}
				if (r[minr] > r[i]) minr = i;
				else if (r[minr] == r[i]) minr = max(minr, i);
			}
		}
		change |= (minc >= 0 && minr >= 0);
	}
	if (tot == 1) {
		bool rorc = min(r[minr], c[minc]) == r[minr];
		if (rorc) {
			fout << minr + 1 << " ";
			for (int i = 0; i < n; i++) {
				if (mat[minr][i] == 0) {
					fout << i + 1 << endl;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (mat[i][minc] == 0) {
					fout << i + 1 << " ";
				}
			}
			fout << minc + 1 << endl;
		}
	}
	else if (tot <= 2 || !change) {
		fout << "-1" << endl;
	}

}