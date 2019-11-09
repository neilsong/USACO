#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> arr;
vector<int> dp;
int n;

bool sortbyarea(pair<int,int> a, pair<int,int> b) {
	return get<0>(a) > get<0>(b);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
		
	}
	sort(arr.begin(), arr.end(), sortbyarea);
	for (auto i : arr) {
		dp.push_back(1);
	}
	int ans = 0;
	for (int i = 1; i < arr.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (get<0>(arr[j]) > get<0>(arr[i]) && get<1>(arr[j]) > get<1>(arr[i]) && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}