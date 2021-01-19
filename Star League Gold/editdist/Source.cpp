#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
string a, b;
int main(void) {
	cin >> a >> b;
	dp.resize(a.size() + 1);
	for (int i = 0; i <= a.size(); i++) {
		dp[i].resize(b.size() + 1);
		dp[i][0] = i;
	}
	iota(dp[0].begin(), dp[0].end(), 0);
	int ans = 0;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				int temp  = min(dp[i - 1][j]+1, dp[i][j - 1]+1);
				temp = min(temp, dp[i - 1][j - 1] + 1);
				dp[i][j] = temp;
			}
		}
	}
	cout << dp[a.size()][b.size()] << endl;
}