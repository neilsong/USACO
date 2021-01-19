#include <bits/stdc++.h>
using namespace std;
string str;
int main(void) {
	getline(cin, str);
	int n = str.length();
	vector<int> pfx;
	int pf = 0;
	for (auto i : str) {
		i == '(' ? pf++ : pf--;
		if (pf < 0) {cout << 0; return 0;}
		pfx.push_back(pf);
	}
	if (pf != 0) { cout << 0; return 0; }
	vector<vector<int>> dp;
	dp.assign(n + 1, vector<int>(n + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (str[i-1] == '(') {
				if(j>0) dp[i][j] = dp[i - 1][j - 1];
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= 2012;
			}
			if (str[i-1] == ')') {
				if (j < n) dp[i][j] = dp[i - 1][j + 1];
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= 2012;
			}
			if (pfx[i - 1] - j < 0) dp[i][j] = 0;
		}
		
	}
	cout << dp[n][0] % 2012;
}