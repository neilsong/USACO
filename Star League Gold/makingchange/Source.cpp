#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int> vec;
	vector<vector<int>> sol;
	int n, x;
	cin >> x >> n;
	vec.resize(n+1);
	sol.resize(n + 1);
	sol[0].resize(x + 1);
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
		sol[i].resize(x + 1);
		sol[i][0] = 0;
	}
	sort(vec.begin(), vec.end());
	fill(sol[0].begin(), sol[0].end(), INT_MAX);
	sol[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			if (j - vec[i] < 0) {
				sol[i][j] = sol[i-1][j];
				continue;
			}
			sol[i][j] = min(sol[i-1][j], sol[i][j - vec[i]] + 1);
		}
	}
	cout << sol[n][x];

}