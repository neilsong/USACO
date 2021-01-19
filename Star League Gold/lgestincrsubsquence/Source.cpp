#include <bits/stdc++.h>
using namespace std;

vector<int> arr, dp, parent;
int main(void) {
	int n;
	cin >> n;
	arr.resize(n);
	dp.resize(n);
	parent.resize(n);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int ans = 0;
	int ind = 0;
	for (int i = 0; i < n; i++) {
		int back = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				/*if (dp[j] > back) {
					parent[i] = j;
				}*/
				back = max(back, dp[j]);
			}
		}
		dp[i] = back + 1;
		/*if (dp[i] > ans) {
			ind = i;
		}*/
		ans = max(ans, dp[i]);
	}
	//parent trace
	//while (ind != 0) {
	//	cout << arr[ind] << " ";
	//	ind = parent[ind];
	//}
	cout << ans << endl;
}