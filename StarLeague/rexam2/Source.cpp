#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector <int> cows;
	vector<int> lookup(100001);
	for (int i = 0; i < n; i++) {
		int cow; cin >> cow;
		lookup[i] = -1;
		for (int j = i - 1; j > -1; j--) {
			int onelook = lookup[j];
			if (cow > cows[j]) {
				if (onelook == -1) {
					lookup[j] = i;
				}
				else {
					lookup[j] = min(onelook, i);
				}
				
			}
				
			else break;
		}
		cows.push_back(cow);
	}
	for (auto i : lookup) {
		if (i != 0) {
			cout << i + 1 << endl;
		}
		
	}
}