#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1001);
int n, m;
pair<int, int> FJ, B;
vector<pair<int, int>> FJp, Bp;
string path1, path2;
int ans = 0;

int main(void) {
	//ifstream fin("radio.in");
	//ofstream fout("radio.out");
	for (int i = 0; i < 1001; i++) {
		dp[i].resize(1001);
	}
	cin >> n >> m >> FJ.first >> FJ.second >> B.first >> B.second >> path1 >> path2;
	FJ.first--; FJ.second--; B.first--; B.second--;
	FJp.push_back(FJ);
	Bp.push_back(B);
	for (auto i : path1) {
		if (i == 'N') {
			FJp.push_back({ FJp.back().first, FJp.back().second + 1 });
		}
		if (i == 'E') {
			FJp.push_back({ FJp.back().first + 1, FJp.back().second });
		}
		if (i == 'S') {
			FJp.push_back({ FJp.back().first, FJp.back().second - 1 });
		}
		if (i == 'W') {
			FJp.push_back({ FJp.back().first - 1, FJp.back().second });
		}
	}
	for (auto i : path2) {
		if (i == 'N') {
			Bp.push_back({ Bp.back().first, Bp.back().second + 1 });
		}
		if (i == 'E') {
			Bp.push_back({ Bp.back().first + 1, Bp.back().second });
		}
		if (i == 'S') {
			Bp.push_back({ Bp.back().first,Bp.back().second - 1 });
		}
		if (i == 'W') {
			Bp.push_back({ Bp.back().first - 1, Bp.back().second });
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i < FJp.size(); i++) {
		FJ = FJp[i];
		for (int j = 0; j < Bp.size(); j++) {
			B = Bp[j];
			int dist = pow(FJ.first - B.first, 2) + pow(FJ.second - B.second, 2);
			if (i > 0 || j > 0) dp[i][j] = INT_MAX;
			if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist);
			if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + dist);
			if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist);
		}
	}
	cout << dp[n][m] << endl;
}