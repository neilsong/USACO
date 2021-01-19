#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
vector<vector<int>> dists;
vector<pair<int,int>> chpts;
int n, k;
int main(void) {
	cin >> n >> k;
	dp.resize(n + 1);
	dists.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i].resize(k+1);
		dists[i].resize(n + 1);
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		chpts.push_back(make_pair(x, y));
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			dists[i][j] = abs(chpts[i - 1].first - chpts[j - 1].first) + abs(chpts[i - 1].second - chpts[j - 1].second);
		}
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = k; j > max(k - i,-1); j--) {
			int ans = INT_MAX;
			int indj = j, indi = i + 1;
			while (indj >= 0 && indi <= n) {
				ans = min(ans, dp[indi][indj] + dists[i][indi]);
				indi++;
				indj--;
			}
			dp[i][j] = ans;
		}
	}
	cout << dp[1][k] << endl;
}