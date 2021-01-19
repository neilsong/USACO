#include <bits/stdc++.h>
using namespace std;

int n, c, t;

vector <int> sarr;
vector<int> stalls;

bool check(int lo, int hi) {
	int mid = (lo + hi) / 2;
	int mindist = sarr[mid];
	int ind = 0;
	bool treturn = 1;
	for (int i = 1; i < c; i++) {
		bool temp = 0;
		for (int j = ind + 1; j < stalls.size(); j++) {
			if (stalls[j] >= stalls[ind] + mindist) {
				temp = 1;
				ind = j;
				break;
			}
		}
		treturn &= temp;
		if (!treturn) return 0;
	}
	return treturn;
}

int bin_search(int lo, int hi) {
	while (hi > lo) {
		int mid = (lo + hi) / 2;
		if (check(lo, hi)) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	return (lo + hi) / 2;
}


int main(void) {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> c;
		int minstall = INT_MAX, maxstall = 0;
		for (int j = 0; j < n; j++) {
			int stall;
			cin >> stall;
			stalls.push_back(stall);
			minstall = min(minstall, stall);
			maxstall = max(maxstall, stall);
		}
		sarr.resize(maxstall - minstall);
		iota(sarr.begin(), sarr.end(), 1);
		sort(stalls.begin(), stalls.end());
		cout << bin_search(0, sarr.size() - 1) << endl;
		sarr.clear();
		stalls.clear();
		n = 0; c = 0;
	}
}