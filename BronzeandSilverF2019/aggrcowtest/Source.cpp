#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
bool check(int diff, vector<int> stalls, int c, int n) {
	int j = 1;
	int curr = stalls[0];
	int check = 1;
	int a = stalls[j];
	for (int i = 0; i < c - 1; i++) {
		while (a < curr + diff) {

			j++;
			a = stalls[j];
			if (diff > stalls[n - 1] - curr) {
				check = 0;
				break;
			}
		}
		if (check == 0) {
			break;
		}
		curr = a;
	}
	if (check == 0) { return false; }
	return true;
}
int main() {
	int t;
	cin >> t;
	while (t > 0) {
		int n, c;
		cin >> n >> c;
		vector<int> stalls;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			stalls.push_back(x);
		}
		sort(stalls.begin(), stalls.end());
		for (int i = 0; i < n; i++) {
		}
		int diff = abs(stalls[0] - stalls[n - 1]);
		int lol = 1;
		int count = 0;
		int first = 0;
		int last = diff;
		int middle = (first + last) / 2;
		while (first <= last)
		{
			if (check(middle, stalls, c, n) && first == last)
			{
				break;

			}
			if (check(middle, stalls, c, n) == false && first == last)
			{
				middle--;
				break;

			}
			if (check(middle, stalls, c, n))
			{
				first = middle;

			}
			else {
				last = middle;
			}
			middle = (first + last) / 2;
		}
		cout << middle;
		t--;
	}
	return 0;
}