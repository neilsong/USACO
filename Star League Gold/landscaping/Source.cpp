#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int x, y, z, n;
vector<int> A, B;
int main(void) {
	cin >> n >> x >> y >> z;
	int size = 0;
	A.push_back(0);
	B.push_back(0);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < a; j++) {
			A.push_back(i);
		}
		for (int j = 0; j < b; j++) {
			B.push_back(i);
		}
	}
	dp.resize(A.size());
	for (int i = 0; i < dp.size(); i++) {
		dp[i].resize(B.size());
		dp[i][0] = i * y;
	}
	for (int i = 0; i < B.size(); i++) {
		dp[0][i] = i * x;
	}
	int ans = 0;
	for (int i = 1; i < A.size(); i++) {
		for (int j = 1; j < B.size(); j++) {
			int temp = min(dp[i][j - 1] + x, dp[i - 1][j] + y);
			temp = min(temp, dp[i - 1][j - 1] + (z * abs(A[i] - B[j])));
			dp[i][j] = temp;
		}
	}
	cout << dp[A.size()-1][B.size()-1] << endl;
}