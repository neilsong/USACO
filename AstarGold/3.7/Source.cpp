#include <bits/stdc++.h>
using namespace std;


//dp(l,r) = max value of range [l,r] inclusive
// l -> leftmost index, r-> rightmost index
//dp[i][j] = max (v[l] + ( n - r + l ) + dp[l+1][r],
				//v[r] + (n - r + l) + dp[l][r+1])

//tableation
//for(len: 2 -> n)
//	for(i: 0 -> i + len - 1 < n
//		j = i+len-1

int main(void) {
	int n;
	cin >> n;
	vector<int> treats(n);
	for (int i = 0; i < n; i++) {
		cin >> treats[i];
	}
	vector<vector<int>> dp;
	dp.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		dp[i][i] = treats[i] * n;
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i + len - 1 < n; i++) {
			int j = i + len - 1;
			dp[i][j] = max(treats[i] * (n - j + i) + dp[i + 1][j], dp[i][j]);
			dp[i][j] = max(treats[j] * (n - j + i) + dp[i][j - 1], dp[i][j]);
		}
	}
	cout << dp[0][n-1];
}	