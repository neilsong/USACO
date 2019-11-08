#include <bits/stdc++.h>
using namespace std;

ifstream fin("teamwork.in");
ofstream fout("teamwork.out");

vector<int> nums;
vector<int> dp;
int n, k;

int main(void) {
	fin >> n >> k;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		fin >> nums[i];
	}
	dp.resize(n);
	dp[0] = nums[0];
	for (int i = 1; i < n; i++) {
		int mx = nums[i];
		for(int j =i; j >= 0 && j > i - k;j--){
			mx = max(mx, nums[j]);
			if (j == 0) dp[i] = max(dp[i], mx * (i + 1 - j));
			else dp[i] = max(dp[i], dp[j - 1] + mx * (i + 1 - j));
		}
	}
	fout << dp[n - 1] << endl;
	return 0;
}