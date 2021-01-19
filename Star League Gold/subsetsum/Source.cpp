#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int> vec;
	vector<vector<int>> sol;
	int n, x;
	cin >> n >> x;
	vec.resize(n);
	sol.resize(n+1);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		sol[i].resize(x+1);
	}
	sol[0][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= x; j++) {
			if (j - vec[i - 1] >= 0) {
				sol[i][j] = sol[i - 1][j] || sol[i - 1][j - vec[i - 1]];
			}
			else {
				sol[i][j] = sol[i - 1][j];
			}
		}
	}
	if (sol[n - 1][x]) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

}