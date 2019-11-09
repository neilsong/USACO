#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> bridges;
vector<int> dp;
int n;

int main(void) {
	cin >> n;
	bridges.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		bridges[i] = { b,a };
	}
	int ans = 0;
	dp[0] = 1;
	sort(bridges.begin(), bridges.end());
	for (int i = 0; i < n; i++) {
		int back = 0;
		for (int j = 0; j < i; j++) {
			if (bridges[j].second < bridges[i].second) {
				back = max(back, dp[j]);
			}
		}
		dp[i] = back + 1;
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}