#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	map<int, int> actions;
	int prevstart = 0;
	int start = 0;
	set <int> pos;
	for (int i = 0; i < n; i++) {
		int a;
		char b;
		cin >> a >> b;
		if (b == 'R') {
			start += a;
			if (i == 0) {
				actions.insert(make_pair(prevstart, 0));
			}
			actions[prevstart]++;
			actions[start]--;
		}
		else {
			start -= a;
			if (i == 0) {
				actions.insert(make_pair(prevstart, 0));
			}
			actions[prevstart]--;
			actions[start]++;
		}
		pos.insert(start);
		pos.insert(prevstart);
		prevstart = start;
	}
	int count = 0;
	int ans = 0;
	int previ = *pos.begin();
	for (auto i : pos) {
		if (count >= k) ans += i - previ;
		count += actions[i];
		previ = i;
	}
	cout << ans << endl;
}