#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int cur = 0;
vector<vector<int>> mat, sol;

int recurse(int x, int y) {
	if (mat[x][y] == cur) {
		return 0;
	}
	if (x == r - 1) {
		if (y == c - 1) {
			sol[x][y] = 1;
			return 1;
		}
	}
	if (sol[x][y] == 0) {
		for (int i = x + 1; i < r; i++) {
			for (int j = y + 1; j < c; j++) {
				cur = mat[x][y];
				sol[x][y] += recurse(i, j);
				sol[x][y] %= 1000000007;
			}
		}
	}
	return sol[x][y];
}

int main(void) {
	cin >> r >> c >> k;
	mat.resize(r);
	sol.resize(r);
	for (int i = 0; i < r; i++) {
		mat[i].resize(c);
		sol[i].resize(c);
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
		}
	}
	long long ans = 0;
	for (int x = 1; x < r; x++) {
		for (int y = 1; y < c; y++) {
			cur = mat[0][0];
			ans += recurse(x,y);
			ans %= 1000000007;
		}
	}
	cout << ans % 1000000007 << endl;
}