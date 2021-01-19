#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f
vector<ll> dx{ 1,-1,0,0 }, dy{ 0,0,-1,1 };
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpair;
typedef vector<vector<pair<ll, ll>>> vvpair;
vll coins;
vvll maxsol;
ll n;
ll sum;
int main(void) {
	cin >> n;
	coins.resize(n + 1);
	maxsol.resize(n + 1);
	sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
		sum += coins[i];
	}
	int k = sum;
	sum /= 2;
	for (int i = 0; i <= n; i++) {
		maxsol[i].resize(sum + 1);
		maxsol[i][0] = 0;
	}
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
	cout << abs((k - maxsol[n][sum]) - maxsol[n][sum]);
	maxsol[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		maxsol[i][0] = 1;
		for (int j = 1; j <= sum; j++) {
			maxsol[i][j] = 0;
			if (j - coins[i] >= 0) {
				maxsol[i][j] = maxsol[i - 1][j] + maxsol[i - 1][j - coins[i]];
			}
			else {
				maxsol[i][j] = maxsol[i - 1][j];
			}
		}
	}
	if (maxsol[n][sum] == 0) cout << 1;
	else cout << endl << maxsol[n][sum];
}