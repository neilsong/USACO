#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector <tuple<int, int, bool>> events(2 * n);
	for (int i = 0; i < n; i++) {
		int a, b,c;
		cin >> a >> b >> c;
		events[2 * i] = make_tuple(a, c, 0);
		events[2 * i + 1] = make_tuple(b, c, 1);
	}
	sort(events.begin(), events.end());
	priority_queue <int> heights;
	int ans = 0;
	int prevpos = get<0>(events[0]);
	for (int i = 0; i < 2 * n;i++) {
		bool push = 1;
		if (heights.empty()) {
			heights.push(get<1>(events[i]));
			push = 0;
		}
		ans += heights.top() * (get<0>(events[i]) - prevpos);
		if (get<2>(events[i]) == 0 && push) heights.push(get<1>(events[i]));
		else if(push) heights.pop();
		prevpos = get<0>(events[i]);
	}
	cout << ans << endl;
}