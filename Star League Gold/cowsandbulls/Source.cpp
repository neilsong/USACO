#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(2);
int n, k;
int main(void) {
	cin >> n >> k;
	for (int i = 0; i < 2; i++)
	{
		dp[i].resize(n+1);
		fill(dp[i].begin(), dp[i].end(), 1);
	}
	dp[1][1] = 1;
	dp[0][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (!j) {
				if (i - 1 - k > 0) {
					dp[j][i] = (dp[j][i - 1 - k] + dp[j + 1][i - 1 - k]) % 5000011;
				}
			}
			else {
				dp[j][i] = (dp[j - 1][i - 1] + dp[j][i - 1]) % 5000011;
			}
		}
	}
	cout << (dp[0][n] + dp[1][n]) % 5000011 << endl;
}