#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> intervals;

#define all(x) x.begin(), x.end()
#define fi first
#define sec second

bool sortbysecond(const pair<int, int> a, const pair<int, int> b) {
	return a.sec < b.sec;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, d;
		cin >> s >> d;
		intervals.push_back({ s,s + d });
	}
	sort(all(intervals), sortbysecond);
	pair<int, int> last = { 0,0 };
	int ans = 0;
	for (auto i : intervals) {
		if (last == make_pair(0, 0)) {
			last = i; ans++; continue;
		}
		if (last.sec <= i.fi) {
			ans++; last = i;
		}
	}
	cout << ans << endl;
}