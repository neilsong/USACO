#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ls, rs, mountains;
int main(void) {
	cin >> n;
	ls.resize(n);
	rs.resize(n);
	mountains.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> mountains[i];
	}
	for (int i = 1; i < n; i++) {
		if (mountains[i] >= mountains[i - 1]) ls[i] = ls[i - 1] + 1;
		else ls[i] = 0;
	}
	for (int i = n - 2; i > -1; i--) {
		if (mountains[i] >= mountains[i + 1]) rs[i] = rs[i + 1] + 1;
		else rs[i] = 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, ls[i] + rs[i]);
	}
	cout << ans + 1<< endl;
}