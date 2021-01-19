#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

vector<ll> c, dp;

struct interval {
	ll first, second, c;
};

vector<interval> intervals;

bool sortbyfirst(const interval a, const interval b) {
	return a.first < b.first;
}

int main() {
	ll n, m, e;
	cin >> n >> m >> e;
	dp.resize(n);
	for (ll i = 0; i < n; i++) {
		ll s, e, cost;
		cin >> s >> e >> cost;
		intervals.push_back({ s,e,cost });
	}
	sort(intervals.begin(), intervals.end(), sortbyfirst);
	for (ll i = 0; i < n; i++) {
		if (intervals[i].first == m) {
			dp[i] = intervals[i].c;
		}
	}
	for (ll i = 0; i < n; i++) {
		if(intervals[i].first > m) dp[i] = 1e13;
		for (ll j = 0; j < i; j++) {
			if(intervals[i].first <= intervals[j].second + 1 && intervals[j].second <= intervals[i].second)
			dp[i] = min(dp[i], intervals[i].c + dp[j]);
		}
	}
	ll ans = 1e13;
	for (ll i = 0; i < n; i++) {
		if (intervals[i].second == e) ans = min(ans, dp[i]);
	}
	if (ans == 1e13) cout << -1 << endl;
	else cout << ans << endl;
}