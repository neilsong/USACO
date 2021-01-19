#include <bits/stdc++.h>
using namespace std;

pair<int, int> option(int i) {
	int largest = 0, smallest = INT_MAX;
	while (i) {
		int r = i % 10;
		largest = max(largest, r);
		if(r != 0) smallest = min(smallest, r);
		i /= 10;
	}
	return { smallest, largest };
}

int main(void) {
	vector<int> dp;
	int g;
	cin >> g;
	dp.resize(1000001);
	dp[0] = 0;
	for (int i = 1; i <= 1000000; i++) {
		pair<int, int> op = option(i);
		dp[i] = !(dp[i - op.first] && dp[ i -op.second]);
	}
	for (int i = 0; i < g; i++) {
		int q; cin >> q;
		if (dp[q]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}