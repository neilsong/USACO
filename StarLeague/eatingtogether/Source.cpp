#include <bits/stdc++.h>
using namespace std;

vector<int> line, diffs;
bool dirr;
int neg = 0, pos = 0, n;

int main(void) {
	cin >> n;
	line.resize(n);
	diffs.resize(n - 1);
	for (int i = 0; i < n; i++) {
		cin >> line[i];
		if (i != 0) {
			diffs[i - 1] = line[i] - line[i - 1];
			if (diffs[i - 1] > 0) {
				pos++;
			}
			else if (diffs[i - 1] < 0) {
				neg++;
			}
		}
	}
	if (pos == 0 && neg == 0) {
		cout << 0 << endl;
		return 0;
	}
	pos == max(pos, neg) ? dirr = 0 : dirr = 1;
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (dirr) {
			if (line[i] < line[i + 1]) {
				ans++;
			}
		}
		else {
			if (line[i] > line[i + 1]) {
				line[i + 1] = line[i];
				ans++;
			}
		}
	}
	cout << ans << endl;
}