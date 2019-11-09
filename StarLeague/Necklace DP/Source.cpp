#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	int n;
	cin >> n;
	string necklace;
	cin >> necklace;
	vector <int> rl(n*2);
	vector <int> rr(n * 2);
	vector <int> bl(n * 2);
	vector <int> br(n * 2);

	string wrapped = necklace;
	wrapped += necklace;
	int ans = 0;

	for (int pos = 0; pos < wrapped.length(); pos++) {
		if (!pos) {
			if (wrapped[pos] == 'w') {
				rl[pos] = 1;
				bl[pos] = 1;
			}
			else if (wrapped[pos] == 'r') {
				rl[pos] = 1;
				bl[pos] = 0;
			}
			else {
				rl[pos] = 0;
				bl[pos] = 1;
			}
		}
		else {
			if (wrapped[pos] == 'w') {
				rl[pos] = rl[pos-1]+1;
				bl[pos] = bl[pos - 1] + 1;
			}
			else if (wrapped[pos] == 'r') {
				rl[pos] = rl[pos - 1] + 1;
				bl[pos] = 0;
			}
			else {
				rl[pos] = 0;
				bl[pos] = bl[pos - 1] + 1;
			}
		}
	}
	for (int pos = wrapped.length()-1; pos >-1; pos--) {
		if (pos == wrapped.length()-1) {
			if (wrapped[pos] == 'w') {
				rr[pos] = 1;
				br[pos] = 1;
			}
			else if (wrapped[pos] == 'r') {
				rr[pos] = 1;
				br[pos] = 0;
			}
			else {
				rr[pos] = 0;
				br[pos] = 1;
			}
		}
		else {
			if (wrapped[pos] == 'w') {
				rr[pos] = rr[pos + 1] + 1;
				br[pos] = br[pos + 1] + 1;
			}
			else if (wrapped[pos] == 'r') {
				rr[pos] = rr[pos + 1] + 1;
				br[pos] = 0;
			}
			else {
				rr[pos] = 0;
				br[pos] = br[pos + 1] + 1;
			}
		}
	}
	for (int pos = 0; pos < wrapped.length()-1; pos++) {
		ans = max(ans, max(rl[pos] + br[pos+1], rr[pos+1] + bl[pos]));
	}
	if (ans > necklace.length()) {
		cout << necklace.length() << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}