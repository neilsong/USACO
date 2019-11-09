#include <bits/stdc++.h>
using namespace std;
int n, x, sum;
vector<int> coins;
vector<vector<int>> maxsol, ways;
int main(void) {
	cin >> n;
	coins.resize(n+1);
	maxsol.resize(n + 1);
	ways.resize(n + 1);
	sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
		sum += coins[i];
	}
	int k = sum;
	sum /= 2;
	for (int i = 0; i <= n; i++) {
		maxsol[i].resize(sum + 1);
		ways[i].resize(sum + 1);
		maxsol[i][0] = 0;
		ways[i][0] = 1;
	}
	fill(maxsol[0].begin(), maxsol[0].end(), 0);
	fill(ways[0].begin(), ways[0].end(), 0);
	ways[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j - coins[i] >= 0) {
				maxsol[i][j] = max(maxsol[i - 1][j], maxsol[i - 1][j - coins[i]] + coins[i]);
			}
			else {
				maxsol[i][j] = maxsol[i - 1][j];
			}
		}
	}
	cout << abs((k - maxsol[n][sum])- maxsol[n][sum]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j - coins[i] >= 0) {
				ways[i][j] = ways[i - 1][j] + ways[i - 1][j - coins[i]];
			}
			else {
				ways[i][j] = ways[i - 1][j];
			}
		}
	}
	cout << endl << ways[n][sum];
}