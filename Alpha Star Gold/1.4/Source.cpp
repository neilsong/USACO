#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> c, r;
int main(void) {
	cin >> n >> m;
	c.resize(n); r.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> r[i]; r[i] -= c[i];
	}
	vector<int> dp(m + 1); int mxprof = 0;
	for (int i = 0; i < n; i++)
		for (int j = c[i]; j <= m; j++)
			dp[j] = max(dp[j], dp[j - c[i]] + r[i]);
	for (int i = 0; i < dp.size(); i++) {
		mxprof = max(mxprof, dp[i] + m - i);
	}
	cout << mxprof << endl;

}