#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr(n);
	float mean = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mean += (float) arr[i];
	}
	mean /= (float)n;
	int ans = 0;
	for (auto i : arr) {
		if ((float)i > mean) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}