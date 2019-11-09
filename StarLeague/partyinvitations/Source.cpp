#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, g;
	cin >> n >> g;
	vector <set<int>> groups(g);
	vector <vector <int>> rindx(n+1);
	for (int i = 0; i < g; i++) {
		int s;
		cin >> s;
		for (int j = 0; j < s; j++) {
			int cow;
			cin >> cow;
			groups[i].insert(cow);
			rindx[cow].push_back(i);
		}
	}
	set<int> q;
	q.insert(1);
	int counter = 1;
	while (!q.empty()) {
		int cow = *q.begin();
		q.erase(q.begin());
		for (auto i : rindx[cow]) {
			groups[i].erase(cow);
			if (groups[i].size() == 1) {
				int prevs = q.size();
				q.insert(*groups[i].begin());
				if (q.size() > prevs) {
					counter++;
				}
			}
		}
	}
	cout << counter << endl;
}