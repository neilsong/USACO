#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> sol;
vector<int> coins;
int main(void) {
	cin >> k >> n;
	sol.resize(n + 1);
	sol[0].resize(1000001);
	coins.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
		sol[i].resize(1000001);
	}
	fill(sol[0].begin(), sol[0].end(), INT_MAX/2);
	sol[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 1000000; j++) {
			if (j - coins[i] >= 0) {
				sol[i][j] = min(sol[i - 1][j], sol[i][j - coins[i]] + 1);
				continue;
			}
			sol[i][j] = sol[i - 1][j];
		}
	}
	for (int i = 1; i <= 1000000; i++) {
		if (sol[n][i] > k) {
			cout << i-1 << endl;
			return 0;
		}
	}
		
}