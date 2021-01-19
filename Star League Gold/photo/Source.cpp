#include <bits/stdc++.h>
using namespace std;

int main(void) {
	map<int, int> pairs;
	
	int n, k;
	cin >> n >> k;
	vector <int> ucows(2 * k);
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		pairs.insert(make_pair(a, b));
		pairs.insert(make_pair(b, a));
		ucows[2 * i] = a;
		ucows[2 * i + 1] = b;
	}
	sort(ucows.begin(), ucows.end());
	int count = 1;
	int start = 1, end = 1;
	for (auto i : ucows) {
		if (pairs[i] >= start && pairs[i] <= end) {
			start = i;
			end = i;
			count++;
		}
		else {
			end = i;
		}
	}
	cout << count << endl;
}