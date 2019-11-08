#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> nums;
int n, k;

int main(void) {
	ifstream fin("snakes.in");
	ofstream fout("snakes.out");
	fin >> n >> k;
	dp.resize(n+1);
	nums.resize(n+1);
	for (int i = 0; i < n + 1; i++) {
		dp[i].resize(k+1);
	}
	int high = 0;
	int total = 0;
	for (int i = 1; i <= n; i++) {
		fin >> nums[i];
		high = max(high, nums[i]);
		dp[i][0] = i * high;
		for (int j = 1; j <= k; j++) {
			int mx = nums[i];
			dp[i][j] = INT_MAX;
			for (int b = i - 1; b >= 0; b--) {
				dp[i][j] = min(dp[i][j], dp[b][j - 1] + mx * (i - b));
				mx = max(mx, nums[b]);
			}
		}
		total += nums[i];
	}
	fout << dp[n][k] - total << endl;
}