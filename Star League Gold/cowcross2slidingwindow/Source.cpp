#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, k, b;
	cin >> n >> k >> b;
	vector <bool> lights(n);
	for (int i = 0; i < b; i++) {
		int broken;
		cin >> broken;
		lights[broken-1] = 1;
	}
	int mcount = INT_MAX;
	int ccount = 0;
	for (int i = 0; i < k; i++) {
		if (lights[i]) {
			ccount++;
		}
	}
	for (int i = 1; i <= n - k; i++) {
		if (lights[i - 1]) {
			ccount--;
		}
		if (lights[i + k-1]) {
			ccount++;
		}
		mcount = min(ccount, mcount);
	}
	cout << mcount << endl;
	return 0;
}