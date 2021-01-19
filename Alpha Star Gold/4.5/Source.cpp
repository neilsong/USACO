#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
int n, t, k;

int mincr;
int main(void) {
	cin >> n >> t >> k;
	vector<int> v(n), h(n), ch, cv;
	vector<int> dp(floor((5 * t / 4)));
	for (int i = 0; i < n; i++) {
		cin >> v[i] >> h[i];
		if (h[i] >= k) {
			cv.push_back(v[i]);
			ch.push_back(h[i]);
		}
	}
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 0; j < v.size() ; j++) {
			if (h[j] <= i) dp[i] = max(dp[i], dp[i - h[j]] + v[j]);
		}
	}
	int ans = dp[t];
	int ind = 0;
	for (auto i : ch) {
		int compare = dp[dp.size() - floor((5*i/4))] + cv[ind];
		ind++;
		ans = max(ans, compare);
	}
	cout << ans << endl;
}