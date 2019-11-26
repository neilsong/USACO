#include <bits/stdc++.h>
using namespace std;

int n, m, k;



vector<pair<long long,long long >> words;
vector<long long> dp(5003), lines(5003);


#define MOD 1000000007

//Credit GeeksforGeeks Modular Power Exponentiation
long long power(long long x, long long y)
{
	long long res = 1;      // Initialize result 

	x = x % MOD;  // Update x if it is more than or  
				// equal to p 

	while (y > 0)
	{
		// If y is odd, multiply x with result 
		if (y & 1)
			res = (res * x+MOD) % MOD;

		// y must be even now 
		y = y >> 1; // y = y/2 
		x = (x * x+MOD) % MOD;
	}
	return res;
}

map<char, long long> fmap;


int main(void) {
	ifstream cin("poetry.in");
	ofstream cout("poetry.out");
	cin >> n >> m >> k;
	words.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i].first >> words[i].second;
	}
	char a;
	cin >> a;
	fmap.insert({ a,1 });
	for (int i = 0; i < m-1; i++) {
		cin >> a;
		if (fmap.find(a) == fmap.end()) {
			fmap.insert({ a,0 });
		}
		fmap[a]++;
	}
	dp[0] = 1;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (words[j].first + i > k) continue;
			else if (words[j].first + i == k) lines[words[j].second] = (lines[words[j].second] + dp[i] + MOD) % MOD;
			else dp[words[j].first + i] = (dp[words[j].first + i] + dp[i] + MOD) % MOD;
		}
	}
	long long ans = 1;
	for (auto i : fmap) {
		long long ret = 0;
		for (int j = 0; j <= n;j++) {
			if (lines[j] == 0) continue;
			ret = (ret + power(lines[j], i.second)+MOD) % MOD;
		}
		ans = (ans * ret+MOD) % MOD;
	}
	cout << ans << endl;
}