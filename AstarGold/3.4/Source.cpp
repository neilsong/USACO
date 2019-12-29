#include <bits/stdc++.h>
using namespace std;


// n^2 solution


//dp[i] = min cost to cover M -> r[i] including interval i


// transitions
// l[j] < l[i]        starts before i
	// sort by start time
// l[i] <= r[j] <= r[i]            ends in middle of i
//	for all j < i  w/ this condition
//		dp[i] = min(dp[i], c[i] + dp[j])


//nlogn solution
// fast way of taking care of second condition
// (r,dp)
//   1       |     5               10   |
//   x       |     x                x   |
//dp = 10    |  dp = 20          dp = 15|
//			l[j]                      r[j]

//Dynamic RMQ (Range minimum query)
// 2BIT OR
// Segment Tree O(logn)

//Gold workaround
//events (i, s/e)
//sweepline
//Multiset of dp values
//interval of i starts
//start: compute dp[i] value and insert in multiset
//end: erase from multiset

//base case 

vector<pair<int, int>> intervals;
vector<int> c, dp;


int main(void) {
	int n, m, e;
	cin >> n >> m >> e;
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		intervals.push_back({ s,e });
		c.push_back(cost);
	}
	sort(intervals.begin(), intervals.end());
	int startind = 0;
	for (int i = 0; i < n; i++) {
		if (intervals[i].first == m) dp[i] = c[i];
		else startind = 1;
	}
	int mx = -1;
	for (int i = startind+1; i < n; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < i && intervals[i].first <= intervals[j].second && intervals[j].second+1 <= intervals[i].second; j++) {
			dp[i] = min(dp[i], c[i] + dp[j]);
		}
		if(dp[i] != INT_MAX) mx = max(mx, dp[i]);
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (intervals[i].second == e) ans = min(ans, dp[i]);
	}
	cout << ans << endl;
}