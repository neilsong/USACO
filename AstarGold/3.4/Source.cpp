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

int main(void) {
	int n, m, e;
	cin >> n >> m >> e;
	
}