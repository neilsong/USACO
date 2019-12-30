#include <bits/stdc++.h>
using namespace std;

map<string, int> dp;

int recur(string s) {
	if (dp.find(s) != dp.end())
		return dp[s];
	int ans = 1;
	int size = s.length();
	for (int i = 1; i * 2 < size; i++) {
		if (s.substr(0, i) == s.substr(size - i, i)) {
			ans += recur(s.substr(i, size - i));
		}
		if (s.substr(0, i) == s.substr(i, i)) {
			ans += recur(s.substr(i, size-i));
		}
		if (s.substr(0, i) == s.substr(size - i, i)) {
			ans += recur(s.substr(0, size - i));
		}
		if (s.substr(size - 2 * i, i) == s.substr(size - i, i)) {
			ans += recur(s.substr(0, size - i));
		}
	}
	ans %= 2014;
	dp[s] = ans;
	return ans;
}


int main(void) {
	//loop i : 0->n/2
	//if (str.subtr(0, i) == str.substr(i, i)) ans += dp[str.substr(i)];
	string s;
	cin >> s;
	int ans = (recur(s) - 1) % 2014;
	cout << ans << endl;
}