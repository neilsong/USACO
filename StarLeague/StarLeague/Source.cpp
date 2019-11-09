#include <bits/stdc++.h>
using namespace std;

bool sortinrev(const int a, const int b) {
	return a > b;
}

set<int> copy(set<int>yeet, int add) {
	yeet.insert(add);
	return yeet;
}

int main(void) {
	int n, h;
	cin >> n >>  h;
	vector<int> cows;
	for (int i = 0; i < n; i++) {
		int cow;
		cin >> cow;
		cows.push_back(cow);
	}

	vector < map <set <int>, int>> gens(cows.size());
	for (int i = 0; i < n;i++) {
		set<int> start;
		start.insert(i);
		gens[0].insert(make_pair(start, cows[i]));
	}
	int j = 1;
	while (j != cows.size()) {
		for (int i = 0; i < n;i++) {
			 for(auto g : gens[j-1]){
				 int prevs = g.first.size();
				set<int> test = copy(g.first, i);
				if (prevs == test.size()) {
					continue;
				}
				gens[j].insert(make_pair(test, g.second + cows[i]));
			 }
		}
		j++;
	}
	int mdiff = INT_MAX;
	for (auto i : gens) {
		for(auto j : i)
			if (j.second > h) {
				mdiff = min(mdiff, abs(h - j.second));
			}
		
	}
	cout << mdiff;
	return 0;
}