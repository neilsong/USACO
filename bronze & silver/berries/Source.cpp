#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;
bool good(int mid) {
	auto iter = lower_bound(arr.begin(), arr.end(), mid);
	int make = 0;
	for (iter; iter != arr.end(); iter++) {
		make += *iter / mid;
	}
	return make >= k;
}

void substract(int mid) {
	int left = 1;
	auto iter = lower_bound(arr.begin(), arr.end(), mid);
	for (iter; iter != arr.end(); iter++) {
		if (arr[(iter - arr.begin())] % mid == 0) {
			arr[(iter - arr.begin())] -= mid;
		}
	}
	arr[n - 1] -= mid;
	sort(arr.begin(), arr.end());
}

int main() {
	ifstream cin("berries.in");
	ofstream cout("berries.out");
	cin >> n >> k;
	arr.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int ans = 0, mberry = arr[n - 1], prevl = 0;
	for (int i = 0; i < k / 2; i++) {
		int l = prevl, r = mberry;
		int mid = (l + r + 1) / 2;
		while (l < r) {
			mid = (l + r + 1) / 2;
			if (good(mid)) {
				l = mid;
			}
			else {
				r = mid - 1;
			}
		}
		mid = (l + r + 1) / 2;
		substract(mid);
		ans += mid;
		prevl = mid;
	}
	cout << ans << endl;
	return 0;
}