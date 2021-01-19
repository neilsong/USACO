#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec, mini, maxi;
int main(void) {
	cin >> n;
	vec.resize(n+1);
	mini.resize(n+1);
	maxi.resize(n+1);
	maxi[0] = 1;
	mini[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> vec[i];
		maxi[i] = max(maxi[i - 1] * vec[i], mini[i - 1] * vec[i]);
		maxi[i] = max(maxi[i], vec[i]);
		mini[i] = min(maxi[i - 1] * vec[i], mini[i - 1] * vec[i]);
		mini[i] = min(mini[i], vec[i]);
	}
	cout << maxi[n] << endl;
}