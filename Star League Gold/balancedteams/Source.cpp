#include <bits/stdc++.h>
using namespace std;

vector <int> arr(12);
int order[] = { 0,0,0,1,1,1,2,2,2,3,3,3 };
int ans = INT_MAX;
int score[4];

int main() {
	for (int x = 0; x < 12; x++) {
		cin >> arr[x];
	}
	sort(arr.begin(), arr.end());

	do {
		for (int x = 0; x < 4; x++) score[x] = 0;
		for (int x = 0; x < 12; x++) score[order[x]] += arr[x];
		int min = INT_MAX;
		int max = 0;
		for (int x = 0; x < 4; x++) {
			if (score[x] < min) min = score[x];
			if (score[x] > max) max = score[x];
		}
		if (max - min < ans) ans = max - min;


	} while (next_permutation(order, order + 12));
	cout << ans << endl;

	return 0;
}