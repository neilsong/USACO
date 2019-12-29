#include <bits/stdc++.h>
using namespace std;
vector<int> cows;

bool sortinrev(const int& a, const int& b) {
	if (a > b) return 1;
	else return 0;
}

int main(void) {
	ifstream cin("lemonade.in");
	ofstream cout("lemonade.out");

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cows.push_back(a);
	}
	sort(cows.begin(), cows.end(), sortinrev);
	bool output = 0;
	for (int i = 0; i < n; i++) {
		if (cows[i] < i) {
			cout << i;
			output = 1;
			break;
		}
	}
	if(!output)cout << n << endl;
	return 0;
}