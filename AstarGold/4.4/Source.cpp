#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
vector<int> a;
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		a.push_back(s);
	}
	vector<vector<int>> dp;
	dp.assign(n + 1, vector<int>(m + 1, INF));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k * k <= j; k++) {
				if (dp[i - 1][j - (k * k)] < INF)
					dp[i][j] = min(dp[i][j], (a[i - 1] - k) * (a[i - 1] - k) + dp[i - 1][j - (k * k)]);
			}
		}
	}
	if (dp[n][m] == INF) { cout << -1 << endl; return 0;}
	 cout << dp[n][m] << endl;
}
