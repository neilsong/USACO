#include <bits/stdc++.h>
using namespace std;

int main(void) {
	long long n, m;
	vector<long long> f,s;
	cin >> n >> m;
	f.resize(n); s.resize(n);
	long long presum = 0;
	int starting = -1;
	multiset<long long> spices;
	for (int i = 0; i < n; i++) {
		cin >> f[i] >> s[i];
		if (starting == -1) {
			presum += f[i]; spices.insert(s[i]);
		}
		if (presum >= m && starting == -1) {
			starting = i;
		}
	}
	long long minspice = *spices.rbegin();
	int backind = 0;
	for (int i = starting + 1; i < n; i++) {
		presum += f[i];
		spices.insert(s[i]);
		if (presum >= m) {
			minspice = min(minspice, *spices.rbegin());
		}
		while (presum - f[backind] >= m) {
			spices.erase(spices.find(s[backind]));
			minspice = min(minspice, *spices.rbegin());
			presum -= f[backind];
			backind++;
		}
	}
	cout << minspice;
}