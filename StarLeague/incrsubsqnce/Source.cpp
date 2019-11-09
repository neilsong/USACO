#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
map<int, int> dp;
int main(void) {
	int n;
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp.insert(make_pair(arr[0], 1));
	for (int i = 1; i < n; i++) {
		auto end = dp.end();
		if (arr[i] > prev(end)->first) {
			dp[arr[i]] = dp.size();
		}
		else if (arr[i] < dp.begin()->second) {
			dp.erase(dp.begin());
			dp[arr[i]] = 0;
		}
		else {
			map<int,int>::iterator val = dp.lower_bound(arr[i]);
			int asdf = val->second;
			dp.erase(val);
			dp[arr[i]] = asdf;
		}
	}
	cout << dp.size() << endl;
}