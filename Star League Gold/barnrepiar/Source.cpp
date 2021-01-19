#include <bits/stdc++.h>
using namespace std;
int m, s, c;
vector<int> occupied;
set<int> diffs;
int main(void) {
	cin >> m >> s >> c;
	occupied.resize(c);
	int Max = 0, Min = INT_MAX;
	for (int i = 0; i < c; i++) {
		cin >> occupied[i];
		Max = max(Max, occupied[i]);
		Min = min(Min, occupied[i]);
		if(i!=0)diffs.insert(occupied[i] - occupied[i - 1]);
	}
	int ans = Max - Min + 1;
	int ind = 0;
	for (auto i= diffs.rbegin(); i != diffs.rend(); i++) {
		if (ind < m - 1) ans -= *i - 1;
		else break;
		ind++;
	}
	cout << ans << endl;
}