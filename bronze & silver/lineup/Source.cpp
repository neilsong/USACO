#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
	ifstream cin("lineup.in");
	ofstream cout("lineup.out");
	cin >> n;

	vector<pair<string, string>> order;
	vector<string> cows{ "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
	sort(cows.begin(), cows.end());
	for (int i = 0; i < n; i++) {
		pair<string, string> toins;
		for (int j = 0; j < 6; j++) {
			string cow;
			cin >> cow;
			if (j == 0 ) {
				toins.first = cow;
			}
			if (j == 5) {
				toins.second = cow;
			}
		}
		order.push_back(toins);
	}
	do {
		bool bigpass = 1;
		for (auto i : order) {
			bool pass = 0;
			for (int j = 0; j < 7; j++) {
				if (cows[j] == i.first) {
					if (cows[j + 1] == i.second) { pass = 1; break; }
				}
				else if (cows[j] == i.second) {
					if (cows[j + 1] == i.first) { pass = 1; break; }
				}
			}
			if (!pass) { bigpass = 0; break; }
		}
		if (bigpass) {
			for(auto i : cows){
				cout << i << endl;
			}
			break;
		}
	} while (next_permutation(cows.begin(), cows.end()));
}