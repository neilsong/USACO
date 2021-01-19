#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> sum(2);
vector<vector<vector<int>>> sol;

int f(int s1,int s2, int i) {
	s1 += i;
	if (i == n) {
		if (s1 == s2) {
			s1 -= i;
			sol[s1][s2][i] = 1;
		}
		else {
			s1 -= i;
			sol[s1][s2][i] = 0;
		}
	}
	if (sol[s1][s2][i] > -1) {
		return sol[s1][s2][i];
	}
	else {
		sol[s1][s2][i] = f(s1, s2, i + 1) + f(s2, s1, i + 1);
	}
	s1 -= i;
	return sol[s1+i][s2][i];
	
}

int main(void) {
	cin >> n;
	sol.resize((n*(1+n)/2)+1);
	for (int i = 0; i <= n * (1 + n) / 2; i++) {
		sol[i].resize((n * (1 + n) / 2)+1);
		for (int j = 0; j <= n * (1 + n) / 2; j++) {
			sol[i][j].resize(n + 1);
			fill(sol[i][j].begin(), sol[i][j].end(), -1);
		}
	}
	int ans = f(0, 0, 1);
	cout << ans << endl;
}