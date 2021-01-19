#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin("lineup1.in");
	ofstream fout("lineup.out");
	set<int> unq;
	int n;
	fin >> n;
	map<int, int> mapped;
	vector <int> pos;
	for (int i = 0; i < n; i++) {
		int a, b;
		fin >> a >> b;
		unq.insert(b);
		mapped.insert(make_pair(a, b));
		pos.push_back(a);
	}
	sort(pos.begin(), pos.end());
	bool valid = 0;
	map<int, int> cids;
	cids.insert(make_pair(mapped[pos[0]], 1));
	int cbest = pos[n - 1] - pos[0];
	int L = 0;
	int R = 0;
	int length = 0;
	for (R = 1; R < n; R++) {
		if (valid) {
			while (valid) {
				length = pos[R] - pos[L];
				cids[mapped[pos[L]]]--;
				if (cids[mapped[pos[L]]] == 0) {
					cids.erase(mapped[pos[L]]);
					valid = 0;
					L++;
					break;
				}
				L++;
			}
			cbest = min(cbest, length);
		}
		else {
			cids[mapped[pos[R]]]++;
			if (cids.size() == unq.size()) { valid = 1; R--; }
		}
	}
	fout << cbest << endl;
}