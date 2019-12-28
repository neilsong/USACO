#include <bits/stdc++.h>
using namespace std;

vector<int> A, prefix;
vector<vector<int>> dp;

int main(void) {
	int n;
	cin >> n;
	dp.assign(n + 1, vector<int>(n + 1, 0));
	A.resize(n); prefix.resize(n+1);
	for (int i = n-1; i >=0; i--) {
		cin >> A[i];
	}
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + A[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i][j]);
			if (i >= 2 * j) dp[i][j] = max(prefix[i] - dp[i - 2 * j][2 * j], dp[i][j]);
			if (i >= 2 * j - 1) dp[i][j] = max(prefix[i] - dp[i - (2 * j - 1)][2 * j - 1], dp[i][j]);
		}
	}
	cout << dp[n][1];
}