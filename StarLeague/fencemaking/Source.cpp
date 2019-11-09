#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int lim, n;
int main(void) {
	cin >> n;
	lim = (n - 1) / 2;
	dp.resize(n+1);
	dp[0].resize(5);
	for (int i = 1; i <= n; i++) {
		dp[i].resize(5);
		if (i <= lim) {
			dp[i][1] = 1;
		}
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[j][i]) {
				continue;
			}
			if (j < i) {
				continue;
			}
			else {
				for (int k = 1; k <= lim; k++) {
					if (j - k < 0) {
						break;
					}
					dp[j][i] += dp[j - k][i - 1];
				}
			}
		}
	}
	cout << dp[n][4] << endl;

}