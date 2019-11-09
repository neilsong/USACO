#include <bits/stdc++.h>
using namespace std;
int n, c;
vector<vector<int>> sol;
int main(void) {
	cin >> n >> c;
	vector<int> s, v;
	s.resize(n + 1);
	v.resize(n + 1);
	sol.resize(2);
	sol[0].resize(c + 1);
	sol[1].resize(c + 1);
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
			if (j - s[i] >= 0) {
				sol[i%2][j] = max(sol[(i-1)%2][j], sol[(i - 1)%2][j - s[i]] + v[i]);
				continue;
			}
			sol[i%2][j] = sol[(i-1)%2][j];
		}
	}
	cout << sol[n%2][c] << endl;
}