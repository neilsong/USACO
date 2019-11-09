#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat, sol;
int n;

int recurse(int i, int j) {
	if (i == n - 1) {
		sol[i][j] = mat[i][j];
	}
	if (sol[i][j] == 0) {
		sol[i][j] = mat[i][j] + max(recurse(i + 1, j), recurse(i + 1, j + 1));
	}
	return sol[i][j];
}

int main(void) {
	
	cin >> n;
	mat.resize(n);
	sol.resize(n);
	for(int i =0;i < n;i++) {
		mat[i].resize(n);
		sol[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int a;
			cin >> a;
			mat[i][j] = a;
		}
	}
	cout << recurse(0,0) << endl;
}