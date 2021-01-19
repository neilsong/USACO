#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<int> nums;
int n;

int main(void) {
	cin >> n;
	nums.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		dp[i].resize(n);
		cin >> nums[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i][i] = nums[i];
	}
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < n; i++) {
			int g = i + j;
			if (j == 1 && i + j < n) {
				dp[i][g] = max(dp[i][g - 1], dp[i + 1][g]);
			}
			else if (i + j < n) {
				dp[i][g] = max(min(dp[i + 2][g], dp[i + 1][g - 1]) + nums[i], min(dp[i][g - 2], dp[i + 1][g - 1])+nums[j] );
			}
		}
	}
	cout << dp[0][n - 1] << endl;
}