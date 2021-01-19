#include <bits/stdc++.h>
using namespace std;
int M, N;
vector<vector<int>> mat, sol;


int recurse(int n, int m) {
	if (n == 0 || m == 0) sol[n][m] = mat[n][m];
	else if (n == 1 && m == 1) sol[n][m] = mat[n][m];
	if (sol[n][m] == 0) {
		int Min = min(recurse(n - 1, m), recurse(n, m - 1));
		sol[n][m] = mat[n][m] + min(Min, recurse(n - 1, m - 1));
	}
	return sol[n][m];
}

int main(void) {
	cin >> N >> M;
	mat.resize(N+1);
	sol.resize(N+1);
	mat[0].resize(M + 1);
	sol[0].resize(M + 1);
	fill(mat[0].begin(), mat[0].end(), INT_MAX);
	for (int i = 1; i <= N; i++) {
		mat[i].resize(M+1);
		mat[i][0] = INT_MAX;
		sol[i].resize(M+1);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i+1][j+1];
		}
	}
	cout << recurse(N, M) << endl;
}