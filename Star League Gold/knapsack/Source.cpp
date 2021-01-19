#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<vector<int>> sol;
int main(void) {
	cin >> n >> c;
	vector<int> s, v;
	s.resize(n + 1);
	v.resize(n + 1);
	sol.resize(n + 1);
	sol[0].resize(c + 1);
	for (int i = 1; i <= n; i++) {
		sol[i].resize(c + 1);
		cin >> s[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
			if (j - s[i] >= 0) {
				sol[i][j] = max(sol[i - 1][j], sol[i - 1][j - s[i]] + v[i]);
				continue;
			}
			sol[i][j] = sol[i - 1][j];
		}
	}
	cout << sol[n][c] << endl;
}