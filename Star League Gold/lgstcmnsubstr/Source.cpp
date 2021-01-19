#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
string a, b;
int main(void) {
	cin >> a >> b;
	dp.resize(a.size()+1);
	for (int i = 0; i <= a.size(); i++) {
		dp[i].resize(b.size()+1);
		dp[i][0] = 0;
	}
	fill(dp[0].begin(), dp[0].end(), 0);
	int ans = 0;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}