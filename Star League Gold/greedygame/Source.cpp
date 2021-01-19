#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> waffle;
vector<int> rsum, csum, rcut, ccut;
int r, c, hc, vc;

int main(void) {
	cin >> r >> c >> hc >> vc;
	waffle.resize(r);
	for (int i = 0; i < r; i++) {
		waffle[i].resize(c);
	}
	rsum.resize(r);
	csum.resize(c);
	int cc = 0;
	for (int i = 0; i < r; i++) {
		string raw = "";
		cin >> raw;
		for (int j = 0; j < c; j++) {
			raw[j] == '@' ? waffle[i][j] = 1 : waffle[i][j] = 0;
			if (waffle[i][j])cc++;
			csum[j] += waffle[i][j];
			rsum[i] += waffle[i][j];
		}
	}
	int vh = cc / (hc + 1), vv = cc / (vc + 1);
	int ch = 0;
	ccut.push_back(0);
	rcut.push_back(0);
	for (int i = 0; i < r; i++) {
		if (ch > vh) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		else if (ch == vh) {
			ch = 0;
			rcut.push_back(i);
		}
		ch += rsum[i];
	}
	int cv = 0;
	for (int i = 0; i < c; i++) {
		if (cv > vv) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		else if (cv == vv) {
			cv = 0;
			ccut.push_back(i);
		}
		cv += csum[i];
	}
	int eqshare = cc / (hc + 1);
	eqshare /= (vc + 1);
	for (int i = 0; i < rcut.size() - 1; i++) {
		for (int j = 0; j < ccut.size() - 1; j++) {
			int test = 0;
			for (int x = rcut[i]; x < rcut[i + 1]; x++) {
				for (int y = ccut[j]; y < ccut[j + 1]; y++) {
					test += waffle[x][y];
				}
			}
			if (test != eqshare) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
		}
	}
	cout << "POSSIBLE" << endl;
	return 0;
}